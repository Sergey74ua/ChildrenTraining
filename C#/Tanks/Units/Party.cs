using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    sealed class Party
    {
        public byte count = 5;

        private List<object> ListUnits = new List<object>();
        private Actions action = new Actions();
        private readonly Random random = new Random();

        //Заполняем список юнитами
        public List<object> CreateListUnits(byte count, Color party)
        {
            PointF position;    //случайная позиция
            float vector;       //поворот на центр

            for (byte i = 0; i < count; i++)
            {
                position = Start(party);
                vector = Vector(position);
                ListUnits.Add(new Tank
                {
                    party = party,
                    position = position,
                    vectorBody = vector,
                    vectorTower = vector,
                    speed = 0.5f,
                    life = 40
                });

                position = Start(party);
                vector = Vector(position);
                ListUnits.Add(new Car
                {
                    party = party,
                    position = position,
                    vectorBody = vector,
                    vectorTower = vector,
                    speed = 1.0f,
                    life = 10
                });
            }
            
            return ListUnits;
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                unit.target = cursor; //должна быть ссылка на функцию определения таргета
                action.SwitchAct(unit); //******** Д О Д Е Л А Т Ь ********
                unit.DrawUnit(g, unit.party);
            }
        }

        //Насальная случайная позиция
        private PointF Start(Color party)
        {
            PointF point = PointF.Empty;
            if (party == Color.DarkBlue)
                point.X = random.Next(50, 440);
            if (party == Color.DarkRed)
                point.X = random.Next(840, 1230);
            point.Y = random.Next(50, 670);

            return point;
        }

        //Начальный угол на центр
        private float Vector(PointF position)
        {
            float vector = (float)(Math.Atan2(360 - position.Y, 640 - position.X) * 180 / Math.PI + 90);
            if (vector < 0) vector += 360;

            return vector;
        }
    }
}