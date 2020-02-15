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

        //Запуск окна
        public Form1()
        {
            InitializeComponent();

            bitmap = new Bitmap(pictureForm.Width, pictureForm.Height);
            random = new Random();

            //Рисуем углы треугольника
            angle = new Point[3];
            angle[0] = new Point(pictureForm.Width / 2, pictureForm.Height / 20);
            angle[1] = new Point(pictureForm.Height / 20, pictureForm.Width / 20 * 18);
            angle[2] = new Point(pictureForm.Height / 20 * 19, pictureForm.Width / 20 * 18);
            for (int i = 0; i < 3; i++)
                bitmap.SetPixel(angle[i].X, angle[i].Y, Color.Red);
            pictureForm.Image = bitmap;
        }

        //Старт работы
        private void pictureForm_Click(object sender, EventArgs e)
        {
            timerForm.Enabled = true;
            point = PointToClient(Cursor.Position);
        }

        //Переисовка окна
        private void timerForm_Tick(object sender, EventArgs e)
        {
            rand = random.Next(3);
            point.X = (point.X + angle[rand].X) / 2;
            point.Y = (point.Y + angle[rand].Y) / 2;
            bitmap.SetPixel(point.X, point.Y, Color.Black);
            label.Text = ("Всего точек:\n" + (number++).ToString());
            pictureForm.Image = bitmap;
        }
    }
}