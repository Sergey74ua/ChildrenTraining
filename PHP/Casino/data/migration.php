<?php
error_reporting(E_ALL);

try {
    //Подключаемся к базе данных
    $connect=new PDO("sqlite:$db");
    //Создаем SQL-запрос на создание таблицы чисел рулетки
    $sql="CREATE TABLE Roulette (
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
        sector INTEGER NOT NULL,
        half INTEGER,
        third INTEGER,
        dozen INTEGER,
        parity TEXT NOT NULL,
        color TEXT NOT NULL,
        stat INTEGER DEFAULT 0
    );";
    //Выполняем SQL-запрос
    $connect->exec($sql);
    echo "Создана таблица: casino/Roulette.<br/>";
    //Заполняем таблицу (желателен цикл)
    $sql = "INSERT INTO Roulette (sector, parity, color) VALUES 
        (0, 'zero', 'green'), 
        (32, 'even', 'red'), 
        (15, 'odd', 'black'),
        (19, 'odd', 'red'),
        (4, 'even', 'black'),
        (2, 'even', 'black'),
        (21, 'odd', 'red'),
        (25, 'odd', 'red'),
        (17, 'odd', 'black'),
        (34, 'even', 'red'),
        (6, 'even', 'black'),
        (27, 'odd', 'red'),
        (13, 'odd', 'black'),
        (36, 'even', 'red'),
        (11, 'odd', 'black'),
        (30, 'even', 'red'),
        (8, 'even', 'black'),
        (23, 'odd', 'red'),
        (10, 'even', 'black'),
        (5, 'odd', 'red'),
        (24, 'even', 'black'),
        (16, 'even', 'red'),
        (33, 'odd', 'black'),
        (1, 'odd', 'red'),
        (20, 'even', 'black'),
        (14, 'even', 'red'),
        (31, 'odd', 'black'),
        (9, 'odd', 'red'),
        (22, 'even', 'black'),
        (18, 'even', 'red'),
        (29, 'odd', 'black'),
        (7, 'odd', 'red'),
        (28, 'even', 'black'),
        (12, 'even', 'red'),
        (35, 'odd', 'black'),
        (3, 'odd', 'red'),
        (26, 'even', 'black')
    ";
    $affectedRowsNumber = $connect->exec($sql);
    echo "В таблицу Roulette добавлено строк: $affectedRowsNumber.<br/>";
    $connect = null;
}
catch (PDOException $e) {
    echo "Ошибка базы данных: " . $e->getMessage();
}