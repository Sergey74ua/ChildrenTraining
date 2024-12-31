package model

type Course struct {
	Id          int
	Name        string
	Icon        string
	Background  string
	Description string
}

// Вывод всех дисциплин
func AllCoursec() *[]Course {
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

func CreateCourse() int {
	return 2
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
func UpdateCourse() int {
	return 4
}

func DeleteCourse() {

}
