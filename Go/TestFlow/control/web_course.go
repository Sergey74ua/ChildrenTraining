package control

import (
	"TestFlow/model"
	"net/http"
	"strconv"
)

// Контролер запроса всех дисциплин
func courses(w http.ResponseWriter, r *http.Request) {
	data := struct {
		Title  string
		Course *[]model.Course
	}{
		Title:  "Дисциплины",
		Course: model.AllCourses(),
	}
	tmpl := tmplFiles("view/course/courses.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

// Контролер запроса создания дисциплины
func createCourse(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		data := struct {
			Title string
		}{
			Title: "Создание дисциплины",
		}
		tmpl := tmplFiles("view/course/create-course.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		name := r.FormValue("name")
		if !valid(name) {
			name = "Unknown"
		}
		icon := "../view/img/course/icon/default.png"
		background := "../view/img/course/background/default.jpg"
		description := r.FormValue("description")
		id := model.CreateCourse(name, icon, background, description)
		http.Redirect(w, r, "/get-course/"+strconv.Itoa(id), http.StatusSeeOther)
	}
}

// Контролер запроса изменения дисциплины
func updateCourse(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	if r.Method == "GET" {
		data := struct {
			Title  string
			Course model.Course
		}{
			Title:  "Дисциплина",
			Course: *model.GetCourse(id),
		}
		tmpl := tmplFiles("view/course/update-course.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		name := r.FormValue("name")
		if !valid(name) {
			name = "Unknown"
		}
		icon := "../view/img/course/icon/default.png"
		background := "../view/img/course/background/default.jpg"
		description := r.FormValue("description")
		model.UpdateCourse(id, name, icon, background, description)
		http.Redirect(w, r, "/get-course/"+strconv.Itoa(id), http.StatusSeeOther)
	}
}

// Контролер запроса дисциплины
func getCourse(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	data := struct {
		Title  string
		Course model.Course
	}{
		Title:  "Дисциплина",
		Course: *model.GetCourse(id),
	}
	tmpl := tmplFiles("view/course/get-course.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

// Контролер запроса удаления дисциплины
func deleteCourse(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	model.DeleteCourse(id)
	http.Redirect(w, r, "/admin", http.StatusSeeOther)
}
