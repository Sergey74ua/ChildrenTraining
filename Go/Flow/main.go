package main

import (
	"flay/control"
	"flay/model"
	//"github.com/mattn/go-sqlite3"
)

func main() {
	model.Msg() //ДЛЯ ТЕСТА
	control.Route("Запуск сервера")
}
