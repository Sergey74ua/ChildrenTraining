<?php
class PetsNurseryPet {
    
    public function __construct() {
        // Регистрируем тип записи сразу при создании экземпляра
        add_action('init', array($this, 'register_post_type'));
        add_action('add_meta_boxes', array($this, 'add_meta_boxes'));
        add_action('save_post', array($this, 'save_meta_boxes'), 10, 2);
        
        // Автоматическое создание заголовка для питомца
        add_filter('wp_insert_post_data', array($this, 'auto_generate_pet_title'), 10, 2);
    }
    
    // Регистрация типа записи "Питомцы"
    public function register_post_type() {
        $labels = array(
            'name' => __('Питомцы', 'pets-nursery'),
            'singular_name' => __('Питомец', 'pets-nursery'),
            'add_new' => __('Добавить питомца', 'pets-nursery'),
            'add_new_item' => __('Добавить нового питомца', 'pets-nursery'),
            'edit_item' => __('Редактировать питомца', 'pets-nursery'),
            'new_item' => __('Новый питомец', 'pets-nursery'),
            'view_item' => __('Просмотреть питомца', 'pets-nursery'),
            'search_items' => __('Поиск питомцев', 'pets-nursery'),
            'not_found' => __('Питомцев не найдено', 'pets-nursery'),
            'not_found_in_trash' => __('В корзине питомцев не найдено', 'pets-nursery'),
            'menu_name' => __('Питомцы', 'pets-nursery')
        );
        
        $args = array(
            'labels' => $labels,
            'public' => true,
            'has_archive' => true,
            'menu_icon' => 'dashicons-pets',
            'supports' => array('title', 'editor', 'thumbnail'),
            'rewrite' => array('slug' => 'pets'),
            'show_in_rest' => true,
            'show_in_menu' => true,
            'menu_position' => 26,
            'capability_type' => 'post',
            'show_ui' => true,
        );
        
        register_post_type('pet', $args);
    }
    
    // Добавление метабоксов
    public function add_meta_boxes() {
        add_meta_box(
            'pet_meta',
            __('Информация о питомце', 'pets-nursery'),
            array($this, 'render_pet_meta_box'),
            'pet',
            'normal',
            'high'
        );
    }
    
    // Отображение метабокса для Питомца
    public function render_pet_meta_box($post) {
        wp_nonce_field('pet_meta_nonce', 'pet_meta_nonce');
        
        $nickname = get_post_meta($post->ID, '_nickname', true);
        $birth_date = get_post_meta($post->ID, '_birth_date', true);
        $litter_id = get_post_meta($post->ID, '_litter_id', true);
        
        // Если кличка пустая, используем заголовок
        if (empty($nickname)) {
            $nickname = $post->post_title;
        }
        
        // Получаем все выводки для выбора
        $all_litters = get_posts(array(
            'post_type' => 'litter',
            'numberposts' => -1,
            'post_status' => 'publish'
        ));
        
        ?>
        <div class="pet-meta-fields">
            <p>
                <label for="nickname"><?php _e('Кличка:', 'pets-nursery'); ?></label>
                <input type="text" id="nickname" name="nickname" value="<?php echo esc_attr($nickname); ?>" style="width: 300px;">
                <br><small><?php _e('Кличка автоматически становится заголовком питомца. Вы можете изменить заголовок выше.', 'pets-nursery'); ?></small>
            </p>
            
            <p>
                <label for="birth_date"><?php _e('Дата рождения:', 'pets-nursery'); ?></label>
                <input type="date" id="birth_date" name="birth_date" value="<?php echo esc_attr($birth_date); ?>" style="width: 200px;">
                <br><small><?php _e('Если питомец привязан к выводку, дата рождения автоматически берется из выводка', 'pets-nursery'); ?></small>
            </p>
            
            <p>
                <label for="litter_id"><?php _e('Выводок:', 'pets-nursery'); ?></label>
                <select id="litter_id" name="litter_id" style="width: 300px;">
                    <option value="">-- <?php _e('Выберите выводок', 'pets-nursery'); ?> --</option>
                    <?php foreach ($all_litters as $litter): 
                        $litter_birth_date = get_post_meta($litter->ID, '_birth_date', true);
                    ?>
                        <option value="<?php echo $litter->ID; ?>" 
                                data-birth-date="<?php echo esc_attr($litter_birth_date); ?>"
                                <?php selected($litter_id, $litter->ID); ?>>
                            <?php echo esc_html($litter->post_title . ' (' . $litter_birth_date . ')'); ?>
                        </option>
                    <?php endforeach; ?>
                </select>
            </p>
        </div>
        <?php
    }
    
    // Автоматическое создание заголовка для питомца
    public function auto_generate_pet_title($data, $postarr) {
        if ($data['post_type'] == 'pet' && !empty($_POST['nickname'])) {
            $data['post_title'] = sanitize_text_field($_POST['nickname']);
        }
        return $data;
    }
    
    // Сохранение метаполей
    public function save_meta_boxes($post_id, $post) {
        // Проверки безопасности
        if (defined('DOING_AUTOSAVE') && DOING_AUTOSAVE) return;
        if (!current_user_can('edit_post', $post_id)) return;
        
        // Сохранение для Питомца
        if (get_post_type($post_id) == 'pet') {
            if (!isset($_POST['pet_meta_nonce']) || !wp_verify_nonce($_POST['pet_meta_nonce'], 'pet_meta_nonce')) return;
            
            if (isset($_POST['nickname'])) {
                update_post_meta($post_id, '_nickname', sanitize_text_field($_POST['nickname']));
            }
            if (isset($_POST['birth_date'])) {
                update_post_meta($post_id, '_birth_date', sanitize_text_field($_POST['birth_date']));
            }
            if (isset($_POST['litter_id'])) {
                $old_litter_id = get_post_meta($post_id, '_litter_id', true);
                $new_litter_id = intval($_POST['litter_id']);
                update_post_meta($post_id, '_litter_id', $new_litter_id);
                
                // Если выбрали новый выводок, берем дату рождения из него
                if ($new_litter_id && $new_litter_id != $old_litter_id) {
                    $litter_birth_date = get_post_meta($new_litter_id, '_birth_date', true);
                    if ($litter_birth_date) {
                        update_post_meta($post_id, '_birth_date', $litter_birth_date);
                    }
                }
            }
        }
    }
}
?>