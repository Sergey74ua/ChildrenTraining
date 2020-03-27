using System.Drawing;

namespace Tanks
{
    class Tank : AUnits
    {
        public Color party;         //команда
        private float vectorTower;   //вектор ствола

        //Изображение танка
        private Bitmap bitmap = new Bitmap(Properties.Resources.spriteTank);
        private Rectangle body = new Rectangle(new Point(0, 0), new Size(128, 128));
        private Rectangle tower = new Rectangle(new Point(128, 0), new Size(128, 128));

        //Отрисовка танка
        public void DrawTank(Graphics g, byte x)
        {
            g.TranslateTransform(position.X += 1 + x, position.Y += 1 + x/2);
            g.RotateTransform(vector += 0.2f);
            g.FillRectangle(new SolidBrush(party), -26, -52, 52, 100);
            g.DrawImage(bitmap, -64, -64, body, GraphicsUnit.Pixel);
            g.RotateTransform(vectorTower -= 0.5f+x);
            g.DrawImage(bitmap, -64, -98, tower, GraphicsUnit.Pixel);
            g.ResetTransform();
        }
    }
}