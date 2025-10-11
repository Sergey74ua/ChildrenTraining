<?php
/**
 * Plugin Name: Pets Nursery
 * Plugin URI: https://yourwebsite.com/pets-nursery
 * Description: Plugin for managing litters and pets with automatic data synchronization
 * Version: 1.0
 * Author: Your Name
 * Text Domain: pets-nursery
 * Domain Path: /languages
 * License: GPL v2 or later
 */

// Безопасность
if (!defined('ABSPATH')) {
    exit;
}

// Определение констант плагина
define('PETS_NURSERY_PLUGIN_URL', plugin_dir_url(__FILE__));
define('PETS_NURSERY_PLUGIN_PATH', plugin_dir_path(__FILE__));
define('PETS_NURSERY_PLUGIN_VERSION', '1.0');

class PetsNurseryPlugin {
    
    private $litter;
    private $pet;
    private $ajax;
    private $shortcodes;
    
    public function __construct() {
        $this->load_dependencies();
        $this->init_hooks();
    }
    
    // Загрузка зависимостей
    private function load_dependencies() {
        require_once PETS_NURSERY_PLUGIN_PATH . 'includes/class-litter.php';
        require_once PETS_NURSERY_PLUGIN_PATH . 'includes/class-pet.php';
        require_once PETS_NURSERY_PLUGIN_PATH . 'includes/class-ajax.php';
        require_once PETS_NURSERY_PLUGIN_PATH . 'includes/class-shortcodes.php';
    }
    
    // Инициализация хуков
    private function init_hooks() {
        // Регистрация типов записей должна быть на init с высоким приоритетом
        add_action('init', array($this, 'init_components'), 5);
        add_action('admin_enqueue_scripts', array($this, 'enqueue_admin_scripts'));
        add_action('plugins_loaded', array($this, 'load_textdomain'));
    }
    
    // Загрузка переводов
    public function load_textdomain() {
        load_plugin_textdomain(
            'pets-nursery',
            false,
            dirname(plugin_basename(__FILE__)) . '/languages/'
        );
    }
    
    // Инициализация компонентов
    public function init_components() {
        $this->litter = new PetsNurseryLitter();
        $this->pet = new PetsNurseryPet();
        $this->ajax = new PetsNurseryAjax();
        $this->shortcodes = new PetsNurseryShortcodes();
    }
    
    // Подключение скриптов и стилей
    public function enqueue_admin_scripts($hook) {
        global $post_type;
        
        // Подключаем на страницах наших типов записей и на главной странице админки
        $our_post_types = array('litter', 'pet');
        $is_our_post_type = in_array($post_type, $our_post_types);
        $is_edit_page = in_array($hook, array('post.php', 'post-new.php'));
        
        if ($is_our_post_type && $is_edit_page) {
            wp_enqueue_script('jquery');
            wp_enqueue_script(
                'pets-nursery-admin-js',
                PETS_NURSERY_PLUGIN_URL . 'assets/js/admin.js',
                array('jquery'),
                PETS_NURSERY_PLUGIN_VERSION,
                true
            );
            
            wp_enqueue_style(
                'pets-nursery-admin-css',
                PETS_NURSERY_PLUGIN_URL . 'assets/css/admin.css',
                array(),
                PETS_NURSERY_PLUGIN_VERSION
            );
            
            // Локализация скрипта
            wp_localize_script('pets-nursery-admin-js', 'petsNursery', array(
                'ajaxurl' => admin_url('admin-ajax.php'),
                'nonce' => wp_create_nonce('pets_nursery_nonce'),
                'searchNonce' => wp_create_nonce('search_pets_nonce'),
                'createNonce' => wp_create_nonce('create_pet_nonce'),
                'updateDateNonce' => wp_create_nonce('update_pet_date_nonce'),
                'updateDatesNonce' => wp_create_nonce('update_dates_nonce'),
                'litterId' => get_the_ID(),
                'i18n' => array(
                    'searchPlaceholder' => __('Search pet by nickname...', 'pets-nursery'),
                    'searchButton' => __('Search', 'pets-nursery'),
                    'createButton' => __('Create Pet', 'pets-nursery'),
                    'newPetPlaceholder' => __('New pet nickname', 'pets-nursery'),
                    'minChars' => __('Enter at least 2 characters for search', 'pets-nursery'),
                    'petExists' => __('This pet is already added to the litter', 'pets-nursery'),
                    'enterNickname' => __('Enter pet nickname', 'pets-nursery'),
                    'enterBirthDate' => __('First enter the litter birth date', 'pets-nursery'),
                    'petsNotFound' => __('Pets not found', 'pets-nursery')
                )
            ));
        }
    }
}

// Инициализация плагина
new PetsNurseryPlugin();

// Активация плагина - перерегистрируем типы записей
register_activation_hook(__FILE__, 'pets_nursery_activate');
function pets_nursery_activate() {
    // Загружаем классы
    require_once plugin_dir_path(__FILE__) . 'includes/class-litter.php';
    require_once plugin_dir_path(__FILE__) . 'includes/class-pet.php';
    
    // Создаем экземпляры для регистрации типов записей
    $litter = new PetsNurseryLitter();
    $pet = new PetsNurseryPet();
    
    // Явно вызываем регистрацию
    $litter->register_post_type();
    $pet->register_post_type();
    
    // Сбрасываем permalinks
    flush_rewrite_rules();
}

// Деактивация плагина
register_deactivation_hook(__FILE__, 'pets_nursery_deactivate');
function pets_nursery_deactivate() {
    // Сбрасываем permalinks при деактивации
    flush_rewrite_rules();
}
?>