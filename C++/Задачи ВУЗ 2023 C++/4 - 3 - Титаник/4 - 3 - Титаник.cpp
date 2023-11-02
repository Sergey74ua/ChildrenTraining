/* В каталоге с программой лежит файл "train.csv" описывающий таблицу с данными о пассажирах Титаника. Сам файл можно посмотреть в каталоге
"data" в этом репозитории под именем "train.csv".
На вход программе подаётся два числа: pclass и age. Выведите на экран имена (полностью поле Name) пассажиров в соответствии с требованиями:
Пассажиры женского пола возрастом больше age и классом равным pclass;
Вывод должен быть отсортирован по возрастанию возраста. В случае, если возраст одинаковый, то в лексикографическом порядке поля Name.
Обратите внимание:
Некоторые данные могут отсутствовать (пустая ячейка), тогда для чисел устанавливайте значение 0, а для строк - пустую строку;
В качестве разделителя ячеек используется символ ,, но этот же символ встречается в поле Name;
В поле Name могут встречаться например такие значения: "Nakid, Miss. Maria (""Mary"")", что должно быть считано как: Nakid, Miss. Maria ("Mary");
Т.е. если данные заключены в двойные кавычки, то двойные кавычки, появляющиеся внутри, должны быть экранированы путем добавления перед ними ещё
одного символа двойной кавычки.
Например: hello => "hello", но File "The Matrix" => "File ""The Matrix""";
Конец строки символ '\r', а не '\n'. Для чтения данных пригодится функция getline.
Количество записей в файле не задано числом, поэтому можно читать пока файл не кончится:
while (not file.eof()) {
    // Читаем и обрабатываем строку 
}
Формат ввода
В папке с программой лежит файл "train.csv".
На вход программе подаётся два числа через пробел: pclass (1, 2 или 3) и age - положительное вещественное число.

Формат вывода
Поле Name полностью. Для каждого пассажира на новой строке.

Пример 1
Ввод	Вывод
1 60
Stone, Mrs. George Nelson (Martha Evelyn)
Andrews, Miss. Kornelia Theodosia
Пример 2
Ввод	Вывод
2 50
Hocking, Mrs. Elizabeth (Eliza Needs)
Hewlett, Mrs. (Mary D Kingcome)
Mack, Mrs. (Mary)
*/

#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

struct Passager {
    std::string name;
    int age;
};

int main()
{
    int pclass, age;                //класс и возраст
    std::string line, word, n;   //строка, слово, имя
    std::vector<std::string> t;     //массив слов из строки
    std::vector<Passager> v;        //список (имя, возраст)
    Passager p;                     //временный пассажир

    std::cin >> pclass >> age;
    std::ifstream file("train.csv");

    while (not file.eof()) {
        std::getline(file, line, '\r');

        //Считываем строку, в пустоты вставляем "0"
        std::istringstream s(line);
        while (std::getline(s, word, ',')) {
            if (word.size()==0)
                word = "0";
            t.push_back(word);
        }

        //Проверяем данные и вносим в массив имя и возраст
        if (t[5] == "female" && std::stoi(t[6]) > age && std::stoi(t[2]) == pclass) {
            t[3].erase(t[3].begin()); //удаляем кавычку в начале
            t[4].pop_back(); //удаляем кавычку в конце
            n = t[3] + ',' + t[4]; //склеиваем имя, восстанавливаем ","
            //n.replace(n.begin(), n.end(), "\"\"", "\""); //// нужно убрать двойные кавычки
            p = {n, std::stoi(t[6])};
            v.push_back(p);
        }
        t.clear();
    }
    file.close();

    //Сортировка с условиями (вручную)
    for (int i = 0; i < v.size(); i++)
        for (int j = i+1; j < v.size(); j++) {
            if (v[i].age > v[j].age || (v[i].age == v[j].age && v[i].name > v[j].name)) {
                p = v[i];
                v[i] = v[j];
                v[j] = p;
            }
        }

    //Вывод списка
    for (auto& i : v) {
        std::cout << i.name << std::endl;
    }
}