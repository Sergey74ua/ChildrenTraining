using System;
using System.Threading;

namespace Audio
{
    class Program
    {
        static void Main(string[] args)
        {
            //StarWars();
            //SW();
            //G();
            for (int i = 100; i < 500; i += 10)
            {
                Console.Beep(i, 100);
            }
        }

        private static void test()
        {
            for (int i = 37; i < 200; i++)
            {
                Console.WriteLine(i);
                Console.Beep(i, 256);
            }
        }

        private static void StarWars()
        {
            Console.Beep(440, 500);
            Console.Beep(440, 500);
            Console.Beep(440, 500);
            Console.Beep(349, 350);
            Console.Beep(523, 150);
            Console.Beep(440, 500);
            Console.Beep(349, 350);
            Console.Beep(523, 150);
            Console.Beep(440, 1000);
            Console.Beep(659, 500);
            Console.Beep(659, 500);
            Console.Beep(659, 500);
            Console.Beep(698, 350);
            Console.Beep(523, 150);
            Console.Beep(415, 500);
            Console.Beep(349, 350);
            Console.Beep(523, 150);
            Console.Beep(440, 1000);
        }

        static void SW()
        {
            Console.Beep(300, 500);
            Thread.Sleep(50);
            Console.Beep(300, 500);
            Thread.Sleep(50);
            Console.Beep(300, 500);
            Thread.Sleep(50);
            Console.Beep(250, 500);
            Thread.Sleep(50);
            Console.Beep(350, 250);
            Console.Beep(300, 500);
            Thread.Sleep(50);
            Console.Beep(250, 500);
            Thread.Sleep(50);
            Console.Beep(350, 250);
            Console.Beep(300, 500);
            Thread.Sleep(50);
        }

        static void G()
        {
            Console.Beep(440, 200);
            Console.Beep(440, 200);
            Console.Beep(494, 200);
            Console.Beep(494, 200);
            Console.Beep(350, 200);
            Console.Beep(350, 200);
            Console.Beep(440, 800);

            Console.Beep(440, 200);
            Console.Beep(440, 200);
            Console.Beep(494, 200);
            Console.Beep(494, 200);
            Console.Beep(350, 200);
            Console.Beep(350, 200);
            Console.Beep(440, 800);

            /*  1   261,63
                2   293,67
                3   329,63
                4   349,23
                5   392,00
                6   440,00
                7   493,88 */
        }
    }
}