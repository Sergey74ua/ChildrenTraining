//3. Создайте класс Seasons, в экземпляре которого должно быть перечисление времен года, реализованное с помощью типа enum.
//Определите метод SeasonsChange, при вызове которого будет меняться время года. Определите метод возвращающий какое время года в данный момент.
//Создать класс ReverseSeason, наследующий от класса Seasons, в котором переопределить метод SeasonsChange так, чтобы перечисление времен года,
//шло в обратном порядке. Протестируйте работу классов.

#include <iostream>
using namespace std;

class Seasons
{
public:
    enum enumSeason
    {
        winter,
        spring,
        summer,
        autumn
    };

    enumSeason currentSeason = winter;

    void SeasonsChange()
    {
        this->currentSeason = enumSeason((currentSeason + 1) % 4);
    }

    void getSeasons()
    {
        string name;
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
        cout << "Season: " << name << endl;
    }
};

class ReverseSeason : public Seasons
{
public:
    void SeasonsChange()
    {
        this->currentSeason = enumSeason((currentSeason + 3) % 4);
    }
};

int main()
{
    Seasons seasons = Seasons();
    for (int i = 0; i < 10; i++)
    {
        seasons.getSeasons();
        seasons.SeasonsChange();
    }

    cout << endl;

    ReverseSeason seasons2 = ReverseSeason();
    for (int i = 0; i < 10; i++)
    {
        seasons2.getSeasons();
        seasons2.SeasonsChange();
    }

    return 0;
}