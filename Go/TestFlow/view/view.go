package view

import "net/http"

//Статические файлы
func Static(stat string) {
	http.Handle("/view/", http.StripPrefix("/view/", http.FileServer(http.Dir(stat))))
}
