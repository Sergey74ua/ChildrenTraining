using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Game
    {
        private const byte count = 3;   //число машин ********
        private List<Party> ListParty;  //комманды
        private Shots ListShots;        //выстрелы
        private Actions Actions;        //действия
        private Shooting Shooting;      //стрельба

        //Комманды и снаряды
        public void StartGame()
        {
            ListParty = new List<Party>();
            ListShots = new Shots();
            Actions = new Actions();
            Shooting = new Shooting();

            //Добавляем команды в список
            //ListParty.Add(new Party());
            //ListParty.Add(new Party(Color.Yellow, count));
            ListParty.Add(new Party(Color.DarkBlue, new Point(35, 25), count));
            ListParty.Add(new Party(Color.DarkRed, new Point(65, 75), count, 3));

            //Sound.StarWars();
        }

        //Шаг/кадр игры
        public void StepGame(Graphics g, Point cursor)
        {
            Actions.ActUnit(ListParty, ListShots);
            Shooting.ActShot(ListParty, ListShots);

            ListShots.DrawListCrater(g);
            foreach (Party party in ListParty)
                party.DrawListUnits(g);
            ListShots.DrawListShot(g);
        }

        //Выделяем юнита ******** ******** ******** П Р О Б Н О ******** ******** ********
        public void SelectUnit(Point cursor)
        {
            PointF _target = cursor;

            //Определяем юнита под кликом
            foreach (Party party in ListParty)
                foreach (dynamic unit in party.ListUnits)
                {
                    unit.delta = unit.Delta(cursor);
                    if (unit.delta < 16)
                    {
                        unit.color = Color.White;
                        _target = unit.position;
                    }
                    else
                    {
                        _target = cursor;
                    }
                }

            //Определяем юнита как цель
            foreach (Party party in ListParty)
                foreach (dynamic unit in party.ListUnits)
                    unit.target = _target;
        }
    }
}