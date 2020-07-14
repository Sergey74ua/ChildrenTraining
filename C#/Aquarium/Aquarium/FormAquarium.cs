using System.Drawing;
using System.Drawing.Drawing2D;
using System.Windows.Forms;

namespace Aquarium
{
    public partial class FormAquarium : Form
    {
        private Fishes fishes;
        private Graphics g;
        private byte count;

        public FormAquarium()
        {
            InitializeComponent();
            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                    ControlStyles.AllPaintingInWmPaint   |
                    ControlStyles.UserPaint, true);
            UpdateStyles();
        }

        private void FormAquarium_Load(object sender, System.EventArgs e)
        {
            count = 5;
            fishes = new Fishes(count);
        }

        private void FormAquarium_DoubleClick(object sender, System.EventArgs e)
        {
            if (FormBorderStyle == FormBorderStyle.None)
                FormBorderStyle = FormBorderStyle.Sizable;
            else
                FormBorderStyle = FormBorderStyle.None;
        }

        private void FormAquarium_Paint(object sender, PaintEventArgs e)
        {
            g = e.Graphics;
            g.SmoothingMode = SmoothingMode.AntiAlias;
            fishes.DriweListFish(g);
        }

        private void timer1_Tick(object sender, System.EventArgs e)
        {
            Refresh();
        }

        private void FormAquarium_Click(object sender, System.EventArgs e)
        {
            timer1.Enabled = !timer1.Enabled;
        }
    }
}