using System;
using System.Collections.Generic;

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

        //Логика действий
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

            //DEAD - если танк убит ******** баг - будет доезжать мертвым ********
            if (unit.life <= 0.0f)
                unit.RemoveUnit(unit);

            else if (unit.targetID == null)
            {
                unit.targetID = unit.FindUnit(ListParty);
                
                //FIND - поиск цели и случайный перекат если ее нет
                if (unit.targetID == null)
                    unit.act = Act.FIND;

                //MOVE - движемся в направлении цели
                else if (unit.targetID != null && unit.Delta(unit.target) > 256 || unit.timeAction < 60)
                    unit.act = Act.MOVE;

                //FIRE - атака живой цели в зоне поражения
                else if(unit.targetID != null && unit.Delta(unit.target) < 256 && unit.timeAction > 60)
                    unit.act = Act.FIRE;
            }

            //WAIT - повторяем в случае сбоя
            else
                unit.act = Act.WAIT;
        }
        //*********************************************************************************************************************
        //Процесс движения в случаную точку при отсутствии цели
        private void ActFind(dynamic unit)
        {
            if (unit.Delta(unit.target) > 16)
                unit.Move();
            else
                unit.act = Act.WAIT;
        }
        //*********************************************************************************************************************
        //Процесс сближения с целью
        private void ActMove(dynamic unit)
        {
            if (unit.Delta(unit.target) > 256 || unit.timeAction < 60)
                unit.Move();
            else if (unit.targetID != null)
                unit.act = Act.FIRE;
            else
                unit.act = Act.WAIT;
        }
        //*********************************************************************************************************************
        //Процесс атаки танка
        private void ActFire(dynamic unit)
        {
            unit.target = unit.targetID.position;
            if (unit.Delta(unit.target) < 256 && unit.timeAction > 180)
            {
                ListShots.NewShot(unit);
                unit.targetID = null;
                unit.timeAction = (uint)random.Next(64);
                unit.act = Act.WAIT;
            }
            else
                unit.vectorTower = unit.Angle(unit.vectorTower, unit.speed * 2);
        }
    }
}