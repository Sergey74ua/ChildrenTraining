using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        public List<object> ListUnits = new List<object>();
        private readonly int height = Tanks.Window.Height;
        private readonly int width = Tanks.Window.Width;
        private readonly Random random = new Random();
        private ushort range; //разброс на старте

        /// <summary> Команда : цвет флага, стартовая позиция(X,Y) в %, число танков, число машин. </summary>
        public Party(Color color, Point start, byte tank, byte car)
        {
            for (byte i = 0; i < tank; i++)
                NewUnit(new Tank(color), start);

            for (byte i = 0; i < car; i++)
                NewUnit(new Car(color), start);
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g)
        {
            foreach (dynamic unit in ListUnits)
                unit.DrawUnit(g, unit.color);
        }

        //Добавляем юнита в список
        private void NewUnit(dynamic unit, Point start)
        {
            ListUnits.Add(unit);
            unit.target = new Point(width / 2, height / 2);
            unit.position = Start(start);
            unit.vector = (float)(unit.Vector() * 180 / Math.PI + 90) + random.Next(-16, 16);
            if (unit.vector < 0)
                unit.vector += 360;
            unit.vectorTower = unit.vector + random.Next(-16, 16);
        }

        //Начальная случайная позиция
        private PointF Start(Point point)
        {
            range = 128;
            point.X = width * point.X / 100 + random.Next(-range, range);
            point.Y = height * point.Y / 100 + random.Next(-range, range);

            return point;
        }
    }
}