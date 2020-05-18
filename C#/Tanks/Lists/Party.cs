using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        public List<object> ListUnits = new List<object>();
        private readonly int width = Tanks.Window.Width;
        private readonly int height = Tanks.Window.Height;
        private readonly Random random = new Random();

        /// <summary>
        /// Команда: цвет флага, стартовая позиция(X,Y) в %, число танков, число машин.
        /// </summary>
        public Party(Color party, Point start, byte tank, byte car)
        {
            for (byte i = 0; i < tank; i++)
                NewUnit(new Tank(party), start);

            for (byte i = 0; i < car; i++)
                NewUnit(new Car(party), start);
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, Shots ListShots, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                unit.timeAction++; //******** пробно ********
                if (unit.Atack) //******** пробно ********
                {
                    ListShots.NewShot(unit);
                    unit.timeAction = 0;
                    unit.Atack = false;
                }
                unit.target = cursor; //должна быть ссылка на функцию определения таргета (см. выше или у Game)

                unit.DrawUnit(g, unit.party);
            }
        }

        //Добавляем юнита в список
        private void NewUnit(dynamic unit, Point start)
        {
            byte delta = 16;
            ListUnits.Add(unit);
            unit.position = Start(start);
            unit.vector = Vector(unit.position) + random.Next(-delta, delta);
            unit.vectorTower = unit.vector + random.Next(-delta, delta);
        }

        //Начальная случайная позиция
        private PointF Start(Point point)
        {
            ushort delta = 128;
            point.X = width * point.X / 100 + random.Next(-delta, delta);
            point.Y = height * point.Y / 100 + random.Next(-delta, delta);

            return point;
        }

        //Начальный угол на центр (можно заменить на 90°/270°)
        private float Vector(PointF position)
        {
            float vector = (float)(Math.Atan2(height/2 - position.Y,
                width/2 - position.X)*180/Math.PI+90);
            if (vector < 0) vector += 360;

            return vector;
        }
    }
}