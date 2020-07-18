using System;
using System.Drawing;

namespace Aquarium
{
    abstract class AFish
    {
        public Bitmap bitmap;
        public PointF position;
        public PointF target;
        public float speed;

        private readonly Random random = new Random();
        private float deltaX, deltaY, vector;

        //Рассчет случайной позиции
        public PointF Target()
        {
            target.X = random.Next(50, 1770);
            target.Y = random.Next(50, 930);

            return target;
        }

        //Рассчет движения
        public PointF Position()
        {
            deltaX = target.X - position.X;
            deltaY = target.Y - position.Y;

            if (Math.Abs(deltaX) > speed && Math.Abs(deltaY) > speed)
            {
                vector = (float)Math.Atan2(deltaY, deltaX);
                position.X += speed * (float)Math.Cos(vector);
                position.Y += speed * (float)Math.Sin(vector);
            }
            else
            {
                target = Target();
                bitmap = Rotate();
            }

            return position;
        }

        //Поворот рыбки в сторону движения
        public Bitmap Rotate()
        {
            bitmap.RotateFlip(RotateFlipType.RotateNoneFlipNone);
            if (position.X > target.X)
                bitmap.RotateFlip(RotateFlipType.Rotate180FlipY);

            return bitmap;
        }
    }
}