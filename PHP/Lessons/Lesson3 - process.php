<?php

$x = 5 <=> 6;
echo '5 <=> 6 : ', $x, '<br/>';

if (5 > 3)
    echo 'Да! 5>3.', '<br/>';

if (5 === 3 and 5 > 0 || true)
    echo 'Равно и по типу?', '<br/>';
else if (5 < 3 && (5 > 0 || 3 < 0)) {
    echo 'Меньше?';
    echo '<br/>';
} else
    echo 'Нет! 5 не равно 3.', '<br/><br/>';

//Другой синтаксис
if (20 > 30):
    echo '20 больше 30';
elseif (20 == 30): //Обязательно слитно!
    echo '20 равно 30';
else:
    echo '20 не больше и не равно 30';
endif;
echo '<br/><br/>';

//Тернарный синтаксис
echo 5>2 ? 'Да!' : 'Нет!';
echo '<br/><br/>';

$x = 5;
switch ($x) {
    case 0:
        echo 'Да! $x = 0';
    break;
    case 1:
        echo 'Да! $x = 1';
    break;
    case 5:
        echo 'Да! $x = 5';
    break;
    default:
        echo 'Все остальое ...';
    break;
}
echo '<br/><br/>';

match($x) {
    0 => print 'Да! match $x = 0',
    5 => print 'Да! match $x = 5',
    default => print 'действие по умолчанию',
};
echo '<br/><br/>';

while ($x > 0):
    $x--;
    if ($x == 3)
        continue; //Прервать и продолжить цикл
    if ($x == 0)
        break; //Прервать цикл вообще
    echo $x, ' ';
endwhile;
echo '<br/><br/>';

for ($i = 0; $i < 10; $i++) { //Цикл с счетчиком
	echo $i, ' ';
}
echo '<br/><br/>';

for ($i = 0, $j = 100; $i < 10; $i++, $j += 50) //С несколькими счетчиками
    echo $i, '-', $j, ' ';
echo '<br/><br/>';

for ($i = 0; $i < 15; $i++); //Цикл без операций
echo $i;
echo '<br/><br/>';

for ($i = 0; $i < 15; print $i++ . ' '); //Цикл с встроенными операциями (echo не сработает)
echo '<br/><br/>';

$arr = [11, 22, 33, 44, 55];
foreach ($arr as $elem)
    echo $elem, ' ';
echo '<br/><br/>';

$arr = ['a' => 1, 'b' => 2, 'c' => 3, 'd' => 4, 'e' => 5];
foreach ($arr as $key => $elem) //Если нужны ключи именованного массива
    echo $key, '-', $elem, ' ';

echo '<br/><br/>';