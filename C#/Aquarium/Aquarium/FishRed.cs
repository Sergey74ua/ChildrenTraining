using System.Drawing;

namespace Aquarium
{
    class FishRed : AFish, IFish
    {
        /// <summary>
        /// Новая рыбка
        /// </summary>
        public FishRed()
        {
            bitmap = Properties.Resources.horse;
            speed = 0.5f;
        }

        //Отрисовка рыбки
        public void DrawFish(Graphics g)
        {
            g.DrawImage(bitmap, position);
        }
    }
}