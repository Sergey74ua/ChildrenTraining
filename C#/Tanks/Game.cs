using System.Drawing;

namespace Tanks
{
    class Game
    {
        private Party PartyRed, PartyBlue;
        private Shot shot = new Shot(); //************************ В Р Е М Е Н Н О ************************

        public void StartGame()
        {
            PartyRed = new Party();
            PartyBlue = new Party();
            PartyRed.CreateListUnits(PartyRed.count, Color.DarkRed);
            PartyBlue.CreateListUnits(PartyBlue.count, Color.DarkBlue);
        }

        public void StepGame(Graphics g, Point cursor)
        {
            PartyRed.DrawListUnits(g, cursor);
            PartyBlue.DrawListUnits(g, cursor);
            
            shot.DrawShot(g, Color.DarkOrange); //**************** В Р Е М Е Н Н О ****************
        }
    }
}
