using System;
using System.Drawing;

namespace Tanks
{
    class Shot : AObject
    {
        private Pen pen;
        private float angle, catetX, catetY;

        //Полет снаряда
        public PointF Position()
        {
            speed = 16.0f; //******** нужно затухание скорости ********

            //Определяем угол на цель
            catetX = target.X - position.X;
            catetY = target.Y - position.Y;
            angle = (float)(Math.Atan2(catetY, catetX) * 180 / Math.PI + 90);
            if (angle < 0) angle += 360;

            //Полет снаряда
            position.X += speed * (float)Math.Cos(angle);
            position.Y += speed * (float)Math.Sin(angle);

            return position;
        }

        //Отрисовка полета снаряда
        public void DrawShot(Graphics g) //зафиксировать старт и цель надо
        {
            PointF _position = position;
            position = Position();
            pen = new Pen(party, 2);

            g.DrawLine(pen, position, _position);
        }
    }
}