using System.Collections.Generic;

namespace Tanks
{
    class Shooting
    {
        private Shot shot;
        private Bang bang;
        private Crater crater;

        //Рассчет выстрелов
        public void ActShot(List<Party> ListParty, Shots Shots)
        {
            //Перерасчет выстрелов
            for (int i = 0; i < Shots.ListShot.Count; i++)
            {
                shot = Shots.ListShot[i];

                shot.Move();
                if (shot.speed < 2 ||
                    shot.Delta(shot.position, shot.target) < shot.speed)
                    Shots.RemoveShot(shot);
            }

            //Перерасчет взрывов
            for (int i = 0; i < Shots.ListBang.Count; i++)
            {
                bang = Shots.ListBang[i];

                //рассчет дамажа ******** НЕ ВЕРНО РАССЧИТЫВАЕТСЯ ДАМАЖ ********
                if (bang.timeAction > 96)
                {
                    foreach (Party party in ListParty)
                        foreach (dynamic unit in party.ListUnits)
                            if (unit.Delta(unit.position, bang.position) < 48 && unit.life > 0)
                                unit.life -= 10 / unit.Delta(unit.position, unit.target);

                    //удаляем взрыв
                    Shots.RemoveBang(bang);
                }
                else
                    //процесс взрыва
                    bang.timeAction += 8;
            }

            //Перерасчет воронок
            for (int i = 0; i < Shots.ListCrater.Count; i++)
            {
                crater = Shots.ListCrater[i];

                crater.timeAction++;
                if (crater.timeAction > 600)
                    Shots.RemoveCrater(crater);
            }
        }
    }
}