using System.Drawing;

namespace Tanks
{
    class Bang
    {
        public PointF position; //позиция
        private byte timeBang;  //таймер взрыва

        //Отрисовывка взрыва
        public void DrawBang(Graphics g)
        {
            g.TranslateTransform(position.X, position.Y);
            g.FillEllipse(new SolidBrush(Color.FromArgb(192 - timeBang, timeBang + 128, timeBang, 0)),
                new RectangleF(-timeBang / 2, -timeBang / 2, timeBang, timeBang));
            g.ResetTransform();
        }
    }
}
