package model

import "strings"

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

func MiniCourses() *[]Course {
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
		arr := strings.Split(course.Description, " ")
		s := ""
		limit := 120
		for _, i := range arr {
			if limit <= 0 {
				break
			}
			s += i + " "
			limit -= len(i)
		}
		course.Description = s + " ..."
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

func CourseTesting(id int) *[]Testing {
	db := connect()
	query := `
		SELECT t.Id, t.Name, c.Name, c.Icon, u.Name, t.Description
		FROM Testing t
		LEFT JOIN Course c ON t.Course_id = c.Id
		LEFT JOIN User u ON t.User_id = u.Id
		WHERE c.Id = ?
	;`
	data, _ := db.Query(query, id)
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
