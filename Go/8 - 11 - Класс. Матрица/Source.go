package main

import "fmt"

type Matrix struct {
	data [][]int
}

// Ваш код здесь //////////////////////

// Создаёт и возвращает новую матрицу с количеством строк rows и столбцов cols. Все элементы матрицы
// заполняются значением value. Первый индекс определяет номер строки, второй - номер столбца;
func NewMatrix(rows, cols, value int) Matrix {
	data := make([][]int, rows)
	for i := 0; i < rows; i++ {
		data[i] = make([]int, cols)
		for j := 0; j < cols; j++ {
			data[i][j] = value
		}
	}
	return Matrix{data: data}
}

// метод возвращает количество строк в матрице m;
func (m *Matrix) Rows() int {
	return len(m.data)
}

// метод возвращает количество столбцов в матрице m;
func (m *Matrix) Cols() int {
	if len(m.data) > 0 {
		return len(m.data[0])
	}
	return 0
}

// метод устанавливает элементу матрицы m с индексом (row, col) значение равное value;
func (m *Matrix) Set(row, col, value int) {
	if row >= 0 && row < len(m.data) && col >= 0 && col < len(m.data[0]) {
		m.data[row][col] = value
	}
}

// метод возвращает значение элемента матрицы m с индексом (row, col);
func (m *Matrix) Get(row, col int) int {
	if row >= 0 && row < len(m.data) && col >= 0 && col < len(m.data[0]) {
		return m.data[row][col]
	}
	return 0
}

// метод выполняет свёртку матрицы m с ядром core. Как результат возвращается новая матрица.
func (m *Matrix) Convolution(core *Matrix) Matrix {
	rows := m.Rows() - core.Rows() + 1
	cols := m.Cols() - core.Cols() + 1
	result := NewMatrix(rows, cols, 0)

	for i := 0; i < rows; i++ {
		for j := 0; j < cols; j++ {
			sum := 0
			for k := 0; k < core.Rows(); k++ {
				for l := 0; l < core.Cols(); l++ {
					sum += m.Get(i+k, j+l) * core.Get(k, l)
				}
			}
			result.Set(i, j, sum)
		}
	}

	return result
}

// метод выполняет умножение матрицы a на матрицу b. Как результат возвращается новая матрица.
//func (a *Matrix) Multiplication(b *Matrix) Matrix {
func (a *Matrix) Multiplication(b *Matrix) string {
	rowsA := a.Rows()
	colsA := a.Cols()
	rowsB := b.Rows()
	colsB := b.Cols()

	if colsA != rowsB {
		//return NewMatrix(0, 0, 0)
		result := NewMatrix(0, 0, 0)
		return result.String()
	}

	result := NewMatrix(rowsA, colsB, 0)

	for i := 0; i < rowsA; i++ {
		for j := 0; j < colsB; j++ {
			sum := 0
			for k := 0; k < colsA; k++ {
				sum += a.Get(i, k) * b.Get(k, j)
			}
			result.Set(i, j, sum)
		}
	}

	//return result
	return result.String()
}

// метод добавляет в конец матрицы m дополнительную строку заполненную значением value. Т.е исходная матрица изменяется;
func (m *Matrix) AddRow(value int) {
	row := make([]int, m.Cols())
	for i := 0; i < m.Cols(); i++ {
		row[i] = value
	}
	m.data = append(m.data, row)
}

// метод добавляет в конец матрицы m дополнительный столбец заполненный значением value. Т.е исходная матрица изменяется;
func (m *Matrix) AddCol(value int) {
	for i := 0; i < m.Rows(); i++ {
		m.data[i] = append(m.data[i], value)
	}
}

// каждый элемент матрицы m добавляется в результирующую строку через пробел. В конце строки вместо пробела символ перевода строки.
func (m *Matrix) String() string {
	result := ""
	for i := 0; i < m.Rows(); i++ {
		for j := 0; j < m.Cols(); j++ {
			result += fmt.Sprintf("%d ", m.Get(i, j))
		}
		result += "\n"
	}
	return result
}

////////////////////////////////////

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
