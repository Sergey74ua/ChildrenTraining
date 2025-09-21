<?php
/**
 * Plugin Name: Sale Posts Only on Homepage
 * Plugin URI: https://amstaf.ru/
 * Description: Плагин для вывода только записей определенной категории на главной странице
 * Version: 1.1
 * Author: Sergey
 * License: GPL2
 */

if (!defined('ABSPATH')) {
    exit;
}

class AdvancedSalePostsOnly {
    
    private $category_slug = 'sale';
    
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
            $category_slug = get_option('sale_posts_category', $this->category_slug);
            $sale_category = get_category_by_slug($category_slug);
            
            if ($sale_category) {
                $query->set('category_name', $category_slug);
            }
        }
    }
    
    /**
     * Добавляем меню в админку
     */
    public function add_admin_menu() {
        add_options_page(
            'Sale Posts Settings',
            'Sale Posts',
            'manage_options',
            'sale-posts-settings',
            array($this, 'settings_page')
        );
    }
    
    /**
     * Инициализируем настройки
     */
    public function settings_init() {
        register_setting('salePostsPlugin', 'sale_posts_category');
        
        add_settings_section(
            'sale_posts_section',
            'Настройки отображения постов',
            array($this, 'settings_section_callback'),
            'salePostsPlugin'
        );
        
        add_settings_field(
            'sale_posts_category_field',
            'Slug категории',
            array($this, 'category_field_render'),
            'salePostsPlugin',
            'sale_posts_section'
        );
    }
    
    /**
     * Описание секции настроек
     */
    public function settings_section_callback() {
        echo '<p>Настройте отображение постов на главной странице</p>';
    }
    
    /**
     * Поле для ввода slug категории
     */
    public function category_field_render() {
        $category_slug = get_option('sale_posts_category', 'sale');
        ?>
        <input type="text" name="sale_posts_category" value="<?php echo esc_attr($category_slug); ?>">
        <p class="description">Введите slug категории, посты которой будут отображаться на главной странице</p>
        <?php
    }
    
    /**
     * Страница настроек
     */
    public function settings_page() {
        ?>
        <div class="wrap">
            <h1>Настройки Sale Posts</h1>
            <form action="options.php" method="post">
                <?php
                settings_fields('salePostsPlugin');
                do_settings_sections('salePostsPlugin');
                submit_button();
                ?>
            </form>
        </div>
        <?php
    }
    
    /**
     * Проверяем существование категории
     */
    public function check_category_exists() {
        $category_slug = get_option('sale_posts_category', $this->category_slug);
        $category = get_category_by_slug($category_slug);
        
        if (!$category && is_admin()) {
            add_action('admin_notices', function() use ($category_slug) {
                echo '<div class="notice notice-warning">';
                echo '<p><strong>Sale Posts Only:</strong> Категория "' . esc_html($category_slug) . '" не найдена.</p>';
                echo '</div>';
            });
        }
    }
}

// Инициализируем плагин
$advanced_sale_posts = new AdvancedSalePostsOnly();
add_action('admin_init', array($advanced_sale_posts, 'check_category_exists'));