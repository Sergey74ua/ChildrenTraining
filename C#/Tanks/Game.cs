using System.Drawing;

namespace Tanks
{
    sealed class Game
    {
        private byte count = 5; //число машин

        private Party PartyRed, PartyBlue;
        private Shots AllShots;
        private Bangs AllBangs;
        private Craters AllCraters;

        //Комманды и снаряды
        public void StartGame()
        {
            Sound.StarWars();

            PartyRed = new Party();
            PartyBlue = new Party();

            AllShots = new Shots();
            AllBangs = new Bangs();
            AllCraters = new Craters();

            //Стартовые позиции
            PartyRed.CreateListUnits(Color.DarkRed, new Point (20, 50), count);
            PartyBlue.CreateListUnits(Color.DarkBlue, new Point(80, 50), count);
        }

        //Шаг(кадр) игры
        public void StepGame(Graphics g, Point cursor)
        {

            AllCraters.DrawListCraters(g);

            PartyRed.DrawListUnits(g, AllShots, cursor); //******** переделать параметры ********
            PartyBlue.DrawListUnits(g, AllShots, cursor);

            AllShots.DrawListShot(g);

            AllBangs.DrawListBangs(g);

            AllShots.Damage(PartyRed); //******** убрать отсюда как-то ********
            AllShots.Damage(PartyBlue);
        }
    }
}