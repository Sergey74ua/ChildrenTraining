using System;
using System.Drawing;
using System.Threading.Tasks;

namespace Tanks
{
    sealed class Game
    {
        private byte count = 5; //число машин

        private Party PartyRed, PartyBlue;
        private Shots AllShots;

        //Комманды и снаряды
        public void StartGame()
        {
            PartyRed = new Party();
            PartyBlue = new Party();
            AllShots = new Shots();

            //Стартовые позиции
            PartyRed.CreateListUnits(Color.DarkRed, count);
            PartyBlue.CreateListUnits(Color.DarkBlue, count);

            StarWars(); //************************* В Р Е М Е Н Н О *************************
        }

        //Шаг(кадр) игры
        public void StepGame(Graphics g, Point cursor)
        {
            PartyRed.DrawListUnits(g, AllShots, cursor);
            PartyBlue.DrawListUnits(g, AllShots, cursor);

            AllShots.DrawListShot(g);
            AllShots.Damage(PartyRed);
            AllShots.Damage(PartyBlue);
        }

        //Музыкальная заставка
        async private void StarWars() //************************* В Р Е М Е Н Н О *************************
        {
            await Task.Run(() =>
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
            });
        }
    }
}