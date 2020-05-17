using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Craters
    {
        public List<Sphere> ListCraters = new List<Sphere>();

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

        //Отрисовывка списка воронок
        public void DrawListCraters(Graphics g)
        {
            foreach (Sphere crater in ListCraters)
            {
                crater.DrawSphere(g);
            }
        }
    }
}