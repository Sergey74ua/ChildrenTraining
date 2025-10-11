jQuery(document).ready(function($) {
    // Поиск питомцев
    $('#search_pet_btn').on('click', function() {
        var searchTerm = $('#search_pet').val();
        if (searchTerm.length < 2) {
            alert('Введите至少 2 символа для поиска');
            return;
        }
        
        $.post(petsNursery.ajaxurl, {
            action: 'search_pets