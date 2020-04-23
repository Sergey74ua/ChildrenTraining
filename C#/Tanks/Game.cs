using System.Drawing;

namespace Tanks
{
    sealed class Game
    {
        private byte count = 3;

        private Party PartyRed, PartyBlue;
        private Shots AllShots;
        private Actions Action;

        public void StartGame(Size Window) // *** преобразовать размеры в позицию
        {
            //Комманды и снаряды
            PartyRed = new Party();
            PartyBlue = new Party();
            AllShots = new Shots();
            Action = new Actions();

            PartyRed.CreateListUnits(Color.DarkRed, count, Window);
            PartyBlue.CreateListUnits(Color.DarkBlue, count, Window);
        }

        public void StepGame(Graphics g, Point cursor)
        {
            DrawListUnits(g, PartyRed.ListUnits , cursor);
            DrawListUnits(g, PartyBlue.ListUnits, cursor);

            AllShots.DrawListShot(g);
        }

        //Отрисовываем юнитов по списку
        public void DrawListUnits(Graphics g, dynamic ListUnits, Point cursor)
        {
            foreach (dynamic unit in ListUnits)
            {
                unit.target = cursor; //должна быть ссылка на функцию определения таргета
                Action.SwitchAct(unit); //******** Д О Д Е Л А Т Ь ********

                //Добавляем выстрел в список
                AllShots.ListShot.Add(unit.shot);

                unit.DrawUnit(g, unit.party);
            }
        }
    }
}