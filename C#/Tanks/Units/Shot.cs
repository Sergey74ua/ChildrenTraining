using System;
using System.Drawing;

namespace Tanks
{
    class Shot : AObject
    {
        private Pen pen;

        //Полет снаряда
        public PointF Position(float vector)
        {
            position.X += speed*(float)Math.Cos(vector);
            position.Y += speed*(float)Math.Sin(vector);
            speed *= 0.98f; //затухание скорости

            return position;
        }

        //Отрисовка полета снаряда
        public void DrawShot(Graphics g) //зафиксировать старт и цель надо
        {
            PointF _position = position;
            position = Position(vector);
            pen = new Pen(party, 3);

            g.DrawLine(pen, position, _position);
        }
    }
}