//1. Наследуются ли конструкторы при наследовании?
//Ответ: Нет. Конструкторы не наследуются. Но могут быть вызваны из базового класса.

//2. Создайте класс Game в экземпляре которого должны быть поле, которое содержит название игры и жанр. Присвойте полям модификаторы
//доступа public и private соответственно. Создайте экземпляр класса и выведите на экран значения полей из экземпляра.

#include <iostream>
using namespace std;

class Game
{
public:
    string name;

    Game(string name_ = "unknown", string genre_ = "unknown")
    {
        name = name_;
        genre = set_genre(genre_);
    }

    string set_genre(string genre_)
    {
        if (genre_ != "unknown")
            return genre_;
        else
            return "unknown";
    }

    string get_genre() {
        return genre;
    }

private:
    string genre;
};

int main()
{
    Game game = Game("Tetris", "Puzzle");

    cout << "Game name: " << game.name << endl;
    cout << "Game genre: " << game.get_genre() << endl;

    return 0;
}