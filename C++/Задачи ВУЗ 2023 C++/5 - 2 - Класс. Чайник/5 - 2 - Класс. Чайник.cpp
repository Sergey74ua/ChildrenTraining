/* Дана начальная температура воды и количество подогреваний чайника. Каждое подогревание увеличивает температуру воды на некоторое количество градусов. Как только вода достигнет 100 градусов чайник должен закипеть. Подогревания, которые не понадобились вывести на экран:
#include <iostream>
#include <deque>

// Ваш код будет вставлен сюда

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for(auto& t : heat) std::cin >> t;
    
    Water water(temperature);
    Teapot teapot(water);
    
    while(not teapot.is_boiling()){
        teapot.heat_up(heat.front());
        heat.pop_front();
    }
    
    for(auto t : heat) std::cout << t << ' ';
}
Этот код будет прогоняться по тестам. Ваша задача реализовать классы Water и Teapot таким образом, чтобы этот код стал рабочим.
метод is_boiling возвращает true, если чайник закипел;
метод heat_up принимает количество градусов на которое нужно увеличить температуру воды.
Формат ввода
В первой строке входных данных указаны 2 целых числа через пробел. Первое temp - начальная температура воды. Второе n - количество подогреваний.
На следующей строке перечислены n целых чисел - температуры на величину которых будет подогрета вода 0≤ni≤10^9.
Формат вывода
Последовательность целых чисел разделённых пробелами.

Пример 1
Ввод	Вывод
50 5
10 50 10 11 12
10 11 12
Пример 2
Ввод	Вывод
100 4
0 10 20 35
0 10 20 35
Примечания
Реализация классов может быть любая. Главное, чтобы код заработал.
*/

#include <iostream>
#include <deque>

class Water {
public:
    int temperature;
    Water() {
        this->temperature = 0;
    }

    Water(int temperature) {
        this->temperature = temperature;
    }
};

class Teapot {
public:
    Water water;

    Teapot(Water water) {
        this->water = water;
    }

    bool is_boiling() {
        return this->water.temperature >= 100;
    }

    void heat_up(int t) {
        this->water.temperature += t;
    }
};

int main()
{
    int temperature, count;
    std::cin >> temperature >> count;
    std::deque<int> heat(count);
    for (auto& t : heat) std::cin >> t;

    Water water(temperature);
    Teapot teapot(water);

    while (not teapot.is_boiling()) {
        teapot.heat_up(heat.front());
        heat.pop_front();
    }

    for (auto t : heat) std::cout << t << ' ';
}
