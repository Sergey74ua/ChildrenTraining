package model

import (
	"time"
)

type Result struct {
	User    string
	Testing string
	Date    string
	Rate    int
}

type UserTest struct {
	Date   string
	Result int
	NameT  string
	NameC  string
	Icon   string
	IdT    int
}

// Смотрим результат теста
func GetResult(user, test int) *[]Result {
	println(user, test)
	arr := []Result{}

	return &arr
}

// Смотрим результаты всех тестов одного пользователя
func GetAllResult(user int) *[]UserTest {
	db := connect()
	query := `
		SELECT ut.Date, ut.Result, t.Name, c.Name, c.Icon, t.Id
		FROM UserTest ut
		JOIN Testing t ON t.Id = ut.Testing_id
		JOIN Course c ON c.Id = t.Course_id
		WHERE ut.User_id = $1
  	;`
	data, _ := db.Query(query, user)
	arr := []UserTest{}
	for data.Next() {
		ut := UserTest{}
		data.Scan(
			&ut.Date,
			&ut.Result,
			&ut.NameT,
			&ut.NameC,
			&ut.Icon,
			&ut.IdT,
		)
		arr = append(arr, ut)
	}
	db.Close()
	return &arr
}

// Вносим результат прохождения теста
func SetResult(user, test int, arr []int) {
	db := connect()
	date := time.Now().Format("2006-01-02")
	//Запрос верных ответов теста
	correctArr := []int{}
	query := `
		SELECT q.Correct
		FROM TestQuestion tq
		JOIN Questions q ON q.Id = tq.Question_id
		WHERE tq.Testing_id = $1
  	;`
	data, _ := db.Query(query, test)
	for data.Next() {
		answer := 0
		data.Scan(&answer)
		correctArr = append(correctArr, answer)
	}
	correctAnswer := 0
	for i := range correctArr {
		if correctArr[i] == arr[i] {
			correctAnswer += 1
		}
	}
	rate := correctAnswer * 100 / len(correctArr)
	query = `INSERT INTO UserTest (User_id, Testing_id, Date, Result)
		VALUES ($1, $2, $3, $4)`
	db.Exec(query, user, test, date, rate)
	db.Close()
}
