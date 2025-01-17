package control

import (
	"TestFlow/model"
	"net/http"
	"strconv"
)

// Контролер запроса создания пользователя
func createUser(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		// Выводим форму для заполнения
		data := struct {
			Title   string
			Courses *[]model.Course
		}{
			Title:   "Регистрация",
			Courses: model.AllCourses(),
		}
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

// Контролер запроса вывода пользователя
func getUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	data := struct {
		Title     string
		User      *model.User
		UserTest  *[]model.UserTest
		Course_Id int
	}{
		Title:     "Профиль пользователя",
		User:      model.GetUser(id),
		UserTest:  model.GetAllResult(id),
		Course_Id: model.GetCourseId(id),
	}
	tmpl := tmplFiles("view/user/get-user.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

// Контролер запроса изменения пользователя
func updateUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	if r.Method == "GET" {
		// Выводим форму для заполнения
		data := struct {
			Title  string
			User   *model.User
			Course *[]model.Course
		}{
			Title:  "Обновление пользователя",
			User:   model.GetUser(id),
			Course: model.AllCourses(),
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

// Контролер запроса удаления пользователя
func deleteUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	model.DeleteUser(id)
	http.Redirect(w, r, "/admin", http.StatusSeeOther)
}

// Контролер запроса всех рользователей
func allUser(w http.ResponseWriter, r *http.Request) {
	data := struct {
		Title string
		Users []model.User
	}{
		Title: "Все пользователи",
		Users: *model.AllUser(),
	}
	tmpl := tmplFiles("view/user/users.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func profile(w http.ResponseWriter, r *http.Request) {
	http.Redirect(w, r, "/get-user/"+strconv.Itoa(User), http.StatusSeeOther)
}
