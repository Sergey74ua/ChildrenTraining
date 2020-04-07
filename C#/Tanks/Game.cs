using System.Drawing;

namespace Tanks
{
    class Game
    {
        private Party PartyRed, PartyBlue;
        Shot shot = new Shot(); //************************ В Р Е М Е Н Н О ************************

        public void StartGame()
        {
            PartyRed = new Party();
            PartyBlue = new Party();
            PartyRed.CreatePartyTank(PartyRed.count, Color.DarkRed);
            PartyBlue.CreatePartyTank(PartyBlue.count, Color.DarkBlue);
        }

        public void StepGame(Graphics g, Point cursor)
        {
            PartyRed.DrawPartyTank(g, cursor);
            PartyBlue.DrawPartyTank(g, cursor);

            shot.DrawShot(g, Color.DarkOrange); //**************** В Р Е М Е Н Н О ****************
        }
    }
}
