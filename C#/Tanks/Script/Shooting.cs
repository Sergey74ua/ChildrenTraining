using System.Collections.Generic;

namespace Tanks
{
    class Shooting
    {
        private Shots ListShots;

        public void ActShot(List<Party> ListParty, Shots ListShots)
        {
            this.ListShots = ListShots;

            //Перерасчет выстрелов
            foreach (Shot shot in ListShots.ListShot)
            {
                shot.Move();
                if (shot.speed < 2 || shot.Delta(shot.target) < shot.speed)
                    ListShots.RemoveShot(shot);
            }

            //Перерасчет взрывов
            for (int i = 0; i < ListShots.ListBang.Count; i++)
            {
                //рассчет дамажа ******** НЕ ВЕРНО РАССЧИТЫВАЕТСЯ ДАМАЖ ********
                if (ListShots.ListBang[i].timeAction > 96)
                {
                    foreach (Party party in ListParty)
                        foreach (dynamic unit in party.ListUnits)
                            if (unit.Delta(ListShots.ListBang[i].position) < 48 && unit.life > 0)
                                unit.life -= 10 / unit.Delta(unit.target);

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