<?php
class PetsNurseryShortcodes {
    
    public function __construct() {
        add_shortcode('litter_info', array($this, 'display_litter_info'));
        add_shortcode('pet_info', array($this, 'display_pet_info'));
    }
    
    // Шорткод для отображения информации о выводке
    public function display_litter_info($atts) {
        $atts = shortcode_atts(array(
            'id' => get_the_ID(),
        ), $atts);
        
        $litter_id = $atts['id'];
        $litter = get_post($litter_id);
        
        if (!$litter || $litter->post_type != 'litter') {
            return '';
        }
        
        $birth_date = get_post_meta($litter_id, '_birth_date', true);
        $father_id = get_post_meta($litter_id, '_father_id', true);
        $mother_id = get_post_meta($litter_id, '_mother_id', true);
        $pets_ids = get_post_meta($litter_id, '_pets_ids', true);
        
        ob_start();
        ?>
        <div class="litter-info">
            <h3><?php _e('Информация о выводке', 'pets-nursery'); ?></h3>
            <p><strong><?php _e('Дата рождения:', 'pets-nursery'); ?></strong> <?php echo esc_html($birth_date); ?></p>
            
            <?php if ($father_id): ?>
                <p><strong><?php _e('Отец:', 'pets-nursery'); ?></strong> 
                    <a href="<?php echo get_permalink($father_id); ?>">
                        <?php echo get_the_title($father_id); ?>
                    </a>
                </p>
            <?php endif; ?>
            
            <?php if ($mother_id): ?>
                <p><strong><?php _e('Мать:', 'pets-nursery'); ?></strong> 
                    <a href="<?php echo get_permalink($mother_id); ?>">
                        <?php echo get_the_title($mother_id); ?>
                    </a>
                </p>
            <?php endif; ?>
            
            <?php if ($pets_ids): ?>
                <h4><?php _e('Питомцы в выводке:', 'pets-nursery'); ?></h4>
                <div class="litter-pets">
                    <?php
                    $pets_ids_array = explode(',', $pets_ids);
                    foreach ($pets_ids_array as $pet_id):
                        if ($pet_id && get_post_status($pet_id) == 'publish'):
                    ?>
                        <div class="pet-card">
                            <a href="<?php echo get_permalink($pet_id); ?>">
                                <?php echo get_the_post_thumbnail($pet_id, 'thumbnail'); ?>
                                <h5><?php echo get_the_title($pet_id); ?></h5>
                            </a>
                        </div>
                    <?php
                        endif;
                    endforeach;
                    ?>
                </div>
            <?php endif; ?>
        </div>
        <?php
        return ob_get_clean();
    }
    
    // Шорткод для отображения информации о питомце
    public function display_pet_info($atts) {
        $atts = shortcode_atts(array(
            'id' => get_the_ID(),
        ), $atts);
        
        $pet_id = $atts['id'];
        $pet = get_post($pet_id);
        
        if (!$pet || $pet->post_type != 'pet') {
            return '';
        }
        
        $nickname = get_post_meta($pet_id, '_nickname', true);
        $birth_date = get_post_meta($pet_id, '_birth_date', true);
        $litter_id = get_post_meta($pet_id, '_litter_id', true);
        
        ob_start();
        ?>
        <div class="pet-info">
            <h3><?php _e('Информация о питомце', 'pets-nursery'); ?></h3>
            
            <?php if ($nickname): ?>
                <p><strong><?php _e('Кличка:', 'pets-nursery'); ?></strong> <?php echo esc_html($nickname); ?></p>
            <?php endif; ?>
            
            <p><strong><?php _e('Дата рождения:', 'pets-nursery'); ?></strong> <?php echo esc_html($birth_date); ?></p>
            
            <?php if ($litter_id): 
                $litter = get_post($litter_id);
                if ($litter):
            ?>
                <p><strong><?php _e('Выводок:', 'pets-nursery'); ?></strong> 
                    <a href="<?php echo get_permalink($litter_id); ?>">
                        <?php echo get_the_title($litter_id); ?>
                    </a>
                </p>
                
                <?php
                // Получаем информацию о родителях из выводка
                $father_id = get_post_meta($litter_id, '_father_id', true);
                $mother_id = get_post_meta($litter_id, '_mother_id', true);
                ?>
                
                <div class="pet-parents">
                    <h4><?php _e('Родители:', 'pets-nursery'); ?></h4>
                    <div class="parents-grid">
                        <?php if ($father_id): ?>
                        <div class="parent-card">
                            <strong><?php _e('Отец:', 'pets-nursery'); ?></strong>
                            <a href="<?php echo get_permalink($father_id); ?>">
                                <?php echo get_the_post_thumbnail($father_id, 'thumbnail'); ?>
                                <h5><?php echo get_the_title($father_id); ?></h5>
                            </a>
                        </div>
                        <?php endif; ?>
                        
                        <?php if ($mother_id): ?>
                        <div class="parent-card">
                            <strong><?php _e('Мать:', 'pets-nursery'); ?></strong>
                            <a href="<?php echo get_permalink($mother_id); ?>">
                                <?php echo get_the_post_thumbnail($mother_id, 'thumbnail'); ?>
                                <h5><?php echo get_the_title($mother_id); ?></h5>
                            </a>
                        </div>
                        <?php endif; ?>
                    </div>
                </div>
            <?php
                endif;
            endif;
            ?>
        </div>
        <?php
        return ob_get_clean();
    }
}
?>