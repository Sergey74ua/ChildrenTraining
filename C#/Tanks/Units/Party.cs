using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        public byte count = 5;

        private List<object> ListUnits = new List<object>();
        private Actions action = new Actions();
        private Random random = new Random();

        //Заполняем список юнитами
        public List<object> CreateListUnits(byte count, Color party)
        {
            for (byte i = 0; i < count; i++)
            {
                ListUnits.Add(new Tank
                {
                    id = i + 1,
                    party = party,
                    position = Start(party),
                    speed = 0.5f,
                    life = 40
                });

                ListUnits.Add(new Car
                {
                    id = i + 11,
                    party = party,
                    position = Start(party),
                    speed = 1.0f,
                    life = 10
                });
            }
            
            return ListUnits;
        }

        //Случайная позиция
        private Point Start(Color party)
        {
            Point point = Point.Empty;
            if (party == Color.DarkBlue)
                point.X = random.Next(50, 590);
            if (party == Color.DarkRed)
                point.X = random.Next(690, 1230);
            point.Y = random.Next(50, 670);

            return point;
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                unit.target = cursor; //должна быть ссылка на функцию определения таргета
                unit.action = action.ChoiseActions(unit);
                unit.DrawUnit(g, unit.party);
            }
        }
    }
}