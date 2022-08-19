/* 
 * Скачиваем файлы SQLite, 3 файла для консоли и с графическим интерфейсом
 * Помещаем все в папку и заходим в нее черех консоль (D: - cd путь)
 * набираем sqlite3
 * 
 * А это кстати комментарии, и одиночные --
 */
.help					-- вывод команд транслятора SQLite3
.open lesson.db			-- общее расширение для БД *.db, или конкретно *.sqlite

CREATE TABLE `user`(	-- создаем таблицу
	`name` TEXT,
	`age` INTEGER
);

INSERT INTO `user` VALUES('Sergey', 48);			-- вносим данные в таблицу

SELECT * FROM `user`;								-- выборка данных с таблицы
.mode line		-- построчно
.mode column	-- колонки
.headers on		-- заголовки


/* пример */
CREATE TABLE Roulette (
        id INTEGER NOT NULL PRIMARY KEY AUTOINCREMENT,
        sector INTEGER NOT NULL,
        half INTEGER,
        third INTEGER,
        dozen INTEGER,
        parity TEXT NOT NULL,
        color TEXT NOT NULL,
        stat INTEGER DEFAULT 0
	);