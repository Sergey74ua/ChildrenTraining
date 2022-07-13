<?php
namespace files;

require 'Lesson5 - OOP.php'; //незаменимый файл (программа останавливается)
include 'Lesson5 - HTTP.___'; //необязательный файл (информирует об ошибке и продолжает работу)
//С исключением повторного подключения
include_once 'Lesson5 - OOP.php';
require_once 'Lesson5 - HTTP.___';

////////////////////////////// ДОРАБОТАТЬ
$hero = new \lessons\Hero();

use \lessons\Hero;
$hero2 = new Hero();

use const \lessons\SIZE;
echo SIZE;

use function \lessons\Hero\getPos;
getPos();