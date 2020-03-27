using System;
using Обучение2;

namespace Обучение
{
    struct Tank
    {
        public string name;
        public int HP;
        public void метод()
        {
            Console.WriteLine("Рррррррррррррррррррр");
            Console.WriteLine(name + " - " + HP);
        }
    }

    class Урок
    {
        //Создаем объект дополнительного класса
        Переменные переменные = new Переменные();

        public static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");
            Console.WriteLine();

            Урок урок = new Урок();
            урок.вывод_на_консоль();

            Console.ReadKey();
        }

        unsafe
        void вывод_на_консоль()
        {
            переменные.сравнение();
            переменные.циклы();
            переменные.условие();
            переменные.логика();
            переменные.перечисления();

            Tank tank;
            tank.name = "Т-34";
            tank.HP = 100;
            tank.метод();

            //Указатель
            int x = 5_000_000;
            int* указатель = &x;

            Console.Write("Адрес переменной : " + (ulong) указатель);
            Console.WriteLine(" и ее значение: " + x);
        }
    }
}