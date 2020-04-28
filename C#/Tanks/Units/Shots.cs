using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading.Tasks;

namespace Tanks
{
    class Shots
    {
        public List<Shot> ListShot = new List<Shot>();
        private byte bang; //взрыв

        //Добавляем выстрел
        public void NewShot(dynamic unit)
        {
            ListShot.Add(new Shot
            {
                party = unit.party,
                position = unit.position,
                target = unit.target,
                vector = (float)Math.Atan2
                    (unit.target.Y - unit.position.Y,
                    unit.target.X - unit.position.X),
                speed = 16.0f
            });
        }

        //Удаляем выстрел
        async public void RemoveShot(Shot shot, Graphics g)
        {
            if (shot.speed < 1 || 
                (Math.Abs(shot.position.X - shot.target.X) < shot.speed &&
                 Math.Abs(shot.position.Y - shot.target.Y) < shot.speed))
            {

                //Отрисовка взрыва
                if (bang < 96)
                {
                    shot.speed = 0;
                    bang += 8;
                    g.TranslateTransform(shot.position.X, shot.position.Y);
                    g.FillEllipse(new SolidBrush(Color.FromArgb(192 - bang, bang+128, bang, 0)),
                        new RectangleF(-bang / 2, -bang / 2, bang, bang));
                    g.ResetTransform();
                }
                else
                {
                    bang = 0;
                    ListShot.Remove(shot);

                    await Task.Run(() => Console.Beep(100, 100));
                }
            }
        }

        //Отрисовываем выстрелы по списку
        public void DrawListShot(Graphics g)
        {
            for (int i = 0; i < ListShot.Count; i++)
            {
                ListShot[i].DrawShot(g);

                //Удаляем снаряды на финише
                RemoveShot(ListShot[i], g);
            }
        }
    }
}