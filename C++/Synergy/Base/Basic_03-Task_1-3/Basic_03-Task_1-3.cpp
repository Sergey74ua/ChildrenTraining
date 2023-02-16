/*
В предыдущем домашнем задании вы реализовали класс Seasons и метод Seasons.Change, который сменяет времена года.От него унаследовали класс
ReverseSeasons и переопределили метод Seasons.Change так, чтобы он сменял сезоны в обратном порядке.
Теперь перепишите ваш код таким образом, чтобы он исключал переопределение.В вашей программе будут :
1.	Базовый класс SeasonsBase с виртуальным деструктором и чисто виртуальным методом Change().
2.	От класса SeasonsBase наследуйте класс Seasons, в котором определите реализацию метода Change().Пометьте данный метод как override
3.	От класса SeasonsBase наследуйте класс ReverseSeasons, в котором определите реализацию метода Change().Пометьте данный метод как override
*/

//не использовать using namespace std
//enum пишем с заглавной буквы
//не называть name_, setName или this->name


#include <iostream>


class SeasonsBase
{
public:
    virtual ~SeasonsBase() {
        std::cout << "SeasonsBase destructor" << std::endl << std::endl;
    }

    virtual void change() = 0;

    void getSeasons()
    {
        std::string name;
        switch (this->currentSeason)
        {
        case 0:
            name = "winter";
            break;
        case 1:
            name = "spring";
            break;
        case 2:
            name = "summer";
            break;
        case 3:
            name = "autumn";
            break;
        default:
            name = "winter";
        }
        std::cout << "Season: " << name << std::endl;
    }

protected:
    enum ListSeason
    {
        winter,
        spring,
        summer,
        autumn
    };

    ListSeason currentSeason = winter;
};


class Seasons : public SeasonsBase
{
public:
    ~Seasons() override
    {
        std::cout << "Seasons destructor" << std::endl;
    }

    void change() override
    {
        this->currentSeason = ListSeason((currentSeason + 1) % 4);
    }
};


class ReverseSeason : public SeasonsBase
{
public:
    void change() override
    {
        this->currentSeason = ListSeason((currentSeason + 3) % 4);
    }
};


int main()
{
    Seasons seasons = Seasons();
    for (int i = 0; i < 4; i++)
    {
        seasons.getSeasons();
        seasons.change();
    }
    std::cout << std::endl;

    ReverseSeason seasons2 = ReverseSeason();
    for (int i = 0; i < 4; i++)
    {
        seasons2.getSeasons();
        seasons2.change();
    }
    std::cout << std::endl;

    return 0;
}