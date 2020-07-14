using System.Drawing;

namespace Aquarium
{
    class FishGold : AFish, IFish
    {
        /// <summary>
        /// Новая рыбка
        /// </summary>
        public FishGold()
        {
            bitmap = bitmap2 = Properties.Resources.FishGold;
            bitmap = Rotate();
            speed = 1.0f;
        }

        //Отрисовка рыбки
        public void DrawFish(Graphics g)
        {
            g.DrawImage(bitmap, position);
        }
    }
}