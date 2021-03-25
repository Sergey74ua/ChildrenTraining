-- phpMyAdmin SQL Dump
-- version 5.0.4
-- https://www.phpmyadmin.net/
--
-- Хост: 127.0.0.1:3306
-- Время создания: Мар 25 2021 г., 17:39
-- Версия сервера: 10.3.22-MariaDB
-- Версия PHP: 7.3.26

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- База данных: `lesson`
--

-- --------------------------------------------------------

--
-- Структура таблицы `orders`
--

CREATE TABLE `orders` (
  `id` int(11) NOT NULL,
  `order_number` int(11) DEFAULT NULL,
  `discount` int(11) DEFAULT NULL,
  `shop_id` int(11) DEFAULT NULL,
  `person_id` int(11) DEFAULT NULL,
  `date_time` datetime DEFAULT current_timestamp()
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Дамп данных таблицы `orders`
--

INSERT INTO `orders` (`id`, `order_number`, `discount`, `shop_id`, `person_id`, `date_time`) VALUES
(1, 1, 5, 1, 1, '2021-03-25 16:08:59'),
(2, 2, 5, 2, 2, '2021-03-25 16:08:59'),
(3, 3, 5, 3, 3, '2021-03-25 16:08:59'),
(4, 4, 5, 4, 4, '2021-03-25 16:08:59'),
(5, 5, 5, 5, 5, '2021-03-25 16:08:59'),
(6, 6, 5, 6, 6, '2021-03-25 16:08:59'),
(7, 7, 5, 5, 7, '2021-03-25 16:08:59'),
(8, 8, 5, 4, 8, '2021-03-25 16:08:59'),
(9, 9, 5, 3, 9, '2021-03-25 16:08:59'),
(10, 10, 5, 2, 10, '2021-03-25 16:08:59');

-- --------------------------------------------------------

--
-- Структура таблицы `people`
--

CREATE TABLE `people` (
  `id` int(11) NOT NULL,
  `name` varchar(48) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `day` date NOT NULL,
  `context` text COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Дамп данных таблицы `people`
--

INSERT INTO `people` (`id`, `name`, `day`, `context`) VALUES
(1, 'Сергей', '1974-06-05', 'Тест ввода строки в таблицу'),
(2, 'Тыченахерущенко', '2000-01-02', NULL),
(3, 'Тыченахерущенко', '1990-02-03', NULL),
(4, 'Вася', '1980-06-15', 'пока ничего'),
(5, 'Туранчекс Таврический', '1980-07-15', 'и тут пока ничего'),
(6, 'Маша', '1980-08-15', 'все еще пока ничего'),
(7, 'Вова', '1980-09-15', 'опять пока ничего'),
(8, 'Агрипина Конесшибченко-Перелюйхатученко', '1900-12-31', 'и опять пока ничего'),
(9, 'Коля', '1980-11-15', 'снова пока ничего'),
(10, 'Архип', '1980-12-15', 'и снова пока ничего'),
(11, 'Прокопий', '1980-06-16', 'и снова опять пока ничего'),
(12, 'Иннокентий', '1980-06-17', 'все еще опять пока ничего');

-- --------------------------------------------------------

--
-- Структура таблицы `shop`
--

CREATE TABLE `shop` (
  `id` int(11) NOT NULL,
  `title` varchar(128) COLLATE utf8mb4_unicode_ci DEFAULT NULL,
  `price` decimal(20,3) DEFAULT NULL,
  `units` varchar(8) COLLATE utf8mb4_unicode_ci DEFAULT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_unicode_ci;

--
-- Дамп данных таблицы `shop`
--

INSERT INTO `shop` (`id`, `title`, `price`, `units`) VALUES
(1, 'iPhone-3', '300.000', '10'),
(2, 'iPhone-4', '300.000', '10'),
(3, 'iPhone-5', '300.000', '10'),
(4, 'iPhone-6', '300.000', '5'),
(5, 'iPhone-7', '300.000', '5'),
(6, 'iPhone-8', '300.000', '5'),
(7, 'iPhone-9', '300.000', '5'),
(8, 'iPhone-10', '300.000', '0'),
(9, 'iPhone-11', '300.000', '0');

--
-- Индексы сохранённых таблиц
--

--
-- Индексы таблицы `orders`
--
ALTER TABLE `orders`
  ADD PRIMARY KEY (`id`),
  ADD KEY `shop_id` (`shop_id`),
  ADD KEY `person_id` (`person_id`);

--
-- Индексы таблицы `people`
--
ALTER TABLE `people`
  ADD PRIMARY KEY (`id`);

--
-- Индексы таблицы `shop`
--
ALTER TABLE `shop`
  ADD PRIMARY KEY (`id`);

--
-- AUTO_INCREMENT для сохранённых таблиц
--

--
-- AUTO_INCREMENT для таблицы `orders`
--
ALTER TABLE `orders`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=11;

--
-- AUTO_INCREMENT для таблицы `people`
--
ALTER TABLE `people`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=14;

--
-- AUTO_INCREMENT для таблицы `shop`
--
ALTER TABLE `shop`
  MODIFY `id` int(11) NOT NULL AUTO_INCREMENT, AUTO_INCREMENT=10;

--
-- Ограничения внешнего ключа сохраненных таблиц
--

--
-- Ограничения внешнего ключа таблицы `orders`
--
ALTER TABLE `orders`
  ADD CONSTRAINT `orders_ibfk_1` FOREIGN KEY (`shop_id`) REFERENCES `shop` (`id`),
  ADD CONSTRAINT `orders_ibfk_2` FOREIGN KEY (`person_id`) REFERENCES `people` (`id`);
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
