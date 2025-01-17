package model

import (
	"strconv"
	"time"
)

// Структура данных пользователей
type User struct {
	Id        int
	Name      string
	Avatar    string
	Password  string
	Email     string
	DataBirth string
	Course    string
	DataReg   string
	Status    string
	Rate      int
}

// Вывод всех пользователей
func AllUser() *[]User {
	db := connect()
	query := "SELECT * FROM User"
	data, _ := db.Query(query)
	users := []User{}
	for data.Next() {
		user := User{}
		data.Scan(
			&user.Id,
			&user.Name,
			&user.Avatar,
			&user.Password,
			&user.Email,
			&user.DataBirth,
			&user.Course,
			&user.DataReg,
			&user.Status,
			&user.Rate,
		)
		users = append(users, user)
	}
	db.Close()

	return &users
}

// Вывод данных пользователя
func GetUser(id int) *User {
	db := connect()
	query := `
		SELECT u.Id, u.Name, u.Avatar, u.Password, u.Email, u.DataBirth,
			c.Name, u.DataReg, u.Status, u.Rate
		FROM User u
		LEFT JOIN Course c ON u.Course_id = c.Id
		WHERE u.Id = $1
	;`
	data := db.QueryRow(query, id)
	user := User{}
	data.Scan(
		&user.Id,
		&user.Name,
		&user.Avatar,
		&user.Password,
		&user.Email,
		&user.DataBirth,
		&user.Course,
		&user.DataReg,
		&user.Status,
		&user.Rate,
	)
	db.Close()
	return &user
}

// Добавление пользователя
func AddUser(name, password, email, dataBirth, course string) int {
	db := connect()
	dataReg := time.Now().Format("2006-01-02")
	avatar := "../view/img/avatar.png"
	course_id, _ := strconv.Atoi(course)
	query := `INSERT INTO User (Name, Avatar, Password, Email, DataBirth, Course_id, DataReg, Status, Rate)
		VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)`
	result, _ := db.Exec(query, name, avatar, password, email, dataBirth, course_id, dataReg, "active", 0)
	db.Close()
	id, _ := result.LastInsertId()
	return int(id)
}

// Обновление пользователя
func UpdateUser(id int, name, password, email, dataBirth, course_id string) {
	db := connect()
	query := `UPDATE User SET Name=?, Password=?, Email=?, DataBirth=?, Course_id=? WHERE id = ?`
	db.Exec(query, name, password, email, dataBirth, course_id, id)
	db.Close()
}

// Удаление пользователя
func DeleteUser(id int) {
	db := connect()
	query := `DELETE FROM User WHERE id = $1`
	db.Exec(query, id)
	db.Close()
}

func LoginPass(login, pass string) int {
	db := connect()
	query := `
		SELECT Id, Name, Password
		FROM User
		WHERE Name = $1
	;`
	data := db.QueryRow(query, login)
	user := struct {
		Id       int
		Name     string
		Password string
	}{}
	data.Scan(
		&user.Id,
		&user.Name,
		&user.Password,
	)
	db.Close()
	if pass == user.Password {
		return user.Id
	}
	return 0
}

func UserBan(id int) {
	db := connect()
	query := `
		SELECT Status
		FROM User
		WHERE Id = $1
	;`
	data := db.QueryRow(query, id)
	user := struct {
		Status string
	}{}
	data.Scan(
		&user.Status,
	)
	if user.Status == "active" {
		user.Status = "banned"
	} else {
		user.Status = "active"
	}
	query = `UPDATE User SET Status=? WHERE Id=?`
	db.Exec(query, user.Status, id)
	db.Close()
}

func GetCourseId(id int) int {
	db := connect()
	query := `
		SELECT Course_id
		FROM User
		WHERE Id = $1
	;`
	data := db.QueryRow(query, id)
	user := struct {
		Course_id int
	}{}
	data.Scan(
		&user.Course_id,
	)
	db.Close()
	return user.Course_id
}
