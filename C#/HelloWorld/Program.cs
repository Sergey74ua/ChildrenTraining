using System;
using Message;

namespace Console1
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Hello World!");

            Message message = new Message();
            message.msg();

            Console.ReadKey();
        }
    }
}