using System.Drawing;

namespace Tanks
{
    class Shot : AObject
    {
        private Pen pen;

        //Отрисовка полета снаряда
        public void DrawShot(Graphics g) //зафиксировать старт и цель надо
        {
            PointF _position = position;
            position = Position();
            speed *= 0.98f; //затухание скорости
            pen = new Pen(party, 3);

            g.DrawLine(pen, position, _position);
        }
    }
}