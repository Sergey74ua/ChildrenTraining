package main

import (
	"TestFlow/control"
	"TestFlow/model"
	"TestFlow/view"
	"encoding/json"
	"log"
	"os"
)

// Глобальные переменные
type Config struct {
	HOST string // Адрес сервера
	PORT string // Порт сервера
	DBMS string // Дравер СУБД
	PATH string // Расположение БД
	STAT string // Расположение файлов
}

func main() {
	// Читаем данные из файла setting.json
	jsonFile, err := os.ReadFile("setting.json")
	if err != nil {
		log.Fatalf("Ошибка чтения файла: %v", err)
	}

	// Создаем экземпляр структуры Config
	var config Config

	// Распарсиваем JSON в структуру config
	err = json.Unmarshal(jsonFile, &config)
	if err != nil {
		log.Fatalf("Ошибка распаковки JSON: %v", err)
	}
	//Создание или проверка базы данных
	model.Init(config.DBMS, config.PATH)

	//Статические файлы
	view.Static(config.STAT)

	//Запуск контроллеров
	control.Tg()
	t := control.MustToken()
	print(t)

	control.Web(config.HOST, config.PORT)
}
