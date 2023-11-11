package main

import (
	"bufio"
	"fmt"
	"log"
	"os"
	"strconv"
	"strings"
)

type Passager struct {
	name string
	age  int
}

func main() {
	var (
		line []string
		t    []string
		v    []Passager
		p    Passager
		s    string
		n    string
		a    int
	)

	// Открывем файл csv
	file, err := os.Open("train.csv")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	// Сканируем большой текст с разбивкой по строкам
	scanner := bufio.NewScanner(file)
	for scanner.Scan() {
		line = strings.Split(scanner.Text(), "\r")
		for _, w := range line {
			t = strings.Split(w, ",")
			s = t[3] + "," + t[4]
			n = s ////УБРАТЬ ПРОБЕЛЫ
			a, err = strconv.Atoi(t[6])
			p = Passager{name: n, age: a}
			v = append(v, p)
		}
	}

	//Сортировка

	//Вывод
	for _, i := range v {
		fmt.Println(i.name)
	}
}
