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
            fish.position = StartPosition();
            fish.target = fish.Target();
            fish.bitmap = Rotate(fish);
        }

        //Поворот рыбки в сторону движения
        public Bitmap Rotate(dynamic fish)
        {
            fish.bitmap.RotateFlip(RotateFlipType.RotateNoneFlipNone);
            if (fish.position.X > fish.target.X)
                fish.bitmap.RotateFlip(RotateFlipType.Rotate180FlipY);

            return fish.bitmap;
        }

        //Рассчет случайной позиции
        public PointF StartPosition()
        {
            PointF position = new PointF();

            position.X = random.Next(50, 1770);
            position.Y = random.Next(50, 930);

            return position;
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