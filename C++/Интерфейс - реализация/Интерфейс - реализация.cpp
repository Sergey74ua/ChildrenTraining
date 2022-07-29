#include <iostream>
using namespace std;

class IUnit
{
public:
    void virtual update() = 0;
    void virtual drive() = 0;
};

class Tank : public IUnit
{
public:
    void update() override
    {
        cout << "Танк обновился" << endl;
    };
    void drive() override
    {
        cout << "Танк отрисовался" << endl;
    };
};

int main()
{
    setlocale(LC_ALL, "Russian");
 
    Tank tank;
    tank.update();
    tank.drive();

    system("pause>nul");
    return 0;
}