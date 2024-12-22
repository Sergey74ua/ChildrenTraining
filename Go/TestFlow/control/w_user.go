package control

import (
	"TestFlow/model"
	"net/http"
	"strconv"
	"strings"
)

// Создать пользователя
func createUser(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		// Выводим форму для заполнения
		data := "Страница регистрации пользователя"
		tmpl := tmplFiles("view/create-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		// Принимаем форму с данными
		name := r.FormValue("name")
		age, err := strconv.Atoi(r.FormValue("age"))
		//Верификация и добавление данных в базу данных
		if err == nil && valid(name, age) {
			id := model.AddUser(name, age)
			http.Redirect(w, r, "/get-user/"+strconv.Itoa(id), http.StatusSeeOther)
		} else {
			http.Redirect(w, r, "/", http.StatusSeeOther) //надо редирект на 404
		}
	}
}

// Вывод пользователя
func getUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	data := model.GetUser(id)
	tmpl := tmplFiles("view/get-user.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

// Редактировать пользователя
func updateUser(w http.ResponseWriter, r *http.Request) {
	id := getId(r.RequestURI)
	if r.Method == "GET" {
		// Выводим форму для заполнения
		data := model.GetUser(id)
		tmpl := tmplFiles("view/update-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		// Принимаем форму с данными
		name := r.FormValue("name")
		age, err := strconv.Atoi(r.FormValue("age"))
		//Верификация и добавление данных в базу данных
		if err == nil && valid(name, age) {
			model.UpdateUser(id, name, age)
			http.Redirect(w, r, "/get-user/"+strconv.Itoa(id), http.StatusSeeOther)
		} else {
			http.Redirect(w, r, "/", http.StatusSeeOther) //надо редирект на 404
		}
	}
}

// Удалить пользователя
func deleteUser(w http.ResponseWriter, r *http.Request) {
	arr := strings.Split(r.RequestURI, "/")
	id, _ := strconv.Atoi(arr[len(arr)-1])
	model.DeleteUser(id)
	http.Redirect(w, r, "/", http.StatusSeeOther)
}
