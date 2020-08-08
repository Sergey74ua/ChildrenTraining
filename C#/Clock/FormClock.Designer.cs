namespace Clock
{
    partial class FormClock
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
            this.timerSec = new System.Windows.Forms.Timer(this.components);
            this.labelClock = new System.Windows.Forms.Label();
            this.SuspendLayout();
            // 
            // timerSec
            // 
            this.timerSec.Enabled = true;
            this.timerSec.Interval = 16;
            this.timerSec.Tick += new System.EventHandler(this.timerSec_Tick);
            // 
            // labelClock
            // 
            this.labelClock.AutoSize = true;
            this.labelClock.Dock = System.Windows.Forms.DockStyle.Fill;
            this.labelClock.Font = new System.Drawing.Font("Segoe UI Semibold", 48F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.labelClock.ForeColor = System.Drawing.Color.Lime;
            this.labelClock.Location = new System.Drawing.Point(0, 0);
            this.labelClock.Margin = new System.Windows.Forms.Padding(0);
            this.labelClock.Name = "labelClock";
            this.labelClock.Size = new System.Drawing.Size(283, 86);
            this.labelClock.TabIndex = 0;
            this.labelClock.Text = "00:00:00";
            // 
            // FormClock
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.Color.Black;
            this.ClientSize = new System.Drawing.Size(283, 90);
            this.Controls.Add(this.labelClock);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.None;
            this.Name = "FormClock";
            this.ShowInTaskbar = false;
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Clock";
            this.TopMost = true;
            this.TransparencyKey = System.Drawing.Color.Black;
            this.DoubleClick += new System.EventHandler(this.FormClock_DoubleClick);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Timer timerSec;
        private System.Windows.Forms.Label labelClock;
    }
}