package main

import "fmt"

func main() {
	var row, col int
	fmt.Scan(&row, &col)
	fmt.Printf("% 5v", "|")
	for i := 1; i <= col; i++ {
		fmt.Printf("% 4v", i)
	}
	fmt.Println()
	fmt.Printf("% 5v", "--")
	for i := 1; i <= col; i++ {
		fmt.Printf("% 4v", "----")
	}
	fmt.Println()
	for i := 1; i <= row; i++ {
		fmt.Printf("% 4v|", i)
		for j := 1; j <= col; j++ {
			fmt.Printf("% 4v", i*j)
		}
		fmt.Println()
	}

	var pause string
	fmt.Scan(&pause)
}
