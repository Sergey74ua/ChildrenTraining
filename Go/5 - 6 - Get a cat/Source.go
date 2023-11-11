package main

import (
	"fmt"
	"math/rand"
)

// структура кота
type Cat struct {
	Live bool // жизнь и смерть кота
	Show bool // закрыт или открыт кот
}

// Конструктор кота
func NewCat() Cat {
	cat := Cat{}
	cat.Live = rand.Intn(2) == 1
	cat.Show = false
	return cat
}

// демонстрируем состояние кота
func (cat *Cat) IsAlive() bool {
	if cat.Show {
		return cat.Live
	} else {
		cat.Live = rand.Intn(2) == 1
		return cat.Live
	}
}

// структура коробки
type Box struct{}

// функция открывания коробки
func (box *Box) open() Cat {
	cat := NewCat()
	cat.Show = true
	return cat
}

func main() {
	var box Box
	cat := box.open()
	if cat.IsAlive() {
		fmt.Print("alive")
	} else {
		fmt.Print("dead")
	}
}
