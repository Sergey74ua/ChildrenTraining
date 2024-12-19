package control

import (
	"TestFlow/model"
	"fmt"
	"html/template"
	"net/http"
	"time"
)

// Формируем список урлов страниц и функций их обработки
func Web(host, port string) {
	//Урлы страниц
	http.HandleFunc("/", index)
	http.HandleFunc("/about/", about)
	http.HandleFunc("/contact/", contact)
	http.HandleFunc("/create-user/", createUser)

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

// Функции страниц:

func index(w http.ResponseWriter, r *http.Request) {
	data := model.AllUser()
	tmpl := tmplFiles("view/index.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func about(w http.ResponseWriter, r *http.Request) {
	data := 16
	tmpl := tmplFiles("view/about.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func contact(w http.ResponseWriter, r *http.Request) {
	data := 7
	tmpl := tmplFiles("view/contact.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func createUser(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		data := "Страница регистрации пользователя с отправкой данных для ввода"
		tmpl := tmplFiles("view/create-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		name := r.FormValue("name")
		age := r.FormValue("age")
		model.AddUser(name, age)
		//Редирект куда-то
		data := "Страница регистрации пользователя с отправкой данных для ввода"
		tmpl := tmplFiles("view/create-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else { //Прочие запросы (OPTIONS, HEAD, PUT, PATCH, DELETE, TRACE, CONNECT)
		data := "Запрос не обрабатывается"
		tmpl := tmplFiles("view/create-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	}
}
