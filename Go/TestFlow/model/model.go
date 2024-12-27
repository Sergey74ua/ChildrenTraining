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

// Структура данных пользователей
type User struct {
	Id   int
	Name string
	Age  int
}

type Courses struct {
	Id   int
	Name string
	// ...
}

// Вывод всех пользователей
func AllUser() *[]User {
	db := connect()
	query := "SELECT * FROM User"
	data, _ := db.Query(query)
	users := []User{}
	for data.Next() {
		user := User{}
		data.Scan(&user.Id, &user.Name, &user.Age)
		users = append(users, user)
	}
	db.Close()

	return &users
}

// Вывод данных пользователя
func GetUser(id int) *User {
	db := connect()
	query := "SELECT * FROM User WHERE id = $1"
	data := db.QueryRow(query, id)
	user := User{}
	data.Scan(&user.Id, &user.Name, &user.Age)
	db.Close()

	return &user
}

// Добавление пользователя
func AddUser(name string, age int) int {
	db := connect()
	query := "INSERT INTO User (Name, Age) VALUES ($1, $2)"
	result, _ := db.Exec(query, name, age)
	db.Close()
	id, _ := result.LastInsertId()
	return int(id)
}

// Обновление пользователя
func UpdateUser(id int, name string, age int) {
	db := connect()
	query := "UPDATE User SET Name=?, Age=? WHERE id = ?"
	db.Exec(query, name, age, id)
	db.Close()
}

// Удаление пользователя
func DeleteUser(id int) {
	db := connect()
	query := "DELETE FROM User WHERE id = $1"
	db.Exec(query, id)
	db.Close()
}

func AllCoursec() int {
	return 1
}

func CreateCourse() int {
	return 2
}

func GetCourse() int {
	return 3
}

func UpdateCourse() int {
	return 4
}

func DeleteCourse() {

}
