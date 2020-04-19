using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Shots
    {
        public List<Shot> ListShot = new List<Shot>();

        //Добавляем выстрел + залп
        public void NewShot(PointF position, PointF target, Color party)
        {
            // ... прописать залп
            ListShot.Add(new Shot
            {
                party = party,
                position = position,
                target = target
            });
        }

        //Удаляем выстрел + взрыв        
        public void RemoveShot(Shot shot) //******** проба ********
        {
            if (Math.Abs(shot.position.X - shot.target.X) < 100 && Math.Abs(shot.position.Y - shot.target.Y) < 100) 
                ListShot.Remove(shot);
            // ... прописать взрыв
        }

        //Отрисовываем выстрелы по списку
        public void DrawListShot(Graphics g)
        {
            foreach (dynamic shot in ListShot)
            {
                shot.DrawShot(g);
            }
        }
    }
}