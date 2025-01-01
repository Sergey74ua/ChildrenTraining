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
	http.HandleFunc("/author/", author)
	http.HandleFunc("/admin/", admin)
	http.HandleFunc("/demo-migration/", demo)

	http.HandleFunc("/create-user/", createUser)
	http.HandleFunc("/get-user/{id}", getUser)
	http.HandleFunc("/update-user/{id}", updateUser)
	http.HandleFunc("/delete-user/{id}", deleteUser)

	http.HandleFunc("/courses/", courses)
	http.HandleFunc("/create-course/", createCourse)
	http.HandleFunc("/get-course/{id}", getCourse)
	http.HandleFunc("/update-course/{id}", updateCourse)
	http.HandleFunc("/delelte-course/{id}", deleteCourse)
	/*

		http.HandleFunc("/course/{id}/tests/", courseTests)
		http.HandleFunc("/course/{id}/users/", courseUsers)
		http.HandleFunc("/course/{id}/add-user/", courseAddUser)
		http.HandleFunc("/course/{id}/del-user/", courseDelUser)

		http.HandleFunc("/create-test/", createTest)
		http.HandleFunc("/test/{id}/", test)
		http.HandleFunc("/test/{id}/setting/", test)
		http.HandleFunc("/test/{id}/switch/", testSwitch)
		http.HandleFunc("/test/{id}/delete/", testDelete)

		http.HandleFunc("/test/{id}/users", testUsers)
		http.HandleFunc("/test/{id}/user/{id}", testUser)

		http.HandleFunc("/quests/", quests)
		http.HandleFunc("/create-quest/", createQuest)
		http.HandleFunc("/quest/{id}/", quest)
		http.HandleFunc("/quest/{id}/setting/", questsSetting)
		http.HandleFunc("/quest/{id}/delete/", questDelete)

	*/

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
	data := "Главная"
	tmpl := tmplFiles("view/index.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func about(w http.ResponseWriter, r *http.Request) {
	data := "О проекте"
	tmpl := tmplFiles("view/about.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func author(w http.ResponseWriter, r *http.Request) {
	data := "Об авторе"
	tmpl := tmplFiles("view/author.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func admin(w http.ResponseWriter, r *http.Request) {
	data := model.AllUser()
	tmpl := tmplFiles("view/admin.html")
	tmpl.ExecuteTemplate(w, "content", data)
}

func demo(w http.ResponseWriter, r *http.Request) {
	model.DemoUser()
	http.Redirect(w, r, "/admin/", http.StatusSeeOther)
}
