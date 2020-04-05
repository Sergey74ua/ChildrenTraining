using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party : List<Tank> //не понятна эксплуатация класса-контейнера (и как же машины и солдаты ???)
    {
        public byte count = 2;

        private List<Tank> PartyTank = new List<Tank>();
        private Random random = new Random();

        //Заполняем список танками
        public List<Tank> CreatePartyTank(byte count, Color party)
        {
            for (byte i = 1; i <= count; i++)
            {
                PartyTank.Add(new Tank()
                {
                    id = i,
                    party = party,
                    life = 100,
                    position = Start(party),
                    target = new PointF(640, 320) //******** ??? ********
                });
            }
            return PartyTank;
        }

        //Отрисовываем танки по списку
        public void DrawPartyTank(Graphics g, Point cursor)
        {
            foreach (Tank tank in PartyTank)
            {
                tank.target = cursor;
                tank.DrawTank(g, tank.party);
            }
        }

        //Случайная позиция
        public Point Start(Color party)
        {
            Point point = Point.Empty;
            if (party == Color.DarkBlue)
                point.X = random.Next(50, 540);
            if (party == Color.DarkRed)
                point.X = random.Next(740, 1230);
            point.Y = random.Next(50, 670);

            return point;
        }
    }
}