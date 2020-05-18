using System;
using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Game
    {
        private List<Party> ListParty;  //комманды
        private Craters ListCraters;    //воронки
        private Shots ListShots;        //выстреы
        private Bangs ListBangs;        //взрывы
        private Actions Actions;        //действия
        private byte count = 3;         //число машин ********

        //Комманды и снаряды
        public void StartGame()
        {
            ListParty = new List<Party>();
            ListCraters = new Craters();
            ListShots = new Shots();
            ListBangs = new Bangs();
            Actions = new Actions();

            //Добавляем команды в список
            ListParty.Add(new Party(Color.DarkRed, new Point(20, 20), count, count));
            ListParty.Add(new Party(Color.DarkBlue, new Point(20, 80), count, count));
            ListParty.Add(new Party(Color.Yellow, new Point(80, 20), count, count));
            ListParty.Add(new Party(Color.Purple, new Point(80, 80), count, count));

            //Sound.StarWars();
        }

        //Шаг/кадр игры
        public void StepGame(Graphics g, Point cursor)
        {
            Actions.Step(ListParty);

            ListCraters.DrawListCraters(g);

            foreach (Party party in ListParty)
            {
                party.DrawListUnits(g, ListShots, cursor); //******** переделать параметры ********
                ListShots.Damage(party); //******** У Б Р А Т Ь  отсюда как-то ********
            }

            ListShots.DrawListShot(g);
            ListBangs.DrawListBangs(g);
        }

        //Выделяем юнита ******** ******** ******** ******** П Р О Б Н О ******** ******** ******** ********
        public void SelectUnit(Point cursor)
        {
            PointF _target = cursor;

            //Определяем юнита под кликом
            foreach (Party party in ListParty)
                foreach (dynamic unit in party.ListUnits)
                {
                    if (Math.Abs(unit.position.X - cursor.X) < 16 &&
                        Math.Abs(unit.position.Y - cursor.Y) < 16)
                    {
                        unit.party = Color.White;
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