using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Shots
    {
        public List<Shot> ListShot = new List<Shot>();

        //Отрисовываем выстрелы по списку
        public void DrawListShot(Graphics g)
        {
            for (int i = 0; i < ListShot.Count; i++)
            {
                ListShot[i].DrawShot(g);

                //Удаляем снаряды на финише
                if (Math.Abs(ListShot[i].position.X - ListShot[i].target.X) < 100 &&
                    Math.Abs(ListShot[i].position.Y - ListShot[i].target.Y) < 100)
                    ListShot.Remove(ListShot[i]);
            }
        }
    }
}