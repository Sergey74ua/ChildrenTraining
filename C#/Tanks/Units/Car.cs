using System.Drawing;

namespace Tanks
{
    class Car : AUnits, IDrawn
    {
        //Изображение танка
        private readonly Bitmap bitmap = new Bitmap(Properties.Resources.btr);
        private readonly Rectangle body = new Rectangle(new Point(0, 0), new Size(64, 64));
        private readonly Rectangle tower = new Rectangle(new Point(64, 0), new Size(64, 64));
        private readonly Rectangle bodyShadow = new Rectangle(new Point(0, 64), new Size(64, 64));
        private readonly Rectangle towerShadow = new Rectangle(new Point(64, 64), new Size(64, 64));
        private readonly byte shadow = Tanks.shadow;
        private SolidBrush solidBrush;

        //Отрисовка танка
        public void DrawUnit(Graphics g, Color party)
        {
            solidBrush = new SolidBrush(party);

            #region ** Этапы отрисовки машины **
            //Тень корпуса
            g.TranslateTransform(position.X + shadow / 2, position.Y + shadow / 2);
            g.RotateTransform(vectorBody);
            g.DrawImage(bitmap, -32, -26, bodyShadow, GraphicsUnit.Pixel);
            g.ResetTransform();

            //Цвет команды
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vectorBody);
            g.FillRectangle(solidBrush, -12, -18, 23, 50);
            g.ResetTransform();

            //Корпус
            g.TranslateTransform(position.X, position.Y);
            g.RotateTransform(vectorBody);
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
    }
}