using System;
using System.Collections.Generic;
using System.Drawing;
using System.Threading.Tasks;

namespace Tanks
{
    class Shots
    {
        public List<Shot> ListShot = new List<Shot>();
        public List<Bang> ListBang = new List<Bang>();
        public List<Crater> ListCrater = new List<Crater>();

        //Добавляем выстрел
        async public void NewShot(dynamic unit)
        {
            ListShot.Add(new Shot(unit));
            await Task.Run(() => Console.Beep(400, 50));
        }

        //Удаляем выстрел / добавляем взрыв ******** д о в е с т и   д о   у м а ********
        async public void RemoveShot(Shot shot)
        {
            await Task.Run(() => Console.Beep(100, 100));
            ListBang.Add(new Bang(shot.position));
            ListShot.Remove(shot);
        }

        //Удаляем взрыв ******** д о в е с т и   д о   у м а ********
        public void RemoveBang(Bang bang)
        {
            ListCrater.Add(new Crater(bang.position));
            ListBang.Remove(bang);
        }

        //Удаляем кратер
        public void RemoveCrater(Crater crater)
        {
            ListCrater.Remove(crater);
        }

        //Отрисовываем и выстрелы и взрывы 
        public void DrawListShot(Graphics g)
        {
            foreach (Shot shot in ListShot)
                shot.DrawShot(g);

            foreach (Bang bang in ListBang)
                bang.DrawBang(g);
        }

        //Отрисовываем воронки 
        public void DrawListCrater(Graphics g)
        {
            foreach (Crater crater in ListCrater)
                crater.DrawCrater(g);
        }
    }
}