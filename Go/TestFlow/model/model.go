package model

import (
	"database/sql"

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
