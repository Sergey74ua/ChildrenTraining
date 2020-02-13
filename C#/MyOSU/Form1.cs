using System;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Media;
using System.Windows.Forms;

namespace MyOSU
{
    public partial class Form1 : Form
    {
        //Объекты и переменные
        private Bitmap aim = Resource1.aim;
        private Point target = Point.Empty;
        private Random random = new Random();
        private Stopwatch stopwatch = new Stopwatch();
        private Pen pen = new Pen(Color.Black, 2);
        private SoundPlayer soundPlayer = new SoundPlayer(Resource1.click);
        private double gipotenuza;
        private int step, score, timer;

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
            ctx.DrawEllipse(pen, targetPosition);

            int katetX = aimPosition.X - targetPosition.X;
            int katetY = aimPosition.Y - targetPosition.Y;
            gipotenuza = (int) Math.Sqrt(katetX * katetX + katetY * katetY);

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
            //Счетчики ходов и таймер
            step++;
            stopwatch.Stop();
            timer = stopwatch.Elapsed.Milliseconds;
            soundPlayer.Play();

            //Подсчет очков
            score += (int) (1000 / gipotenuza * (timer / 600)); //*************** ИСПРАВИТЬ ПОДСЧЕТ ОЧКОВ ***************

            //Информационная панель
            txtScore.Text = ("Score:\n" + score.ToString());
            txtLevel.Text = ("step:  " + step.ToString());
            txtTimer.Text = ("timer: " + timer.ToString());
            txtPixel.Text = ("pixel:  " + gipotenuza.ToString());

            randomTarget();

            Refresh();

            stopwatch.Start();
        }

        //Перемещение цели
        private void randomTarget()
        {
            target.X = 600 + random.Next(-4, 4) * 100;
            target.Y = 400 + random.Next(-3, 3) * 100;
        }
    }
}