using System.Drawing;

namespace Tanks
{
    sealed class Game
    {
        private byte count = 3; //число машин

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
        }

        //Шаг(кадр) игры
        public void StepGame(Graphics g, Point cursor)
        {
            PartyRed.DrawListUnits(g, AllShots, cursor);
            PartyBlue.DrawListUnits(g, AllShots, cursor);

            AllShots.DrawListShot(g);
        }
    }
}