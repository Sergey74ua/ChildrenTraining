using System;
using System.Drawing;
using System.Windows.Forms;

namespace Tanks
{
    public partial class Tanks : Form
    {
        Party party;
        Graphics g;

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
            party = new Party();
        }

        //Отрисовка кадра
        private void Tanks_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            party.DrawPartyTank(g);
        }

        //Таймер обновления кадра
        private void timer_Tick(object sender, EventArgs e)
        {
            Refresh();
        }
    }
}