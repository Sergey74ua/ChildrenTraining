using System;

namespace Обучение2
{
    class Переменные
    {
        public void сравнение()
        {
            Console.Write("Проверка 2 > 3 : ");
            Console.WriteLine(2 > 3);
            Console.WriteLine();

            Console.Write("Проверка 2 = 3 : ");
            Console.WriteLine(2 == 3);
            Console.WriteLine();

            Console.Write("Проверка 2 < 3 : ");
            Console.WriteLine(2 < 3);
            Console.WriteLine();

            Console.Write("Проверка X = 2 == 3 : ");
            bool x = 2 == 3;
            Console.WriteLine(x);
            Console.WriteLine();
        }

        public void циклы()
        {
            int i = 2147400000;
            bool x = 2 == 3;
            do
            {
                Console.WriteLine(i++);
            }
            while (x);
        }

        public void условие()
        {
            bool x = 2 == 3;
            if (x)
            {
                Console.WriteLine("Проверка 2 == 3 : ПРАВДА");
            }
            else
            {
                Console.Write("Проверка 2 == 3 : ЛОЖЬ");
            }
        }

        public void логика()
        {
            Console.Write("Проверка ПРАВДА и ПРАВДА : ");
            Console.WriteLine(true & true);
            Console.WriteLine();

            Console.Write("Проверка ПРАВДА и ЛОЖЬ : ");
            Console.WriteLine(true & false);
            Console.WriteLine();

            Console.Write("Проверка ПРАВДА или ПРАВДА : ");
            Console.WriteLine(true | true);
            Console.WriteLine();

            Console.Write("Проверка ПРАВДА или ЛОЖЬ : ");
            Console.WriteLine(true | false);
            Console.WriteLine();

            Console.Write("Проверка ПРАВДА либо ПРАВДА : ");
            Console.WriteLine(true ^ true);
            Console.WriteLine();

            Console.Write("Проверка ПРАВДА либо ЛОЖЬ : ");
            Console.WriteLine(true ^ false);
            Console.WriteLine();

            Console.Write("Проверка ЛОЖЬ либо ПРАВДА : ");
            Console.WriteLine(false ^ true);
            Console.WriteLine();

            Console.Write("Проверка ЛОЖЬ либо ЛОЖЬ : ");
            Console.WriteLine(false ^ false);
            Console.WriteLine();
        }

        //Переменные
        public enum Неделя { Понедельник, Вторник, Среда, Четверг, Пятница, Суббота, Воскресенье }

        public void перечисления()
        {
            Console.WriteLine(3.2e4);       // 32000 в виде степени
            Console.WriteLine(1.2e-3);      // 0.0012 в виде степени
            Console.WriteLine(0b100001);    // 33 в бинарном виде
            Console.WriteLine(0xA1);        // 161 в байт-коде
            Console.WriteLine("\u0420");    // "P" в Юникоде (16 бит)
            Console.WriteLine("\x5A");      // "Z" в ASCII (16 бит)

            int x = 16;
            Console.WriteLine($"Остаток от деления 16/5 : {x % 5}\n");      // 1
            Console.WriteLine($"Побитовый сдвиг 16 >> 1 : {x >>= 1}\n");    // 8
            Console.WriteLine($"Побитовый сдвиг 8 << 2 : {x <<= 2}\n");     // 32

            Неделя день = 0;
            for (byte i = 0; i < 7; i++)
                Console.WriteLine($"День недели : {день + i}\n");

            var tuple = (1, "Сергей", 1974, день, 5);
            Console.WriteLine($"Кортеж целиком: {tuple}\n");
            Console.WriteLine($"Кортеж, 2 элемент: {tuple.Item2}\n");
            Console.WriteLine($"Кортеж, 3 элемент : {tuple.Item5}\n");

            DateTime MyDR = new DateTime(1974, 06, 05);
            Console.WriteLine($"Я родился в : {MyDR.DayOfWeek}\n");
            DateTime Today = DateTime.Now;
            var time = Today - MyDR;
            Console.WriteLine($"Мне : {time.Days} дней\n");
        }
    }
}