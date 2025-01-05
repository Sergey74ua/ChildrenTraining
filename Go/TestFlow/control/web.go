package control

import (
	"TestFlow/model"
	"fmt"
	"html/template"
	"net/http"
	"strconv"
	"strings"
	"time"
)

var User int = 1

// Формируем список урлов страниц и функций их обработки
func Web(host, port string) {
	//Урлы страниц
	http.HandleFunc("/", index)
	http.HandleFunc("/about/", about)
	http.HandleFunc("/author/", author)
	http.HandleFunc("/login-pass/", loginPass)

	http.HandleFunc("/admin/", admin)
	http.HandleFunc("/copy-DB/", copyDB)
	http.HandleFunc("/demo-migration/", demo)

	http.HandleFunc("/users/", allUser)
	http.HandleFunc("/create-user/", createUser)
	http.HandleFunc("/get-user/{id}", getUser)
	http.HandleFunc("/update-user/{id}", updateUser)
	http.HandleFunc("/delete-user/{id}", deleteUser)

	http.HandleFunc("/courses/", courses)
	http.HandleFunc("/create-course/", createCourse)
	http.HandleFunc("/get-course/{id}", getCourse)
	http.HandleFunc("/update-course/{id}", updateCourse)
	http.HandleFunc("/delete-course/{id}", deleteCourse)

	http.HandleFunc("/testing/", testing)
	http.HandleFunc("/create-test/", createTesting)
	http.HandleFunc("/get-test/{id}", getTesting)
	http.HandleFunc("/update-test/{id}", updateTesting)
	http.HandleFunc("/delete-test/{id}", deleteTesting)

	//Сообщение в терминал
	t := time.Now()
	fmt.Println(t.Format("2006.01.02") + " " + t.Format("15:04:05") + " " + "Web-сервер успешно запущен")

	//Слушатель порта
	http.ListenAndServe(host+":"+port, nil)
}

// Добавляем контент в список компонентов для генерации страниц (а если надо 2+ ?)
func tmplFiles(content string) *template.Template {
	tmpl, err := template.ParseFiles(
		"view/inc/header.html",
		"view/inc/menu.html",
		"view/inc/footer.html",
		content,
	)
	if err != nil {
		fmt.Println(err.Error())
	}
	return tmpl
}

// Верификация
func valid(name string) bool {
	vName := name != "" && len(name) < 128
	return vName
}

// Выборка id из урла
func getId(url string) int {
	arr := strings.Split(url, "/")
	id, _ := strconv.Atoi(arr[len(arr)-1])
	return id
}

// Функции страниц:

func index(w http.ResponseWriter, r *http.Request) {
	data := struct {
		Title   string
		Course  *[]model.Course
		Testing *[]model.Testing
	}{
		Title:   "TestFlow",
		Course:  model.AllCourses(),
		Testing: model.AllTests(),
	}
	tmpl := tmplFiles("view/index.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func about(w http.ResponseWriter, r *http.Request) {
	data := struct {
		Title string
	}{
		Title: "О проекте",
	}
	tmpl := tmplFiles("view/about.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func author(w http.ResponseWriter, r *http.Request) {
	data := struct {
		Title string
	}{
		Title: "Об авторе",
	}
	tmpl := tmplFiles("view/author.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func admin(w http.ResponseWriter, r *http.Request) {
	data := struct {
		Title   string
		User    *[]model.User
		Course  *[]model.Course
		Testing *[]model.Testing
	}{
		Title:   "Админ-панель",
		User:    model.AllUser(),
		Course:  model.AllCourses(),
		Testing: model.AllTests(),
	}
	tmpl := tmplFiles("view/admin.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func demo(w http.ResponseWriter, r *http.Request) {
	model.Demo()
	http.Redirect(w, r, "/admin/", http.StatusSeeOther)
}

func copyDB(w http.ResponseWriter, r *http.Request) {
	model.BackupDB()
	http.Redirect(w, r, "/admin/", http.StatusSeeOther)
}

// ПРОВЕРИТЬ И/ИЛИ ДОДЕЛАТЬ
func loginPass(w http.ResponseWriter, r *http.Request) {
	login := r.FormValue("login")
	pass := r.FormValue("pass")
	User = model.LoginPass(login, pass)
	http.Redirect(w, r, "/", http.StatusSeeOther)
}
