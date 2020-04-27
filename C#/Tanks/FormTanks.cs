using System;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace Tanks
{
    public partial class Tanks : Form
    {
        public static Size Window; //размер окна
        public const byte Shadow = 8; //размер тени

        private Game game;
        private Graphics g;
        private Point cursor; //************************* В Р Е М Е Н Н О *************************

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
            Console.Beep(440, 64);
            if (timer.Enabled == false)
                timer.Enabled = true;
            else
                timer.Enabled = false;
        }

        //Отрисовка кадра
        private void Tanks_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.SmoothingMode = SmoothingMode.AntiAlias;
            cursor = PointToClient(Cursor.Position); //************** В Р Е М Е Н Н О *************
            game.StepGame(g, cursor);
        }

        //Таймер обновления кадра
        private void timer_Tick(object sender, EventArgs e)
        {
            Refresh();
        }
    }
}