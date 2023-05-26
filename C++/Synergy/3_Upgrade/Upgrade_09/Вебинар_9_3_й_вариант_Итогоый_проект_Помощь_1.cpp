#include <windows.h>
#include <sqlext.h>
#include <sqltypes.h>
#include <sql.h>
#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <iomanip> //библиотека для красивого вывода таблицы с помощью setw

using namespace std;

// Функция для получения случайного числа в диапазоне [min, max]
int getRandomNumber(int min, int max) {
	return rand() % (max - min + 1) + min;
}

int main() {
	// Установка семени для генератора случайных чисел
	srand(time(NULL));
	setlocale(LC_CTYPE, "");
	// Создание строки соединения
	string connectionStr = "DRIVER={SQL Server};SERVER=DESKTOP-I29V48P;DATABASE=my_db;Trusted_Connection=yes;";

	// Преобразование строки в тип SQLWCHAR
	int size = MultiByteToWideChar(CP_UTF8, 0, connectionStr.c_str(), -1, NULL, 0);
	vector < SQLWCHAR > wconnStr(size);
	MultiByteToWideChar(CP_UTF8, 0, connectionStr.c_str(), -1, wconnStr.data(), size);
	SQLWCHAR * sqlConnectionStr = wconnStr.data();

	// Создание переменных для соединения с базой данных
	SQLHENV hEnv = NULL;
	SQLHDBC hDbc = NULL;
	SQLHSTMT hStmt = NULL;

	// Выделение памяти для буфера вывода
	const int bufferSize = 50;
	SQLWCHAR coreName[bufferSize];
	SQLWCHAR woodName[bufferSize];

	// Подключение к базе данных
	SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &hEnv);
	SQLSetEnvAttr(hEnv, SQL_ATTR_ODBC_VERSION, (SQLPOINTER)SQL_OV_ODBC3, SQL_IS_INTEGER);
	SQLAllocHandle(SQL_HANDLE_DBC, hEnv, &hDbc);
	SQLRETURN ret = SQLDriverConnectW(hDbc, NULL, sqlConnectionStr, SQL_NTS, NULL, 0, NULL, SQL_DRIVER_COMPLETE);
	if (ret != SQL_SUCCESS && ret != SQL_SUCCESS_WITH_INFO) {
		cout << "Connection Failed" << endl;
		exit(1);
	}

	// Создание SQL-запроса для выборки данных из таблицы core и wood
	string query = "SELECT core.core_name, wood.wood_name, (core.core_cost + wood.wood_cost) * 1.2 AS cost FROM core, wood WHERE core.core_id = " +
		to_string(getRandomNumber(1, 5)) + " AND wood.wood_id = " +
		to_string(getRandomNumber(1, 5));

	int querySize = MultiByteToWideChar(CP_UTF8, 0, query.c_str(), -1, NULL, 0);
	vector < SQLWCHAR > wQuery(querySize);
	MultiByteToWideChar(CP_UTF8, 0, query.c_str(), -1, wQuery.data(), querySize);
	SQLWCHAR * sqlQuery = wQuery.data();

	// Выполнение SQL-запроса
	SQLAllocHandle(SQL_HANDLE_STMT, hDbc, &hStmt);
	SQLExecDirectW(hStmt, sqlQuery, SQL_NTS);

	// Вывод результатов на экран
	//setw(число) (это простронство в символах для следующей строки для красивого вывода)
	wcout << setw(28) << left << L"Сердцевина" <<
		setw(18) << L"Дерево" <<
		setw(8) << L"Цена" << endl <<
		L"-----------------------------------------------------------" << endl;
	while (SQLFetch(hStmt) == SQL_SUCCESS) {
		SQLGetData(hStmt, 1, SQL_WCHAR, coreName, bufferSize, NULL);
		SQLGetData(hStmt, 2, SQL_WCHAR, woodName, bufferSize, NULL);
		double cost;
		SQLGetData(hStmt, 3, SQL_DOUBLE, &cost, sizeof(cost), NULL);
		wcout << setw(28) << left << coreName <<
			setw(18) << woodName <<
			setw(8) << cost << endl;
	}

	// Освобождение ресурсов
	SQLFreeHandle(SQL_HANDLE_STMT, hStmt);
	SQLDisconnect(hDbc);
	SQLFreeHandle(SQL_HANDLE_DBC, hDbc);
	SQLFreeHandle(SQL_HANDLE_ENV, hEnv);

	return 0;
}