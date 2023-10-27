/* Дан файл "data.json" следующего вида:
[
   {
      "project_id": 1,
      "tasks": [
         {
            "user_id": 1,
            "id": 1,
            "title": "delectus aut autem",
            "completed": false
         },
         {
            "user_id": 5,
            "id": 2,
            "title": "quis ut nam facilis et officia qui",
            "completed": true
         }
      ]
   },
   {
      "project_id": 2,
      "tasks": []
   }
]
Файл содержит массив объектов описывающих задачи в некоторых проектах. Каждый объект состоит из полей:
	project_id - целочисленный идентификатор проекта [1...2⋅10^9];
	tasks - массив задач;
	Каждая задача представляет из себя объект содержащий поля:
		user_id - целочисленный идентификатор пользователя которому поручена задача [1...2⋅10^9]. Во всех проектах,
			для одного и того же пользователя используется один и тот же идентификатор;
		id - целочисленный идентификатор задачи в проекте [1...2⋅10^9];
		title - строка состоящая из латинских символов - описание задачи;
		completed - булев флаг состояния задачи. true - завершена, false - не завершена;

Напишите программу, которая определит для указанного id пользователя, количество задач которое он завершил.
Внимание: для решения задачи нужно использовать стандартный пакет encoding/json.

Формат ввода
На вход подаётся одно целое число - идентификатор пользователя.
В папке с программой будет файл "data.json".
Формат вывода
Одно целое число.

Пример 1
Ввод	Вывод
1		34
Пример 2
Ввод	Вывод
2	25
*/

package main

import (
	"encoding/json"
	"fmt"
	"io"
	"log"
	"os"
)

// Структура задачи
type Task struct {
	User_id   int
	Id        int
	Title     string
	Completed bool
}

// Структура проекта с задачами
type Project struct {
	Project_id int
	Tasks      []Task
}

func main() {
	var (
		n        int       // Номер исполнителя
		s        int       // Число выполненных задач
		projects []Project // Список проектов
	)

	fmt.Scan(&n)
	s = 0

	// Открывем файл json
	file, err := os.Open("data.json")
	if err != nil {
		log.Fatal(err)
	}
	defer file.Close()

	// Сохраняем данные из файла в массив структур
	data, err := io.ReadAll(file)
	if err != nil {
		log.Fatal(err)
	}
	jsonErr := json.Unmarshal(data, &projects)
	if jsonErr != nil {
		log.Fatal(jsonErr)
	}

	// Обходим проекты, а в них задачи и считаем выполнения
	for _, project := range projects {
		for _, task := range project.Tasks {
			if task.User_id == n && task.Completed {
				s++
			}
		}
	}

	// Количество выполненных задач исполнителем
	fmt.Println(s)
}
