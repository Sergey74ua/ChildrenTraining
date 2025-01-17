package control

import (
	"flag"
	"fmt"
	"log"
	"time"
)

// Контролер телеграмм-бота
func Tg() {
	t := time.Now()
	fmt.Println(t.Format("2006.01.02") + " " + t.Format("15:04:05") + " " + "Телеграм сервис недоступен")
}

func MustToken() string {
	token := flag.String("token-bot-token", "", "tokn for acces to telegram bot")
	flag.Parse()
	if *token == "a" { //"" {
		log.Fatal("token is not specified")
	}

	return *token
}
