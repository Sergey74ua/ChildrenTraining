using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyOSU
{
    public partial class Form1 : Form
    {
        //Объекты и переменные
        private Bitmap aim = Resource1.aim;
        private Point target = Point.Empty;
        private Random random = new Random();
        private int score;
        private double gipotenuza;

        //Запуск окна
        public Form1()
        {
            InitializeComponent();

            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                     ControlStyles.AllPaintingInWmPaint |
                     ControlStyles.UserPaint, true);

            UpdateStyles();

            randomTarget();
        }

        //Отрисовка окна
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics ctx = e.Graphics;
            ctx.SmoothingMode = SmoothingMode.AntiAlias; // AntiAlias / HighQuality

            Point cursor = PointToClient(Cursor.Position);

            Rectangle aimPosition = new Rectangle(cursor.X - 50, cursor.Y - 50, 100, 100);
            Rectangle targetPosition = new Rectangle(target.X - 50, target.Y - 50, 100, 100);

            ctx.DrawImage(aim, aimPosition);
            ctx.DrawEllipse(new Pen(Color.Black, 2), targetPosition);

            int katetX = aimPosition.X - targetPosition.X;
            int katetY = aimPosition.Y - targetPosition.Y;
            gipotenuza = Math.Sqrt(katetX * katetX + katetY * katetY);

        }

        //Анимация графики
        private void timer1_Tick(object sender, EventArgs e)
        {
            Refresh();
        }

        //Событие мышки
        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            StepGame();
        }

        //Событие клавиатуры
        private void Form1_KeyDown(object sender, KeyEventArgs e)
        {
            StepGame();
        }

        //Ход игры
        private void StepGame()
        {
            //Подсчет очков
            score = (int)gipotenuza;
            label1.Text = score.ToString();

            randomTarget();

            Refresh();
        }

        //Перемещение цели
        private void randomTarget()
        {
            target.X = 600 + random.Next(-4, 4) * 100;
            target.Y = 400 + random.Next(-3, 3) * 100;
        }
    }
}
