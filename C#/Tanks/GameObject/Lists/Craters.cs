using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Craters
    {
        public List<PointF> listCraters = new List<PointF>();

        public PointF position; //позиция
        private byte timeCraters; //таймер взрыва

        //Добавляем воронку в список
        public void NewCrater()
        {
            //********
        }

        //Удаляем воронку из списка
        public void RemoveCrater()
        {
            //********
        }

        public void DrawListCraters(Graphics g)
        {
            //Отрисовка взрыва
            if (timeCraters < 96)
            {
                timeCraters += 8;
                g.TranslateTransform(position.X, position.Y);
                g.FillEllipse(new SolidBrush(Color.FromArgb(192 - timeCraters, timeCraters + 128, timeCraters, 0)),
                    new RectangleF(-timeCraters / 2, -timeCraters / 2, timeCraters, timeCraters));
                g.ResetTransform();
            }
        }
    }
}