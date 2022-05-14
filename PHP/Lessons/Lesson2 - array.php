<?php
    
    $arr = array(11, 22, 33, 44, 55);
    echo $arr, '<br/>';
    echo $arr[2], '<br/>';
    echo print_r($arr), '<br/>';
    echo var_dump($arr), '<br/>';
    echo var_export($arr), '<br/><br/>';

    $arr2 = ['имя' => 'Вася', 'возраст' => 15, 'класс' => '8A', 'оценки' => [5, 3, 4, 5, 'Н/Б'], 'двоешник' => false];
    echo var_dump($arr2), '<br/>';
    echo $arr2['класс'], '<br/>';
    echo var_export($arr2['двоешник']), '<br/>'; //На примере bool очевидно различие функций вывода
    echo $arr2['оценки'][4], '<br/><br/>';

    $week = [1 => 'пн', 'вт', 'ср', 'чт', 'пт', 'сб']; //Автонумерация
    echo $week[3], '<br/>';
    $week[] = 'вс'; //Автодополнение без индекса
    echo $week[7], '<br/>';

    echo count($week), '<br/>';
    sort($week); //asort() - по убыванию
    echo var_export($week), '<br/>';
    /*
    ОПЕРАЦИИ ДЛЯ МАССИВОВ:
    count, in_array, array_sum, array_product, range, array_merge, array_slice,
    array_splice, array_keys, array_values, array_combine, array_flip,
    array_reverse, array_search, array_replace, array_count_values,
    array_rand, shuffle, array_unique, array_shift, array_pop, array_unshift,
    array_push, array_pad, array_fill, array_fill_keys, array_chunk,
    array_count_values, array_map, array_intersect, array_diff, array_map.
    */