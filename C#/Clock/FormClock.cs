using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Clock
{
    public partial class FormClock : Form
    {
        public FormClock()
        {
            InitializeComponent();

            SetStyle(ControlStyles.OptimizedDoubleBuffer |
                    ControlStyles.AllPaintingInWmPaint |
                    ControlStyles.UserPaint, true);
            UpdateStyles();
        }

        private void timerSec_Tick(object sender, EventArgs e)
        {
            labelClock.Text = DateTime.Now.ToString("T");
        }

        private void FormClock_DoubleClick(object sender, EventArgs e)
        {
            if (FormBorderStyle == FormBorderStyle.Sizable)
                FormBorderStyle = FormBorderStyle.None;
            else
                FormBorderStyle = FormBorderStyle.Sizable;
        }
    }
}
