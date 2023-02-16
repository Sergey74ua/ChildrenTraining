//���� "����" - ��������� ���������� ���� �����, ������� ����������� �� ��������.
//�������� ������ ������� � ��������� ����� ����(�����, �������) �������� ���������� �����������.

#include <iostream>
#include <Windows.h>
using namespace std;

bool game = true;

//��� ���� �������
HWND window_header = GetConsoleWindow();

//���������� ��� ������������ ����� � �������
HANDLE descriptor = GetStdHandle(STD_INPUT_HANDLE); // �������� ����������
INPUT_RECORD InputRecord; // ������������ ��� ����������� ���������� � ������� ���������� � ���������� ������� ������
DWORD Events; // unsigned long
DWORD prev_mode; //������ ��������� �������
COORD coord; // ��� ��������� X, Y

const unsigned int map_y = 10, map_x = 10;
int map[map_y][map_x] = {};

void init()
{
    //setlocale(LC_ALL, "RUS");
    system("title ����.");
    system("color 0a");
    system("mode con cols=40 lines=24");

    //����������� ��������� ���������� ��� ������ ������
    GetConsoleMode(descriptor, &prev_mode);
    SetConsoleMode(GetStdHandle(STD_INPUT_HANDLE), ENABLE_EXTENDED_FLAGS | (prev_mode & ~ENABLE_QUICK_EDIT_MODE));
    SetConsoleMode(descriptor, ENABLE_MOUSE_INPUT); // ��������� ��������� ����

    //��������� �������� �������
    srand(time(NULL));
    for (int y = 0; y < map_y; y++)
        for (int x = 0; x < map_x; x++)
            if (rand() % 5 == 0)
                map[y][x] = 9;
            else
                map[y][x] = 0;

    //������� ����� � �������� �������
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
    while (true) //������
    {
        ReadConsoleInput(descriptor, &InputRecord, 1, &Events); // ���������� 

        if (InputRecord.Event.MouseEvent.dwButtonState == MOUSE_WHEELED) // ������ ��������
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            cout << "Kolesiko nazhato - X" << coord.X << ", Y = " << coord.Y << endl;
        }
        else if (InputRecord.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) // ������ ������
        {
            coord.X = InputRecord.Event.MouseEvent.dwMousePosition.X;
            coord.Y = InputRecord.Event.MouseEvent.dwMousePosition.Y;
            cout << "right - X" << coord.X << ", Y = " << coord.Y << endl;
        }
        else if (InputRecord.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) // ����� ������
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