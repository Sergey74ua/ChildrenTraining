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
            bitmap = Properties.Resources.FishGold;
            speed = 1.0f;
        }

        //Отрисовка рыбки
        public void DrawFish(Graphics g)
        {
            g.DrawImage(bitmap, position);
        }
    }
}