using System;
using System.Drawing;

namespace Tanks
{
    sealed class Tank : AUnits
    {
        //Изображение танка
        private Bitmap bitmap = new Bitmap(Properties.Resources.tank4);
        private Rectangle body = new Rectangle(new Point(0, 0), new Size(128, 128));
        private Rectangle tower = new Rectangle(new Point(128, 0), new Size(128, 128));
        private Rectangle bodyShadow = new Rectangle(new Point(0, 128), new Size(128, 128));
        private Rectangle towerShadow = new Rectangle(new Point(128, 128), new Size(128, 128));
        private SolidBrush solidBrush;
        private byte shadow = Tanks.shadow;
        private float vectorTower;

        //Отрисовка танка
        public void DrawTank(Graphics g, Color party)
        {
            vector = Vector();
            vectorTower = VectorTower();
            position = Position();
            solidBrush = new SolidBrush(party);

            //Тень корпуса
            g.TranslateTransform(position.X + shadow, position.Y + shadow);
            g.RotateTransform(vector);
            g.DrawImage(bitmap, -64, -64, bodyShadow, GraphicsUnit.Pixel);
            g.ResetTransform();

            //Цвет команды
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vector);
            g.FillRectangle(solidBrush, -26, -52, 52, 100);
            g.ResetTransform();

            //Корпус
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vector);
            g.DrawImage(bitmap, -64, -64, body, GraphicsUnit.Pixel);
            g.ResetTransform();

            //Тень башни
            g.TranslateTransform(position.X + shadow, position.Y + shadow);
            g.RotateTransform(vectorTower);
            g.DrawImage(bitmap, -64, -98, towerShadow, GraphicsUnit.Pixel);
            g.ResetTransform();

            //Башня
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vectorTower);
            g.DrawImage(bitmap, -64, -98, tower, GraphicsUnit.Pixel);
            g.ResetTransform();

            DrawInfo(g);
        }

        //Направление башни
        private float VectorTower()
        {
            vectorTower = vector; //*** ! * ! * ! ***

            return vectorTower;
        }
    }
}