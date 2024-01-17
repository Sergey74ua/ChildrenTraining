package main

import (
	"fmt"
	"strconv"
	"strings"
)

type BinaryTreeNode struct {
	Value       int
	Left, Right *BinaryTreeNode
}

func NewBinaryTreeNode(value int) *BinaryTreeNode {
	return &BinaryTreeNode{Value: value}
}

func (t *BinaryTreeNode) insertNode(value int) {
	if value == t.Value {
		return
	}
	if value < t.Value {
		if t.Left == nil {
			t.Left = NewBinaryTreeNode(value)
		} else {
			t.Left.insertNode(value)
		}
	} else {
		if t.Right == nil {
			t.Right = NewBinaryTreeNode(value)
		} else {
			t.Right.insertNode(value)
		}
	}
}
func (t *BinaryTreeNode) removeNode(value int) *BinaryTreeNode {
	if t == nil {
		return nil
	}

	if value < t.Value {
		t.Left = t.Left.removeNode(value)
	} else if value > t.Value {
		t.Right = t.Right.removeNode(value)
	} else {
		if t.Left == nil {
			return t.Right
		} else if t.Right == nil {
			return t.Left
		}

		maxLeft := t.Left.findMax()
		t.Value = maxLeft.Value
		t.Left = t.Left.removeNode(maxLeft.Value)
	}
	return t
}

func (t *BinaryTreeNode) findMax() *BinaryTreeNode {
	for t.Right != nil {
		t = t.Right
	}
	return t
}

func (t *BinaryTreeNode) findNode(value int) *BinaryTreeNode {
	if t == nil || t.Value == value {
		return t
	}

	if value < t.Value {
		return t.Left.findNode(value)
	}

	return t.Right.findNode(value)
}

func (t *BinaryTreeNode) String() string {
	result := ""
	queue := []*BinaryTreeNode{t}

	for len(queue) > 0 {
		current := queue[0]
		queue = queue[1:]

		if current != nil {
			result += strconv.Itoa(current.Value) + " "
			queue = append(queue, current.Left, current.Right)
		}
	}

	return strings.TrimSpace(result)
}

func main() {
	var count int
	fmt.Scan(&count)

	var root *BinaryTreeNode
	for count > 0 {
		var command string
		var value int
		fmt.Scan(&command, &value)

		if command == "insert" {
			if root == nil {
				root = NewBinaryTreeNode(value)
			}
			root.insertNode(value)
		} else if command == "remove" {
			root = root.removeNode(value)
		} else if command == "find" {
			fmt.Println(root.findNode(value))
		}

		count--
	}
}
