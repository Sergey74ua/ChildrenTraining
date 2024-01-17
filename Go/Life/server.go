package main

import (
	"encoding/json"
	"fmt"
	"log"
	"net/http"
)

type Point struct {
	x int
	y int
}

var matrix []Point

func main() {
	http.HandleFunc("/status", stat)
	http.HandleFunc("/matrix", step)

	err := http.ListenAndServe("localhost:8080", nil)
	if err != nil {
		log.Fatal(err)
	}
}

func stat(w http.ResponseWriter, r *http.Request) {
	fmt.Fprint(w, "Сервер работает.")
}

func step(w http.ResponseWriter, r *http.Request) {
	switch r.Method {
	case http.MethodGet:
		getStep(w, r)
	case http.MethodPost:
		postStep(w, r)
	default:
		http.Error(w, "Неизвестный запрос (используйте get или post)", http.StatusMethodNotAllowed)
	}
}

func getStep(w http.ResponseWriter, r *http.Request) {
	json.NewEncoder(w).Encode(matrix)
}

func postStep(w http.ResponseWriter, r *http.Request) {
	var point Point
	err := json.NewDecoder(r.Body).Decode(&point)
	if err != nil {
		http.Error(w, err.Error(), http.StatusInternalServerError)
		return
	}

	matrix = append(matrix, point)
	fmt.Fprint(w, "добавлена клетка: ", point)
}
