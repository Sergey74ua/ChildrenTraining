using System.Collections.Generic;
using System.Drawing;

namespace Tanks
{
    class Party
    {
        //Список танков
        private const byte count = 6;
        private List<Tank> PartyTank = new List<Tank>(count);

        public void DrawPartyTank(Graphics g)
        {
            //Заполняем список танками
            while (PartyTank.Count < count)
            {
                PartyTank.Add(new Tank()
                {
                    party = Color.DarkRed
                });
            }

            byte x = 0; //*************************************************************************
            //Отрисовываем танки по списку
            foreach (Tank tank in PartyTank)
            {
                x++; //****************************************************************************
                if (x % 2 == 0)
                    tank.party = Color.DarkBlue; //************************************************
                    
                tank.DrawTank(g, x);
            }
        }
    }
}