package main

import "fmt"

type Human struct {
	name string
	age  int
}

// Ваш код здесь
func printTypes(data []interface{}) {
	for _, val := range data {
		switch val.(type) {
		case int:
			fmt.Print("int ")
		case string:
			fmt.Print("string ")
		case Human:
			fmt.Print("Human ")
		case *Human:
			fmt.Print("*Human ")
		default:
			fmt.Print("interface ")
		}
	}
}

func main() {
	var count int
	fmt.Scan(&count)

	var data []interface{} = make([]interface{}, count)
	for i := 0; i < count; i++ {
		var t string
		fmt.Scan(&t)
		switch t {
		case "int":
			var val int = 0
			data[i] = interface{}(val)
		case "string":
			var val string = "0"
			data[i] = interface{}(val)
		case "Human":
			var val Human = Human{}
			data[i] = interface{}(val)
		case "*Human":
			var val *Human = &Human{}
			data[i] = interface{}(val)
		}
	}

	printTypes(data)
}
