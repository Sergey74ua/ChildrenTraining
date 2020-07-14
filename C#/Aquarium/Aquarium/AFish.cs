using System;
using System.Drawing;

namespace Aquarium
{
    abstract class AFish
    {
        public Bitmap bitmap, bitmap2;
        public PointF position;
        public PointF target;
        public float speed;

        private readonly Random random = new Random();
        private float deltaX, deltaY, vector;

        //Рассчет случайной позиции
        public PointF RandomPosition()
        {
            PointF point = new PointF();

            point.X = random.Next(50, 1770);
            point.Y = random.Next(50, 930);

            return point;
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
                target = RandomPosition();
                bitmap = Rotate();
            }

            return position;
        }

        public Bitmap Rotate()
        {
            if (position.X > target.X)
                bitmap.RotateFlip(RotateFlipType.Rotate180FlipY);
            else
                bitmap = bitmap2;

            return bitmap;
        }
    }
}