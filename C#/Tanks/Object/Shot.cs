using System.Drawing;

namespace Tanks
{
    class Shot : AObject
    {
        public uint timeShot; //перезарядка

        private Pen pen;
        private PointF _position;

        //Конструктор
        public Shot()
        {
            speed = 16.0f;
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