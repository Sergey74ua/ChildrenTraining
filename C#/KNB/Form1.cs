using System;
using System.Windows.Forms;

namespace KNB
{
    public partial class Form1 : Form
    {
        Game game = new Game();

        public Form1()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            label9.Text = "КАМЕНЬ";
            StepGame(0);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            label9.Text = "НОЖНИЦЫ";
            StepGame(1);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            label9.Text = "БУМАГА";
            StepGame(2);
        }

        private void StepGame(byte player)
        {
            game.StepGame(player);

            label11.Text = game.resGame;
            label4.Text = game.win.ToString();
            label5.Text = game.lose.ToString();
            label6.Text = game.draw.ToString();

            switch (game.compHand)
            {
                case 0:
                    label10.Text = "КАМЕНЬ";
                    break;
                case 1:
                    label10.Text = "НОЖНИЦЫ";
                    break;
                case 2:
                    label10.Text = "БУМАГА";
                    break;
            }
        }
    }
}