#pragma once

void fillStaff() {
    rc = sqlite3_open("staff.sqlite", &db);
    if (rc)
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

    //Создаем таблицу, если ее нет Shaft
    {
        std::stringstream SQL;
        SQL << "CREATE TABLE IF NOT EXISTS `shaft` (";
        SQL << "   `id` INTEGER PRIMARY KEY AUTOINCREMENT,";
        SQL << "   `material` TEXT,";
        SQL << "   `price` INTEGER";
        SQL << ");";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    {
        std::stringstream SQL;
        SQL << "INSERT INTO `shaft` (`material`, `price`) VALUES";
        SQL << "  ('Акация', 4),";
        SQL << "  ('Английский дуб', 6),";
        SQL << "  ('Боярышник', 3),";
        SQL << "  ('Бузина', 10),";
        SQL << "  ('Бук', 5),";
        SQL << "  ('Виноград', 2),";
        SQL << "  ('Вишневое дерево', 5),";
        SQL << "  ('Вяз', 2),";
        SQL << "  ('Граб', 3),";
        SQL << "  ('Грецкий орех', 6),";
        SQL << "  ('Грушевое дерево', 3),";
        SQL << "  ('Ель', 5),";
        SQL << "  ('Ива', 2),";
        SQL << "  ('Каштан', 3),";
        SQL << "  ('Кедр', 8),";
        SQL << "  ('Кизил', 4),";
        SQL << "  ('Кипарис', 5),";
        SQL << "  ('Клён', 3),";
        SQL << "  ('Красный дуб', 4),";
        SQL << "  ('Лавровое дерево', 5),";
        SQL << "  ('Липа', 7),";
        SQL << "  ('Лиственница', 4),";
        SQL << "  ('Ольха', 3),";
        SQL << "  ('Орешник', 4),";
        SQL << "  ('Осина', 4),";
        SQL << "  ('Остролист', 1),";
        SQL << "  ('Пихта', 2),";
        SQL << "  ('Розовое дерево', 6),";
        SQL << "  ('Рябина', 3),";
        SQL << "  ('Секвойя', 4),";
        SQL << "  ('Сосна', 2),";
        SQL << "  ('Терновник', 5),";
        SQL << "  ('Тис', 3),";
        SQL << "  ('Тополь', 4),";
        SQL << "  ('Чёрный орешник', 6),";
        SQL << "  ('Эбеновое дерево', 6),";
        SQL << "  ('Явор (белый клён)', 11),";
        SQL << "  ('Яблоня', 2),";
        SQL << "  ('Ясень', 4)";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    //Создаем таблицу, если ее нет Core
    {
        std::stringstream SQL;
        SQL << "CREATE TABLE IF NOT EXISTS `core` (";
        SQL << "   `id` INTEGER PRIMARY KEY AUTOINCREMENT,";
        SQL << "   `material` TEXT,";
        SQL << "   `price` INTEGER";
        SQL << ");";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    {
        std::stringstream SQL;
        SQL << "INSERT INTO `core` (`material`, `price`) VALUES";
        SQL << "  ('Волос единорога', 5),";
        SQL << "  ('Перо феникса', 6),";
        SQL << "  ('Сердечная жила дракона', 3),";
        SQL << "  ('Чешуя дракона', 7),";
        SQL << "  ('Коготь дракона', 7),";
        SQL << "  ('Перо гиппогрифа', 4),";
        SQL << "  ('Волос вейлы', 5),";
        SQL << "  ('Волос сфинкса', 3),";
        SQL << "  ('Перо пегаса', 4),";
        SQL << "  ('Шерсть пегаса', 2),";
        SQL << "  ('Сушеный корень мандрагоры', 3),";
        SQL << "  ('Зуб василиска', 8),";
        SQL << "  ('Волчья шерсть', 3),";
        SQL << "  ('Чешуя змеи', 2),";
        SQL << "  ('Жилы из крыла летучей мыши', 1),";
        SQL << "  ('Коготь грифона', 2),";
        SQL << "  ('Чешуя саламандры', 3),";
        SQL << "  ('Перо орла', 4),";
        SQL << "  ('Перо ворона', 2),";
        SQL << "  ('Совиное перо', 3),";
        SQL << "  ('Соколиное перо', 2),";
        SQL << "  ('Петушиное перо', 3),";
        SQL << "  ('Волос кельпи', 5)";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    //Закрываем базу данных
    sqlite3_close(db);
}

//Вывод списка всех студентов, находящихся в базе данных.
/*void StaffCore() {
    rc = sqlite3_open("staff.sqlite", &db);
    if (rc)
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

    std::stringstream SQL;
    SQL << "SELECT * FROM `student`;";

    rc = sqlite3_prepare_v2(db, SQL.str().c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg); sqlite3_free(zErrMsg);
    } else
        while ((rc = sqlite3_step(stmt) == SQLITE_ROW))
            std::cout << sqlite3_column_text(stmt, 0) << ".  "
            << sqlite3_column_text(stmt, 1) << "  -  "
            << sqlite3_column_text(stmt, 2) << "  -  "
            << sqlite3_column_text(stmt, 3) << "  -  "
            << sqlite3_column_text(stmt, 4) << "\n";

    //Закрываем базу данных
    sqlite3_close(db);
}*/

//Вывод информации о конкретном студенте по его имени.
/*void infoStudent() {
    rc = sqlite3_open("staff.sqlite", &db);
    if (rc)
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

    std::string name;
    std::cout << "\nВедите имя студента: ";
    std::cin >> name;

    std::stringstream SQL;
    SQL << "SELECT * FROM `student` WHERE `name` = '" << name << "';";

    rc = sqlite3_prepare_v2(db, SQL.str().c_str(), -1, &stmt, NULL);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg); sqlite3_free(zErrMsg);
    } else
        while ((rc = sqlite3_step(stmt) == SQLITE_ROW))
            std::cout << sqlite3_column_text(stmt, 0) << ".  "
            << sqlite3_column_text(stmt, 1) << "  -  "
            << sqlite3_column_text(stmt, 2) << "  -  "
            << sqlite3_column_text(stmt, 3) << "  -  "
            << sqlite3_column_text(stmt, 4) << "\n";
    std::cout << "\nДанные по студенту.\n";

    //Закрываем базу данных
    sqlite3_close(db);
}*/