package model

import "strconv"

type Testing struct {
	Id          int
	Name        string
	Course      string
	CourseIcon  string
	User        string
	Description string
}

// Вывод всех тестов
func AllTests() *[]Testing {
	db := connect()
	query := `
		SELECT t.Id, t.Name, c.Name, c.Icon, u.Name, t.Description
		FROM Testing t
		LEFT JOIN Course c ON t.Course_id = c.Id
		LEFT JOIN User u ON t.User_id = u.Id
	;`
	data, _ := db.Query(query)
	tests := []Testing{}
	for data.Next() {
		test := Testing{}
		data.Scan(
			&test.Id,
			&test.Name,
			&test.Course,
			&test.CourseIcon,
			&test.User,
			&test.Description,
		)
		tests = append(tests, test)
	}
	db.Close()

	return &tests
}

// Создание теста
func CreateTest(name, description, quest, correct, answer_1, answer_2, answer_3, answer_4, answer_5, answer_6, course string, user int) int {
	db := connect()
	course_id, _ := strconv.Atoi(course)
	correct_int, _ := strconv.Atoi(correct)

	query := `INSERT INTO Testing (Name, Course_id, User_id, Description)
		VALUES ($1, $2, $3, $4)`
	result, _ := db.Exec(query, name, course_id, user, description)
	idT, _ := result.LastInsertId()

	query = `INSERT INTO Questions (NumberQuestion, Question, Correct, Answer_1, Answer_2, Answer_3, Answer_4, Answer_5, Answer_6)
		VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)`
	result, _ = db.Exec(query, 1, quest, correct_int, answer_1, answer_2, answer_3, answer_4, answer_5, answer_6)
	idQ, _ := result.LastInsertId()

	query = `INSERT INTO TestQuestion (Testing_id, Question_id)
		VALUES ($1, $2)`
	db.Exec(query, idT, idQ)

	db.Close()
	return int(idT)
}

// Получаем тест
func GetTest(id int) *Testing {
	db := connect()
	query := `
		SELECT t.Id, t.Name, Course.Name, User.Name, t.Description
		FROM Testing t
		LEFT JOIN Course ON t.Course_id = Course.Id
		LEFT JOIN User ON t.User_id = User.Id
		WHERE t.Id = $1
	;`
	data := db.QueryRow(query, id)
	testing := Testing{}
	data.Scan(
		&testing.Id,
		&testing.Name,
		&testing.Course,
		&testing.User,
		&testing.Description,
	)
	db.Close()
	//Добавить подвязку вопросов
	return &testing
}

// Измененние теста
func UpdateTest(id, user int, name, course, description, quest, correct, answer_1, answer_2, answer_3, answer_4, answer_5, answer_6 string) {

	course_id, _ := strconv.Atoi(course)
	correct_int, _ := strconv.Atoi(correct)

	db := connect()
	query := `UPDATE Testing SET Name=?, Course_id=?, User_id=?, Description=? WHERE id = ?`
	db.Exec(query, name, course_id, user, description, id)
	query = `INSERT INTO Questions (NumberQuestion, Question, Correct, Answer_1, Answer_2, Answer_3, Answer_4, Answer_5, Answer_6)
		VALUES ($1, $2, $3, $4, $5, $6, $7, $8, $9)`
	result, _ := db.Exec(query, 1, quest, correct_int, answer_1, answer_2, answer_3, answer_4, answer_5, answer_6)
	idQ, _ := result.LastInsertId()

	query = `INSERT INTO TestQuestion (Testing_id, Question_id)
		VALUES ($1, $2)`
	db.Exec(query, id, idQ)

	db.Close()
	//Добавить подвязку вопросов
}

// Удаление теста
func DeleteTest(id int) {
	db := connect()
	query := `DELETE FROM Testing WHERE id = $1`
	db.Exec(query, id)
	db.Close()
	//Добавить подвязку вопросов
}
