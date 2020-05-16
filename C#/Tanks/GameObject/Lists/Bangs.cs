using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Bangs
    {
        public List<Sphere> ListBang = new List<Sphere>();

        //Добавляем взрыв в список
        public void NewBang(Shot shot)
        {
            ListBang.Add(new Sphere()
            {
                position = shot.position,
                color = shot.party,
                timeAction = 0
            });
        }

        //Удаляем взрыв из списка
        public void RemoveBang()
        {
            //********
        }

        //Отрисовывка списка взрывов
        public void DrawListBangs(Graphics g)
        {
            foreach (Sphere bang in ListBang)
            {
                bang.DrawSphere(g);
            }
        }
    }
}