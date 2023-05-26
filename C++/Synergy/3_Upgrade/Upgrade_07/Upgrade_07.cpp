//Настроить проект С++ для работы с любой СУБД, сделать любой запрос к существующей базе данных на вашем компьютере.
//Сделать скрины этапов подключения, результата запуска проекта и данных, которые хранятся в таблицах базы данных.

#include "sqlite3.h"
#include <iostream>
#include <sstream>

sqlite3* db;
char* zErrMsg = 0;
int rc;
sqlite3_stmt* stmt;

int main()
{
    //Создаем/открываем базу даных
    rc = sqlite3_open("Upgrade_07.sqlite", &db);
    if (rc) {
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
        return(0);
    }

    //Создаем таблицу
    {
        std::stringstream SQL;
        SQL << "CREATE TABLE `playlist`(";
        SQL << "   `id` INTEGER PRIMARY KEY AUTOINCREMENT,";
        SQL << "   `title` TEXT,";
        SQL << "   `artist` TEXT";
        SQL << ");";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    //Записываем данные
    {
        std::stringstream SQL;
        SQL << "INSERT INTO `playlist` (`title`, `artist`) VALUES";
        SQL << "  ('Queen', 'Bohemian Rhapsody'),";
        SQL << "  ('Michael Jackson', 'Billie Jean'),";
        SQL << "  ('The Beatles', 'Hey Jude'),";
        SQL << "  ('Madonna', 'Like a Prayer'),";
        SQL << "  ('Beyonce', 'Crazy in Love'),";
        SQL << "  ('Prince', 'Purple Rain'),";
        SQL << "  ('Whitney Houston', 'I Will Always Love You'),";
        SQL << "  ('Elvis Presley', 'Jailhouse Rock'),";
        SQL << "  ('Bob Marley', 'No Woman, No Cry'),";
        SQL << "  ('Adele', 'Someone Like You');";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    //Извлекаем данные
    {
        std::stringstream SQL;
        SQL << "SELECT * FROM `playlist`;";

        rc = sqlite3_prepare_v2(db, SQL.str().c_str(), -1, &stmt, NULL);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg); sqlite3_free(zErrMsg);
        } else
            while ((rc = sqlite3_step(stmt) == SQLITE_ROW))
                std::cout << sqlite3_column_text(stmt, 0) << ".  " << sqlite3_column_text(stmt, 1)
                    << "  -  " << sqlite3_column_text(stmt, 2) << "\n";
    }

    //Закрываем базу данных
    sqlite3_close(db);
    return 0;
}