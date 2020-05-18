using System.Collections.Generic;

namespace Tanks
{
    sealed class Actions
    {
        //Перебор списков всех юнитов
        public void Step(List<Party> ListParty)
        {
            foreach (Party party in ListParty)
                foreach (dynamic unit in party.ListUnits)
                    SwitchAct(unit);
        }

        //Выбор действия
        private void SwitchAct(dynamic unit)
        {
            switch (unit.act)
            {
                case Act.BURN: //танк убит
                    unit.timeAction++;
                    break;

                case Act.WAIT: //ожидание
                    ActWait(unit);
                    break;

                case Act.BACK: //отступление
                    ActBack(unit);
                    break;

                case Act.FIRE: //атака
                    ActFire(unit);
                    break;

                case Act.FIND: //поиск цели
                    ActFind(unit);
                    break;

                default: //бездействие по умолчанию
                    unit.act = Act.WAIT;
                    break;
            }
        }

        //При бездейсвии танка
        private void ActWait(dynamic unit)
        {
            if (unit.life <= 0)
                unit.act = Act.BURN;
            if (unit.life <= 2)
            {

                unit.act = Act.WAIT;
            }
            //если ХП < 10% то Act.BACK - методы отката и ремонта
            //если есть живая цель Act.FIRE - методы поворот, подкат и выстрел
            //если цели нет, искать цель - поворот и подкат на рандомную точку
            //поиск целт (если надо)
        }

        //Отступление танка
        private void ActBack(dynamic unit)
        {
            if (unit.target == null) //проверка на отсутствие врага **** не таргет ****
                unit.life += 0.05f;
            //иначе - рассчет точки отката
            //откат
            //обзор
            if (unit.life >= 40)
                unit.act = Act.WAIT;
        }

        //Атака танка
        private void ActFire(dynamic unit)
        {
            //если направление и дистанция позволяет - стоять и стрелять
            //рассчет дамажа
            //иначе - поворот на цель
            //и движение к цели
            //а если цель убита - ActWait
        }

        //Поиск в отсутствии цели
        private void ActFind(dynamic unit)
        {
            //выбор рандомной точки
            //поворот на точку
            //и движение к точке
        }
    }
}