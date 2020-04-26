using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Shots
    {
        public List<Shot> ListShot = new List<Shot>();

        //Добавляем выстрел + залп
        public void NewShot(PointF position, PointF target, Color party) //********
        {
            float vector = (float)Math.Atan2(target.Y - position.Y, target.X - position.X);
            ListShot.Add(new Shot
            {
                party = party,
                position = position,
                target = target,
                vector = vector,
                speed = 16.0f
            });
        }

        //Отрисовываем выстрелы по списку
        public void DrawListShot(Graphics g)
        {
            for (int i = 0; i < ListShot.Count; i++)
            {
                ListShot[i].DrawShot(g);

                //Удаляем снаряды на финише
                if (ListShot[i].speed < 1 ||
                    (Math.Abs(ListShot[i].position.X - ListShot[i].target.X) < ListShot[i].speed &&
                    Math.Abs(ListShot[i].position.Y - ListShot[i].target.Y) < ListShot[i].speed))
                {
                    //передаем координаты в функцию взрыва
                    ListShot.Remove(ListShot[i]);
                }
            }
        }
    }
}