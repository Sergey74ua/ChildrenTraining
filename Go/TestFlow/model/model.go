package model

import (
	"database/sql"
	"io"
	"os"
	"time"

	_ "github.com/mattn/go-sqlite3"
)

// Подключение к БД
func connect() *sql.DB {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}

	return db
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
