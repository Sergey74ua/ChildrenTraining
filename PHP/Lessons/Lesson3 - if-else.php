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