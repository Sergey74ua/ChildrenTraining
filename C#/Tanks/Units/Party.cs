using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        public byte count = 20;
        private List<Tank> PartyTank = new List<Tank>();
        private Random random = new Random();

        //Заполняем список танками
        public List<Tank> CreatePartyTank(byte count, Color party)
        {
            while (PartyTank.Count < count)
            {
                PartyTank.Add(new Tank()
                {
                    party = party,
                    position = PointRandom(party),
                    target = new Point(640, 720)
                });
            }
            return PartyTank;
        }

        //Отрисовываем танки по списку
        public void DrawPartyTank(Graphics g)
        {
            foreach (Tank tank in PartyTank)
            {                    
                tank.DrawTank(g, tank.party);
            }
        }

        //Случайная позиция
        private Point PointRandom(Color party)
        {
            Point point = Point.Empty;
            if (party == Color.DarkBlue)
                point.X = random.Next(50, 320);
            if (party == Color.DarkRed)
                point.X = random.Next(960, 1230);
            point.Y = random.Next(50, 670);
            return point;
        }
    }
}