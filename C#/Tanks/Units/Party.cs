using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party : List<Tank> //не понятна эксплуатация класса-контейнера (и как же машины и солдаты ???)
    {
        public byte count = 3;
        private List<Tank> PartyTank = new List<Tank>();
        private Game game = new Game();

        //Заполняем список танками
        public List<Tank> CreatePartyTank(byte count, Color party)
        {
            for (byte i = 1; i <= count; i++)
            {
                PartyTank.Add(new Tank()
                {
                    id = i,
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