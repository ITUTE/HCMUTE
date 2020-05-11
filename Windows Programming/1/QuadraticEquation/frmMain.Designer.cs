namespace QuadraticEquation
{
    partial class frmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.label1 = new System.Windows.Forms.Label();
            this.lbNumA = new System.Windows.Forms.Label();
            this.lbNumB = new System.Windows.Forms.Label();
            this.lbNumC = new System.Windows.Forms.Label();
            this.txtNumA = new System.Windows.Forms.TextBox();
            this.txtNumC = new System.Windows.Forms.TextBox();
            this.txtNumB = new System.Windows.Forms.TextBox();
            this.lbResult = new System.Windows.Forms.Label();
            this.txtResult = new System.Windows.Forms.TextBox();
            this.btnSolve = new System.Windows.Forms.Button();
            this.btnDel = new System.Windows.Forms.Button();
            this.btnExit = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.label1.ForeColor = System.Drawing.Color.Red;
            this.label1.Location = new System.Drawing.Point(54, 9);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(242, 31);
            this.label1.TabIndex = 0;
            this.label1.Text = "ax^2 + bx + c = 0 ";
            // 
            // lbNumA
            // 
            this.lbNumA.AutoSize = true;
            this.lbNumA.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lbNumA.Location = new System.Drawing.Point(30, 60);
            this.lbNumA.Name = "lbNumA";
            this.lbNumA.Size = new System.Drawing.Size(31, 17);
            this.lbNumA.TabIndex = 1;
            this.lbNumA.Text = "a =";
            // 
            // lbNumB
            // 
            this.lbNumB.AutoSize = true;
            this.lbNumB.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lbNumB.Location = new System.Drawing.Point(30, 98);
            this.lbNumB.Name = "lbNumB";
            this.lbNumB.Size = new System.Drawing.Size(31, 17);
            this.lbNumB.TabIndex = 2;
            this.lbNumB.Text = "b =";
            // 
            // lbNumC
            // 
            this.lbNumC.AutoSize = true;
            this.lbNumC.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lbNumC.Location = new System.Drawing.Point(30, 134);
            this.lbNumC.Name = "lbNumC";
            this.lbNumC.Size = new System.Drawing.Size(30, 17);
            this.lbNumC.TabIndex = 3;
            this.lbNumC.Text = "c =";
            // 
            // txtNumA
            // 
            this.txtNumA.Location = new System.Drawing.Point(76, 60);
            this.txtNumA.Name = "txtNumA";
            this.txtNumA.Size = new System.Drawing.Size(220, 20);
            this.txtNumA.TabIndex = 4;
            this.txtNumA.Leave += new System.EventHandler(this.txtNumA_Leave);
            // 
            // txtNumC
            // 
            this.txtNumC.Location = new System.Drawing.Point(76, 134);
            this.txtNumC.Name = "txtNumC";
            this.txtNumC.Size = new System.Drawing.Size(220, 20);
            this.txtNumC.TabIndex = 6;
            this.txtNumC.Leave += new System.EventHandler(this.txtNumC_Leave);
            // 
            // txtNumB
            // 
            this.txtNumB.Location = new System.Drawing.Point(76, 98);
            this.txtNumB.Name = "txtNumB";
            this.txtNumB.Size = new System.Drawing.Size(220, 20);
            this.txtNumB.TabIndex = 5;
            this.txtNumB.Leave += new System.EventHandler(this.txtNumB_Leave);
            // 
            // lbResult
            // 
            this.lbResult.AutoSize = true;
            this.lbResult.Font = new System.Drawing.Font("Microsoft Sans Serif", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lbResult.ForeColor = System.Drawing.Color.DodgerBlue;
            this.lbResult.Location = new System.Drawing.Point(29, 186);
            this.lbResult.Name = "lbResult";
            this.lbResult.Size = new System.Drawing.Size(61, 20);
            this.lbResult.TabIndex = 7;
            this.lbResult.Text = "Result";
            // 
            // txtResult
            // 
            this.txtResult.Location = new System.Drawing.Point(33, 223);
            this.txtResult.Multiline = true;
            this.txtResult.Name = "txtResult";
            this.txtResult.Size = new System.Drawing.Size(263, 56);
            this.txtResult.TabIndex = 8;
            // 
            // btnSolve
            // 
            this.btnSolve.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnSolve.Location = new System.Drawing.Point(33, 290);
            this.btnSolve.Name = "btnSolve";
            this.btnSolve.Size = new System.Drawing.Size(75, 23);
            this.btnSolve.TabIndex = 9;
            this.btnSolve.Text = "Solve";
            this.btnSolve.UseVisualStyleBackColor = true;
            this.btnSolve.Click += new System.EventHandler(this.btnSolve_Click);
            // 
            // btnDel
            // 
            this.btnDel.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnDel.Location = new System.Drawing.Point(127, 290);
            this.btnDel.Name = "btnDel";
            this.btnDel.Size = new System.Drawing.Size(75, 23);
            this.btnDel.TabIndex = 10;
            this.btnDel.Text = "Delete All";
            this.btnDel.UseVisualStyleBackColor = true;
            this.btnDel.Click += new System.EventHandler(this.btnDel_Click);
            // 
            // btnExit
            // 
            this.btnExit.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnExit.Location = new System.Drawing.Point(221, 290);
            this.btnExit.Name = "btnExit";
            this.btnExit.Size = new System.Drawing.Size(75, 23);
            this.btnExit.TabIndex = 11;
            this.btnExit.Text = "&Exit";
            this.btnExit.UseVisualStyleBackColor = true;
            this.btnExit.Click += new System.EventHandler(this.btnExit_Click);
            // 
            // frmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(330, 335);
            this.Controls.Add(this.btnExit);
            this.Controls.Add(this.btnDel);
            this.Controls.Add(this.btnSolve);
            this.Controls.Add(this.txtResult);
            this.Controls.Add(this.lbResult);
            this.Controls.Add(this.txtNumB);
            this.Controls.Add(this.txtNumC);
            this.Controls.Add(this.txtNumA);
            this.Controls.Add(this.lbNumC);
            this.Controls.Add(this.lbNumB);
            this.Controls.Add(this.lbNumA);
            this.Controls.Add(this.label1);
            this.Name = "frmMain";
            this.Text = "Quadratic Equation";
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lbNumA;
        private System.Windows.Forms.Label lbNumB;
        private System.Windows.Forms.Label lbNumC;
        private System.Windows.Forms.TextBox txtNumA;
        private System.Windows.Forms.TextBox txtNumC;
        private System.Windows.Forms.TextBox txtNumB;
        private System.Windows.Forms.Label lbResult;
        private System.Windows.Forms.TextBox txtResult;
        private System.Windows.Forms.Button btnSolve;
        private System.Windows.Forms.Button btnDel;
        private System.Windows.Forms.Button btnExit;
    }
}

