using System;
using System.Drawing;

namespace Tanks
{
    abstract class AUnits : AObject
    {
        //Общие поля юнитов
        public int id;                  //имя
        public A action;                //действие
        public float life;              //жизнь
        protected float vector;         //вектор
        protected float vectorTower;    //вектор башни
        private float angle, catetX, catetY;  //*** П Е Р Е Д Е Л А Т Ь ***

        //Данные для отисовки
        private SolidBrush solidBrushFont = new SolidBrush(Color.LightGreen);
        private Font font = new Font("Arial", 10, FontStyle.Bold, GraphicsUnit.Point);
        private Pen pen = new Pen(Color.Green, 2);

        //Отрисовка имени и жизни
        public void DrawInfo(Graphics g)
        {
            //Наименование
            g.TranslateTransform(position.X, position.Y);
            g.DrawString("= " + id.ToString() + " =", font, solidBrushFont, -20, -42);
            g.ResetTransform();

            //Жизнь
            g.TranslateTransform(position.X, position.Y);
            g.DrawLine(pen, -32, -26, 32, -26);
            g.ResetTransform();
        }

        //Направление юнита
        public float Vector(float vector, float speed)
        {
            //Определяем угол на цель
            catetX = target.X - position.X;
            catetY = target.Y - position.Y;
            angle = (float)(Math.Atan2(catetY, catetX) * 180 / Math.PI + 90);
            if (angle < 0) angle += 360;

            //Текущий угол поворота к цели
            if (Math.Abs(vector - angle) > speed)
            {
                if ((vector < angle && (angle - vector) < 180) ^ (angle - vector) > -180)
                    vector = (vector - speed + 360) % 360;
                else
                    vector = (vector + speed) % 360;
            }
            else
            {
                vector = angle;
            }

            return vector;
        }

        //Перемещение юнита
        public PointF Position(float speed)
        {
            double gipotenuza = Math.Sqrt(catetX * catetX + catetY * catetY);
            if (gipotenuza > 128 && vector == angle)
            {
                position.X += speed * (float)Math.Cos(vector);
                position.Y += speed * (float)Math.Sin(vector);
            }
            
            return position;
        }
    }
}