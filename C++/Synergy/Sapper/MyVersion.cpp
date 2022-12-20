//Игра "Сапёр" - Повторить реализацию игры «Сапёр», которую рассмотрели на вебинаре.
//Напротив каждой функции и значимого блока кода(циклы, условия) написать поясняющий комментарий.

#include <iostream>
#include <Windows.h>
using namespace std;

bool game = true;

//Для окна консоли
HWND window_header = GetConsoleWindow();

//Переменные для отслеживания мышки в консоле
HANDLE descriptor = GetStdHandle(STD_INPUT_HANDLE); // получаем дескриптор
INPUT_RECORD InputRecord; // используется для возвращения информации о входных сообщениях в консольном входном буфере
DWORD Events; // unsigned long
DWORD prev_mode; //Запрет выделение консоли
COORD coord; // для координат X, Y

const unsigned int map_y = 10, map_x = 10;
int map[map_y][map_x] = {};

void init()
{
    //setlocale(LC_ALL, "RUS");
    system("title Сапёр.");
    system("color 0a");
    system("mode con cols=40 lines=24");

    //Присваеваем значяения переменным для работы мышкой
    GetConsoleMode(descriptor, &prev_mode);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
    SetConsoleMode(descriptor, ENABLE_MOUSE_INPUT); // разрешаем обработку мыши

    //Заполняем рандомно бомбами
    srand(time(NULL));
    for (int y = 0; y < map_y; y++)
        for (int x = 0; x < map_x; x++)
            if (rand() % 5 == 0)
                map[y][x] = 9;
            else
                map[y][x] = 0;

    //Считаем бомбы в соседних ячейках
    for (int y = 0; y < map_y; y++)
        for (int x = 0; x < map_x; x++)
            if (map[y][x] != 9)
                map[y][x] = 9;
}

void model(bool& game)
{
    if (false)
    {
        game = false;
    }
}

void view(int map_x, int map_y)
{
    system("cls");
    for (int x = 1; x <= map_x; x++)
        printf("%2d ", x);
    cout << endl;
    for (int y = 1; y <= map_y; y++)
    {
        printf("%3d ", y);
        for (int x = 1; x <= map_x; x++)
        {
            cout << "\xB2\xB2" << " ";
        }
        cout << endl << endl;
    }
}

void control(bool game)
{
    while (true) //УБРАТЬ
    {
        ReadConsoleInput(descriptor, &InputRecord, 1, &Events); // считывание 

        if (InputRecord.Event.MouseEvent.dwButtonState == MOUSE_WHEELED) // нажато колесико
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            cout << "Kolesiko nazhato - X" << coord.X << ", Y = " << coord.Y << endl;
        }
        else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) // правая кнопка
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            cout << "right - X" << coord.X << ", Y = " << coord.Y << endl;
        }
        else if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // левая кнопка
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            cout << "left - X" << coord.X << ", Y = " << coord.Y << endl;
        }
    }
}

int _main()
{
    init();

    while (game)
    {
        model(game);
        view(map_x, map_y);
        control(game);
    }
    return 0;
}