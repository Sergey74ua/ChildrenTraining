/*package main

import (
	"fmt"
	"math/rand"
	"time"
)

type Board [3][3]string

func NewBoard() Board {
	return [3][3]string{{" ", " ", " "}, {" ", " ", " "}, {" ", " ", " "}}
}

func (b *Board) set(row, col int, marker string) (ok bool) {
	if b[row][col] != " " {
		return false
	}
	b[row][col] = marker
	return true
}

func (b *Board) isGameOver() (ok bool, winner string) {
	for row := 0; row < 3; row++ {
		if b[row][0] != " " && b[row][0] == b[row][1] && b[row][0] == b[row][2] {
			return true, b[row][0]
		}
	}

	for col := 0; col < 3; col++ {
		if b[0][col] != " " && b[0][col] == b[1][col] && b[0][col] == b[2][col] {
			return true, b[0][col]
		}
	}

	if b[0][0] != " " && b[0][0] == b[1][1] && b[0][0] == b[2][2] {
		return true, b[0][0]
	}
	if b[0][2] != " " && b[0][2] == b[1][1] && b[0][2] == b[2][0] {
		return true, b[0][2]
	}

	isDraw := true
	for row := 0; row < 3; row++ {
		for col := 0; col < 3; col++ {
			if b[row][col] == " " {
				isDraw = false
				break
			}
		}
	}

	return isDraw, "-"
}

type Bot interface {
	startGame(marker string)
	getMarker() string
	step(board Board) (row, col int, marker string)
	endGame(winner string)
}

type RandomBot struct {
	marker string
}

func NewRandomBot() *RandomBot {
	return &RandomBot{"?"}
}

func (b *RandomBot) startGame(marker string) {
	b.marker = marker
}

func (b *RandomBot) getMarker() string {
	return b.marker
}

func (b *RandomBot) step(board Board) (row, col int, marker string) {
	for {
		row, col, marker = rand.Intn(3), rand.Intn(3), b.marker
		if board[row][col] == " " {
			return
		}
	}
}

func (b *RandomBot) endGame(winner string) {
	// Бот не обучается
}

// Ваш код здесь //////////////////////

type UserBot struct {
	marker string
}

func NewUserBot() *UserBot {
	return &UserBot{"?"}
}

func (b *UserBot) startGame(marker string) {
	b.marker = marker
}

func (b *UserBot) getMarker() string {
	return b.marker
}

func (b *UserBot) step(board Board) (row, col int, marker string) {
	// 1. Победная точка
	// горизонтали
	for y := 0; y < 3; y++ {
		if board[y][0] == b.marker && board[y][1] == b.marker && board[y][2] == " " {
			return y, 2, b.marker
		} else if board[y][0] == b.marker && board[y][2] == b.marker && board[y][1] == " " {
			return y, 1, b.marker
		} else if board[y][1] == b.marker && board[y][2] == b.marker && board[y][0] == " " {
			return y, 0, b.marker
		}
	}
	// вертикали
	for x := 0; x < 3; x++ {
		if board[0][x] == b.marker && board[1][x] == b.marker && board[2][x] == " " {
			return 2, x, b.marker
		} else if board[0][x] == b.marker && board[2][x] == b.marker && board[1][x] == " " {
			return 1, x, b.marker
		} else if board[1][x] == b.marker && board[2][x] == b.marker && board[0][x] == " " {
			return 0, x, b.marker
		}
	}

	// диагонали
	if board[0][0] == b.marker && board[1][1] == b.marker && board[2][2] == " " {
		return 2, 2, b.marker
	} else if board[0][0] == b.marker && board[2][2] == b.marker && board[1][1] == " " {
		return 1, 1, b.marker
	} else if board[1][1] == b.marker && board[2][2] == b.marker && board[0][0] == " " {
		return 0, 0, b.marker
	} else if board[0][2] == b.marker && board[1][1] == b.marker && board[2][0] == " " {
		return 2, 0, b.marker
	} else if board[0][2] == b.marker && board[2][0] == b.marker && board[1][1] == " " {
		return 1, 1, b.marker
	} else if board[1][1] == b.marker && board[2][0] == b.marker && board[0][2] == " " {
		return 0, 2, b.marker
	}

	// 2. Вторая точка
	for y := 0; y < 3; y++ {
		for x := 0; x < 3; x++ {
			if board[y][x] == b.marker {
				// горизонталь
				if (board[y][0] == " " || board[y][0] == b.marker) &&
					(board[y][1] == " " || board[y][1] == b.marker) &&
					(board[y][2] == " " || board[y][2] == b.marker) {
					for i := 0; i < 3; i++ {
						if board[y][i] == " " {
							return y, i, b.marker
						}
					}
				}
				// вертикаль
				if (board[0][x] == " " || board[0][x] == b.marker) &&
					(board[1][x] == " " || board[1][x] == b.marker) &&
					(board[2][x] == " " || board[2][x] == b.marker) {
					for i := 0; i < 3; i++ {
						if board[y][i] == " " {
							return i, x, b.marker
						}
					}
				}
				// диогональ
			}
		}
	}

	// 3. Центр
	if board[1][1] == " " {
		return 1, 1, b.marker
	}
	// 4. Углы
	if board[0][0] == " " {
		return 0, 0, b.marker
	} else if board[0][2] == " " {
		return 0, 2, b.marker
	} else if board[2][0] == " " {
		return 2, 0, b.marker
	} else if board[2][2] == " " {
		return 2, 2, b.marker
	}
	// 5. Cерединки
	if board[0][1] == " " {
		return 0, 1, b.marker
	} else if board[1][0] == " " {
		return 1, 0, b.marker
	} else if board[1][2] == " " {
		return 1, 2, b.marker
	} else if board[2][1] == " " {
		return 2, 1, b.marker
	}

	return
}

func (b *UserBot) endGame(winner string) {
	// Бот не обучается
}

///////////////////////////////////////

func main() {
	rand.Seed(time.Now().UnixNano())
	//trainGames, battleGames := 10000, 1000
	trainGames, battleGames := 10, 10 /////////////////////
	totalGames := trainGames + battleGames

	userBot := NewUserBot()
	randomBot := NewRandomBot()

	var winsCount int
	for i := 0; i < totalGames; i++ {
		isRandomBotTurn := (rand.Int()%2 == 0)
		if isRandomBotTurn {
			randomBot.startGame("X")
			userBot.startGame("O")
		} else {
			randomBot.startGame("O")
			userBot.startGame("X")
		}

		board := NewBoard()
		for {
			if ok, winner := board.isGameOver(); ok {
				userBot.endGame(winner)
				randomBot.endGame(winner)
				if i >= trainGames {
					if winner != "-" && winner != userBot.getMarker() {
						winsCount++
					}
				}

				break
			}

			if isRandomBotTurn {
				if !board.set(randomBot.step(board)) {
					panic("Сell is not empty")
				}
			} else {
				if !board.set(userBot.step(board)) {
					panic("Сell is not empty")
				}
			}
			// ТЕСТ ВЫВОДА //
			for y := 0; y < 3; y++ {
				for x := 0; x < 3; x++ {
					if board[y][x] == " " {
						fmt.Print("_")
					} else {
						fmt.Print(board[y][x])
					}
				}
				fmt.Println()
			}
			fmt.Println()
			/////////////////
			isRandomBotTurn = !isRandomBotTurn
		}
		fmt.Println(userBot.getMarker(), i, winsCount) ///////////////
	}

	if winsCount >= int(0.8*float64(battleGames)) {
		fmt.Println("YES")
	} else {
		fmt.Println("NO")
	}
}
*/