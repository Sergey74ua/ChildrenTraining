﻿using System;
using Обучение2;

namespace Обучение
{
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

        void вывод_на_консоль()
        {
            переменные.логика();
        }
    }
}