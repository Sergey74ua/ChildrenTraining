<?php

function func() {
    echo 'Привет мир!', '<br/>';
}
func();

function func2($x) {
    echo $x, '<br/>';
}
func2(5);

function func3() {
    return 'Возврат'; //После return - ничего не сработает!
}
echo func3(), '<br/>';

function func4($x = 20) { //С параметром по умолчанию
    echo $x, '<br/>';
}
func4(10);
func4();

function func5(int $x) { //С преобразованием типа данных
    echo $x, '<br/>';
}
func5(12.345);

$f = function($x) { //Переменная = анонимная функция
    echo $x, '<br/>';
};
$f('Переменная = анонимная функция');

/*
//Стрелочные функции с версии PHP 7.4+
$x = fn() => 10 + 20;
echo $x;
*/