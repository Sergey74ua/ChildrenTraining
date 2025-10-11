<?php
/**
 * Plugin Name: Advanced Sale Posts Only on Homepage
 * Plugin URI: https://amstaf.ru/
 * Description: Плагин для вывода только записей выбранной категории, метки или типа записи на главной странице
 * Version: 1.2
 * Author: Sergey
 * License: GPL2
 */

if (!defined('ABSPATH')) {
    exit;
}

class AdvancedSalePostsOnly {
    
    private $default_category_slug = 'sale';
    private $default_post_type = 'post';
    private $default_max_posts = 10;
    
    public function __construct() {
        add_action('pre_get_posts', array($this, 'filter_homepage_posts'));
        add_action('admin_menu', array($this, 'add_admin_menu'));
        add_action('admin_init', array($this, 'settings_init'));
    }
    
    /**
     * Фильтруем посты на главной странице
     */
    public function filter_homepage_posts($query) {
        if ($query->is_home() && $query->is_main_query()) {
            $filter_type = get_option('sale_posts_filter_type', 'category');
            $filter_value = get_option('sale_posts_filter_value', $this->default_category_slug);
            $max_posts = get_option('sale_posts_max_count', $this->default_max_posts);
            
            // Устанавливаем максимальное количество постов
            if (!empty($max_posts) && is_numeric($max_posts)) {
                $query->set('posts_per_page', intval($max_posts));
            }
            
            // Применяем фильтр в зависимости от выбранного типа
            switch ($filter_type) {
                case 'category':
                    if (!empty($filter_value)) {
                        $query->set('category_name', $filter_value);
                    }
                    break;
                    
                case 'tag':
                    if (!empty($filter_value)) {
                        $query->set('tag', $filter_value);
                    }
                    break;
                    
                case 'post_type':
                    if (!empty($filter_value)) {
                        $query->set('post_type', $filter_value);
                    }
                    break;
                    
                case 'taxonomy':
                    $taxonomy_parts = explode(':', $filter_value);
                    if (count($taxonomy_parts) === 2) {
                        $taxonomy = $taxonomy_parts[0];
                        $term_slug = $taxonomy_parts[1];
                        $query->set('tax_query', array(
                            array(
                                'taxonomy' => $taxonomy,
                                'field' => 'slug',
                                'terms' => $term_slug,
                            )
                        ));
                    }
                    break;
            }
        }
    }
    
    /**
     * Добавляем меню в админку
     */
    public function add_admin_menu() {
        add_options_page(
            'Advanced Posts Filter Settings',
            'Posts Filter',
            'manage_options',
            'advanced-posts-filter-settings',
            array($this, 'settings_page')
        );
    }
    
    /**
     * Инициализируем настройки
     */
    public function settings_init() {
        register_setting('advancedPostsFilterPlugin', 'sale_posts_filter_type');
        register_setting('advancedPostsFilterPlugin', 'sale_posts_filter_value');
        register_setting('advancedPostsFilterPlugin', 'sale_posts_max_count');
        
        add_settings_section(
            'advanced_posts_filter_section',
            'Настройки отображения постов на главной странице',
            array($this, 'settings_section_callback'),
            'advancedPostsFilterPlugin'
        );
        
        add_settings_field(
            'sale_posts_filter_type_field',
            'Тип фильтра',
            array($this, 'filter_type_field_render'),
            'advancedPostsFilterPlugin',
            'advanced_posts_filter_section'
        );
        
        add_settings_field(
            'sale_posts_filter_value_field',
            'Значение для фильтра',
            array($this, 'filter_value_field_render'),
            'advancedPostsFilterPlugin',
            'advanced_posts_filter_section'
        );
        
        add_settings_field(
            'sale_posts_max_count_field',
            'Максимальное количество записей',
            array($this, 'max_count_field_render'),
            'advancedPostsFilterPlugin',
            'advanced_posts_filter_section'
        );
    }
    
    /**
     * Описание секции настроек
     */
    public function settings_section_callback() {
        echo '<p>Настройте отображение постов на главной странице. Выберите тип фильтра и соответствующее значение.</p>';
    }
    
    /**
     * Поле для выбора типа фильтра
     */
    public function filter_type_field_render() {
        $current_type = get_option('sale_posts_filter_type', 'category');
        ?>
        <select name="sale_posts_filter_type" id="sale_posts_filter_type">
            <option value="category" <?php selected($current_type, 'category'); ?>>Категория</option>
            <option value="tag" <?php selected($current_type, 'tag'); ?>>Метка (тег)</option>
            <option value="post_type" <?php selected($current_type, 'post_type'); ?>>Тип записи</option>
            <option value="taxonomy" <?php selected($current_type, 'taxonomy'); ?>>Произвольная таксономия</option>
        </select>
        <p class="description">Выберите тип контента для фильтрации на главной странице</p>
        
        <script>
        jQuery(document).ready(function($) {
            function updateFilterValueOptions() {
                var filterType = $('#sale_posts_filter_type').val();
                var data = {
                    'action': 'get_filter_options',
                    'filter_type': filterType,
                    'nonce': '<?php echo wp_create_nonce('filter_options_nonce'); ?>'
                };
                
                $.post(ajaxurl, data, function(response) {
                    if (response.success) {
                        $('#sale_posts_filter_value').html(response.data.options);
                    }
                });
            }
            
            $('#sale_posts_filter_type').change(updateFilterValueOptions);
        });
        </script>
        <?php
    }
    
    /**
     * Поле для выбора значения фильтра
     */
    public function filter_value_field_render() {
        $current_type = get_option('sale_posts_filter_type', 'category');
        $current_value = get_option('sale_posts_filter_value', $this->default_category_slug);
        
        echo $this->get_filter_value_options($current_type, $current_value);
        ?>
        <p class="description" id="filter_value_description">
            <?php echo $this->get_filter_value_description($current_type); ?>
        </p>
        <?php
    }
    
    /**
     * Поле для максимального количества записей
     */
    public function max_count_field_render() {
        $max_posts = get_option('sale_posts_max_count', $this->default_max_posts);
        ?>
        <input type="number" name="sale_posts_max_count" value="<?php echo esc_attr($max_posts); ?>" min="1" max="100" step="1">
        <p class="description">Максимальное количество записей для отображения на главной странице (1-100)</p>
        <?php
    }
    
    /**
     * Генерирует опции для выпадающего списка в зависимости от типа фильтра
     */
    private function get_filter_value_options($filter_type, $current_value = '') {
        $options = '';
        
        switch ($filter_type) {
            case 'category':
                $categories = get_categories(array('hide_empty' => false));
                foreach ($categories as $category) {
                    $selected = selected($current_value, $category->slug, false);
                    $options .= "<option value='{$category->slug}' {$selected}>{$category->name} ({$category->slug})</option>";
                }
                break;
                
            case 'tag':
                $tags = get_tags(array('hide_empty' => false));
                foreach ($tags as $tag) {
                    $selected = selected($current_value, $tag->slug, false);
                    $options .= "<option value='{$tag->slug}' {$selected}>{$tag->name} ({$tag->slug})</option>";
                }
                break;
                
            case 'post_type':
                $post_types = get_post_types(array('public' => true), 'objects');
                foreach ($post_types as $post_type) {
                    $selected = selected($current_value, $post_type->name, false);
                    $options .= "<option value='{$post_type->name}' {$selected}>{$post_type->label} ({$post_type->name})</option>";
                }
                break;
                
            case 'taxonomy':
                $taxonomies = get_taxonomies(array('public' => true), 'objects');
                foreach ($taxonomies as $taxonomy) {
                    $terms = get_terms(array(
                        'taxonomy' => $taxonomy->name,
                        'hide_empty' => false
                    ));
                    
                    foreach ($terms as $term) {
                        $value = $taxonomy->name . ':' . $term->slug;
                        $selected = selected($current_value, $value, false);
                        $options .= "<option value='{$value}' {$selected}>{$taxonomy->labels->singular_name}: {$term->name} ({$term->slug})</option>";
                    }
                }
                break;
        }
        
        return "<select name='sale_posts_filter_value' id='sale_posts_filter_value'>{$options}</select>";
    }
    
    /**
     * Возвращает описание для поля значения фильтра
     */
    private function get_filter_value_description($filter_type) {
        switch ($filter_type) {
            case 'category': return 'Выберите категорию, посты которой будут отображаться на главной странице';
            case 'tag': return 'Выберите метку (тег), посты которой будут отображаться на главной странице';
            case 'post_type': return 'Выберите тип записи, который будет отображаться на главной странице';
            case 'taxonomy': return 'Выберите термин из произвольной таксономии для отображения на главной странице';
            default: return 'Выберите значение для фильтра';
        }
    }
    
    /**
     * AJAX обработчик для получения опций
     */
    public function ajax_get_filter_options() {
        check_ajax_referer('filter_options_nonce', 'nonce');
        
        $filter_type = sanitize_text_field($_POST['filter_type']);
        $options = $this->get_filter_value_options($filter_type);
        $description = $this->get_filter_value_description($filter_type);
        
        wp_send_json_success(array(
            'options' => $options,
            'description' => $description
        ));
    }
    
    /**
     * Страница настроек
     */
    public function settings_page() {
        ?>
        <div class="wrap">
            <h1>Настройки фильтра постов на главной странице</h1>
            <form action="options.php" method="post">
                <?php
                settings_fields('advancedPostsFilterPlugin');
                do_settings_sections('advancedPostsFilterPlugin');
                submit_button();
                ?>
            </form>
        </div>
        <?php
    }
    
    /**
     * Проверяем существование выбранного значения фильтра
     */
    public function check_filter_exists() {
        $filter_type = get_option('sale_posts_filter_type', 'category');
        $filter_value = get_option('sale_posts_filter_value', $this->default_category_slug);
        
        $exists = false;
        
        switch ($filter_type) {
            case 'category':
                $exists = get_category_by_slug($filter_value) !== false;
                break;
                
            case 'tag':
                $tag = get_term_by('slug', $filter_value, 'post_tag');
                $exists = $tag !== false;
                break;
                
            case 'post_type':
                $exists = post_type_exists($filter_value);
                break;
                
            case 'taxonomy':
                $taxonomy_parts = explode(':', $filter_value);
                if (count($taxonomy_parts) === 2) {
                    $taxonomy = $taxonomy_parts[0];
                    $term_slug = $taxonomy_parts[1];
                    $term = get_term_by('slug', $term_slug, $taxonomy);
                    $exists = $term !== false && taxonomy_exists($taxonomy);
                }
                break;
        }
        
        if (!$exists && is_admin() && !empty($filter_value)) {
            add_action('admin_notices', function() use ($filter_type, $filter_value) {
                echo '<div class="notice notice-warning">';
                echo '<p><strong>Advanced Posts Filter:</strong> Выбранный фильтр "' . esc_html($filter_type) . '" со значением "' . esc_html($filter_value) . '" не найден.</p>';
                echo '</div>';
            });
        }
    }
}

// Инициализируем плагин
$advanced_sale_posts = new AdvancedSalePostsOnly();

// Регистрируем AJAX обработчики
add_action('wp_ajax_get_filter_options', array($advanced_sale_posts, 'ajax_get_filter_options'));

// Проверяем существование выбранного фильтра
add_action('admin_init', array($advanced_sale_posts, 'check_filter_exists'));