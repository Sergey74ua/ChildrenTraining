using System;
using System.Drawing;

namespace Tanks
{
    class Game
    {
        private Random random = new Random();

        //Случайная позиция
        public Point Start(Color party)
        {
            Point point = Point.Empty;
            if (party == Color.DarkBlue)
                point.X = random.Next(50, 540);
            if (party == Color.DarkRed)
                point.X = random.Next(740, 1230);
            point.Y = random.Next(50, 670);

            return point;
        }

        //Перемещение танков
        public Tank Step(Tank tank, Point cursor)
        {
            tank.target.X = cursor.X;
            tank.target.Y = cursor.Y;

            return tank;
        }
    }
}