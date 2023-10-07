package main

import "fmt"

func fill(maze [][]int) {
	var n int
	for y := 0; y < len(maze); y++ {
		for x := 0; x < len(maze[y]); x++ {
			n = 0
			if maze[y][x] != -1 {
				if y > 0 && maze[y-1][x] == -1 {
					n++
				}
				if y > 0 && x < len(maze[y])-1 && maze[y-1][x+1] == -1 {
					n++
				}
				if x < len(maze[y])-1 && maze[y][x+1] == -1 {
					n++
				}
				if y < len(maze)-1 && x < len(maze[y])-1 && maze[y+1][x+1] == -1 {
					n++
				}
				if y < len(maze)-1 && maze[y+1][x] == -1 {
					n++
				}
				if y < len(maze)-1 && x > 0 && maze[y+1][x-1] == -1 {
					n++
				}
				if x > 0 && maze[y][x-1] == -1 {
					n++
				}
				if y > 0 && x > 0 && maze[y-1][x-1] == -1 {
					n++
				}
				maze[y][x] = n
			}
		}
	}
}

func main() {
	var rows, cols int
	fmt.Scanf("%d %d\n", &rows, &cols)

	// Создаём срез и заполняем его данными о расположении мин
	maze := make([][]int, rows, rows)
	for i := range maze {
		maze[i] = make([]int, cols, cols)
		for j := range maze[i] {
			fmt.Scanf("%d", &maze[i][j])
		}
	}

	// Заполняем игровое поле подсказками
	fill(maze)

	// Выводим на экран
	for _, row := range maze {
		for _, cell := range row {
			fmt.Printf("%3d", cell)
		}
		fmt.Println()
	}
}
