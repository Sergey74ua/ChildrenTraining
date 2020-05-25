using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Game
    {
        private List<Party> ListParty;  //комманды
        private Shots ListShots;        //выстрелы
        private Actions Actions;        //действия

        private readonly byte count = 3;//число машин ********

        //Комманды и снаряды
        public void StartGame()
        {
            ListParty = new List<Party>();
            ListShots = new Shots();
            Actions = new Actions();

            //Добавляем команды в список
            //ListParty.Add(new Party());
            //ListParty.Add(new Party(Color.Yellow, count));
            ListParty.Add(new Party(Color.DarkBlue, new Point(70, 75), count));
            ListParty.Add(new Party(Color.DarkRed, new Point(30, 25), count, 3));

            //Sound.StarWars();
        }

        //Шаг/кадр игры
        public void StepGame(Graphics g, Point cursor)
        {
            Actions.ActObject(ListParty, ListShots);

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