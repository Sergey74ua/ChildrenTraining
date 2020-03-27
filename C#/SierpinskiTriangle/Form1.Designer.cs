namespace SierpinskiTriangle
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
            this.pictureForm = new System.Windows.Forms.PictureBox();
            this.timerForm = new System.Windows.Forms.Timer(this.components);
            this.label = new System.Windows.Forms.Label();
            ((System.ComponentModel.ISupportInitialize)(this.pictureForm)).BeginInit();
            this.SuspendLayout();
            // 
            // pictureForm
            // 
            this.pictureForm.BackColor = System.Drawing.SystemColors.Info;
            this.pictureForm.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pictureForm.Location = new System.Drawing.Point(0, 0);
            this.pictureForm.Name = "pictureForm";
            this.pictureForm.Size = new System.Drawing.Size(800, 800);
            this.pictureForm.TabIndex = 0;
            this.pictureForm.TabStop = false;
            this.pictureForm.Click += new System.EventHandler(this.pictureForm_Click);
            // 
            // timerForm
            // 
            this.timerForm.Interval = 1;
            this.timerForm.Tick += new System.EventHandler(this.timerForm_Tick);
            // 
            // label
            // 
            this.label.AutoSize = true;
            this.label.BackColor = System.Drawing.SystemColors.Info;
            this.label.Font = new System.Drawing.Font("Microsoft Sans Serif", 15.75F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(204)));
            this.label.Location = new System.Drawing.Point(0, 0);
            this.label.Name = "label";
            this.label.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.label.Size = new System.Drawing.Size(177, 25);
            this.label.TabIndex = 1;
            this.label.Text = "Поставьте точку";
            this.label.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(800, 800);
            this.Controls.Add(this.label);
            this.Controls.Add(this.pictureForm);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "Form1";
            this.Text = "SierpinskiTriangle";
            ((System.ComponentModel.ISupportInitialize)(this.pictureForm)).EndInit();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.PictureBox pictureForm;
        private System.Windows.Forms.Timer timerForm;
        private System.Windows.Forms.Label label;
    }
}

