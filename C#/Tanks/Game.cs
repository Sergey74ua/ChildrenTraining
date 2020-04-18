using System.Drawing;

namespace Tanks
{
    class Game
    {
        private Party PartyRed, PartyBlue;
        private Shots ListShot;

        public void StartGame()
        {
            PartyRed = new Party();
            PartyBlue = new Party();
            ListShot = new Shots();

            PartyRed.CreateListUnits(PartyRed.count, Color.DarkRed);
            PartyBlue.CreateListUnits(PartyBlue.count, Color.DarkBlue);
            //******** отсюда надо как-то вызвать функцию создания выстрелов ... ********
            ListShot.NewShot(new PointF(10, 10), new PointF(1000, 600), Color.DarkOrange); //******** В Р Е М Е Н Н О ********
            ListShot.NewShot(new PointF(20, 600), new PointF(1100, 30), Color.LimeGreen); //******** В Р Е М Е Н Н О ********
        }

        public void StepGame(Graphics g, Point cursor)
        {
            PartyRed.DrawListUnits(g, cursor);
            PartyBlue.DrawListUnits(g, cursor);
            ListShot.DrawListShot(g);
        }
    }
}