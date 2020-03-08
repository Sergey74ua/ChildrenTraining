using System;

namespace Password
{
    class Program
    {
        static void Main(string[] args)
        {
            //Переменные
            string password, _password;

            //Пароль для входа
            password = "123456";

            //Проверка пароля
            _password = "0";
            while (password != _password)
            {
                Console.Write("Введите пароль: ");
                _password = Console.ReadLine();
                if (_password != password) Console.WriteLine("в доступе отказано\n");
            }

            //Открываем доступ
            for (byte i = 0; i < 10; i++)
            {
                Console.WriteLine(i + " ДОСТУП ОТКРЫТ");
            }
            Console.ReadKey();
        }
    }
}