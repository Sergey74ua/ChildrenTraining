package control

import (
	"TestFlow/model"
	"net/http"
	"strconv"
)

// Создать пользователя
func createUser(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		// Выводим форму для заполнения
		data := model.AllCourse()
		tmpl := tmplFiles("view/user/create-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		// Принимаем форму с данными
		name := r.FormValue("name")
		if !valid(name) {
			name = "Unknown"
		}
		password := r.FormValue("password")
		email := r.FormValue("email")
		dataBirth := r.FormValue("dataBirth")
		course := r.FormValue("course")
		id := model.AddUser(name, password, email, dataBirth, course)
		http.Redirect(w, r, "/get-user/"+strconv.Itoa(id), http.StatusSeeOther)
	}
}

// Вывод пользователя
func getUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	data := model.GetUser(id)
	tmpl := tmplFiles("view/user/get-user.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

// Редактировать пользователя
func updateUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	if r.Method == "GET" {
		// Выводим форму для заполнения
		data := struct {
			User   model.User
			Course []model.Course
		}{
			User:   *model.GetUser(id),
			Course: *model.AllCourse(),
		}
		tmpl := tmplFiles("view/user/update-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		// Принимаем форму с данными
		name := r.FormValue("name")
		if !valid(name) {
			name = "Unknown"
		}
		password := r.FormValue("password")
		email := r.FormValue("email")
		dataBirth := r.FormValue("dataBirth")
		course := r.FormValue("course")
		model.UpdateUser(id, name, password, email, dataBirth, course)
		http.Redirect(w, r, "/get-user/"+strconv.Itoa(id), http.StatusSeeOther)
	}
}

// Удалить пользователя
func deleteUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	model.DeleteUser(id)
	http.Redirect(w, r, "/", http.StatusSeeOther)
}
