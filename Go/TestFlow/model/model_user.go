package model

import "time"

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
func AllUsers() *[]User {
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
	query := `SELECT * FROM User WHERE Id = $1`
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
	// Костыль года!
	course := Course{}
	query = `SELECT Name FROM Course WHERE id = $1`
	data = db.QueryRow(query, &user.Course)
	data.Scan(&course.Name)
	user.Course = course.Name
	db.Close()

	return &user
}

// Добавление пользователя
func AddUser(name, password, email, dataBirth, course_id string) int {
	db := connect()
	dataReg := time.Now().Format("2006-01-02")
	avatar := "../view/img/avatar.png"
	query := `INSERT INTO User (Name, Avatar, Password, Email, DataBirth, Course_id, DataReg, Rate)
		VALUES ($1, $2, $3, $4, $5, $6, $7, $8)`
	res, err := db.Exec(query, name, avatar, password, email, dataBirth, course_id, dataReg, 0)
	if err != nil {
		panic(err)
	}
	id, _ := res.LastInsertId()
	db.Close()
	return int(id)
}

// Обновление пользователя
func UpdateUser(id, course_id int, name, password, email, dataBirth string) {
	db := connect()
	query := "UPDATE User SET Name=?, Password=?, Email=?, DataBirth=?, Сourse_id=? WHERE id = ?"
	db.Exec(query, name, password, email, dataBirth, course_id, id)
	db.Close()
}

// Удаление пользователя
func DeleteUser(id int) {
	db := connect()
	query := "DELETE FROM User WHERE id = $1"
	db.Exec(query, id)
	db.Close()
}
