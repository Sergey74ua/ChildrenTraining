<?php

$x = 5;

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