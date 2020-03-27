using System;
using System.Drawing;
using System.Windows.Forms;

namespace SierpinskiTriangle
{
    public partial class Form1 : Form
    {
        //Переменные и объекты
        private Bitmap bitmap;
        private Point point;
        private Point[] angle;
        private Random random;
        private int number, rand;
        private byte count = 4;

        //Запуск окна
        public Form1()
        {
            InitializeComponent();

            bitmap = new Bitmap(pictureForm.Width, pictureForm.Height);
            random = new Random();

            //Рисуем углы треугольника
            angle = new Point[count];
            angle[0] = new Point(795, 5);
            angle[1] = new Point(795, 795);
            angle[2] = new Point(5, 795);
            angle[3] = new Point(5, 5);

            for (int i = 0; i < count; i++)
                bitmap.SetPixel(angle[i].X, angle[i].Y, Color.Red);
        }

        //Старт работы
        private void pictureForm_Click(object sender, EventArgs e)
        {
            timerForm.Enabled = true;
            point = PointToClient(Cursor.Position);
        }

        //Перерисовка окна
        private void timerForm_Tick(object sender, EventArgs e)
        {
            for (byte i = 0; i < byte.MaxValue; i++)
            {
                rand = random.Next(count);
                point.X = (point.X + angle[rand].X) / 2;
                point.Y = (point.Y + angle[rand].Y) / 2;

                bitmap.SetPixel(point.X, point.Y, Color.Black);

                label.Text = (number++.ToString());
            }

            pictureForm.Image = bitmap;
        }
    }
}