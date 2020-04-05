using System;
using System.Drawing;

namespace Tanks
{
    abstract class AUnits
    {
        //Общие поля юнитов
        public int id;          //имя
        public Color party;     //команда
        public PointF position; //позиция
        public PointF target;   //цель
        public float vector;    //вектор
        public float life;      //жизнь

        //Данные для отисовки
        private SolidBrush solidBrushFont = new SolidBrush(Color.LightGreen);
        private Font font = new Font("Arial", 10, FontStyle.Bold, GraphicsUnit.Point);
        private Pen pen = new Pen(Color.Green, 2);
        private float catetX, catetY;
        private float speed;

        //Отрисовка имени и жизни
        public void DrawInfo(Graphics g)
        {
            //Наименование
            g.TranslateTransform(position.X, position.Y);
            g.DrawString("- = " + id.ToString() + " = -", font, solidBrushFont, -18, -42);
            g.ResetTransform();

            //Жизнь
            g.TranslateTransform(position.X, position.Y);
            g.DrawLine(pen, -32, -26, 32, -26);
            g.ResetTransform();
        }

        //Направление юнита
        public float Vector() //******** сделать универсально для всех частей ********
        {
            speed = life / 100;
            float angle;

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
                vector = angle;

            return vector;
        }

        //Перемещение юнита
        public PointF Position()
        {
            speed = life / 200;
            double gipotenuza = Math.Sqrt(catetX * catetX + catetY * catetY);
            if (gipotenuza > 128)
            {
                position.X += speed * (float)Math.Cos(vector);
                position.Y += speed * (float)Math.Sin(vector);
            }
            return position;
        }
    }
}