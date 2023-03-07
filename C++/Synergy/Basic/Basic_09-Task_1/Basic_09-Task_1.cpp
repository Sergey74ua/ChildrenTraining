/*
Мастер волшебных палочек Олливандер решил открыть еще один магазин, но в маглловской (не волшебной) части Лондона.

Пожилому волшебнику требуется ваша помощь с расчетом чистой прибыли за продажи палочек, при этом важно учесть все расходы:
1.	Аренда помещения
2.	Оплата материалов для изготовления палочек (древесина + сердцевина)
3.	Зарплата для сотрудника
4.	Услуги мракоборцев (авроров - волшебная полиция) - установка магглоотталкивающих щитов, защиты здания

Задачи
Задачи:
1.	Создать класс филиал (NewBranch).
a.	Класс является наследником класса BrunchFinances
b.	Класс содержит приватную строковую переменную (для хранения имени филиала)
c.	Класс содержит конструктор, который принимает строковую переменную, и деструктор
2.	Класс прибыль (BranchFinances)
a.	Класс содержит константные переменные, необходимые для расчёта
b.	Класс содержит конструктор по умолчанию и деструктор
c.	Метод класса. Расчёт стоимости аренды помещения. Формула расчёта: арендная плата в месяц =  ставка + ((прибыль - сумма,
    сверхкоторой нужно платить процент) × процент). Если прибыль меньше установленной суммы, то арендная плата равна ставке.
d.	Метод класса. Расчёт всех расходов. Формула: Р = Зп + Аренда + услуги мракоборцев.
e.	Метод класса. Вывод всех расходов в консоль.
f.	Метод класса. Подбор выручки с помощью ГПСЧ.
g.	Метод класса. Расчёт чистой прибыли. Формула: чистая прибыль = выручка - расходы.
3.	Функция main()
a.	Создать объект класса NewBranch
b.	Вывести чистую прибыль.
Условия
Условия для задачи:
1.	Для аренды:
a.	Арендная ставка составляет 50 галлеонов в месяц;
b.	Процент, который Олливандер должен платить в дополнение к арендной ставке, составляет 7% от выручки;
c.	Сумма выручки, сверх которой Олливандеру нужно платить процент, составляет 270 галлеонов в месяц;
2.	Для чистой прибыли:
a.	Выручка магазина волшебных палочек составляет от 250 до 500 галлеонов в месяц;
b.	Зарплата сотруднику составляет 35 галлеонов в месяц;
c.	Расходы на услуги мракоборцев составляет 15 галлеонов в месяц;
*/

#include <iostream>
#include <string>
#include <iomanip>
#define $ std::cout << "\n" << std::string(32, '=') << "\n\n";


class BrunchFinances
{
private:
    const double tariff     =   50.00;  //ставка
    const double percent    =   7.0;    //проценты
    const double limit      =   270.00; //лимит
    const double salary     =   35.00;  //зарплата
    const double security   =   15.00;  //услуги

    double rent             =   0.0;    //аренда
    double sales            =   0.0;    //доход
    double costs            =   0.0;    //расход
    double profit           =   0.0;    //прибыль

public:
    BrunchFinances()
    {
        sales = (rand() % 25001) / 100.0 + 250.0;
        rent = tariff + std::max(0.0, (sales - limit) * percent / 100.0);
        costs = rent + salary + security;
        profit = sales - costs;
    }

    ~BrunchFinances()
    {
        std::cout << "Ollivander company - closed.\n";
    }

    //Доход
    void getSales()
    {
        std::cout << " Sales:\t\t" << sales << " galleons\n"; $
    }

    //Расход
    void getCosts()
    {
        std::cout << " Rent:\t\t" << rent << " galleons\n";
        std::cout << " Salary:\t" << salary << " galleons\n";
        std::cout << " Security:\t" << security << " galleons\n";
        std::cout << " " << std::string(30, '-') << "\n";
        std::cout << " Costs:\t\t" << costs << " galleons\n"; $
    }

    //Прибыль
    void getProfit()
    {
        std::cout << " Profit:\t" << profit << " galleons\n"; $
    }
};


class NewBranch : public BrunchFinances
{
public:
    NewBranch(std::string name) : BrunchFinances()
    {
        this->name = name;
        std::cout << "\n     -=#  Shop: " << this->name << "  #=-\n"; $
    }

    ~NewBranch()
    {
        std::cout << this->name << " - closed.\n";
    }

private:
    std::string name = "Ollivander shop";   //название филиала
};


int main()
{
    std::string name;
    std::cout << "Enter shop name: ";
    std::getline(std::cin, name);

    std::cout << std::fixed << std::setprecision(2);
    srand(time(NULL));
    system("cls");

    NewBranch branch(name);
    branch.getSales();
    branch.getCosts();
    branch.getProfit();

    return 0;
}