/*
package main

import "fmt"

type Matrix struct {
	data [][]int
}

// Начало вставленного кода
func NewMatrix(rows, cols, value int) Matrix {
	matrix := Matrix{}
	for i := 0; i < rows; i++ {
		new_cols := make([]int, cols)
		for j := 0; j < cols; j++ {
			new_cols[j] = value
		}
		matrix.data = append(matrix.data, new_cols)
	}
	return matrix
}

func (m *Matrix) Rows() int {
	return len(m.data)
}

func (m *Matrix) Cols() int {
	return len(m.data[0])
}

func (m *Matrix) Set(row, col, value int) {
	m.data[row][col] = value
}

func (m *Matrix) Get(row, col int) int {
	return m.data[row][col]
}

func (m *Matrix) String() string {
	res := ""
	for _, row := range m.data {
		for _, item := range row {
			res += fmt.Sprintf("%d", item) + " "
		}
		res += "\n"
	}
	return res
}

func (m *Matrix) AddRow(value int) {
	newRow := make([]int, m.Cols())
	for i := 0; i < m.Cols(); i++ {
		newRow[i] = value
	}
	m.data = append(m.data, newRow)
}

func (m *Matrix) AddCol(value int) {
	for i := 0; i < m.Rows(); i++ {
		m.data[i] = append(m.data[i], value)
	}
}

func (m *Matrix) Convolution(core *Matrix) Matrix {
	newRows := m.Rows() - core.Rows() + 1
	newCols := m.Cols() - core.Cols() + 1
	newMatrix := NewMatrix(newRows, newCols, 0)

	// Move core start pos
	for y1 := 0; y1 < newRows; y1++ {
		for x1 := 0; x1 < newCols; x1++ {
			curSum := 0
			// Move inside current core place
			for y2 := 0; y2 < core.Rows(); y2++ {
				for x2 := 0; x2 < core.Cols(); x2++ {
					curSum += m.data[y1+y2][x1+x2] * core.Get(y2, x2)
				}
			}
			newMatrix.Set(y1, x1, curSum)
		}
	}
	return newMatrix
}

func (a *Matrix) Multiplication(b *Matrix) *Matrix {
	newRows := a.Rows()
	newCols := b.Cols()
	newMatrix := NewMatrix(newRows, newCols, 0)

	for i := 0; i < newRows; i++ {
		for j := 0; j < newCols; j++ {
			for k := 0; k < b.Rows(); k++ {
				newMatrix.Set(i, j, newMatrix.Get(i, j)+a.Get(i, k)*b.Get(k, j))
			}
		}
	}
	return &newMatrix
}

// Конец вставленного кода

func main() {
	var rowsFirst, colsFirst, firstInitVal,
		rowsCore, colsCore int

	fmt.Scan(&rowsFirst, &colsFirst, &firstInitVal)
	first := NewMatrix(rowsFirst, colsFirst, firstInitVal)
	for i := 0; i < first.Rows(); i++ {
		for j := 0; j < first.Cols(); j++ {
			var t int
			fmt.Scan(&t)
			first.Set(i, j, t)
		}
	}

	fmt.Scan(&rowsCore, &colsCore)
	core := NewMatrix(rowsCore, colsCore, 0)
	for i := 0; i < core.Rows(); i++ {
		for j := 0; j < core.Cols(); j++ {
			var t int
			fmt.Scan(&t)
			core.Set(i, j, t)
		}
	}

	conv := first.Convolution(&core)

	conv.AddRow(1)
	conv.AddCol(1)
	conv.AddCol(1)

	mult := conv.Multiplication(&first)

	fmt.Print(mult)
}
*/