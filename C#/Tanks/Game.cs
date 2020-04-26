using System.Drawing;

namespace Tanks
{
    sealed class Game
    {
        private byte count = 3;

        private Party PartyRed, PartyBlue;
        private Shots AllShots;

        public void StartGame() //******** преобразовать размеры в позицию ********
        {
            //Комманды и снаряды
            PartyRed = new Party();
            PartyBlue = new Party();
            AllShots = new Shots();

            PartyRed.CreateListUnits(Color.DarkRed, count);
            PartyBlue.CreateListUnits(Color.DarkBlue, count);
        }

        public void StepGame(Graphics g, Point cursor)
        {
            PartyRed.DrawListUnits(g, AllShots, cursor);
            PartyBlue.DrawListUnits(g, AllShots, cursor);

            AllShots.DrawListShot(g);
        }
    }
}