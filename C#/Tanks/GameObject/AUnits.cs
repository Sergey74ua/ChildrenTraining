﻿using System;
using System.Drawing;

namespace Tanks
{
    abstract class AUnits : AObject
    {
        private static uint ID;

        //Общие поля юнитов
        public uint id = ++ID;      //имя
        public float life;          //жизнь
        public float vectorTower;   //вектор башни
        public uint timeShot;       //******** перезарядка (проба)
        public bool Atack;          //********
        //public bool Select;         //Выбор

        private float angle, gipotenuza;

        //Данные для отисовки
        private readonly SolidBrush solidBrushFont = new SolidBrush(Color.LightGreen);
        private readonly Font font = new Font("Arial", 10, FontStyle.Bold, GraphicsUnit.Point);
        private readonly Pen penGrren = new Pen(Color.Green, 2);
        private readonly Pen penRed = new Pen(Color.Red, 2);
        public float lifeLine, line = 64.0f; //********

        //Отрисовка имени и жизни
        protected void DrawInfo(Graphics g)
        {
            //Наименование и полоса жизни
            g.TranslateTransform(position.X, position.Y);
            g.DrawString("= " + id.ToString() + " =", font, solidBrushFont, -20, -42);
            g.DrawLine(penGrren, -line/2, -26, lifeLine, -26);
            g.DrawLine(penRed, lifeLine, -26, line/2, -26);
            g.ResetTransform();
        }

        //Направление юнита
        public float Vector(float vector, float speed)
        {
            float catetX = target.X - position.X;
            float catetY = target.Y - position.Y;

            //Расстояние и угол к цели
            gipotenuza = (float)Math.Sqrt(catetX*catetX + catetY*catetY);
            angle = (float)(Math.Atan2(catetY, catetX) * 180/Math.PI+90);
            if (angle < 0) angle += 360;

            //Текущий угол поворота к цели
            if (Math.Abs(vector - angle) > speed)
            {
                if ((vector < angle && (angle - vector) < 180) ^ (angle - vector) > -180)
                    vector = (vector - speed+360) % 360;
                else
                    vector = (vector + speed) % 360;
            }
            else
                vector = angle;

            return vector;
        }

        //Перемещение юнита
        public PointF Position(PointF position, float speed)
        {
            if (gipotenuza > 128 && vector == angle)
            {
                position = Position();
                if (gipotenuza < 512 && timeShot >= 180)
                    Atack = true;
            }

            return position;
        }
    }
}