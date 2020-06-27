using System;
using System.Drawing;

namespace Tanks
{
    abstract class AObject
    {
        public Color color;     //команда
        public PointF position; //позиция
        public PointF target;   //цель
        public float vector;    //вектор
        public float speed;     //скорость
        public float delta;     //дальность
        public uint timeAction; //******** перезарядка (проба) ********

        //Рассчет координат при перемещении
        public PointF Position()
        {
            position.X += speed * (float)Math.Cos(vector);
            position.Y += speed * (float)Math.Sin(vector);

            return position;
        }

        //Рассчет угла на цель
        public float Vector()
        {
            float vector = (float)Math.Atan2(target.Y - position.Y, target.X - position.X);

            return vector;
        }
    }
}