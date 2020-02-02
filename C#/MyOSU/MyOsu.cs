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
    public partial class MyOsu : Form
    {
        public Bitmap HandlerTexture = Resource1.tigr,
                      TargetTexture  = Resource1.circle;

        public MyOsu()
        {
            InitializeComponent();

            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                ControlStyles.AllPaintingInWmPaint |
                ControlStyles.UserPaint, true);

            UpdateStyles();
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            Refresh();
        }

        private void Form1_Paint(object sender, PaintEventArgs e)
        {
            Graphics g = e.Graphics;

            var localPosition = this.PointToClient(Cursor.Position);
            var handlerRectangle = new Rectangle(localPosition.X - 50, localPosition.Y - 50, 100, 100);

            g.DrawImage(HandlerTexture, handlerRectangle);
            g.DrawImage(TargetTexture, new Rectangle(500, 300, 100, 100));
        }
    }
}
