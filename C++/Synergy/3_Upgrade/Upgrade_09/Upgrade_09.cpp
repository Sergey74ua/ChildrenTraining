#include "sqlite3.h"
#include "request.h"

#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip> //библиотека для красивого вывода таблицы с помощью setw

sqlite3* db;
char* zErrMsg = 0;
int rc;
sqlite3_stmt* stmt;


int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    srand(time(NULL));

    int x = rand() % (max - min + 1) + std::min;

    //Рабочий цикл
    while (true) {
        int operation;
        std::cout << "Список - 1, найти - 2, добавить - 3, обновить - 4, удалить - 5, выход - 0.";
        std::cout << "\nВыберите операцию: ";
        std::cin >> operation;

        //Создаем/открываем базу даных
        rc = sqlite3_open("shop.sqlite", &db);
        if (rc) {
            fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));
            return(0);
        }

        //Создаем таблицу, если ее нет
        std::stringstream SQL;
        SQL << "CREATE TABLE IF NOT EXISTS `student` (";
        SQL << "   `id` INTEGER PRIMARY KEY AUTOINCREMENT,";
        SQL << "   `name` TEXT,";
        SQL << "   `age` TEXT,";
        SQL << "   `group` TEXT,";
        SQL << "   `grade` TEXT";
        SQL << ");";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }


        switch (operation) {
        case 0:
            sqlite3_close(db); return 0; break;
        case 1:
            allStudent(); break;
        case 2:
            infoStudent(); break;
        case 3:
            addStudent(); break;
        case 4:
            updateStudent(); break;
        case 5:
            deleteStudent(); break;
        default:
            continue;
        }
        std::cout << "\n";
    }

    //Закрываем базу данных
    sqlite3_close(db);
    return 0;
}