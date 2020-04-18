using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Shots
    {
        private List<Shot> ListShot = new List<Shot>();

        //Добавляем выстрел
        public void NewShot(PointF position, PointF target, Color party)
        {
            ListShot.Add(new Shot
            {
                party = party,
                position = position,
                target = target
            });
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