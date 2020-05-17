using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        public List<object> ListUnits = new List<object>();
        private readonly Size window = Tanks.Window;
        private readonly Random random = new Random();

        /// <summary>
        /// Команда: цвет флага, стартовая позиция(X,Y) в %, число танков, число машин.
        /// </summary>
        public Party(Color party, Point start, byte tank, byte car)
        {
            for (byte i = 0; i < tank; i++)
                NewUnit(party, start, new Tank());

            for (byte i = 0; i < car; i++)
                NewUnit(party, start, new Car());
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, Shots ListShots, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                unit.timeShot++; //******** пробно ********
                if (unit.Atack) //******** пробно ********
                {
                    ListShots.NewShot(unit);
                    unit.timeShot = 0;
                    unit.Atack = false;
                }
                //unit.target = cursor; //должна быть ссылка на функцию определения таргета (см. выше или у Game)

                unit.DrawUnit(g, unit.party);
            }
        }

        //Добавляем юнита в список
        private void NewUnit(Color party, Point start, dynamic unit)
        {
            ListUnits.Add(unit);
            unit.party = party;
            unit.position = Start(start);
            unit.vector = Vector(unit.position);
            unit.vectorTower = unit.vector - 5;
        }

        //Начальная случайная позиция
        private PointF Start(Point point)
        {
            point.X = window.Width * point.X / 100 + random.Next(-300, 200);
            point.Y = window.Height * point.Y / 100 + random.Next(-300, 300);

            return point;
        }

        //Начальный угол на центр (можно заменить на 90°/270°)
        private float Vector(PointF position)
        {
            float vector = (float)(Math.Atan2(window.Height/2 - position.Y,
                window.Width/2 - position.X)*180/Math.PI+90);
            if (vector < 0) vector += 360;

            return vector;
        }
    }
}