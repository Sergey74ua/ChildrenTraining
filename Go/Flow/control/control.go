package control

import (
	"fmt"
	"net/http"
	"text/template"
)

func index(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "<h1>Главная</h1><div><a href='/about'>О нас</a><a href='/contact'>Контакты</a></div>")
}

func about(w http.ResponseWriter, r *http.Request) {
	page, _ := template.ParseFiles("view/about.html")
	page.Execute(w, "О нас")
}

func contact(w http.ResponseWriter, r *http.Request) {
	page, err := template.ParseFiles(
		"view/contact.html",
		"view/inc/header.html",
		"view/inc/menu.html",
		"view/inc/footer.html",
	)
	if err != nil {
		fmt.Fprint(w, err.Error())
	}
	page.ExecuteTemplate(w, "content", nil)
}

func Route(msg string) {
	fmt.Println(msg)

	http.Handle("/view/", http.StripPrefix("/view/", http.FileServer(http.Dir("./view/"))))

	http.HandleFunc("/", index)
	http.HandleFunc("/about/", about)
	http.HandleFunc("/contact/", contact)

	http.ListenAndServe("localhost:8080", nil)
}
