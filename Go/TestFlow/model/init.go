package model

import (
	"database/sql"
	"fmt"
	"io"
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
		createTable()
	} else {
		backupDB()
	}
}

// Первичное создание БД
func createTable() {
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
	// Добавить сообщение о создании или наличии БД
	fmt.Println(data.RowsAffected())
}

// Резервное копирование БД
func backupDB() {
	if false { //false - заменить на проверку периодичности сохранения
		t := time.Now()
		name := "./model/backup/" + t.Format("2006-01-02") + "_" + t.Format("15-04-05") + ".db"
		file, err := os.Create(name)
		if err != nil {
			panic(err)
		}

		db, err := os.Open(Path)
		if err != nil {
			panic(err)
		}

		_, err = io.Copy(db, file)
		if err != nil {
			panic(err)
		} else {
			println("Создана резервная копия БД: " + name)
		}

		db.Close()
		file.Close()
	}
}
