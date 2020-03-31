using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party : List<Tank> //не понятна эксплуатация класса-контейнера (и как же машины и солдаты ???)
    {
        public byte count = 10;
        private List<Tank> PartyTank = new List<Tank>();
        private Game game = new Game();

        //Заполняем список танками
        public List<Tank> CreatePartyTank(byte count, Color party)
        {
            while (PartyTank.Count < count)
            {
                PartyTank.Add(new Tank()
                {
                    party = party,
                    position = game.Start(party)
                });
            }
            return PartyTank;
        }

        //Отрисовываем танки по списку
        public void DrawPartyTank(Graphics g, Point cursor)
        {
            foreach (Tank tank in PartyTank)
            {
                game.Step(tank, cursor);
                tank.DrawTank(g, tank.party);
            }
        }
    }
}