using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        public List<object> ListUnits = new List<object>();
        private Random random = new Random();

        //Заполняем список юнитами
        public List<object> CreateListUnits(Color party, byte count, Size Window)
        {
            PointF position;    //случайная позиция
            float vector;       //поворот на центр

            for (byte i = 0; i < count; i++)
            {
                position = Start(party, Window);
                vector = Vector(position, Window);
                ListUnits.Add(new Tank
                {
                    party = party,
                    position = position,
                    vector = vector,
                    vectorTower = vector+5,
                    speed = 0.5f,
                    life = 40
                });

                position = Start(party, Window);
                vector = Vector(position, Window);
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
        private PointF Start(Color party, Size Window)
        {
            PointF point = PointF.Empty;
            if (party == Color.DarkBlue)
                point.X = random.Next(50, Window.Width/2-200);
            if (party == Color.DarkRed)
                point.X = random.Next(Window.Width/2+200, Window.Width-50);
            point.Y = random.Next(50, Window.Height-50);

            return point;
        }

        //Начальный угол на центр (можно заменить на 90°/270°)
        private float Vector(PointF position, Size Window)
        {
            float vector = (float)(Math.Atan2(Window.Height/2 - position.Y, Window.Width/2 - position.X)*180/Math.PI+90);
            if (vector < 0) vector += 360;

            return vector;
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, Shots AllShots, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                if (unit.timeShot <= 0)
                {
                    AllShots.NewShot(unit.position, unit.target, unit.party); //******** пробно ********
                    unit.timeShot = 120; //******** пробно ********
                }
                unit.timeShot--;
                unit.target = cursor; //должна быть ссылка на функцию определения таргета
                unit.DrawUnit(g, unit.party);
            }
        }
    }
}