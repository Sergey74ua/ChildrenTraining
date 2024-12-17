package model

import (
	"database/sql"
	"fmt"

	//go get github.com/mattn/go-sqlite3
	_ "github.com/mattn/go-sqlite3"
)

type user struct {
	Id   int
	Name string
	Age  int
}

func CreateTable() { //Одноразово
	path := "./model/sqlite.db"
	db, err := sql.Open("sqlite3", path)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	query := "CREATE TABLE IF NOT EXISTS User (Id INTEGER PRIMARY KEY AUTOINCREMENT, Name TEXT, Age INTEGER)"
	data, err := db.Exec(query)
	if err != nil {
		panic(err)
	}
	fmt.Println(data.RowsAffected())
}

func AddUser() {
	path := "./model/sqlite.db"
	db, err := sql.Open("sqlite3", path)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	query := "INSERT INTO User (Name, Age) VALUES ($1, $2)"
	data, err := db.Exec(query, "Коля", 456)
	if err != nil {
		panic(err)
	}
	fmt.Print(data.RowsAffected())
	fmt.Println(data.LastInsertId())
}

func AllUser() []user {
	path := "./model/sqlite.db"
	db, err := sql.Open("sqlite3", path)
	if err != nil {
		panic(err)
	}
	defer db.Close()
	rows, err := db.Query("SELECT * FROM User")
	if err != nil {
		panic(err)
	}
	defer rows.Close()
	data := []user{}

	for rows.Next() {
		u := user{}
		err := rows.Scan(&u.Id, &u.Name, &u.Age)
		if err != nil {
			fmt.Println(err)
			continue
		}
		data = append(data, u)
	}

	return data
}
