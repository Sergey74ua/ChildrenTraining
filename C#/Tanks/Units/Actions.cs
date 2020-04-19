using System;
using System.Drawing;

namespace Tanks
{
    public enum Act : byte //********  В О Т   О Н О   Н А Д О  ?  ********
    {
        BURN,   //смерть
        WAIT,   //ожидание
        BACK,   //отъезд
        FIRE,   //выстрел
        FIND    //разветка
    }

    class Actions
    {
        private dynamic unit;
        private float angle, catetX, catetY;  //******** П Е Р Е Д Е Л А Т Ь ********
        private double gipotenuza;

        //Выбор действия
        public void SwitchAct(dynamic unit) //******** П Р Е Д В А Р И Т Е Л Ь Н О ********
        {
            this.unit = unit;
            unit.vectorBody = Vector(unit.vectorBody, unit.speed);
            unit.vectorTower = Vector(unit.vectorTower, unit.speed * 2);
            unit.position = Position(unit.position, unit.speed);
        }

        /*//Поиск цели **************************************************************************************************
        public PointF Find()
        {
            foreach (dynamic unit in ListUnits)
            {
                float catetX = unit.target.X - unit.position.X;
                float catetY = unit.target.Y - unit.position.Y;
                if (Math.Abs(unit.target.X - position.X) < 256 && Math.Abs(unit.target.Y - position.Y) < 256)
                    unit.target;
            }

            return target;
        }*/

        //Направление юнита
        private float Vector(float vector, float speed)
        {
            //Определяем угол на цель
            catetX = unit.target.X - unit.position.X;
            catetY = unit.target.Y - unit.position.Y;
            gipotenuza = Math.Sqrt(catetX * catetX + catetY * catetY);
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
        private PointF Position(PointF position, float speed)
        {
            gipotenuza = Math.Sqrt(catetX * catetX + catetY * catetY);
            if (gipotenuza > 128 && unit.vectorBody == angle) //******** вынести проверку в логику ********
            {
                position.X += speed * (float)Math.Cos(unit.vectorBody);
                position.Y += speed * (float)Math.Sin(unit.vectorBody);
            }

            return position;
        }
    }
}