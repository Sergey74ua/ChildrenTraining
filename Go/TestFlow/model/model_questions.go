package model

type Questions struct {
	Id             int
	NumberQuestion int
	Question       int
	Correct        int
	Answer_1       string
	Answer_2       string
	Answer_3       string
	Answer_4       string
	Answer_5       string
	Answer_6       string
}

// Получаем список вопросов
func GetQuestions(id int) *[]Questions {
	db := connect()
	// ЭТО НЕ ТО !!! НАДО ЧЕРЕЗ JOIN СВЯЗУЮЩУЮ ТАБЛИЦУ
	query := `
		SELECT *
		FROM Questions
		WHERE NumberQuestion = $1
	;`
	data, _ := db.Query(query, id)
	questions := []Questions{}
	for data.Next() {
		question := Questions{}
		data.Scan(
			&question.Id,
			&question.NumberQuestion,
			&question.Question,
			&question.Correct,
			&question.Answer_1,
			&question.Answer_2,
			&question.Answer_3,
			&question.Answer_4,
			&question.Answer_5,
			&question.Answer_6,
		)
		questions = append(questions, question)
	}
	db.Close()

	return &questions
}
