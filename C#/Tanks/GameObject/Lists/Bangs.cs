using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Bangs
    {
        public List<Bang> listBang = new List<Bang>();

        //Добавляем взрыв в список
        public void NewBang()
        {
            //********
        }

        //Удаляем взрыв из списка
        public void RemoveBang()
        {
            //********
        }

        //Отрисовывка сиска взрывов
        public void DrawListBangs(Graphics g)
        {
            foreach (Bang bang in listBang)
            {
                bang.DrawBang(g);
            }
        }
    }
}
