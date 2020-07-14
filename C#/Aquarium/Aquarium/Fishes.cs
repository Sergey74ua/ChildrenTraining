using System;
using System.Collections.Generic;
using System.Drawing;

namespace Aquarium
{
    class Fishes
    {
        public List<object> ListFish = new List<object>();

        private readonly Random random = new Random();

        /// <summary>
        /// Список рыбок
        /// </summary>
        public Fishes(byte count)
        {
            for (byte i = 0; i < count; i++)
            {
                NewUnit(new FishGold());
                NewUnit(new FishBlue());
                NewUnit(new FishRed());
            }
        }

        //Добавляем рыбку в список
        private void NewUnit(dynamic fish)
        {
            ListFish.Add(fish);
            fish.position = RandomPosition();
            fish.target = RandomPosition();
            fish.bitmap = fish.Rotate();
        }

        //Рассчет случайной позиции
        public PointF RandomPosition()
        {
            PointF point = new PointF();

            point.X = random.Next(50, 1770);
            point.Y = random.Next(50, 930);

            return point;
        }

        //Отрисовка списка рыбок
        public void DriweListFish(Graphics g)
        {
            foreach (dynamic fish in ListFish)
            {
                fish.Position();
                fish.DrawFish(g);
            }
        }
    }
}