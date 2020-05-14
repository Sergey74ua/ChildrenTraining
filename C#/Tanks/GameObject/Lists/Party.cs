using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        private readonly Size window = Tanks.Window;
        private Random random = new Random();

        public List<object> ListUnits = new List<object>();

        //Заполняем список юнитами
        public List<object> CreateListUnits(Color party, Point point, byte count)
        {
            PointF position; //случайная позиция
            float vector; //поворот на центр

            for (byte i = 0; i < count; i++)
            {
                position = Start(point);
                vector = Vector(position);
                ListUnits.Add(new Tank
                {
                    party = party,
                    position = position,
                    vector = vector,
                    vectorTower = vector+5,
                    speed = 0.5f,
                    life = 40
                });

                position = Start(point);
                vector = Vector(position);
                ListUnits.Add(new Car
                {
                    party = party,
                    position = position,
                    vector = vector,
                    vectorTower = vector-5,
                    speed = 1.0f,
                    life = 10
                });
            }
            
            return ListUnits;
        }

        //Начальная случайная позиция
        private PointF Start(Point point)
        {
            point.X = window.Width * point.X / 100 + random.Next(-300, 300);
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

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, Shots AllShots, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                //Поиск цели ******** НЕ РАБОТАЕТ ПОКА ЧТО И НЕ ТУТ ЕМУ МЕСТО ********
                /*foreach (dynamic targetUnit in ListUnits)
                {
                    if (unit.party != targetUnit.party &&
                        Math.Abs(unit.position.X - targetUnit.position.X) < 1024 &&
                        Math.Abs(unit.position.Y - targetUnit.position.Y) < 1024)
                    {
                        unit.Atack = true;
                        unit.target = targetUnit.position;
                    }
                    else
                    {
                        unit.Atack = false;
                        unit.target = new Point(window.Width / 2, window.Height / 2);
                    }
                }*/

                unit.timeShot++; //******** пробно ********
                if (unit.Atack) //******** пробно ********
                {
                    AllShots.NewShot(unit);
                    unit.timeShot = 0;
                    unit.Atack = false;
                }
                unit.target = cursor; //должна быть ссылка на функцию определения таргета

                unit.DrawUnit(g, unit.party);
            }
        }
    }
}