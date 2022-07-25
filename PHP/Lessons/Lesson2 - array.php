<?php

$arr = array(11, 22, 33, 44, 33);
//echo $arr, '<br/>';
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
echo var_export($week), '<br/><br/>';

//Добавить элемент
$arr[] = 66;
echo var_export($arr), '<br/>';
$arr2['пол'] = 'мальчик';
echo var_export($arr2), '<br/>';

//Проверить наличие элемента
echo '44 в массиве - ', in_array(44, $arr), '<br/>';
echo '444 в массиве - ', in_array(444, $arr), '<br/>';
echo '"44" в массиве - ', in_array("44", $arr), '<br/>';
echo '"44" в массиве с учетом типа - ', in_array("44", $arr, true), '<br/>';
//Позиция первого элемента
echo 'индекс 33 - ', array_search(33, $arr), '<br/>';
//Массив со всеми позициями искомого эдемента
echo 'все индексы 33 - ', print_r(array_keys($arr, 33)), '<br/>';

/*
ОПЕРАЦИИ ДЛЯ МАССИВОВ:
count, in_array, array_sum, array_product, range, array_merge, array_slice,
array_splice, array_keys, array_values, array_combine, array_flip,
array_reverse, array_search, array_replace, array_count_values,
array_rand, shuffle, array_unique, array_shift, array_pop, array_unshift,
array_push, array_pad, array_fill, array_fill_keys, array_chunk,
array_count_values, array_map, array_intersect, array_diff.
*/