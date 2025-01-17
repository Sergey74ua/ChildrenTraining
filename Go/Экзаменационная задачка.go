/*
Дана матрица целых чисел размером n строк и n столбцов.
Замените обратную диагональ матрицы на сумму индексов элемента равного среднему арифметическому элементов
расположенных одновременно над главной и под обратной диагоналями.
Гарантируется, что таких элементов матрице не больше одного.
Если элементов, удовлетворяющих требованиям в матрице не нашлось, то для замены используйте -1.

3
1 2 3
4 5 6
7 8 9

1 2 3
4 3 6
3 8 9

4
1 3 7 4
5 6 7 8
9 0 1 2
1 2 3 4

1 3 7 1
5 6 1 8
9 1 1 2
1 2 3 4
*/

package main

import (
	"bufio"
	"fmt"
	"os"
	"strconv"
	"strings"
)

func main() {
	scanner := bufio.NewScanner(os.Stdin)
	scanner.Scan()
	n, _ := strconv.Atoi(scanner.Text())

	// Ввод
	matrix := make([][]int, n)
	for i := 0; i < n; i++ {
		scanner.Scan()
		line := strings.Split(scanner.Text(), " ")
		matrix[i] = make([]int, n)
		for j := 0; j < n; j++ {
			matrix[i][j], _ = strconv.Atoi(line[j])
		}
	}

	// Среднее арифметическое
	sum := 0
	c := 0
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			if j > i && (n-1)-i < j {
				sum += matrix[i][j]
				c += 1
			}
		}
	}

	// Сумма индексов
	e := -1
	if sum%c == 0 {
		avg := sum / c
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if matrix[i][j] == avg {
					e = i + j
				}
			}
		}
	}

	// Заменяем диагональ
	for i := 0; i < n; i++ {
		matrix[i][n-i-1] = e
	}

	// Вывод
	for i := 0; i < n; i++ {
		for j := 0; j < n; j++ {
			fmt.Print(matrix[i][j])
			if j < n-1 {
				fmt.Print(" ")
			}
		}
		fmt.Println()
	}
}
