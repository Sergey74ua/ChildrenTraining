package model

import (
	"database/sql"
	"fmt"
	"os"
	"time"
)

var (
	Dbms string
	Path string
)

func Init(DBMS, PATH string) {
	Dbms = DBMS
	Path = PATH

	_, err := os.Stat(Path)
	if err != nil && os.IsNotExist(err) {
		createDB()
	} else {
		backupDB()
	}
}

// Первичное создание БД
func createDB() {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	query := "CREATE TABLE IF NOT EXISTS User (Id INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Age INTEGER)"
	data, err := db.Exec(query)
	if err != nil {
		panic(err)
	}
	fmt.Println(data.RowsAffected()) //Сообщение о создании БД или что она уже есть
}

// Резервное копирование БД
func backupDB() { // ДОДЕЛАТЬ КОПИРОВАНИЕ
	t := time.Now()
	file := "./model/backup/" + t.Format("2006-01-02") + "_" + t.Format("15-04-05") + ".db"
	println(file)
}
