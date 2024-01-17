package main

import (
	"fmt"
)

type Stack interface {
	empty() bool
	push(r rune)
	top() rune
	pop() rune
}

// Ваш код здесь //////////////////////

// Реализация типа SimpleStack, удовлетворяющая интерфейсу Stack
type SimpleStack struct {
	stack []rune
}

// NewSimpleStack - создаёт пустой стек
func NewSimpleStack() *SimpleStack {
	return &SimpleStack{stack: []rune{}}
}

// возвращает true, если стек пуст
func (s *SimpleStack) empty() bool {
	return len(s.stack) == 0
}

// добавляет на вершину стека символ r
func (s *SimpleStack) push(r rune) {
	s.stack = append(s.stack, r)
}

// возвращает элемент расположенный на вершине стека
func (s *SimpleStack) top() rune {
	if s.empty() {
		return 0
	}
	return s.stack[len(s.stack)-1]
}

// извлекает элемент расположенный на вершине стека и возвращает его
func (s *SimpleStack) pop() rune {
	if s.empty() {
		return 0
	}
	popValue := s.stack[len(s.stack)-1]
	s.stack = s.stack[:len(s.stack)-1]
	return popValue
}

///////////////////////////////////////

func bracketValidator(stack Stack, str string) bool {
	mapping := map[rune]rune{
		')': '(',
		']': '[',
		'}': '{',
	}

	for _, char := range str {
		if char == '(' || char == '[' || char == '{' {
			stack.push(char)
		} else if char == ')' || char == ']' || char == '}' {
			if stack.empty() || stack.top() != mapping[char] {
				return false
			}
			stack.pop()
		}
	}

	return stack.empty()
}

func main() {
	var input string
	fmt.Scan(&input)
	fmt.Println(bracketValidator(NewSimpleStack(), input))
}
