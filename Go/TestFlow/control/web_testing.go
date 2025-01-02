package control

import (
	"TestFlow/model"
	"net/http"
	"strconv"
)

// Контролер запроса создания теста
func createTesting(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		data := struct {
			Title string
		}{
			Title: "Создание теста",
		}
		tmpl := tmplFiles("view/test/create-test.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		name := r.FormValue("name")
		course := r.FormValue("course")
		user := r.FormValue("user")
		description := r.FormValue("description")
		id := model.CreateTest(name, course, user, description)
		http.Redirect(w, r, "/get-test/"+strconv.Itoa(id), http.StatusSeeOther)
	}
}

// Контролер запроса изменения теста
func updateTesting(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	if r.Method == "GET" {
		data := struct {
			Title   string
			Testing model.Testing
			Course  []model.Course
		}{
			Title:   "Редактирование теста",
			Testing: *model.GetTest(id),
			Course:  *model.AllCourses(),
		}
		tmpl := tmplFiles("view/test/update-test.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		name := r.FormValue("name")
		course := r.FormValue("course")
		user := r.FormValue("user")
		description := r.FormValue("description")
		model.UpdateTest(id, name, course, user, description)
		http.Redirect(w, r, "/get-test/"+strconv.Itoa(id), http.StatusSeeOther)
	}
}

// Контролер запроса теста
func getTesting(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	data := struct {
		Title   string
		Testing model.Testing
	}{
		Title:   "Тестирование",
		Testing: *model.GetTest(id),
	}
	tmpl := tmplFiles("view/test/get-test.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

// Контролер запроса удаления теста
func deleteTesting(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	model.DeleteTest(id)
	http.Redirect(w, r, "/", http.StatusSeeOther)
}
