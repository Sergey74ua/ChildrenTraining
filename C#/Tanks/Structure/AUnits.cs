using System;
using System.Drawing;

namespace Tanks
{
    abstract class AUnits : AObject
    {
        private static uint ID;

        //Общие поля юнитов
        public uint id = ++ID;      //имя
        public Act act;             //действие
        public float life, lifeLine;//жизнь
        public float vectorTower;   //вектор башни
        public object targetID;     //******** атакуемая цель (проба) ********

        //Данные для отисовки
        private readonly SolidBrush solidBrushFont = new SolidBrush(Color.LightGreen);
        private readonly Font font = new Font("Arial", 10, FontStyle.Bold, GraphicsUnit.Point);
        private readonly Pen penGrn = new Pen(Color.Green, 2);
        private readonly Pen penRed = new Pen(Color.Red, 2);
        private float angle, line = 64.0f;

        //Отрисовка имени и жизни
        protected void DrawInfo(Graphics g)
        {
            //Наименование и полоса жизни
            g.TranslateTransform(position.X, position.Y);
            g.DrawString("= " + id.ToString() + " =", font, solidBrushFont, -20, -42);
            g.DrawLine(penGrn, -line / 2, -26, lifeLine, -26);
            g.DrawLine(penRed, lifeLine, -26, line / 2, -26);
            g.ResetTransform();
        }

        //Движения юнита к цели
        public void Move()
        {
            vector = Angle(vector, speed);
            vectorTower = Angle(vectorTower, speed * 2);

            if (vector == angle)
                position = Position();
        }

        //Направление юнита
        public float Angle(float vector, float speed)
        {
            //Расстояние и угол к цели
            delta = Delta(target);
            angle = (float)(Vector() * 180 / Math.PI + 90);
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

        //Уничтожение юнита
        public void RemoveUnit(dynamic unit)
        {
            unit.life = 0.0f;
            unit.speed = 0.0f;
            unit.color = Color.Black;
        }
    }
}