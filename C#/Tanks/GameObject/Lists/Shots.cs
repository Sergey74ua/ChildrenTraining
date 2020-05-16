using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading.Tasks;

namespace Tanks
{
    class Shots
    {
        public List<Shot> ListShot = new List<Shot>();
        public List<PointF> ListBang = new List<PointF>();
        private byte timeBang; //таймер взрыва
        private Color color; //цвет снаряда

        //Добавляем выстрел
        async public void NewShot(dynamic unit)
        {
            ListShot.Add(new Shot()
            {
                party = ColorShot(unit.party),
                position = unit.position,
                target = unit.target,
                vector = (float)Math.Atan2
                    (unit.target.Y - unit.position.Y,
                    unit.target.X - unit.position.X)
            });
            await Task.Run(() => Console.Beep(400, 50));
        }

        //Цвет выстрела
        private Color ColorShot(Color party)
        {
            color = Color.FromArgb
            (
                party.R + (255 - party.R) / 4,
                party.G + (255 - party.G) / 8,
                party.B + (255 - party.B) / 4
            );

            return color;
        }

        //Удаляем выстрел
        async private void RemoveShot(Shot shot, Graphics g)
        {
            if (shot.speed < 1 ||
                (Math.Abs(shot.position.X - shot.target.X) < shot.speed &&
                Math.Abs(shot.position.Y - shot.target.Y) < shot.speed))
            {
                //Отрисовка взрыва
                if (timeBang < 96)
                {
                    shot.speed = 0;
                    timeBang += 8;
                    g.TranslateTransform(shot.position.X, shot.position.Y);
                    g.FillEllipse(new SolidBrush(Color.FromArgb(192 - timeBang, timeBang + 128, timeBang, 0)),
                        new RectangleF(-timeBang / 2, -timeBang / 2, timeBang, timeBang));
                    g.ResetTransform();
                }
                else
                {
                    await Task.Run(() => Console.Beep(100, 100));
                    ListBang.Add(shot.position);
                    ListShot.Remove(shot);
                    timeBang = 0;
                }
            }
        }

        //Нанесение урона
        public void Damage(Party party)
        {
            for (int i = 0; i < ListBang.Count; i++)
            {
                foreach (dynamic unit in party.ListUnits)
                {
                    float catetX = ListBang[i].X - unit.position.X;
                    float catetY = ListBang[i].Y - unit.position.Y;
                    float gipotenuza = (float)Math.Sqrt(catetX * catetX + catetY * catetY);

                    if (gipotenuza < 50)
                    {
                        unit.life -= 10 / gipotenuza;
                        if (unit.life <= 0)
                        {
                            unit.life = 0;
                            unit.speed = 0;
                            unit.Atack = false;
                            unit.party = Color.Black;
                        }
                    }
                }
                ListBang.Remove(ListBang[i]);
            }
        }

        //Отрисовываем и удаляем выстрелы по списку
        public void DrawListShot(Graphics g)
        {
            for (int i = 0; i < ListShot.Count; i++)
            {
                ListShot[i].DrawShot(g);
                RemoveShot(ListShot[i], g); //Удаляем снаряды на финише
            }
        }
    }
}