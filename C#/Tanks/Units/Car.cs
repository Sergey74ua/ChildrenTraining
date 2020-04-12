using System;
using System.Drawing;

namespace Tanks
{
    class Car : AUnits
    {
        //Изображение танка
        private Bitmap bitmap = new Bitmap(Properties.Resources.btr);
        private Rectangle body = new Rectangle(new Point(0, 0), new Size(64, 64));
        private Rectangle tower = new Rectangle(new Point(64, 0), new Size(64, 64));
        private Rectangle bodyShadow = new Rectangle(new Point(0, 64), new Size(64, 64));
        private Rectangle towerShadow = new Rectangle(new Point(64, 64), new Size(64, 64));
        private SolidBrush solidBrush;
        private byte shadow = Tanks.shadow;
        private float vectorTower;

        //Отрисовка танка
        public void DrawUnit(Graphics g, Color party)
        {
            vector = Vector();
            vectorTower = VectorTower();
            position = Position();
            solidBrush = new SolidBrush(party);

            #region ** Этапы отрисовки машины **
            //Тень корпуса
            g.TranslateTransform(position.X + shadow / 2, position.Y + shadow / 2);
            g.RotateTransform(vector);
            g.DrawImage(bitmap, -32, -26, bodyShadow, GraphicsUnit.Pixel);
            g.ResetTransform();

            //Цвет команды
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vector);
            g.FillRectangle(solidBrush, -12, -18, 23, 50);
            g.ResetTransform();

            //Корпус
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vector);
            g.DrawImage(bitmap, -32, -26, body, GraphicsUnit.Pixel);
            g.ResetTransform();

            //Тень башни
            g.TranslateTransform(position.X + shadow / 3, position.Y + shadow / 3);
            g.RotateTransform(vectorTower);
            g.DrawImage(bitmap, -32, -26, towerShadow, GraphicsUnit.Pixel);
            g.ResetTransform();

            //Башня
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vectorTower);
            g.DrawImage(bitmap, -32, -26, tower, GraphicsUnit.Pixel);
            g.ResetTransform();
            #endregion

            DrawInfo(g);
        }

        //Направление башни
        private float VectorTower()
        {
            speed = life / 50;

            //Текущий угол поворота башни на цель
            if (Math.Abs(vectorTower - angle) > speed)
            {
                if ((vectorTower < angle && (angle - vectorTower) < 180) ^ (angle - vectorTower) > -180)
                    vectorTower = (vectorTower - speed + 360) % 360;
                else
                    vectorTower = (vectorTower + speed) % 360;
            }
            else
                vectorTower = angle;

            return vectorTower;
        }
    }
}
