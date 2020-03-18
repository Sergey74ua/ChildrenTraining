using System;
using System.Diagnostics;

namespace MyTestNew
{
    class Program
    {
        static void Main(string[] args)
        {
            Stopwatch stopwatch = new Stopwatch();
            unsafe
            {
                //int variable; //Вариант 1 - переменная вне цикла

                stopwatch.Start();
                for (int i = 0; i < 1000; i++)
                {
                    int variable; //Вариант 2 - переменная в цикле

                    int* pointer = &variable; //указатель
                    ulong address = (ulong)pointer; //адрес
                    Console.Write("Адрес переменной: {0}", address);
                    Console.WriteLine(" и ее значение: {0}", variable++);
                }
                stopwatch.Stop();
                Console.WriteLine(stopwatch.ElapsedMilliseconds);
            }
            Console.ReadLine();
        }
    }
}
