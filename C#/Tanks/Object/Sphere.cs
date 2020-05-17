using System.Drawing;

namespace Tanks
{
    class Sphere
    {
        public PointF position;    //позиция
        public Color color;        //цвет сферы
        public byte timeAction;    //время действия

        public Sphere() //********
        {
            timeAction = 128;
        }

        //Отрисовывка взрыва
        public void DrawSphere(Graphics g)
        {
            g.TranslateTransform(position.X, position.Y);
            g.FillEllipse(new SolidBrush(color), new RectangleF(-timeAction / 2, -timeAction / 2, timeAction, timeAction));
            g.ResetTransform();
        }
    }
}