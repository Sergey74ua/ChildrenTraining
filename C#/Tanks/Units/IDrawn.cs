using System.Drawing;

namespace Tanks
{
    interface IDrawn
    {
        //Метод отрисовки
        void DrawUnit(Graphics g, Color party);
    }
}