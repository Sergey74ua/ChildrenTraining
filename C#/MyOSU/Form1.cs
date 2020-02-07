using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyOSU
{
    public partial class Form1 : Form
    {
        private Bitmap aim = Resource1.aim;
        private Point target = Point.Empty;

        public Form1()
        {
            InitializeComponent();

            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                     ControlStyles.AllPaintingInWmPaint |
                     ControlStyles.UserPaint, true);

            UpdateStyles();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics ctx = e.Graphics;

            var cursor = this.PointToClient(Cursor.Position);

            target.X = 400;
            target.Y = 500;

            var aimPosition = new Rectangle(cursor.X - 50, cursor.Y - 50, 100, 100);
            var targetPosition = new Rectangle(target.X - 50, target.Y - 50, 100, 100);

            ctx.DrawImage(aim, aimPosition);
            ctx.DrawEllipse(new Pen(Color.Black, 2), targetPosition);
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Refresh();
        }
    }
}
