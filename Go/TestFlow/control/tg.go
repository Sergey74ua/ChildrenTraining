package control

import (
	"fmt"
	"time"
)

// Контролер телеграмм-бота
func Tg() {
	t := time.Now()
	fmt.Println(t.Format("2006.01.02") + " " + t.Format("15:04:05") + " " + "Телеграм сервис недоступен")
}
