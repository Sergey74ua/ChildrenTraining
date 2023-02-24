/*
1. Создать класс Butterfly  у которого есть поля: 
Строка “стадия жизни”(гусеница, куколка или бабочка);
Число “дни жизни”;

В нашей задаче следующие условия для перехода на следующую стадию жизни объекта :
гусеница = от 0 до 7 дней
куколка = от 8 до 15 дней
бабочка = от 16 до 23 дней
Если бабочка прожила 24 дня она становится гусеницей 0 дней.

Необходимо создать метод в классе, который добавляет единицу к текущему дню этой бабочки и переводит её на следующую стадию жизни если условия соблюдены.

Например если была гусеница, которая живет уже 7 дней, то эта функция превратит её в куколку, которая живет 8 дней.
Или если была куколка, которая живет 13 дней, эта функция изменит только её дни жизни.

Задача: Создать вектор указателей на объекты класса Butterfly.Добавить 10 указателей на объекты и с помощью цикла вызвать этот метод для каждого объекта.
Вывести на экран исходный и получившийся вектор
*/

#include <iostream>
#include <vector>

using namespace std;

class Butterfly
{
public:
    Butterfly()
    {
        this->life_days = 0;
        this->life_stage = stage[this->life_days];
    }

    //Добавляем день жизни, переопределяем стадию
    void nextDay()
    {
        this->life_days++;
        this->life_stage = stage[(this->life_days % 24) / 8];
    }

    //Выводим значения
    void getInfo()
    {
        cout << "Day: " << this->life_days << ", stage: " << this->life_stage << endl;
    }

private:
    int life_days;
    string life_stage;

    string stage[3] =
    {
        "caterpillar",
        "chrysalis",
        "butterfly"
    };
};


int main()
{
    vector<Butterfly> colony = {};

    //Выводим исходный (пустой) вектор
    for (auto i : colony)
        i.getInfo();
    cout << "- vector size: " << colony.size() << endl << endl;

    //Заполняем вектор объектами
    srand(time(NULL));
    int days = 0;
    for (int i = 0; i < 10; i++)
    {
        Butterfly butterfly = Butterfly();

        //Добавляем каждому объекту дни жизни, случайно, с нарастанием
        days += rand() % 3 + i;
        for (int i = 0; i < days; i++)
            butterfly.nextDay();
        
        colony.push_back(butterfly);
    }

    //Выводим заполненный вектор
    for (auto i : colony)
        i.getInfo();
    cout << "- vector size: " << colony.size() << endl;

    return 0;
}