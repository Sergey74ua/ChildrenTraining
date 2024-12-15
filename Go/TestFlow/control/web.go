package control

import (
	"TestFlow/model"
	"fmt"
	"html/template"
	"net/http"
	"time"
)

func index(w http.ResponseWriter, r *http.Request) {
	data := model.AllUser()
	page, err := template.ParseFiles(
		"view/index.html",
		"view/inc/header.html",
		"view/inc/menu.html",
		"view/inc/footer.html",
	)
	if err != nil {
		fmt.Fprint(w, err.Error())
	}
	page.ExecuteTemplate(w, "content", data)
}

func about(w http.ResponseWriter, r *http.Request) {
	data := 16
	page, err := template.ParseFiles(
		"view/about.html",
		"view/inc/header.html",
		"view/inc/menu.html",
		"view/inc/footer.html",
	)
	if err != nil {
		fmt.Fprint(w, err.Error())
	}
	page.ExecuteTemplate(w, "content", data)
}

func contact(w http.ResponseWriter, r *http.Request) {
	data := 7
	page, err := template.ParseFiles(
		"view/contact.html",
		"view/inc/header.html",
		"view/inc/menu.html",
		"view/inc/footer.html",
	)
	if err != nil {
		fmt.Fprint(w, err.Error())
	}
	page.ExecuteTemplate(w, "content", data)
}

func Web() {
	t := time.Now()
	fmt.Println(t.Format("2006.01.02") + " " + t.Format("15:04:05") + " " + "Web-сервер успешно запущен")

	//Статические файлы
	http.Handle("/view/", http.StripPrefix("/view/", http.FileServer(http.Dir("./view/"))))

	//Урлы страниц
	http.HandleFunc("/", index)
	http.HandleFunc("/about/", about)
	http.HandleFunc("/contact/", contact)

	//Слушатель порта
	http.ListenAndServe("localhost:8888", nil)
}
