using System.Drawing;

namespace Tanks
{
    sealed class Game
    {
        private byte count = 3;

        private Party PartyRed, PartyBlue;
        private Shots PartyShots;
        private Actions Action;

        public void StartGame(Size Window) // *** преобразовать размеры в позицию
        {
            //Комманды
            PartyRed = new Party();
            PartyBlue = new Party();

            //Стрельба
            PartyShots = new Shots();

            //Действия
            Action = new Actions();

            PartyRed.CreateListUnits(Color.DarkRed, count, Window);
            PartyBlue.CreateListUnits(Color.DarkBlue, count, Window);

            PartyShots.NewShot(new PointF(0, 0), new PointF(1980, 1000), Color.DarkOrange); //******** В Р Е М Е Н Н О ********
            PartyShots.NewShot(new PointF(0, 1000), new PointF(1980, 0), Color.LimeGreen); //******** В Р Е М Е Н Н О ********
        }

        public void StepGame(Graphics g, Point cursor)
        {
            DrawListUnits(g, PartyRed.ListUnits , cursor);
            DrawListUnits(g, PartyBlue.ListUnits, cursor);

            PartyShots.DrawListShot(g);
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, dynamic ListUnits, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                unit.target = cursor; //должна быть ссылка на функцию определения таргета
                Action.SwitchAct(unit); //******** Д О Д Е Л А Т Ь ********

                //***************************** В Р Е М Е Н Н О *****************************
                if (unit.timeShot <= 0)
                {
                    PartyShots.NewShot(unit.position, unit.target, unit.party);
                    unit.timeShot = 180;
                }
                unit.timeShot--;
                //***************************** В Р Е М Е Н Н О *****************************

                unit.DrawUnit(g, unit.party);
            }
        }
    }
}