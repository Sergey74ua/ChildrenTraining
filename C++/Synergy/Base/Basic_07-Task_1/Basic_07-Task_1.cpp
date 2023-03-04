/*
Есть класс “Заклинание”, который хранит поля :
число “Сила заклинания”
число “Расходуемая энергия”(или “Мана”)

В функции main создан вектор объектов этого класса со случайно заполненными полями
1.	Перегрузить оператор сравнения так, чтобы при сравнении двух объектов меньшим считался тот, у которого расходуемая энергия меньше
2.	Создать компаратор который считает меньшим объект, у которого “сила заклинания” меньше.Если “сила заклинания” одинаковая, то
    меньшим считается объект, у которого “расходуемая энергия” больше
Необходимо отсортировать вектор двумя способами и оба вывести на экран
*/

//не использовать using namespace std; (я думал, что это только при сочетании с enum)
//variableOne, methodSayHello() - начинаем с маленькой буквы, последующие слова с большой.


#include <iostream>
#include <vector>
#include <algorithm>

class Spell
{
public:
    int power;
    int mana;

    Spell(int power, int mana)
    {
        this->power = power;
        this->mana = mana;
    }

    bool operator <  (Spell r)
    {
        return this->mana < r.mana;
    }
};

bool comp(Spell l, Spell r)
{
    return l.power < r.power || (l.power == r.power && l.mana > r.mana);
}

int main()
{
    //Заполняем список заклинаний с случайными значениями
    std::vector<Spell> spells = {};
    srand(time(NULL));
    for (int i = 0; i < 10; i++)
        spells.push_back(Spell(rand() % 20, rand() % 100));

    //Выводим несортированный список
    std::cout << "     -= ORIGINAL =-" << std::endl;
    for (auto i : spells)
        std::cout << "power: " << i.power << "\tmana: " << i.mana << std::endl;

    //Выводим список отсортированный по манне
    std::sort(spells.begin(), spells.end());
    std::cout << std::endl << "   -= SORT BY MANA =-" << std::endl;
    for (auto i : spells)
        std::cout << "power: " << i.power << "\tmana: " << i.mana << std::endl;

    //Выводим список отсортированный по силе, затем по манне с реверсом
    std::sort(spells.begin(), spells.end(), comp);
    std::cout << std::endl << "-= SORT BY POWER/MANA =-" << std::endl;
    for (auto i : spells)
        std::cout << "power: " << i.power << "\tmana: " << i.mana << std::endl;
}