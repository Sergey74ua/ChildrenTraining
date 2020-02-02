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
    }
}