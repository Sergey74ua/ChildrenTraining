package model

import (
	"database/sql"
	"fmt"

	_ "github.com/mattn/go-sqlite3"
)

type user struct {
	Id   int
	Name string
	Age  uint16
}

func AllUser() []user {
	path := "./model/data/db.sqlite"
	db, err := sql.Open("sqlite3", path)
	if err != nil {
		panic(err)
	}
	defer db.Close()
	rows, err := db.Query("SELECT * from User")
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
