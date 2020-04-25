using System;
using System.Drawing;

namespace Tanks
{
    abstract class AUnits : AObject
    {
        private static uint ID;

        //Общие поля юнитов
        public uint id = ++ID;          //имя
        public float life;              //жизнь
        public float vectorTower;       //вектор башни
        public uint timeShot;          //******** перезарядка (проба)
        private float angle, catetX, catetY;  //******** П Е Р Е Д Е Л А Т Ь ********
        private double gipotenuza;

        //Данные для отисовки
        private readonly SolidBrush solidBrushFont = new SolidBrush(Color.LightGreen);
        private readonly Font font = new Font("Arial", 10, FontStyle.Bold, GraphicsUnit.Point);
        private readonly Pen pen = new Pen(Color.Green, 2);

        //Отрисовка имени и жизни
        protected void DrawInfo(Graphics g)
        {
            //Наименование и полоса жизни
            g.TranslateTransform(position.X, position.Y);
            g.DrawString("= " + id.ToString() + " =", font, solidBrushFont, -20, -42);
            g.DrawLine(pen, -32, -26, 32, -26);
            g.ResetTransform();
        }

        //Направление юнита
        public float Vector(float vector, float speed)
        {
            //Определяем угол на цель
            catetX = target.X - position.X;
            catetY = target.Y - position.Y;
            gipotenuza = Math.Sqrt(catetX * catetX + catetY * catetY);
            angle = (float)(Math.Atan2(catetY, catetX)*180/Math.PI+90);
            if (angle < 0) angle += 360;

            //Текущий угол поворота к цели
            if (Math.Abs(vector - angle) > speed)
            {
                if ((vector < angle && (angle - vector) < 180) ^ (angle - vector) > -180)
                    vector = (vector - speed+360)%360;
                else
                    vector = (vector + speed)%360;
            }
            else
                vector = angle;

            return vector;
        }

        //Перемещение юнита
        public PointF Position(PointF position, float speed)
        {
            gipotenuza = Math.Sqrt(catetX*catetX + catetY*catetY);
            if (gipotenuza > 128 && vector == angle) //******** вынести проверку в логику ********
            {
                position.X += speed*(float)Math.Cos(vector);
                position.Y += speed*(float)Math.Sin(vector);
            }

            return position;
        }
    }
}