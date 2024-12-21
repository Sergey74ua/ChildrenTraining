package model

import (
	"database/sql"
	"fmt"

	_ "github.com/mattn/go-sqlite3"
)

// ВСЕ ЭТО НАДО ОПТИМИЗИРОВАТЬ!
var (
	Dbms string
	Path string
)

type user struct {
	Id   int
	Name string
	Age  int
}

// Данные пользователя  ПЕРЕДОДЕЛАТЬ
func GetUser(id int) *user {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	query := "SELECT * FROM User WHERE id = $1"
	data := db.QueryRow(query, id)

	user := user{}
	err = data.Scan(&user.Id, &user.Name, &user.Age)
	if err != nil {
		panic(err)
	}

	return &user
}

// Регистрация пользователя
func AddUser(name string, age int) {
	db, err := sql.Open(Dbms, Path)
	if err != nil {
		panic(err)
	}
	defer db.Close()

	query := "INSERT INTO User (Name, Age) VALUES ($1, $2)"
	data, err := db.Exec(query, name, age)
	if err != nil {
		panic(err)
	}
	fmt.Print(data.RowsAffected())
	fmt.Println(data.LastInsertId())
}

// Вывод всех пользователей
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
