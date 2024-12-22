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

// Формируем список урлов страниц и функций их обработки
func Web(host, port string) {
	//Урлы страниц
	http.HandleFunc("/", index)
	http.HandleFunc("/about/", about)
	http.HandleFunc("/contact/", contact)
	http.HandleFunc("/create-user/", createUser)
	http.HandleFunc("/get-user/{id}", getUser)
	http.HandleFunc("/update-user/{id}", updateUser)
	http.HandleFunc("/delete-user/{id}", deleteUser)

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
		// Выводим форму для заполнения
		data := "Страница регистрации пользователя"
		tmpl := tmplFiles("view/create-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		// Принимаем форму с данными
		name := r.FormValue("name")
		age, err := strconv.Atoi(r.FormValue("age"))
		//Верификация
		if name == "" || len(name) > 127 {
			fmt.Fprintf(w, "Имя указано не верно")
		}
		if err != nil || age < 0 || age > 127 {
			fmt.Fprintf(w, "Возраст указан не верно")
		}
		//Добавляем данные в базу данных
		model.AddUser(name, age)
		//Редирект после отправки формы
		http.Redirect(w, r, "/", http.StatusSeeOther)
	}
}

func getUser(w http.ResponseWriter, r *http.Request) {
	arr := strings.Split(r.RequestURI, "/")
	id, _ := strconv.Atoi(arr[len(arr)-1])
	data := model.GetUser(id)
	tmpl := tmplFiles("view/get-user.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func updateUser(w http.ResponseWriter, r *http.Request) {
	if r.Method == "GET" {
		// Выводим форму для заполнения
		arr := strings.Split(r.RequestURI, "/")
		id, _ := strconv.Atoi(arr[len(arr)-1])
		data := model.GetUser(id)
		tmpl := tmplFiles("view/update-user.html")
		tmpl.ExecuteTemplate(w, "content", data)
	} else if r.Method == "POST" {
		// Принимаем форму с данными
		arr := strings.Split(r.RequestURI, "/")
		id, _ := strconv.Atoi(arr[len(arr)-1])
		name := r.FormValue("name")
		age, err := strconv.Atoi(r.FormValue("age"))
		//Верификация
		if name == "" || len(name) > 127 {
			fmt.Fprintf(w, "Имя указано не верно")
		}
		if err != nil || age < 0 || age > 127 {
			fmt.Fprintf(w, "Возраст указан не верно")
		}
		//Добавляем данные в базу данных
		model.UpdateUser(id, name, age)
		//Редирект после отправки формы
		http.Redirect(w, r, "/", http.StatusSeeOther)
	}
}

func deleteUser(w http.ResponseWriter, r *http.Request) {
	arr := strings.Split(r.RequestURI, "/")
	id, _ := strconv.Atoi(arr[len(arr)-1])
	model.DeleteUser(id)
	http.Redirect(w, r, "/", http.StatusSeeOther)
}
