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
            bitmap = bitmap2 = Properties.Resources.FishBlue;
            bitmap = Rotate();
            speed = 1.5f;
        }

        //Отрисовка рыбки
        public void DrawFish(Graphics g)
        {
            g.DrawImage(bitmap, position);
        }
    }
}