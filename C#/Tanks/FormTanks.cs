using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace Tanks
{
    public partial class Tanks : Form
    {
        public static Size Window;      //размер окна
        public const byte Shadow = 8;   //размер тени
        public Point cursor;

        private Game game;
        private Graphics g;

        //Запуск окна
        public Tanks()
        {
            InitializeComponent();
            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                    ControlStyles.AllPaintingInWmPaint   |
                    ControlStyles.UserPaint, true);
            UpdateStyles();
        }

        //Загрузка содержимого окна
        private void Tanks_Load(object sender, EventArgs e)
        {
            Window = ClientSize;
            game = new Game();
            game.StartGame();
        }

        //Запуск таймера
        private void Tanks_Click(object sender, EventArgs e)
        {
            Console.Beep(5000, 50);
            timer.Enabled = !timer.Enabled;
            //game.SelectUnit(cursor); //************** П Р О Б Н О *************
        }

        //Таймер обновления кадра
        private void timer_Tick(object sender, EventArgs e)
        {
            Refresh();
        }

        //Смена оконного режима
        private void Tanks_DoubleClick(object sender, EventArgs e)
        {
            if (FormBorderStyle == FormBorderStyle.None)
                FormBorderStyle = FormBorderStyle.Sizable;
            else
                FormBorderStyle = FormBorderStyle.None;
        }

        //Отрисовка кадра
        private void Tanks_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.SmoothingMode = SmoothingMode.AntiAlias;
            cursor = PointToClient(Cursor.Position);
            game.StepGame(g, cursor);
        }
    }
}