using System;
using System.Drawing;
using System.Windows.Forms;

namespace Tanks
{
    public partial class Tanks : Form
    {
        private Party PartyRed, PartyBlue;
        private Graphics g;

        public Tanks()
        {
            InitializeComponent();
            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                    ControlStyles.AllPaintingInWmPaint   |
                    ControlStyles.UserPaint, true);
            UpdateStyles();
        }

        //Загрузка окна
        private void Tanks_Load(object sender, EventArgs e)
        {
            PartyRed = new Party();
            PartyBlue = new Party();
            PartyRed.CreatePartyTank(PartyRed.count, Color.DarkRed);
            PartyBlue.CreatePartyTank(PartyBlue.count, Color.DarkBlue);
        }

        //Запуск таймера
        private void Tanks_Click(object sender, EventArgs e)
        {
            if (timer.Enabled == false) timer.Enabled = true;
            else timer.Enabled = false;
        }

        //Таймер обновления кадра
        private void timer_Tick(object sender, EventArgs e)
        {
            Refresh();
        }

        //Отрисовка кадра
        private void Tanks_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            PartyRed.DrawPartyTank(g);
            PartyBlue.DrawPartyTank(g);
        }
    }
}