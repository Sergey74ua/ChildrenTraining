using System.Drawing;

namespace Aquarium
{
    class FishBlue : AFish, IFish
    {
        /// <summary>
        /// Новая рыбка
        /// </summary>
        public FishBlue()
        {
            bitmap = Properties.Resources.FishBlue;
            speed = 1.5f;
        }

        //Отрисовка рыбки
        public void DrawFish(Graphics g)
        {
            g.DrawImage(bitmap, position);
        }
    }
}