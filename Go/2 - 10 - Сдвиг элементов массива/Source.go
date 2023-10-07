package main

import "fmt"

func shift(data []int, steps int) {
	temp := make([]int, len(data), cap(data))
	n := (len(data)*2 - steps%len(data)) % len(data)
	temp = append(data[n:], data[:n]...)
	copy(data, temp)
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
