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

function func5(string $x) { //С преобразованием типа данных
    var_dump( $x);
    echo '<br/>';
}
func5(12.345);

$f = function($x) { //Переменная = анонимная функция
    echo $x, '<br/>';
};
$f('Переменная = анонимная функция');

//Стрелочные функции (с версии PHP 7.4+)
$x = fn() => 10 + 20;
echo $x();

//Генератор Yield
echo '<br/><p>Yield</p>';
function funk6() {
        yield 1;
        yield 2;
        yield from [3, 4];
        yield from new ArrayIterator([5, 6]);
        yield from funk7();
        yield 9;
        yield 10;
}
    
function funk7() {
    yield 7;
    yield from funk8();
}

function funk8() {
    yield 8;
}

//Вызов функции
foreach (funk6() as $x) {
    echo "$x ";
}