package model

type Course struct {
	Id          int
	Name        string
	Icon        string
	Background  string
	Description string
}

// Вывод всех дисциплин
func AllCourses() *[]Course {
	db := connect()
	query := "SELECT * FROM Course"
	data, _ := db.Query(query)
	courses := []Course{}
	for data.Next() {
		course := Course{}
		data.Scan(
			&course.Id,
			&course.Name,
			&course.Icon,
			&course.Background,
			&course.Description,
		)
		courses = append(courses, course)
	}
	db.Close()

	return &courses
}

// Создание дисциплины
func CreateCourse(name, icon, background, description string) int {
	db := connect()
	query := `INSERT INTO Course (Name, Icon, Background, Description)
		VALUES ($1, $2, $3, $4)`
	result, _ := db.Exec(query, name, icon, background, description)
	db.Close()
	id, _ := result.LastInsertId()
	return int(id)
}

// Получаем дисциплину
func GetCourse(id int) *Course {
	db := connect()
	query := "SELECT * FROM Course WHERE id = $1"
	data := db.QueryRow(query, id)
	course := Course{}
	data.Scan(
		&course.Id,
		&course.Name,
		&course.Icon,
		&course.Background,
		&course.Description,
	)
	db.Close()
	return &course
}

// Измененние дисциплины
func UpdateCourse(id int, name, icon, background, description string) {
	db := connect()
	query := `UPDATE Course SET Name=?, Icon=?, Background=?, Description=? WHERE id = ?`
	db.Exec(query, name, icon, background, description, id)
	db.Close()
}

// Удаление дисциплины
func DeleteCourse(id int) {
	db := connect()
	query := `DELETE FROM Course WHERE id = $1`
	db.Exec(query, id)
	db.Close()
}
