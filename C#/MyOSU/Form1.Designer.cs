namespace MyOSU
{
    partial class Form1
    {
        /// <summary>
        /// Обязательная переменная конструктора.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Освободить все используемые ресурсы.
        /// </summary>
        /// <param name="disposing">истинно, если управляемый ресурс должен быть удален; иначе ложно.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Код, автоматически созданный конструктором форм Windows

        /// <summary>
        /// Требуемый метод для поддержки конструктора — не изменяйте 
        /// содержимое этого метода с помощью редактора кода.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(Form1));
            this.timer1 = new System.Windows.Forms.Timer(this.components);
            this.txtTotalScore = new System.Windows.Forms.Label();
            this.txtLevel = new System.Windows.Forms.Label();
            this.txtTimer = new System.Windows.Forms.Label();
            this.txtPixel = new System.Windows.Forms.Label();
            this.txtScore = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // timer1
            // 
            this.timer1.Enabled = true;
            this.timer1.Interval = 16;
            this.timer1.Tick += new System.EventHandler(this.timer1_Tick);
            // 
            // txtTotalScore
            // 
            this.txtTotalScore.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Right)));
            this.txtTotalScore.AutoSize = true;
            this.txtTotalScore.BackColor = System.Drawing.Color.Transparent;
            this.txtTotalScore.Font = new System.Drawing.Font("Microsoft Sans Serif", 36F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.txtTotalScore.Location = new System.Drawing.Point(980, 20);
            this.txtTotalScore.Name = "txtTotalScore";
            this.txtTotalScore.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.txtTotalScore.Size = new System.Drawing.Size(163, 55);
            this.txtTotalScore.TabIndex = 0;
            this.txtTotalScore.Text = "Score:";
            this.txtTotalScore.TextAlign = System.Drawing.ContentAlignment.MiddleRight;
            // 
            // txtLevel
            // 
            this.txtLevel.AutoSize = true;
            this.txtLevel.BackColor = System.Drawing.Color.Transparent;
            this.txtLevel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.txtLevel.ForeColor = System.Drawing.Color.DarkGreen;
            this.txtLevel.Location = new System.Drawing.Point(980, 180);
            this.txtLevel.Name = "txtLevel";
            this.txtLevel.Size = new System.Drawing.Size(70, 31);
            this.txtLevel.TabIndex = 1;
            this.txtLevel.Text = "level";
            // 
            // txtTimer
            // 
            this.txtTimer.AutoSize = true;
            this.txtTimer.BackColor = System.Drawing.Color.Transparent;
            this.txtTimer.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.txtTimer.ForeColor = System.Drawing.Color.Blue;
            this.txtTimer.Location = new System.Drawing.Point(980, 240);
            this.txtTimer.Name = "txtTimer";
            this.txtTimer.Size = new System.Drawing.Size(65, 31);
            this.txtTimer.TabIndex = 2;
            this.txtTimer.Text = "time";
            // 
            // txtPixel
            // 
            this.txtPixel.AutoSize = true;
            this.txtPixel.BackColor = System.Drawing.Color.Transparent;
            this.txtPixel.Font = new System.Drawing.Font("Microsoft Sans Serif", 20.25F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.txtPixel.Location = new System.Drawing.Point(980, 300);
            this.txtPixel.Name = "txtPixel";
            this.txtPixel.Size = new System.Drawing.Size(69, 31);
            this.txtPixel.TabIndex = 3;
            this.txtPixel.Text = "pixel";
            // 
            // txtScore
            // 
            this.txtScore.AutoSize = true;
            this.txtScore.BackColor = System.Drawing.Color.Transparent;
            this.txtScore.Font = new System.Drawing.Font("Microsoft Sans Serif", 9.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.txtScore.ForeColor = System.Drawing.Color.Red;
            this.txtScore.Location = new System.Drawing.Point(987, 75);
            this.txtScore.Name = "txtScore";
            this.txtScore.Size = new System.Drawing.Size(15, 16);
            this.txtScore.TabIndex = 4;
            this.txtScore.Text = "0";
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Desktop;
            this.BackgroundImage = global::MyOSU.Resource1.fon;
            this.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Stretch;
            this.ClientSize = new System.Drawing.Size(1184, 761);
            this.Controls.Add(this.txtScore);
            this.Controls.Add(this.txtPixel);
            this.Controls.Add(this.txtLevel);
            this.Controls.Add(this.txtTimer);
            this.Controls.Add(this.txtTotalScore);
            this.Cursor = System.Windows.Forms.Cursors.Cross;
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "MyOSU";
            this.Paint += new System.Windows.Forms.PaintEventHandler(this.Form1_Paint);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.Form1_KeyDown);
            this.MouseDown += new System.Windows.Forms.MouseEventHandler(this.Form1_MouseDown);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion
        private System.Windows.Forms.Timer timer1;
        private System.Windows.Forms.Label txtTotalScore;
        private System.Windows.Forms.Label txtLevel;
        private System.Windows.Forms.Label txtTimer;
        private System.Windows.Forms.Label txtPixel;
        private System.Windows.Forms.Label txtScore;
    }
}

