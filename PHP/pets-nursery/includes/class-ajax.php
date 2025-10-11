<?php
class PetsNurseryAjax {
    
    public function __construct() {
        // AJAX обработчики
        add_action('wp_ajax_search_pets', array($this, 'ajax_search_pets'));
        add_action('wp_ajax_create_pet_for_litter', array($this, 'ajax_create_pet_for_litter'));
        add_action('wp_ajax_update_pet_birth_date', array($this, 'ajax_update_pet_birth_date'));
        add_action('wp_ajax_update_litter_pets_birth_dates', array($this, 'ajax_update_litter_pets_birth_dates'));
    }
    
    // AJAX поиск питомцев
    public function ajax_search_pets() {
        check_ajax_referer('search_pets_nonce', 'security');
        
        $search_term = sanitize_text_field($_POST['search_term']);
        
        $pets = get_posts(array(
            'post_type' => 'pet',
            's' => $search_term,
            'numberposts' => 10,
            'post_status' => 'publish'
        ));
        
        $results = array();
        foreach ($pets as $pet) {
            $results[] = array(
                'id' => $pet->ID,
                'title' => $pet->post_title
            );
        }
        
        if (!empty($results)) {
            wp_send_json_success($results);
        } else {
            wp_send_json_error(__('Питомцы не найдены', 'pets-nursery'));
        }
    }
    
    // AJAX создание питомца для выводка
    public function ajax_create_pet_for_litter() {
        check_ajax_referer('create_pet_nonce', 'security');
        
        $nickname = sanitize_text_field($_POST['nickname']);
        $birth_date = sanitize_text_field($_POST['birth_date']);
        $litter_id = intval($_POST['litter_id']);
        
        if (empty($nickname)) {
            wp_send_json_error(__('Кличка не может быть пустой', 'pets-nursery'));
        }
        
        // Создаем нового питомца
        $pet_id = wp_insert_post(array(
            'post_type' => 'pet',
            'post_title' => $nickname,
            'post_status' => 'publish',
            'meta_input' => array(
                '_nickname' => $nickname,
                '_birth_date' => $birth_date,
                '_litter_id' => $litter_id
            )
        ));
        
        if ($pet_id && !is_wp_error($pet_id)) {
            wp_send_json_success(array(
                'id' => $pet_id,
                'title' => $nickname
            ));
        } else {
            wp_send_json_error(__('Ошибка при создании питомца', 'pets-nursery'));
        }
    }
    
    // AJAX обновление даты рождения питомца
    public function ajax_update_pet_birth_date() {
        check_ajax_referer('update_pet_date_nonce', 'security');
        
        $pet_id = intval($_POST['pet_id']);
        $birth_date = sanitize_text_field($_POST['birth_date']);
        
        if ($pet_id && $birth_date) {
            update_post_meta($pet_id, '_birth_date', $birth_date);
            wp_send_json_success();
        } else {
            wp_send_json_error();
        }
    }
    
    // AJAX обновление дат рождения всех питомцев выводка
    public function ajax_update_litter_pets_birth_dates() {
        check_ajax_referer('update_dates_nonce', 'security');
        
        $litter_id = intval($_POST['litter_id']);
        $birth_date = sanitize_text_field($_POST['birth_date']);
        $pets_ids = sanitize_text_field($_POST['pets_ids']);
        
        if ($litter_id && $birth_date && $pets_ids) {
            $pets_ids_array = explode(',', $pets_ids);
            foreach ($pets_ids_array as $pet_id) {
                if ($pet_id) {
                    update_post_meta($pet_id, '_birth_date', $birth_date);
                }
            }
            wp_send_json_success();
        } else {
            wp_send_json_error();
        }
    }
}
?>