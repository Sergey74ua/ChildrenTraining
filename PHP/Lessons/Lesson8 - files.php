<?php

namespace files;

require 'Lesson5 - function.php'; //незаменимый файл (программа останавливается)
//include 'Необязательный.файл'; //необязательный файл (информирует об ошибке и продолжает работу)
//С исключением повторного подключения
include_once 'Lesson6 - OOP.php';
//require_once 'Необязательный.файл';
echo '<br/>';

//Автозагрузка файлов, где autoloader - название функции подключающей файлы
function autoloader($class) {
    echo "Подключение класса $class <br/>";
    include_once $class . '.php';
}
//spl_autoload_register("autoloader");
//$x = new NewClass(); //Файл с названием неизвестного класса должен подключиться (ДОРАБОТАТЬ)

echo '<h3>Импорт пространства имен.</h3>';
//Путь к классу в другом пространестве имен
//$hero = new Hero('Тест1', 55); //не сработает, т.к. иное пространство имен
$hero = new \lessons\Hero('Тест1', 55); //а так работает
echo $hero -> name, '<br/>';

use \lessons\Hero; //а так можно заранее подключить пространство имен
$hero2 = new Hero('Тест2', 66);
echo $hero2 -> name, '<br/>';

use \lessons\Hero as H; //тоже самое, но с псевдонимом
$hero3 = new H('Тест3', 77);
echo $hero3 -> name, '<br/>';

//use \base\classes\{Person as User, Employee as Employee}; //пример подключения множества классов

//Подключение констант с другого пространства имен
use const \lessons\TEST;
echo TEST, '<br/>';
//Такое же подключение функций
//use function \lessons\имя_функции;

//Файловая система.
echo '<h3>Файловая система.</h3>';
// die = exit; exit(); exit(0); - выход из скрипта, возможно с сообщением об ошибке.

$file = fopen("test.txt", 'w') or die("не удалось открыть файл");
// r  - файл открывается только для чтения. Если файла не существует, возвращает false
// r+ - .. только для чтения с возможностью записи. Если файла не существует, возвращает false
// w  - файл открывается для записи. Если такой файл уже существует, то он перезаписывается, если нет - то он создается
// w+ - .. для записи с возможностью чтения. Если такой файл уже существует, то он перезаписывается, если нет - то он создается
// a  - .. для записи. Если такой файл уже существует, то данные записываются в конец файла, а старые данные остаются. Если файла нет, то он создается
// a+ - .. для чтения и записи. Если файл уже существует, то данные дозаписываются в конец файла. Если файла нет, то он создается
fwrite($file, "Тестовая запись\r\n"); //Запись в файл
fwrite($file, "Еще одна запись" . PHP_EOL);
fclose($file);

$file = fopen("test.txt", 'r') or die("не удалось открыть файл");
while(!feof($file)) {
    $str = htmlentities(fgets($file)); //Чтение из файла
    echo 'Чтение из файла - ', $str, '<br/>';
}
fclose($file);
echo '<br/><br/>';

//Чтение файлов полностью
$str = htmlentities(file_get_contents("test.txt"));
echo $str;

//Создание папки
if(mkdir("NewFolder"))
    echo "Каталог создан.<br/>";
else
    echo "Ошибка при создании каталога.<br/>";

$path = getcwd();
echo $path, '<br/>';

//Копирование файла
if (copy("test.txt", "test_2.txt"))
    echo "Копия файла создана.<br/>";
else
    echo "Ошибка копирования файла.<br/>";

//Перемещение файла
if (!rename("test_2.txt", "NewFolder/test_3.txt"))
    echo "Ошибка перемещения файла.<br/>";
else
    echo "Файл перемещен.<br/>";

//Удаление файла
if (unlink("NewFolder/test_3.txt"))
    echo "Файл удален.<br/>";
else
    echo "Ошибка при удалении файла.<br/>";

//Удаление папки
if(rmdir("NewFolder"))
    echo "Каталог удален.<br/>";
else
    echo "Ошибка при удалении каталога.<br/>";

//Открытие, чтение и вывод содержимого папок
$dir = getcwd(); //получаем текущий каталог
if (is_dir($dir)) { //является ли путь каталогом
    if ($temp = opendir($dir)) { //открываем каталог
        while (($file = readdir($temp)) !== false) { //считываем по одному файл или подкаталогу пока не дойдем до конца
            if($file=='.' || $file=='..')  //пропускаем символы .. и .
                continue;
            if(is_dir($file))
                echo "каталог: $file <br>"; //если каталог или файл
            else
                echo "файл:    $file <br>";
        }
        closedir($temp); //закрываем каталог
    }
}