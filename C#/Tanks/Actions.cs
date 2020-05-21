using System;
using System.Collections.Generic;

namespace Tanks
{
    class Actions
    {
        private List<Party> ListParty;
        private Shots ListShots;
        private Random random = new Random();
        private readonly byte range = 64;
        private float delta, _delta;

        //Перебор списков всех юнитов
        public void ActObject(List<Party> ListParty, Shots ListShots)
        {
            this.ListParty = ListParty;
            this.ListShots = ListShots;

            //Перерасчет юнитов
            foreach (Party party in ListParty)
                foreach (dynamic unit in party.ListUnits)
                    SelectAct(unit);

            //Перерасчет выстрелов
            foreach (Shot shot in ListShots.ListShot)
            {
                shot.timeAction++;
                shot.Move();
                if (shot.speed < 1 || shot.Delta(shot.target) < shot.speed)
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

        //Выбор действия
        private void SelectAct(dynamic unit)
        {
            switch (unit.act)
            {
                case Act.DEAD:  //подбит
                    break;
                case Act.WAIT:  //ожидание
                    ActWait(unit);
                    break;
                case Act.FIRE:  //атака
                    ActFire(unit);
                    break;
                case Act.FIND:  //поиск
                    ActFind(unit);
                    break;
                default:        //прочее
                    unit.act = Act.WAIT;
                    break;
            }
        }

        //Определяем действие танка
        private void ActWait(dynamic unit)
        {
            //если танк убит
            if (unit.life <= 0.0f)
            {
                unit.RemoveUnit(unit);
                unit.act = Act.DEAD;
            }

            //если у танка есть живая цель
            else if (unit.targetID != null)
            {
                if (unit.delta < 512 && unit.timeAction >= 180)
                    unit.Atack = true;
                unit.act = Act.FIRE;
            }

            //поиск цели, если ее нет
            else if (unit.targetID == null)
            {
                foreach (Party party in ListParty)
                    foreach (dynamic _unit in party.ListUnits)
                    {
                        //поиск цели
                        if (unit.color != _unit.color && _unit.life > 0)
                        {
                            //отбор ближайшей цели (точно работает?)
                            _delta = unit.Delta(_unit.position);
                            if (delta > _delta)
                            {
                                delta = _delta;
                                unit.targetID = _unit;
                                unit.target = _unit.position;
                                unit.act = Act.FIRE;
                            }
                            else
                                delta = 756;
                        }
                    }
            }

            //повторяем если цель убита или не найдена ********  Н Е   Р А Б О Т А Е Т  ********
            else
            {
                unit.target.X = unit.position.X + random.Next(-range, range);
                unit.target.Y = unit.position.Y + random.Next(-range, range);
                unit.act = Act.FIND;
            }
        }

        //Процесс атаки танка
        private void ActFire(dynamic unit)
        {
            if (unit.Delta(unit.targetID.position) < 256 && unit.timeAction > 60)
            {
                ListShots.NewShot(unit);
                unit.targetID = null;
                unit.timeAction = 0;
                unit.act = Act.WAIT;
            }
            else
            {
                unit.timeAction++;
                unit.Move();
            }
        }

        //Процесс поиска цели
        private void ActFind(dynamic unit)
        {
            if (unit.Delta(unit.target) < 128 && unit.timeAction < 60) //******** тут все нормально? ********
            {
                unit.timeAction++;
                unit.Move(); Console.WriteLine(unit.Delta(unit.target).ToString()); //****
            }
            else
            {
                unit.timeAction = 0;
                unit.act = Act.WAIT;
            }
        }
    }
}