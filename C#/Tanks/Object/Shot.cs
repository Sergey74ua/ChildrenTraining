using System;
using System.Drawing;

namespace Tanks
{
    class Shot : AObject
    {
        public byte timeShot;       //перезарядка

        private PointF _position;   //хвост снаряда
        private Color color;        //цвет снаряда
        private Pen pen;            //перо для снаряда (для пулеметов можно сделать другой)

        /// <summary>
        /// Выстрел: рассчитывается из объекта.
        /// </summary>
        public Shot(dynamic unit)
        {
            party = ColorShot(unit.party);
            position = unit.position;
            target = unit.target;
            vector = (float)Math.Atan2(target.Y - position.Y, target.X - position.X);
            speed = 16.0f;
        }

        //Цвет выстрела
        private Color ColorShot(Color party)
        {
            color = Color.FromArgb
            (
                party.R + (255 - party.R) / 4,
                party.G + (255 - party.G) / 8,
                party.B + (255 - party.B) / 4
            );

            return color;
        }


        //Отрисовка полета снаряда
        public void DrawShot(Graphics g)
        {
            _position = position;
            position = Position();
            speed *= 0.98f; //затухание скорости
            pen = new Pen(party, 3);

            g.DrawLine(pen, position, _position);
        }
    }
}