package view

import "net/http"

//Статические файлы(путь доступа для клиента)
func Static(stat string) {
	http.Handle("/view/", http.StripPrefix("/view/", http.FileServer(http.Dir(stat))))
}
