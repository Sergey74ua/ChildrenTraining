using System;
using System.Drawing;

namespace Tanks
{
    class Shot : AObject
    {
        private Pen pen;
        private PointF position0;
        protected float angle, catetX, catetY;

        public void DrawShot(Graphics g, Color color)
        {
            position = Position();
            position0.X = position.X + 16;
            position0.Y = position.Y + 10;
            target = new Point(1000, 600);
            pen = new Pen(color, 3);

            g.TranslateTransform(position.X, position.Y);
            g.DrawLine(pen, position0, position);
            g.ResetTransform();
        }

        //Полет снаряда
        public PointF Position()
        {
            speed = 8;

            //Определяем угол на цель
            catetX = target.X - position.X;
            catetY = target.Y - position.Y;
            angle = (float)(Math.Atan2(catetY, catetX) * 180 / Math.PI + 90);
            if (angle < 0) angle += 360;

            position.X += speed * (float)Math.Cos(angle);
            position.Y += speed * (float)Math.Sin(angle);

            return position;
        }
    }
}
