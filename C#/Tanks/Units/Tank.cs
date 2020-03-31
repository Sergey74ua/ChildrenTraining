using System;
using System.Drawing;

namespace Tanks
{
    sealed class Tank : AUnits
    {
        public Color party;

        //Изображение танка
        private Bitmap bitmap = new Bitmap(Properties.Resources.tank4);
        private Rectangle body = new Rectangle(new Point(0, 0), new Size(128, 128));
        private Rectangle tower = new Rectangle(new Point(128, 0), new Size(128, 128));
        private Rectangle bodyShadow = new Rectangle(new Point(0, 128), new Size(128, 128));
        private Rectangle towerShadow = new Rectangle(new Point(128, 128), new Size(128, 128));
        private SolidBrush solidBrush;

        private float vectorTower;
        private byte shadow = 8; //******** УБРАТЬ КУДА-ТО В ГЛОБАЛЬНЫЕ ПОЛЯ ********
        
        private Random random = new Random();

        //МАССИВ БЫ   DrawImage(Image image, Point point);

        //Отрисовка танка
        public void DrawTank(Graphics g, Color party)
        {
            vector = Vector();
            vectorTower = VectorTower();
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

            g.SmoothingMode = System.Drawing.Drawing2D.SmoothingMode.AntiAlias; // *** У Д А Л И Т Ь ***
            g.DrawEllipse(new Pen(Color.Red, 3), target.X-10, target.Y-10, 20, 20); // *** У Д А Л И Т Ь ***
        }

        //Направление танка
        private float Vector()
        {
            //vector = (float)Math.Atan2((target.Y - position.Y), (target.X - position.X)) * 180 / (float)Math.PI + 90;
            vector += vectorTower / random.Next(90, 360);
            return vector;
        }

        //Направление башни
        private float VectorTower()
        {
            vectorTower = (float)Math.Atan2((target.Y - position.Y), (target.X - position.X)) * 180 / (float)Math.PI + 90;
            return vectorTower;
        }
    }
}