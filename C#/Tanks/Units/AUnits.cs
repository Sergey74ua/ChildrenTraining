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

        //Данные для отисовки
        private SolidBrush solidBrushFont = new SolidBrush(Color.LightGreen);
        private Font font = new Font("Arial", 10, FontStyle.Bold, GraphicsUnit.Point);
        private Pen pen = new Pen(Color.Green, 2);

        //Отрисовка имени и жизни
        public void DrawInfo(Graphics g)
        {
            //Наименование
            g.TranslateTransform(position.X, position.Y);
            g.DrawString("= " + vector.ToString() + " - " + angle.ToString() + " =", font, solidBrushFont, -18, -42);
            g.ResetTransform();

            //Жизнь
            g.TranslateTransform(position.X, position.Y);
            g.DrawLine(pen, -32, -26, 32, -26);
            g.ResetTransform();
        }
        float angle;
        //Направление юнита
        public float Vector(PointF position, PointF target) //******** Д О Р А Б О Т А Т Ь ********
        {
            const byte MAX_ROTATE_SPEED = 1*0; //********
            float speed = MAX_ROTATE_SPEED *0.5f;

            float catetX = target.X - position.X;
            float catetY = target.Y - position.Y;
             angle = (float)Math.Atan2(catetY, catetX) * 180 / (float)Math.PI + 90; //********

            if (angle < 180)
                speed *= -1;
            else
                speed *= 1;

            if (Math.Round(vector * 0.2f) != Math.Round(angle * 0.2f))
                vector += speed;
            else
                vector = angle % 180;

                vector = (float)Math.Atan2(catetY, catetX) * 180 / (float)Math.PI + 90; //********

            return vector;
        }

        //Перемещение юнита
        public PointF Position()
        {
            const byte MAX_SPEED = 1;
            float speed = MAX_SPEED;

            if (position != target)
            {
                position.X += speed * (float)Math.Cos(vector);
                position.Y += speed * (float)Math.Sin(vector);
            }
            return position;
        }
    }
}