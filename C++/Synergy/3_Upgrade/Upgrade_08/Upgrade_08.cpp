//Создайте простую таблицу в базе данных, например, для хранения информации о студентах с полями, такими как имя, возраст, класс и оценки.
//Можете взять похожую таблицу из предыдущих домашних заданий.
//Используя язык программирования С++, напишите программу, которая будет взаимодействовать с базой данных.Задание можно делать как в консоли,
//так и в оконном приложении.Программа должна предоставлять следующий функционал :
//Вывод списка всех студентов, находящихся в базе данных.
//Вывод информации о конкретном студенте по его имени.
//Протестируйте программу, добавляя записи о студентах в базу данных, выводя список студентов и обновляя информацию о них.
//Проверьте работу программы на наличие ошибок и обработайте их, если они возникнут(например, отсутствие соединения с базой данных или некорректные данные).
//Дополнительное задание(для более продвинутых) : Реализуйте функционал удаления записей о студентах из базы данных.


#include "sqlite3.h"
#include <iostream>
#include <windows.h>
#include <string>
#include <sstream>

sqlite3* db;
char* zErrMsg = 0;
int rc;
sqlite3_stmt* stmt;

//Вывод списка всех студентов, находящихся в базе данных.
void allStudent() {
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
}

//Вывод информации о конкретном студенте по его имени.
void infoStudent() {
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
}

//Добавляем данные студента
void addStudent() {
    std::string name, age, group, grade;

    std::cout << "\nВедите имя студента: ";
    std::cin >> name;
    std::cout << "Ведите возраст студента: ";
    std::cin >> age;
    std::cout << "Ведите группу студента: ";
    std::cin >> group;
    std::cout << "Ведите оценку студента: ";
    std::cin >> grade;

    std::stringstream SQL;
    SQL << "INSERT INTO `student` (`name`, `age`, `group`, `grade`) VALUES ('";
    SQL << name << "', '";
    SQL << age << "', '";
    SQL << group << "', '";
    SQL << grade << "');";

    rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else
        std::cout << "\nСтудент " << name << " добавлен.\n";
}

//Обновление информации студента.
void updateStudent() {
    int id;
    std::cout << "\nВедите номер студента для обновлений: ";
    std::cin >> id;

    std::string grade;
    std::cout << "Ведите новую оценку студента: ";
    std::cin >> grade;

    std::stringstream SQL;
    SQL << "UPDATE `student` SET `grade` = '" << grade << "' WHERE `id` = " << id << ";";

    rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else
        std::cout << "\nДанные студента № " << id << " обнавлены.\n";
}

//удаления записей о студентах из базы данных.
void deleteStudent() {
    int id;
    std::cout << "\nВедите номер студента для удаления: ";
    std::cin >> id;

    std::stringstream SQL;
    SQL << "DELETE FROM `student` WHERE `id` = " << id << ";";

    rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
    if (rc != SQLITE_OK) {
        fprintf(stderr, "SQL error: %s\n", zErrMsg);
        sqlite3_free(zErrMsg);
    } else
        std::cout << "\nСтудент № " << id << " удален.\n";
}

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    //Создаем/открываем базу даных
    rc = sqlite3_open("Upgrade_08.sqlite", &db);
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

    //Рабочий цикл
    while (true) {
        int operation;
        std::cout << "Список - 1, найти - 2, добавить - 3, обновить - 4, удалить - 5, выход - 0.";
        std::cout << "\nВыберите операцию: ";
        std::cin >> operation;

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