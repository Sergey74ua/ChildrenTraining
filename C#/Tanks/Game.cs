using System.Drawing;

namespace Tanks
{
    sealed class Game
    {
        private byte count = 3;

        private Party PartyRed, PartyBlue;
        private Shots AllShots;

        public void StartGame(Size Window) // *** преобразовать размеры в позицию
        {
            //Комманды и снаряды
            PartyRed = new Party();
            PartyBlue = new Party();
            AllShots = new Shots();

            PartyRed.CreateListUnits(Color.DarkRed, count, Window);
            PartyBlue.CreateListUnits(Color.DarkBlue, count, Window);

            //AllShots.NewShot(new PointF(0, 0), new PointF(1280, 720), Color.DarkOrange); //******** пробно ********
        }

        public void StepGame(Graphics g, Point cursor)
        {
            PartyRed.DrawListUnits(g, AllShots, cursor);
            PartyBlue.DrawListUnits(g, AllShots, cursor);

            AllShots.DrawListShot(g);
        }
    }
}