#pragma once

void fillStaff() {
    rc = sqlite3_open("staff.sqlite", &db);
    if (rc)
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

    //������� �������, ���� �� ��� Shaft
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
        SQL << "  ('������', 4),";
        SQL << "  ('���������� ���', 6),";
        SQL << "  ('���������', 3),";
        SQL << "  ('������', 10),";
        SQL << "  ('���', 5),";
        SQL << "  ('��������', 2),";
        SQL << "  ('�������� ������', 5),";
        SQL << "  ('���', 2),";
        SQL << "  ('����', 3),";
        SQL << "  ('������� ����', 6),";
        SQL << "  ('�������� ������', 3),";
        SQL << "  ('���', 5),";
        SQL << "  ('���', 2),";
        SQL << "  ('������', 3),";
        SQL << "  ('����', 8),";
        SQL << "  ('�����', 4),";
        SQL << "  ('�������', 5),";
        SQL << "  ('���', 3),";
        SQL << "  ('������� ���', 4),";
        SQL << "  ('�������� ������', 5),";
        SQL << "  ('����', 7),";
        SQL << "  ('�����������', 4),";
        SQL << "  ('�����', 3),";
        SQL << "  ('�������', 4),";
        SQL << "  ('�����', 4),";
        SQL << "  ('���������', 1),";
        SQL << "  ('�����', 2),";
        SQL << "  ('������� ������', 6),";
        SQL << "  ('������', 3),";
        SQL << "  ('�������', 4),";
        SQL << "  ('�����', 2),";
        SQL << "  ('���������', 5),";
        SQL << "  ('���', 3),";
        SQL << "  ('������', 4),";
        SQL << "  ('׸���� �������', 6),";
        SQL << "  ('�������� ������', 6),";
        SQL << "  ('���� (����� ���)', 11),";
        SQL << "  ('������', 2),";
        SQL << "  ('�����', 4)";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    //������� �������, ���� �� ��� Core
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
        SQL << "  ('����� ���������', 5),";
        SQL << "  ('���� �������', 6),";
        SQL << "  ('��������� ���� �������', 3),";
        SQL << "  ('����� �������', 7),";
        SQL << "  ('������ �������', 7),";
        SQL << "  ('���� ����������', 4),";
        SQL << "  ('����� �����', 5),";
        SQL << "  ('����� �������', 3),";
        SQL << "  ('���� ������', 4),";
        SQL << "  ('������ ������', 2),";
        SQL << "  ('������� ������ ����������', 3),";
        SQL << "  ('��� ���������', 8),";
        SQL << "  ('������ ������', 3),";
        SQL << "  ('����� ����', 2),";
        SQL << "  ('���� �� ����� ������� ����', 1),";
        SQL << "  ('������ �������', 2),";
        SQL << "  ('����� ����������', 3),";
        SQL << "  ('���� ����', 4),";
        SQL << "  ('���� ������', 2),";
        SQL << "  ('������� ����', 3),";
        SQL << "  ('��������� ����', 2),";
        SQL << "  ('��������� ����', 3),";
        SQL << "  ('����� ������', 5)";

        rc = sqlite3_exec(db, SQL.str().c_str(), NULL, 0, &zErrMsg);
        if (rc != SQLITE_OK) {
            fprintf(stderr, "SQL error: %s\n", zErrMsg);
            sqlite3_free(zErrMsg);
        }
    }

    //��������� ���� ������
    sqlite3_close(db);
}

//����� ������ ���� ���������, ����������� � ���� ������.
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

    //��������� ���� ������
    sqlite3_close(db);
}*/

//����� ���������� � ���������� �������� �� ��� �����.
/*void infoStudent() {
    rc = sqlite3_open("staff.sqlite", &db);
    if (rc)
        fprintf(stderr, "Can't open database: %s\n", sqlite3_errmsg(db));

    std::string name;
    std::cout << "\n������ ��� ��������: ";
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
    std::cout << "\n������ �� ��������.\n";

    //��������� ���� ������
    sqlite3_close(db);
}*/