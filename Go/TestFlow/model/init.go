package model

import (
	"database/sql"
	"os"
)

var (
	Dbms string
	Path string
)

// Выполняется при запуске
func Init(DBMS, PATH string) {
	Dbms = DBMS
	Path = PATH

	_, err := os.Stat(Path)
	if err != nil && os.IsNotExist(err) {
		//Таблицы
		tableCourse()
		tableUser()
		tableQuestion()
		tableTesting()
		tableUserTest()
		tableTestQuestion()
		//Миграции
		DataCourse()
	}
}

// Создание бд пользователей
func tableUser() {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}

	query := `CREATE TABLE IF NOT EXISTS User (
		Id INTEGER PRIMARY KEY AUTOINCREMENT,
		Name TEXT NOT NULL,
		Avatar TEXT DEFAULT "../view/img/avatar.png",
		Password TEXT NOT NULL,
		Email TEXT NOT NULL,
		DataBirth TEXT,
		Course_id INTEGER DEFAULT 1,
		DataReg TEXT NOT NULL,
		Status TEXT DEFAULT "active",
		Rate INTEGER DEFAULT 0,
		FOREIGN KEY (Course_id) REFERENCES Course (Id)
	)`
	db.Exec(query)
	db.Close()
}

// Создание бд курсов
func tableCourse() {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	query := `CREATE TABLE IF NOT EXISTS Course (
		Id INTEGER PRIMARY KEY AUTOINCREMENT,
		Name TEXT,
		Icon TEXT,
		Background TEXT,
		Description TEXT
	)`
	db.Exec(query)
	db.Close()
}

// Создание бд тестов
func tableTesting() {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	query := `CREATE TABLE IF NOT EXISTS Testing (
		Id INTEGER PRIMARY KEY AUTOINCREMENT,
		Name TEXT NOT NULL,
		Course_id INTEGER DEFAULT 0,
		User_id INTEGER DEFAULT 0,
		Description TEXT,
		FOREIGN KEY (Course_id) REFERENCES Course (Id),
		FOREIGN KEY (User_id) REFERENCES User (Id)
	)`
	db.Exec(query)
	db.Close()
}

// Создание бд вопросов
func tableQuestion() {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	query := `CREATE TABLE IF NOT EXISTS Questions (
		Id INTEGER PRIMARY KEY AUTOINCREMENT,
		NumberQuestion INTEGER,
		Question TEXT NOT NULL,
		Correct INTEGER NOT NULL,
		Answer_1 TEXT,
		Answer_2 TEXT,
		Answer_3 TEXT,
		Answer_4 TEXT,
		Answer_5 TEXT,
		Answer_6 TEXT
	)`
	db.Exec(query)
	db.Close()
}

// Связь пользователь-тесты
func tableUserTest() {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	query := `CREATE TABLE IF NOT EXISTS UserTest (
		User_id INTEGER DEFAULT 0,
		Testing_id INTEGER DEFAULT 0,
		Date TEXT,
		Result INTEGER DEFAULT 0,
		FOREIGN KEY (User_id) REFERENCES User (Id),
		FOREIGN KEY (Testing_id) REFERENCES Testing (Id)
	)`
	db.Exec(query)
	db.Close()
}

// Связь тесты-вопросы
func tableTestQuestion() {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	query := `CREATE TABLE IF NOT EXISTS TestQuestion (
		Testing_id INTEGER DEFAULT 0,
		Question_id INTEGER DEFAULT 0,
		FOREIGN KEY (Testing_id) REFERENCES Testing (Id),
		FOREIGN KEY (Question_id) REFERENCES Questions (Id)
	)`
	db.Exec(query)
	db.Close()
}
