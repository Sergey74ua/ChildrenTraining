/* Реализуйте классы Box и Cat следующим образом:
У класса Box должен быть метод open не принимающий параметров и возвращающий экземпляр класса Cat.
У класса Cat должен быть метод is_alive не принимающий параметров и возвращающий true или false в зависимости от того, в каком состоянии находится кот.
Состояние кота, которого уже достали из коробки меняться не должно, но пока кота из коробки не достали, есть вероятность вытащить кота в любом состоянии.
Классы будут проверяться на выполнение условий перечисленных выше.
Пример возможного использования класса:
Box box;
Cat cat = box.open();
if (cat.is_alive()) std::cout << "alive";
else std::cout << "dead";
Формат ввода
Нет
Формат вывода
Нет
Примечания
В качестве источника случайности можно использовать обычный rand
*/

#include <iostream>

class Cat {
public:
    bool live; // жизнь или смерть кота
    bool show; // закрыт или открыт кот

    // Конструктор
    Cat() {
        this->live = rand() % 2;
        this->show = false;
    }

    // Демонстрируем состояние кота
    bool is_alive() {
        if (this->show)
            this->live;
        else
            this->live = rand() % 2;
        return this->live;
    };
};

class Box {
public:
    // Открываем коробку
    Cat open() {
        Cat cat;
        cat.show = true;
        return cat;
    };
};

int main() {
    Box box;
    Cat cat = box.open();

    if (cat.is_alive())
        std::cout << "alive";
    else
        std::cout << "dead";

    return 0;
}