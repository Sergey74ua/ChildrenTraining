<?php
namespace lessons;

define('SIZE', 1920); //Константа

class Unit {
    const PI = 3.14;

    public $name;
    private $life;
    protected $pos;

    public function __construct($name, $life=100) {
        $this -> name = $name;
        $this -> life = $life;
        $this -> pos = 200;
    }

    public function getLife($pass) {
        echo self:: PI, '<br/>';
        if ($pass == '123456')
            return $this -> life;
        else
            return 0;
    }
}

echo Unit:: PI; //Константы (статические данные)
echo '<br/><br/>';

$unit = new Unit('Вася', 50);
var_dump($unit);
echo '<br/><br/>';
echo $unit -> name;
echo '<br/><br/>';
//echo $unit -> life; //Ошибка доступа
echo $unit -> getLife('123456');
echo '<br/><br/>';


class Hero extends Unit {
    public static $color='black';
    public $armor;

    public function __construct($name, $life) {
        parent:: __construct($name, $life); //Родительский конструктор
        $this -> armor = 1000;
    }

    public function getPos() {
        echo parent:: PI, '<br/>'; //хотя self тоже работает
        return $this -> pos;
    }

    //Геттеры и сеттеры
    public function __get($name) {
        return $this -> $name;
    }
    
    public function __set($name, $value) {
        $this -> $name = $value;
    }
}

echo Hero::$color, '<br/>';
$hero = new Hero('Вася', 50);
echo $hero -> armor;
echo '<br/><br/>';
echo $hero -> name;
echo '<br/><br/>';
//echo $hero -> pos; //Ошибка доступа
//echo '<br/><br/>';
echo $hero -> getPos();
echo '<br/><br/>';
echo 'instanceof hero - ', $hero instanceof Hero, '<br/>';
echo 'instanceof hero - ', $hero instanceof Unit, '<br/>';
echo 'instanceof unit - ', $unit instanceof Hero, '<br/>'; //Нет!
echo '<br/><br/>';

trait Super { //Набор функций для вставки в класс
    public function talkText() {
        echo 'Супер-герой', '<br/>';
    }
}
 
class SuperHero extends Unit {
    use Super;
}
?>