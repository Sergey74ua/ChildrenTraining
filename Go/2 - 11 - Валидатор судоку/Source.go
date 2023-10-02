package main

import "fmt"

const rows int = 9
const cols int = 9

// Ваш код будет вставлен сюда
func test(line []int) bool {
	for i := 0; i < len(line)-1; i++ {
		for j := i + 1; j < len(line); j++ {
			if line[i] > line[j] {
				line[i], line[j] = line[j], line[i]
			}
		}
	}
	for i := 0; i < len(line); i++ {
		if line[i] != i+1 {
			return false
		}
	}
	return true
}

func isValidSudoku(bord [rows][cols]int) bool {
	var shaft [cols][rows]int

	for i := 0; i < rows; i++ {
		//Проверка по рядам
		line := make([]int, len(bord[i]), cap(bord[i]))
		copy(line, bord[i][:])
		if !test(line) {
			return false
		}
		//Распределение по колонкам
		for j := 0; j < rows; j++ {
			shaft[j][i] = bord[i][j]
		}
	}
	//Проверка по колонкам
	for i := 0; i < cols; i++ {
		line := make([]int, len(shaft[i]), cap(shaft[i]))
		copy(line, shaft[i][:])
		if !test(line) {
			return false
		}
	}

	return true
}

func main() {
	var bord [rows][cols]int

	for row := 0; row < rows; row++ {
		for col := 0; col < cols; col++ {
			fmt.Scanf("%c", &bord[row][col]) // Считываем один символ
			bord[row][col] -= '0'            // Чтобы из ASCII кода символа получить цифру
		}
		fmt.Scanf("\n")
	}

	if isValidSudoku(bord) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
