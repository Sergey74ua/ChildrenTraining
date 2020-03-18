using System;
using System.Diagnostics;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Media;
using System.Windows.Forms;

namespace MyOSU
{
    public partial class FormMyOsu : Form
    {
        //Объекты и переменные
        private Bitmap aim = Resource1.aim;
        private Pen pen = new Pen(Color.Black, 3);
        private Point cursor, target = Point.Empty;
        private Rectangle aimPosition, targetPosition;
        private SoundPlayer soundPlayer = new SoundPlayer(Resource1.click);
        private Stopwatch stopwatch = new Stopwatch();
        private Random random = new Random();
        private double gipotenuza;
        private int katetX, katetY, step, time, score, totalScore;

        //Запуск окна
        public FormMyOsu()
        {
            InitializeComponent();
            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                     ControlStyles.AllPaintingInWmPaint  |
                     ControlStyles.UserPaint, true);
            UpdateStyles();
            Cursor.Hide();
            randomTarget();
            stopwatch.Start();
        }

        //Отрисовка окна
        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;
            g.SmoothingMode = SmoothingMode.AntiAlias;

            //Отрисовка прицела и цели
            cursor = PointToClient(Cursor.Position);
            aimPosition = new Rectangle(cursor.X - 50, cursor.Y - 50, 100, 100);
            targetPosition = new Rectangle(target.X - 50, target.Y - 50, 100, 100);
            g.DrawImage(aim, aimPosition);
            g.DrawEllipse(pen, targetPosition);
        }

        //Перемещение цели (рекурсия)
        private void randomTarget()
        {
            Point _target = target;
            target.X = Width / 2 + random.Next(-4, 4) * 100;
            target.Y = Height / 2 + random.Next(-3, 3) * 100;
            if (target == _target) randomTarget();
        }

        //Ход игры
        private void StepGame()
        {
            //Счетчик ходов и таймер
            step++;
            time = (int) stopwatch.Elapsed.TotalMilliseconds;
            soundPlayer.Play();

            //Точность попадания
            katetX = aimPosition.X - targetPosition.X;
            katetY = aimPosition.Y - targetPosition.Y;
            gipotenuza = (int) Math.Sqrt(katetX * katetX + katetY * katetY);

            //Информационная панель
            score = (int) (750 / gipotenuza + 37500 / time);
            totalScore += score;
            txtTotalScore.Text = ("Score:\n" + totalScore.ToString());
            txtScore.Text = (score.ToString());
            txtLevel.Text = ("step:  " + step.ToString());
            txtTimer.Text = ("timer: " + time.ToString());
            txtPixel.Text = ("pixel:  " + gipotenuza.ToString());

            //Рестарт хода
            randomTarget();
            Refresh();
            stopwatch.Restart();
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
    }
}