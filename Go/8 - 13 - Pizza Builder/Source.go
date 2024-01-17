package main

import "fmt"

type PizzaIngredients struct {
	dough    string
	sauces   []string
	toppings []string
	cheeses  []string
}

type Pizza struct { // Product
	PizzaIngredients
}

func NewPizza(dough string, sauces []string, toppings []string, cheeses []string) Pizza {
	var p Pizza
	p.dough = dough
	p.sauces = sauces
	p.toppings = toppings
	p.cheeses = cheeses

	return p
}

func (p Pizza) String() string {
	str := p.dough
	for _, v := range p.sauces {
		str += " " + v
	}
	for _, v := range p.toppings {
		str += " " + v
	}
	for _, v := range p.cheeses {
		str += " " + v
	}
	return str
}

type PizzaRecipe interface { // Builder
	newPizza() PizzaRecipe

	// Builder type 1
	makeBase() PizzaRecipe
	makeFilling() PizzaRecipe
	Bake() Pizza

	// Builder type 2
	setDough(dough string) PizzaRecipe
	addSauce(sauce string) PizzaRecipe
	addTopping(topping string) PizzaRecipe
	addCheese(cheese string) PizzaRecipe
}

type PizzaChef struct { // Director
	recipe PizzaRecipe
}

func (c *PizzaChef) setRecipe(recipe PizzaRecipe) {
	c.recipe = recipe
}

func (c *PizzaChef) cook() Pizza {
	return c.recipe.
		newPizza().
		makeBase().
		makeFilling().
		Bake()
}

type MargheritaRecipe struct {
	PizzaIngredients
}

func (r *MargheritaRecipe) newPizza() PizzaRecipe {
	r.dough = ""
	r.sauces = nil
	r.toppings = nil
	r.cheeses = nil
	return r
}

func (r *MargheritaRecipe) makeBase() PizzaRecipe {
	r.dough = "MargheritaDough"
	return r
}
func (r *MargheritaRecipe) makeFilling() PizzaRecipe {
	r.sauces = append(r.sauces, "Tomato paste")
	r.toppings = append(r.toppings, "Tomato", "Basil leaves")
	r.cheeses = append(r.cheeses, "Mozzarella", "Parmesan")
	return r
}
func (r *MargheritaRecipe) Bake() Pizza {
	return NewPizza(r.dough, r.sauces, r.toppings, r.cheeses)
}
func (r *MargheritaRecipe) setDough(dough string) PizzaRecipe {
	return r
}
func (r *MargheritaRecipe) addSauce(sauce string) PizzaRecipe {
	return r
}
func (r *MargheritaRecipe) addTopping(topping string) PizzaRecipe {
	return r
}
func (r *MargheritaRecipe) addCheese(cheese string) PizzaRecipe {
	return r
}

type CustomRecipe struct {
	PizzaIngredients
}

func (r *CustomRecipe) newPizza() PizzaRecipe {
	r.dough = ""
	r.sauces = nil
	r.toppings = nil
	r.cheeses = nil
	return r
}

func (r *CustomRecipe) makeBase() PizzaRecipe {
	return r
}
func (r *CustomRecipe) makeFilling() PizzaRecipe {
	return r
}
func (r *CustomRecipe) Bake() Pizza {
	p := NewPizza(r.dough, r.sauces, r.toppings, r.cheeses)
	return p
}

func (r *CustomRecipe) setDough(dough string) PizzaRecipe {
	r.dough = dough
	return r
}
func (r *CustomRecipe) addSauce(sauce string) PizzaRecipe {
	r.sauces = append(r.sauces, sauce)
	return r
}
func (r *CustomRecipe) addTopping(topping string) PizzaRecipe {
	r.toppings = append(r.toppings, topping)
	return r
}
func (r *CustomRecipe) addCheese(cheese string) PizzaRecipe {
	r.cheeses = append(r.cheeses, cheese)
	return r
}

// Ваш код здесь //////////////////////
// Ваша задача реализовать два рецепта:

// PepperoniRecipe. Основа для пиццы: "PepperoniDough". Соус: "Tomato paste". Топпинги: "Pepperoni" и "Garlic". Сыры: "Mozzarella" и "Fontina";
type PepperoniRecipe struct {
	PizzaIngredients
}

func (r *PepperoniRecipe) newPizza() PizzaRecipe {
	r.dough = ""
	r.sauces = nil
	r.toppings = nil
	r.cheeses = nil
	return r
}

func (r *PepperoniRecipe) makeBase() PizzaRecipe {
	r.dough = "PepperoniDough"
	return r
}
func (r *PepperoniRecipe) makeFilling() PizzaRecipe {
	r.sauces = append(r.sauces, "Tomato paste")
	r.toppings = append(r.toppings, "Pepperoni", "Garlic")
	r.cheeses = append(r.cheeses, "Mozzarella", "Fontina")
	return r
}
func (r *PepperoniRecipe) Bake() Pizza {
	return NewPizza(r.dough, r.sauces, r.toppings, r.cheeses)
}
func (r *PepperoniRecipe) setDough(dough string) PizzaRecipe {
	return r
}
func (r *PepperoniRecipe) addSauce(sauce string) PizzaRecipe {
	return r
}
func (r *PepperoniRecipe) addTopping(topping string) PizzaRecipe {
	return r
}
func (r *PepperoniRecipe) addCheese(cheese string) PizzaRecipe {
	return r
}

// HawaiianRecipe. Основа для пиццы: "HawaiianDough". Соус: "Tomato paste". Топпинги: "Pineapple", "Onion" и "Bacon". Сыр: "Mozzarella";
type HawaiianRecipe struct {
	PizzaIngredients
}

func (r *HawaiianRecipe) newPizza() PizzaRecipe {
	r.dough = ""
	r.sauces = nil
	r.toppings = nil
	r.cheeses = nil
	return r
}

func (r *HawaiianRecipe) makeBase() PizzaRecipe {
	r.dough = "HawaiianDough"
	return r
}
func (r *HawaiianRecipe) makeFilling() PizzaRecipe {
	r.sauces = append(r.sauces, "Tomato paste")
	r.toppings = append(r.toppings, "Pineapple", "Onion", "Bacon")
	r.cheeses = append(r.cheeses, "Mozzarella")
	return r
}
func (r *HawaiianRecipe) Bake() Pizza {
	return NewPizza(r.dough, r.sauces, r.toppings, r.cheeses)
}
func (r *HawaiianRecipe) setDough(dough string) PizzaRecipe {
	return r
}
func (r *HawaiianRecipe) addSauce(sauce string) PizzaRecipe {
	return r
}
func (r *HawaiianRecipe) addTopping(topping string) PizzaRecipe {
	return r
}
func (r *HawaiianRecipe) addCheese(cheese string) PizzaRecipe {
	return r
}

///////////////////////////////////////

func main() {
	var chef PizzaChef

	var count int
	fmt.Scan(&count)
	for count > 0 {
		var pizzaType string
		fmt.Scan(&pizzaType)

		var p Pizza
		switch pizzaType {
		case "hawaiian":
			chef.setRecipe(&HawaiianRecipe{})
			p = chef.cook()
		case "pepperoni":
			chef.setRecipe(&PepperoniRecipe{})
			p = chef.cook()
		case "margherita":
			chef.setRecipe(&MargheritaRecipe{})
			p = chef.cook()
		case "custom":
			p = (&CustomRecipe{}).newPizza().
				setDough("CustomDough").
				addSauce("CustomSauce").
				addTopping("CustomTopping1").
				addTopping("CustomTopping2").
				addCheese("CustomCheese").
				Bake()
		}
		fmt.Println(p)

		count--
	}
}
