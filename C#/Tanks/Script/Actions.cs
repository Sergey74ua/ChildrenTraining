using System;
using System.Collections.Generic;
using Game2D;

namespace Tanks
{
    class Actions
    {
        private readonly Random random = new Random();
        private List<Party> ListParty;
        private Shots ListShots;

        //Перебор всех юнитов
        public void ActUnit(List<Party> ListParty, Shots ListShots)
        {
            this.ListParty = ListParty;
            this.ListShots = ListShots;

            //Перебор действий юнитов
            foreach (Party party in ListParty)
                foreach (dynamic unit in party.ListUnits)
                    if (unit.act != Act.DEAD)
                        SelectAct(unit);
        }

        //Переключатель действий
        private void SelectAct(dynamic unit)
        {
            unit.timeAction++;
            switch (unit.act)
            {
                case Act.WAIT:  //ожидание
                    ActWait(unit);
                    break;
                case Act.FIND:  //поиск
                    ActFind(unit);
                    break;
                case Act.MOVE:  //подкат
                    ActMove(unit);
                    break;
                case Act.FIRE:  //атака
                    ActFire(unit);
                    break;
                default:        //прочее
                    unit.act = Act.WAIT;
                    break;
            }
        }

        //Определяем действие танка
        private void ActWait(dynamic unit)
        {
            unit.timeAction = 0;
            float findDelta;

            //DEAD - если танк убит
            if (unit.life <= 0.0f)
                unit.RemoveUnit(unit);
            else
            {
                unit.delta = unit.vision * 2;
                
                //Поиск ближайшего чужого живого танка
                foreach (Party party in ListParty)
                    foreach (dynamic findUnit in party.ListUnits)
                        if (unit.color != findUnit.color && findUnit.act != Act.DEAD)
                        {
                            findDelta = Func2D.Delta(findUnit.position, unit.target);
                            if (findDelta < unit.delta)
                            {
                                unit.delta = findDelta;
                                unit.target = findUnit.position;
                            }
                        }

                //FIND - поиск цели и случайный перекат если ее нет
                if (unit.delta > unit.vision)
                {
                    unit.target.X = unit.position.X + random.Next(-64, 64);
                    unit.target.Y = unit.position.Y + random.Next(-64, 64);
                    unit.act = Act.FIND;
                }

                //MOVE - движемся в направлении цели **********************************************
                else if (unit.delta > unit.vision / 2 && unit.timeAction < 60)
                    unit.act = Act.MOVE;

                //FIRE - атака живой цели в зоне поражения ****************************************
                else if (unit.delta < unit.vision / 2 && unit.timeAction < 60)
                    unit.act = Act.FIRE;

                //WAIT - повторяем в случае сбоя
                else
                    unit.act = Act.WAIT;
            }
        }

        //Процесс движения в случаную точку при отсутствии цели ***********************************
        private void ActFind(dynamic unit)
        {
            if (unit.delta > unit.speed)
                unit.Move();
            else
                unit.act = Act.WAIT;
        }

        //Процесс сближения с целью ***************************************************************
        private void ActMove(dynamic unit)
        {
            if (unit.delta > 256 && unit.timeAction < 60)
            {
                unit.vectorTower = unit.Angle(unit.vectorTower, unit.speed * 2);
                unit.Move();
            }
            else
                unit.act = Act.WAIT;
        }

        //Процесс атаки танка *********************************************************************
        private void ActFire(dynamic unit)
        {
            if (Func2D.Delta(unit.position, unit.target) < unit.vision && unit.timeAction > 120)
            {
                ListShots.NewShot(unit);
                unit.act = Act.WAIT;
            }
            else
            {
                unit.vectorTower = unit.Angle(unit.vectorTower, unit.speed * 2);
                unit.Move();
            }
        }
    }
}