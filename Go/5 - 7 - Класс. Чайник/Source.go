package main

import "fmt"

type Water struct {
	temperature int
}

func NewWater(temperature int) *Water {
	return &Water{
		temperature: temperature,
	}
}

type Teapot struct {
	water *Water
}

func NewTeapot(water *Water) *Teapot {
	return &Teapot{
		water: water,
	}
}

func (this *Teapot) is_boiling() bool {
	return this.water.temperature >= 100
}

func (this *Teapot) heat_up(t int) {
	this.water.temperature += t
}

func main() {
	var temperature, count int
	fmt.Scan(&temperature, &count)

	heat := NewQueue()
	for i := 0; i < count; i++ {
		var t int
		fmt.Scan(&t)
		heat.Push(t)
	}

	water := NewWater(temperature)
	teapot := NewTeapot(water)

	for !teapot.is_boiling() {
		teapot.heat_up(heat.Pop())
	}

	for !heat.IsEmpty() {
		fmt.Print(heat.Pop(), " ")
	}
}
