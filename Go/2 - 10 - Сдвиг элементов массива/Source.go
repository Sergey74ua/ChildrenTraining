package main

import "fmt"

func shift(data []int, steps int) []int {
	fmt.Println(data, steps)
	//...................................
	return data
}

func main() {
	var steps int
	fmt.Scan(&steps)

	var data [10]int
	for index := range data {
		fmt.Scan(&data[index])
	}

	shift(data[:], steps)
	for _, value := range data {
		fmt.Printf("%d ", value)
	}
}
