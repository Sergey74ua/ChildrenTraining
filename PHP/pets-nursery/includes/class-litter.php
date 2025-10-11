<?php
class PetsNurseryLitter {
    
    public function __construct() {
        // Регистрируем тип записи сразу при создании экземпляра
        add_action('init', array($this, 'register_post_type'));
        add_action('add_meta_boxes', array($this, 'add_meta_boxes'));
        add_action('save_post', array($this, 'save_meta_boxes'), 10, 2);
        add_action('updated_post_meta', array($this, 'sync_birth_dates'), 10, 4);
    }
    
    // Регистрация типа записи "Выводок"
    public function register_post_type() {
        $labels = array(
            'name' => __('Выводки', 'pets-nursery'),
            'singular_name' => __('Выводок', 'pets-nursery'),
            'add_new' => __('Добавить выводок', 'pets-nursery'),
            'add_new_item' => __('Добавить новый выводок', 'pets-nursery'),
            'edit_item' => __('Редактировать выводок', 'pets-nursery'),
            'new_item' => __('Новый выводок', 'pets-nursery'),
            'view_item' => __('Просмотреть выводок', 'pets-nursery'),
            'search_items' => __('Поиск выводков', 'pets-nursery'),
            'not_found' => __('Выводков не найдено', 'pets-nursery'),
            'not_found_in_trash' => __('В корзине выводков не найдено', 'pets-nursery'),
            'menu_name' => __('Выводки', 'pets-nursery')
        );
        
        $args = array(
            'labels' => $labels,
            'public' => true,
            'has_archive' => true,
            'menu_icon' => 'dashicons-groups',
            'supports' => array('title', 'editor', 'thumbnail'),
            'rewrite' => array('slug' => 'litters'),
            'show_in_rest' => true,
            'show_in_menu' => true,
            'menu_position' => 25,
            'capability_type' => 'post',
            'show_ui' => true,
        );
        
        register_post_type('litter', $args);
    }
    
    // Добавление метабоксов
    public function add_meta_boxes() {
        add_meta_box(
            'litter_meta',
            __('Информация о выводке', 'pets-nursery'),
            array($this, 'render_litter_meta_box'),
            'litter',
            'normal',
            'high'
        );
    }
    
    // Отображение метабокса для Выводка
    public function render_litter_meta_box($post) {
        wp_nonce_field('litter_meta_nonce', 'litter_meta_nonce');
        
        $birth_date = get_post_meta($post->ID, '_birth_date', true);
        $father_id = get_post_meta($post->ID, '_father_id', true);
        $mother_id = get_post_meta($post->ID, '_mother_id', true);
        $pets_ids = get_post_meta($post->ID, '_pets_ids', true);
        
        // Получаем всех питомцев для выбора родителей
        $all_pets = get_posts(array(
            'post_type' => 'pet',
            'numberposts' => -1,
            'post_status' => 'publish'
        ));
        
        ?>
        <div class="litter-meta-fields">
            <p>
                <label for="birth_date"><?php _e('Дата рождения выводка:', 'pets-nursery'); ?></label>
                <input type="date" id="birth_date" name="birth_date" value="<?php echo esc_attr($birth_date); ?>" style="width: 200px;">
                <br><small><?php _e('Эта дата автоматически станет датой рождения всех питомцев в выводке', 'pets-nursery'); ?></small>
            </p>
            
            <p>
                <label for="father_id"><?php _e('Отец:', 'pets-nursery'); ?></label>
                <select id="father_id" name="father_id" style="width: 300px;">
                    <option value="">-- <?php _e('Выберите отца', 'pets-nursery'); ?> --</option>
                    <?php foreach ($all_pets as $pet): ?>
                        <option value="<?php echo $pet->ID; ?>" <?php selected($father_id, $pet->ID); ?>>
                            <?php echo esc_html($pet->post_title); ?>
                        </option>
                    <?php endforeach; ?>
                </select>
            </p>
            
            <p>
                <label for="mother_id"><?php _e('Мать:', 'pets-nursery'); ?></label>
                <select id="mother_id" name="mother_id" style="width: 300px;">
                    <option value="">-- <?php _e('Выберите мать', 'pets-nursery'); ?> --</option>
                    <?php foreach ($all_pets as $pet): ?>
                        <option value="<?php echo $pet->ID; ?>" <?php selected($mother_id, $pet->ID); ?>>
                            <?php echo esc_html($pet->post_title); ?>
                        </option>
                    <?php endforeach; ?>
                </select>
            </p>
            
            <p>
                <label><?php _e('Питомцы в выводке:', 'pets-nursery'); ?></label>
                <div id="pets_list">
                    <?php
                    if (!empty($pets_ids)) {
                        $pets_ids_array = explode(',', $pets_ids);
                        foreach ($pets_ids_array as $pet_id) {
                            if ($pet_id) {
                                $pet = get_post($pet_id);
                                if ($pet) {
                                    echo '<div class="pet-item">';
                                    echo '<span>' . esc_html($pet->post_title) . '</span>';
                                    echo '<button type="button" class="remove-pet" data-pet-id="' . $pet_id . '">×</button>';
                                    echo '</div>';
                                }
                            }
                        }
                    }
                    ?>
                </div>
                <input type="hidden" id="pets_ids" name="pets_ids" value="<?php echo esc_attr($pets_ids); ?>">
                
                <div style="margin-top: 10px;">
                    <input type="text" id="search_pet" placeholder="<?php _e('Поиск питомца по кличке...', 'pets-nursery'); ?>" style="width: 300px;">
                    <button type="button" id="search_pet_btn" class="button"><?php _e('Найти', 'pets-nursery'); ?></button>
                    <div id="search_results" style="margin-top: 10px;"></div>
                </div>
                
                <div style="margin-top: 15px; padding: 10px; background: #f7f7f7;">
                    <strong><?php _e('Или создайте нового питомца:', 'pets-nursery'); ?></strong>
                    <input type="text" id="new_pet_nickname" placeholder="<?php _e('Кличка нового питомца', 'pets-nursery'); ?>" style="width: 250px; margin: 5px;">
                    <button type="button" id="create_pet_btn" class="button"><?php _e('Создать питомца', 'pets-nursery'); ?></button>
                </div>
            </p>
        </div>
        <?php
    }
    
    // Синхронизация дат рождения
    public function sync_birth_dates($meta_id, $post_id, $meta_key, $meta_value) {
        // Если обновилась дата рождения выводка
        if ($meta_key == '_birth_date') {
            $post_type = get_post_type($post_id);
            
            if ($post_type == 'litter') {
                // Обновляем даты рождения всех питомцев в выводке
                $pets_ids = get_post_meta($post_id, '_pets_ids', true);
                if ($pets_ids) {
                    $pets_ids_array = explode(',', $pets_ids);
                    foreach ($pets_ids_array as $pet_id) {
                        if ($pet_id) {
                            update_post_meta($pet_id, '_birth_date', $meta_value);
                        }
                    }
                }
            }
        }
        
        // Если питомец добавлен в выводок
        if ($meta_key == '_pets_ids') {
            $litter_birth_date = get_post_meta($post_id, '_birth_date', true);
            if ($litter_birth_date && $meta_value) {
                $pets_ids_array = explode(',', $meta_value);
                foreach ($pets_ids_array as $pet_id) {
                    if ($pet_id) {
                        update_post_meta($pet_id, '_birth_date', $litter_birth_date);
                    }
                }
            }
        }
    }
    
    // Сохранение метаполей
    public function save_meta_boxes($post_id, $post) {
        // Проверки безопасности
        if (defined('DOING_AUTOSAVE') && DOING_AUTOSAVE) return;
        if (!current_user_can('edit_post', $post_id)) return;
        
        // Сохранение для Выводка
        if (get_post_type($post_id) == 'litter') {
            if (!isset($_POST['litter_meta_nonce']) || !wp_verify_nonce($_POST['litter_meta_nonce'], 'litter_meta_nonce')) return;
            
            if (isset($_POST['birth_date'])) {
                update_post_meta($post_id, '_birth_date', sanitize_text_field($_POST['birth_date']));
            }
            if (isset($_POST['father_id'])) {
                update_post_meta($post_id, '_father_id', intval($_POST['father_id']));
            }
            if (isset($_POST['mother_id'])) {
                update_post_meta($post_id, '_mother_id', intval($_POST['mother_id']));
            }
            if (isset($_POST['pets_ids'])) {
                update_post_meta($post_id, '_pets_ids', sanitize_text_field($_POST['pets_ids']));
            }
        }
    }
}
?>