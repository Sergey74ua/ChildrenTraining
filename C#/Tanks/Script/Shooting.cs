using System.Collections.Generic;
using Game2D;

namespace Tanks
{
    class Shooting
    {
        //Рассчет выстрелов
        public void ActShot(List<Party> ListParty, Shots ListShots)
        {
            //Перерасчет выстрелов
            for (int i = 0; i < ListShots.ListShot.Count; i++)
            {
                ListShots.ListShot[i].Move();
                if (ListShots.ListShot[i].speed < 2 ||
                    Func2D.Delta(ListShots.ListShot[i].position, ListShots.ListShot[i].target) < ListShots.ListShot[i].speed)
                    ListShots.RemoveShot(ListShots.ListShot[i]);
            }

            //Перерасчет взрывов
            for (int i = 0; i < ListShots.ListBang.Count; i++)
            {
                //рассчет дамажа ******** НЕ ВЕРНО РАССЧИТЫВАЕТСЯ ДАМАЖ ********
                if (ListShots.ListBang[i].timeAction > 96)
                {
                    foreach (Party party in ListParty)
                        foreach (dynamic unit in party.ListUnits)
                            if (Func2D.Delta(unit.position, ListShots.ListBang[i].position) < 48 && unit.life > 0)
                                unit.life -= 10 / Func2D.Delta(unit.position, unit.target);

                    //удаляем взрыв
                    ListShots.RemoveBang(ListShots.ListBang[i]);
                }
                else
                    //процесс взрыва
                    ListShots.ListBang[i].timeAction += 8;
            }

            //Перерасчет воронок
            for (int i = 0; i < ListShots.ListCrater.Count; i++)
            {
                ListShots.ListCrater[i].timeAction++;
                if (ListShots.ListCrater[i].timeAction > 600)
                    ListShots.RemoveCrater(ListShots.ListCrater[i]);
            }
        }
    }
}