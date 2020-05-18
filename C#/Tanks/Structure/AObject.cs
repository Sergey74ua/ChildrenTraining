using System;
using System.Drawing;

namespace Tanks
{
    abstract class AObject
    {
        public Color party;     //команда
        public PointF position; //позиция
        public PointF target;   //цель
        public float vector;    //вектор
        public float speed;     //скорость


        //Рассчет координат при перемещении
        public PointF Position()
        {
            position.X += speed * (float)Math.Cos(vector);
            position.Y += speed * (float)Math.Sin(vector);

            return position;
        }

        /*
        //Рассчет угла на цель
        public float Vector()
        {
            vector = (float)Math.Atan2(target.Y - position.Y, target.X - position.X);

            return vector;
        }

        
        //из нев Шот
        vector = (float) Math.Atan2
                    (unit.target.Y - unit.position.Y,
                    unit.target.X - unit.position.X),

        //из СтартГейм
        float vector = (float)(Math.Atan2(window.Height / 2 - position.Y,
        window.Width / 2 - position.X) * 180 / Math.PI + 90);
        if (vector< 0) vector += 360;

        //из АЮнитс
        float catetX = target.X - position.X;
        float catetY = target.Y - position.Y;

        gipotenuza = (float) Math.Sqrt(catetX* catetX + catetY* catetY);
        angle = (float) (Math.Atan2(catetY, catetX) * 180/Math.PI+90);
        if (angle< 0) angle += 360;
        */
    }
}