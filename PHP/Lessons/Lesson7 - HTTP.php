<?php

echo '<h3>Протокол HTTP.</h3>';
echo '<h4>GET запросы:</h4>';

// http://localhost:3000/Lesson6%20-%20HTTP.php?TEST

$x = "неизвестное";
if(isset($_GET["x"])) {
    $x = $_GET["x"];
    echo 'Принято из строки браузера: ', $x, '<br/>';
}
// http://localhost:3000/Lesson6%20-%20HTTP.php?x=Sergey
echo '<br/>';

if(isset($_GET["y"])) {
    $y = $_GET["y"];
    echo 'Принято несколько значений из строки(&): <b style="color: Red">', $x, ' ', $y, '</b><br/>';
}
// http://localhost:3000/Lesson6%20-%20HTTP.php?x=Hello&y=World!
echo '<br/>';

// Пример GET с ссылкой
echo '<a href="http://localhost:3000/Lesson6%20-%20HTTP.php?x=НАЖАТА&y=ССЫЛКА">Ссылка с вложенным GET-запросом.</a><br/><br/>';

// Пример GET с кнопкой
?> <form>
    <a href="http://localhost:3000/Lesson6%20-%20HTTP.php?x=НАЖАТА&y=КНОПКА">
        <input type="button" value="Кнопка с вложенным GET-запросом.">
    </a>
</form><br/><br/> <?php

// Пример GET с полем для ввода
?> <form method="GET" action="http://localhost:3000/Lesson6%20-%20HTTP.php">
  Введите Ваше имя: <input type="text" name="y">
  <input type="submit" name="x" value="Привет"/>
</form> <?php

// Вывод результата
echo '<h5>Данные в массиве _GET(var_export):</h5>';
var_export($_GET);
echo '<br/><hr/>';


// Пример с POST с полем для ввода
echo '<h4>POST запросы:</h4>';

$name = "неизвестно";
$age = "неизвестно";
if(isset($_POST["name"]))
    $name = $_POST["name"];
if(isset($_POST["age"]))
    $age = $_POST["age"];
echo "Имя: $name <br/> Возраст: $age";

?>
<h3>Форма ввода данных</h3>
<form method="POST">
    <p>Имя: <input type="text" name="name" /></p>
    <p>Возраст: <input type="number" name="age" /></p>
    <input type="submit" value="Отправить">
</form>
<?php

echo '<br/><hr/>';

//атрибут формы action="user.php" - указывает на файл скрипта, который должен принимать данные.

// Глобальные данные
echo '<h5>Содержимое супер-глабального массива $GLOBALS:</h5>';
var_dump($GLOBALS);
echo '<br/>';
echo '<h5>Данные переданные в $_SERVER[\'argv\'](var_export):</h5>';
var_export($_SERVER['argv']);
echo '<br/>';