/*
 * Proect:  Библиотека методов для рассчетов в режиме 2D
 * Version: 1.0.0.1
 * Date:    20.06.2020
 * Autor:   Сергей
 * Email:   Sergey74ua@gmail.com
 */

using System;
using System.Drawing;

namespace Game2D
{
    public static class Func2D
    {
        private static float catetX, catetY;

        /// <summary>
        /// Рассчет расстояния до цели (откуда X/Y, куда X/Y)
        /// </summary>
        public static float Delta(PointF position, PointF target)
        {
            catetX = target.X - position.X;
            catetY = target.Y - position.Y;
            return (float)Math.Sqrt(catetX * catetX + catetY * catetY);
        }

        /// <summary>
        /// Рассчет расстояния до цели (откуда X/Y, куда X/Y)
        /// </summary>
        public static float Delta(Point position, Point target)
        {
            catetX = target.X - position.X;
            catetY = target.Y - position.Y;
            return (float)Math.Sqrt(catetX * catetX + catetY * catetY);
        }

        /// <summary>
        /// Рассчет угла на цель (откуда X/Y, куда X/Y)
        /// </summary>
        public static float Vector(PointF position, PointF target)
        {
            return (float)Math.Atan2(target.Y - position.Y, target.X - position.X);
        }

        /// <summary>
        /// Рассчет угла на цель (откуда X/Y, куда X/Y)
        /// </summary>
        public static float Vector(Point position, Point target)
        {
            return (float)Math.Atan2(target.Y - position.Y, target.X - position.X);
        }

        /// <summary>
        /// Рассчет координат хода (откуда X/Y, угол, скорость)
        /// </summary>
        public static PointF Position(PointF position, float vector, float speed)
        {
            position.X += (float)Math.Cos(vector) * speed;
            position.Y += (float)Math.Sin(vector) * speed;

            return position;
        }

        /// <summary>
        /// Рассчет координат хода (откуда X/Y, угол, скорость)
        /// </summary>
        public static PointF Position(Point position, float vector, float speed)
        {
            position.X += (int)(Math.Cos(vector) * speed);
            position.Y += (int)(Math.Sin(vector) * speed);

            return position;
        }
    }
}
