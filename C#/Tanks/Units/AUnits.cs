using System.Drawing;

namespace Tanks
{
    abstract class AUnits : AObject
    {
        private static uint ID;

        //Общие поля юнитов
        public uint id = ++ID;          //имя
        public Act action = Act.WAIT;   //действие
        public float life;              //жизнь
        public float vectorBody;        //вектор корпуса
        public float vectorTower;       //вектор башни

        //Данные для отисовки
        private readonly SolidBrush solidBrushFont = new SolidBrush(Color.LightGreen);
        private readonly Font font = new Font("Arial", 10, FontStyle.Bold, GraphicsUnit.Point);
        private readonly Pen pen = new Pen(Color.Green, 2);

        //Отрисовка имени и жизни
        protected void DrawInfo(Graphics g)
        {
            //Наименование
            g.TranslateTransform(position.X, position.Y);
            g.DrawString("= " + id.ToString() + " =", font, solidBrushFont, -20, -42);
            g.ResetTransform();

            //Жизнь
            g.TranslateTransform(position.X, position.Y);
            g.DrawLine(pen, -32, -26, 32, -26);
            g.ResetTransform();
        }
    }
}