package model

type Testing struct {
	Id          int
	Name        string
	Course      string
	User        string
	Description string
}

// Вывод всех тестов
func AllTests() *[]Testing {
	db := connect()
	query := "SELECT * FROM Testing"
	data, _ := db.Query(query)
	tests := []Testing{}
	for data.Next() {
		test := Testing{}
		data.Scan(
			&test.Id,
			&test.Name,
			&test.Course,
			&test.User,
			&test.Description,
		)
		tests = append(tests, test)
	}
	db.Close()
	//Добавить подвязку вопросов
	return &tests
}

// Создание теста
func CreateTest(name, course, user, description string) int {
	db := connect()
	query := `INSERT INTO Testing (Name, Course, User, Description)
		VALUES ($1, $2, $3, $4)`
	result, _ := db.Exec(query, name, course, user, description)
	db.Close()
	id, _ := result.LastInsertId()
	//Добавить подвязку вопросов
	return int(id)
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
func UpdateTest(id int, name, course, user, description string) {
	db := connect()
	query := `UPDATE Testing SET Name=?, Course=?, User=?, Description=? WHERE id = ?`
	db.Exec(query, name, course, user, description, id)
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
