<? print('Hello world!'); ?>

</br>
<h1>Любой код HTML</h1>
<!-- HTML комментарий -->
</br>

<?php
    /*
    Основы PHP
    */
    $x = 2; //Переменные без строгой типизации INT
    echo $x;
    echo '<br/>'; //Для консоли - PHP_EOL
    $x += 2.345; //Преобразует в FLOAT
    echo $x, '<br/>'; //Можно выводить набор данных через запятую
    print $x; //Выводит что-то одно, но с return 1(true), удобно для функций
    echo '<br/>';
    print_r($x); //Форматирует в строку
    echo '<br/>';
    var_dump($x); //С указанием типа данных, удобно для отладки
    echo '<br/>';
    var_export($x); //Вывод в формате исполняемого кода
    echo '<br/>';
    echo 'Конкатенация $x' . " - склейка строк. Результат 2+2=$x"; //В одинарных - только строка, в двойных - раскрываются переменные
    echo '<br/>';
    $x='Кон';
    echo $x.='кате', '<br/>';
    echo $x.='нация', '<br/>';
    echo '<br/>';
    $x = null;
    var_dump($x); //Другой вывод не сработает вообще
    echo '<br/><br/>';

    echo (int)123.456, '<br/><br/>';
    /*
    (int), (integer) - приведение к int
    (bool), (boolean) - приведение к bool
    (float), (double), (real) - приведение к float
    (string) - приведение к string
    (array) - приведение к array
    (object) - приведение к object
    (unset) - приведение к NULL
    + (binary) - бинарный код, но сути стринг
    */

    echo("<script>console.log('From PHP with love');</script>");

    $zzz='колдунство с указателями';
    $x='zzz'; //Строка
    echo $x, '<br/>';
    echo $$x, '<br/>';
    echo '<br/><br/>';

    echo 2+2, ' ', 2-2, ' ', 2*2, ' ', 2/2, '<br/>';
    echo 10%3, '<br/>';
    echo abs(-5), '<br/>';
    echo min(10, 20), '<br/>';
    echo max(10, 20), '<br/>';
    echo pow(5, 2), '<br/>';
    echo sqrt(25), '<br/>';
    echo rand(10, 20), '<br/>';
    echo mt_rand(10, 20), '<br/>'; //Более распределенный алгоритм
    echo 'floor : ', floor(5.9), '<br/>';
    echo 'ceil : ', ceil(5.1), '<br/>';
    echo 'round : ', round(5.5), '<br/>';
    echo 'Число Пи: ', M_PI, '<br/>';
    echo 'Число E: ', M_E, '<br/>';

    $x = 10;
    $y = $x++;
    echo 'X++ : ', $x, ' ', $y, '<br/>';
    $x = 10;
    $y = ++$x;
    echo '++X : ', $x, ' ', $y, '<br/>';
    $x = 10;
    $y = $x--;
    echo 'X-- : ', $x, ' ', $y, '<br/>';
    $x = 10;
    $y = --$x;
    echo '--X : ', $x, ' ', $y, '<br/>';

    echo date('d.m.Y H:i'), '<br/>', '<br/>'; //Системная дата, с указанием формата

    echo 2 + '2', '<br/>';
    echo '2' + '2', '<br/>';
    echo 2 + true, '<br/>';
    echo '2' * false, '<br/><br/>';

    $x = false; // без равно, 1, 0, null, false
    echo 'empty : ', empty($x), '<br/>'; //Проверка на пустоту
    echo 'isset : ', isset($x), '<br/><br/>'; //Проверка на существование

    echo strlen('Hello');
    /*
    ОПЕРАЦИИ ДЛЯ СТРОК:
    strtolower, strtoupper, ucfirst, lcfirst, ucwords, strlen, substr,
    str_replace, strtr, substr_replace, strpos, strrpos, strstr, explode,
    implode, str_split, trim, ltrim, rtrim, strrev, str_shuffle,
    number_format, str_repeat, htmlspecialchars, strip_tags, chr, ord,
    str_word_count, substr_count, count_chars, strchr, strrchr
    */

    phpinfo();
?>