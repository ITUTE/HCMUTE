namespace Calculator
{
    partial class frmCalculator
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
            this.components = new System.ComponentModel.Container();
            this.pnlView = new System.Windows.Forms.Panel();
            this.txtInput = new System.Windows.Forms.TextBox();
            this.txtEquation = new System.Windows.Forms.TextBox();
            this.btnMemClear = new System.Windows.Forms.Button();
            this.btnMemRecall = new System.Windows.Forms.Button();
            this.btnMemStore = new System.Windows.Forms.Button();
            this.btnMemAdd = new System.Windows.Forms.Button();
            this.btnMemSub = new System.Windows.Forms.Button();
            this.btnDel = new System.Windows.Forms.Button();
            this.btnClearEntry = new System.Windows.Forms.Button();
            this.btnClear = new System.Windows.Forms.Button();
            this.btnChangeSign = new System.Windows.Forms.Button();
            this.btnSqrt = new System.Windows.Forms.Button();
            this.btnNum7 = new System.Windows.Forms.Button();
            this.btnNum8 = new System.Windows.Forms.Button();
            this.btnNum9 = new System.Windows.Forms.Button();
            this.btnDiv = new System.Windows.Forms.Button();
            this.btnPercent = new System.Windows.Forms.Button();
            this.btnNum4 = new System.Windows.Forms.Button();
            this.btnNum5 = new System.Windows.Forms.Button();
            this.btnNum6 = new System.Windows.Forms.Button();
            this.btnMul = new System.Windows.Forms.Button();
            this.btnInverse = new System.Windows.Forms.Button();
            this.btnNum1 = new System.Windows.Forms.Button();
            this.btnNum2 = new System.Windows.Forms.Button();
            this.btnNum3 = new System.Windows.Forms.Button();
            this.btnSub = new System.Windows.Forms.Button();
            this.btnEqual = new System.Windows.Forms.Button();
            this.btnNum0 = new System.Windows.Forms.Button();
            this.btnDot = new System.Windows.Forms.Button();
            this.btnAdd = new System.Windows.Forms.Button();
            this.toolTip = new System.Windows.Forms.ToolTip(this.components);
            this.pnlView.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlView
            // 
            this.pnlView.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.pnlView.Controls.Add(this.txtInput);
            this.pnlView.Controls.Add(this.txtEquation);
            this.pnlView.Location = new System.Drawing.Point(25, 25);
            this.pnlView.Name = "pnlView";
            this.pnlView.Size = new System.Drawing.Size(335, 59);
            this.pnlView.TabIndex = 0;
            // 
            // txtInput
            // 
            this.txtInput.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtInput.CharacterCasing = System.Windows.Forms.CharacterCasing.Upper;
            this.txtInput.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.txtInput.Font = new System.Drawing.Font("Consolas", 20F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.txtInput.Location = new System.Drawing.Point(0, 25);
            this.txtInput.Name = "txtInput";
            this.txtInput.ReadOnly = true;
            this.txtInput.Size = new System.Drawing.Size(333, 32);
            this.txtInput.TabIndex = 3;
            this.txtInput.TabStop = false;
            this.txtInput.Text = "0";
            this.txtInput.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            this.txtInput.WordWrap = false;
            // 
            // txtEquation
            // 
            this.txtEquation.BorderStyle = System.Windows.Forms.BorderStyle.None;
            this.txtEquation.Dock = System.Windows.Forms.DockStyle.Top;
            this.txtEquation.Font = new System.Drawing.Font("Consolas", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.txtEquation.Location = new System.Drawing.Point(0, 0);
            this.txtEquation.Name = "txtEquation";
            this.txtEquation.ReadOnly = true;
            this.txtEquation.Size = new System.Drawing.Size(333, 19);
            this.txtEquation.TabIndex = 2;
            this.txtEquation.TabStop = false;
            this.txtEquation.Text = "0";
            this.txtEquation.TextAlign = System.Windows.Forms.HorizontalAlignment.Right;
            // 
            // btnMemClear
            // 
            this.btnMemClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnMemClear.Location = new System.Drawing.Point(26, 104);
            this.btnMemClear.Name = "btnMemClear";
            this.btnMemClear.Size = new System.Drawing.Size(60, 45);
            this.btnMemClear.TabIndex = 1;
            this.btnMemClear.TabStop = false;
            this.btnMemClear.Text = "MC";
            this.toolTip.SetToolTip(this.btnMemClear, "Clear All Memory");
            this.btnMemClear.UseVisualStyleBackColor = true;
            this.btnMemClear.Click += new System.EventHandler(this.btnMemClear_Click);
            this.btnMemClear.MouseHover += new System.EventHandler(this.btnMem_MouseHover);
            // 
            // btnMemRecall
            // 
            this.btnMemRecall.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnMemRecall.Location = new System.Drawing.Point(95, 104);
            this.btnMemRecall.Name = "btnMemRecall";
            this.btnMemRecall.Size = new System.Drawing.Size(60, 45);
            this.btnMemRecall.TabIndex = 2;
            this.btnMemRecall.TabStop = false;
            this.btnMemRecall.Text = "MR";
            this.toolTip.SetToolTip(this.btnMemRecall, "Memory Recall");
            this.btnMemRecall.UseVisualStyleBackColor = true;
            this.btnMemRecall.Click += new System.EventHandler(this.btnMemRecall_Click);
            this.btnMemRecall.MouseHover += new System.EventHandler(this.btnMem_MouseHover);
            // 
            // btnMemStore
            // 
            this.btnMemStore.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnMemStore.Location = new System.Drawing.Point(163, 104);
            this.btnMemStore.Name = "btnMemStore";
            this.btnMemStore.Size = new System.Drawing.Size(60, 45);
            this.btnMemStore.TabIndex = 3;
            this.btnMemStore.TabStop = false;
            this.btnMemStore.Text = "MS";
            this.toolTip.SetToolTip(this.btnMemStore, "Memory Store");
            this.btnMemStore.UseVisualStyleBackColor = true;
            this.btnMemStore.Click += new System.EventHandler(this.btnMemStore_Click);
            this.btnMemStore.MouseHover += new System.EventHandler(this.btnMem_MouseHover);
            // 
            // btnMemAdd
            // 
            this.btnMemAdd.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnMemAdd.Location = new System.Drawing.Point(231, 104);
            this.btnMemAdd.Name = "btnMemAdd";
            this.btnMemAdd.Size = new System.Drawing.Size(60, 45);
            this.btnMemAdd.TabIndex = 4;
            this.btnMemAdd.TabStop = false;
            this.btnMemAdd.Text = "M+";
            this.toolTip.SetToolTip(this.btnMemAdd, "Memory Add");
            this.btnMemAdd.UseVisualStyleBackColor = true;
            this.btnMemAdd.Click += new System.EventHandler(this.btnMemAdd_Click);
            this.btnMemAdd.MouseHover += new System.EventHandler(this.btnMem_MouseHover);
            // 
            // btnMemSub
            // 
            this.btnMemSub.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnMemSub.Location = new System.Drawing.Point(297, 104);
            this.btnMemSub.Name = "btnMemSub";
            this.btnMemSub.Size = new System.Drawing.Size(60, 45);
            this.btnMemSub.TabIndex = 5;
            this.btnMemSub.TabStop = false;
            this.btnMemSub.Text = "M-";
            this.toolTip.SetToolTip(this.btnMemSub, "Memory Subtract");
            this.btnMemSub.UseVisualStyleBackColor = true;
            this.btnMemSub.Click += new System.EventHandler(this.btnMemSub_Click);
            this.btnMemSub.MouseHover += new System.EventHandler(this.btnMem_MouseHover);
            // 
            // btnDel
            // 
            this.btnDel.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnDel.Location = new System.Drawing.Point(27, 155);
            this.btnDel.Name = "btnDel";
            this.btnDel.Size = new System.Drawing.Size(60, 45);
            this.btnDel.TabIndex = 6;
            this.btnDel.TabStop = false;
            this.btnDel.Text = "";
            this.toolTip.SetToolTip(this.btnDel, "Backspace");
            this.btnDel.UseVisualStyleBackColor = true;
            this.btnDel.Click += new System.EventHandler(this.btnDel_Click);
            // 
            // btnClearEntry
            // 
            this.btnClearEntry.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnClearEntry.Location = new System.Drawing.Point(95, 156);
            this.btnClearEntry.Name = "btnClearEntry";
            this.btnClearEntry.Size = new System.Drawing.Size(60, 45);
            this.btnClearEntry.TabIndex = 7;
            this.btnClearEntry.TabStop = false;
            this.btnClearEntry.Text = "CE";
            this.toolTip.SetToolTip(this.btnClearEntry, "Clear Entry");
            this.btnClearEntry.UseVisualStyleBackColor = true;
            this.btnClearEntry.Click += new System.EventHandler(this.btnClearEntry_Click);
            // 
            // btnClear
            // 
            this.btnClear.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnClear.Location = new System.Drawing.Point(163, 156);
            this.btnClear.Name = "btnClear";
            this.btnClear.Size = new System.Drawing.Size(60, 45);
            this.btnClear.TabIndex = 8;
            this.btnClear.TabStop = false;
            this.btnClear.Text = "C";
            this.toolTip.SetToolTip(this.btnClear, "Clear");
            this.btnClear.UseVisualStyleBackColor = true;
            this.btnClear.Click += new System.EventHandler(this.btnClear_Click);
            // 
            // btnChangeSign
            // 
            this.btnChangeSign.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnChangeSign.Location = new System.Drawing.Point(231, 156);
            this.btnChangeSign.Name = "btnChangeSign";
            this.btnChangeSign.Size = new System.Drawing.Size(60, 45);
            this.btnChangeSign.TabIndex = 9;
            this.btnChangeSign.TabStop = false;
            this.btnChangeSign.Text = "±";
            this.btnChangeSign.UseVisualStyleBackColor = true;
            this.btnChangeSign.Click += new System.EventHandler(this.btnChangeSign_Click);
            // 
            // btnSqrt
            // 
            this.btnSqrt.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnSqrt.Location = new System.Drawing.Point(297, 156);
            this.btnSqrt.Name = "btnSqrt";
            this.btnSqrt.Size = new System.Drawing.Size(60, 45);
            this.btnSqrt.TabIndex = 10;
            this.btnSqrt.TabStop = false;
            this.btnSqrt.Text = "";
            this.toolTip.SetToolTip(this.btnSqrt, "Square Root");
            this.btnSqrt.UseVisualStyleBackColor = true;
            this.btnSqrt.Click += new System.EventHandler(this.btnSqrt_Click);
            // 
            // btnNum7
            // 
            this.btnNum7.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum7.Location = new System.Drawing.Point(27, 206);
            this.btnNum7.Name = "btnNum7";
            this.btnNum7.Size = new System.Drawing.Size(60, 45);
            this.btnNum7.TabIndex = 11;
            this.btnNum7.TabStop = false;
            this.btnNum7.Text = "7";
            this.btnNum7.UseVisualStyleBackColor = true;
            this.btnNum7.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnNum8
            // 
            this.btnNum8.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum8.Location = new System.Drawing.Point(95, 206);
            this.btnNum8.Name = "btnNum8";
            this.btnNum8.Size = new System.Drawing.Size(60, 45);
            this.btnNum8.TabIndex = 12;
            this.btnNum8.TabStop = false;
            this.btnNum8.Text = "8";
            this.btnNum8.UseVisualStyleBackColor = true;
            this.btnNum8.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnNum9
            // 
            this.btnNum9.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum9.Location = new System.Drawing.Point(163, 206);
            this.btnNum9.Name = "btnNum9";
            this.btnNum9.Size = new System.Drawing.Size(60, 45);
            this.btnNum9.TabIndex = 13;
            this.btnNum9.TabStop = false;
            this.btnNum9.Text = "9";
            this.btnNum9.UseVisualStyleBackColor = true;
            this.btnNum9.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnDiv
            // 
            this.btnDiv.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnDiv.Location = new System.Drawing.Point(231, 207);
            this.btnDiv.Name = "btnDiv";
            this.btnDiv.Size = new System.Drawing.Size(60, 45);
            this.btnDiv.TabIndex = 14;
            this.btnDiv.TabStop = false;
            this.btnDiv.Text = "/";
            this.btnDiv.UseVisualStyleBackColor = true;
            this.btnDiv.Click += new System.EventHandler(this.btnOperator_Click);
            // 
            // btnPercent
            // 
            this.btnPercent.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnPercent.Location = new System.Drawing.Point(297, 207);
            this.btnPercent.Name = "btnPercent";
            this.btnPercent.Size = new System.Drawing.Size(60, 45);
            this.btnPercent.TabIndex = 15;
            this.btnPercent.TabStop = false;
            this.btnPercent.Text = "%";
            this.btnPercent.UseVisualStyleBackColor = true;
            this.btnPercent.Click += new System.EventHandler(this.btnPercent_Click);
            // 
            // btnNum4
            // 
            this.btnNum4.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum4.Location = new System.Drawing.Point(26, 257);
            this.btnNum4.Name = "btnNum4";
            this.btnNum4.Size = new System.Drawing.Size(60, 45);
            this.btnNum4.TabIndex = 16;
            this.btnNum4.TabStop = false;
            this.btnNum4.Text = "4";
            this.btnNum4.UseVisualStyleBackColor = true;
            this.btnNum4.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnNum5
            // 
            this.btnNum5.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum5.Location = new System.Drawing.Point(95, 257);
            this.btnNum5.Name = "btnNum5";
            this.btnNum5.Size = new System.Drawing.Size(60, 45);
            this.btnNum5.TabIndex = 17;
            this.btnNum5.TabStop = false;
            this.btnNum5.Text = "5";
            this.btnNum5.UseVisualStyleBackColor = true;
            this.btnNum5.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnNum6
            // 
            this.btnNum6.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum6.Location = new System.Drawing.Point(163, 257);
            this.btnNum6.Name = "btnNum6";
            this.btnNum6.Size = new System.Drawing.Size(60, 45);
            this.btnNum6.TabIndex = 18;
            this.btnNum6.TabStop = false;
            this.btnNum6.Text = "6";
            this.btnNum6.UseVisualStyleBackColor = true;
            this.btnNum6.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnMul
            // 
            this.btnMul.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnMul.Location = new System.Drawing.Point(231, 258);
            this.btnMul.Name = "btnMul";
            this.btnMul.Size = new System.Drawing.Size(60, 45);
            this.btnMul.TabIndex = 19;
            this.btnMul.TabStop = false;
            this.btnMul.Text = "*";
            this.btnMul.UseVisualStyleBackColor = true;
            this.btnMul.Click += new System.EventHandler(this.btnOperator_Click);
            // 
            // btnInverse
            // 
            this.btnInverse.Font = new System.Drawing.Font("Microsoft Sans Serif", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnInverse.Location = new System.Drawing.Point(297, 259);
            this.btnInverse.Name = "btnInverse";
            this.btnInverse.Size = new System.Drawing.Size(60, 45);
            this.btnInverse.TabIndex = 20;
            this.btnInverse.TabStop = false;
            this.btnInverse.Text = "1/x";
            this.toolTip.SetToolTip(this.btnInverse, "Inverse");
            this.btnInverse.UseVisualStyleBackColor = true;
            this.btnInverse.Click += new System.EventHandler(this.btnInverse_Click);
            // 
            // btnNum1
            // 
            this.btnNum1.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum1.Location = new System.Drawing.Point(27, 308);
            this.btnNum1.Name = "btnNum1";
            this.btnNum1.Size = new System.Drawing.Size(60, 45);
            this.btnNum1.TabIndex = 21;
            this.btnNum1.TabStop = false;
            this.btnNum1.Text = "1";
            this.btnNum1.UseVisualStyleBackColor = true;
            this.btnNum1.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnNum2
            // 
            this.btnNum2.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum2.Location = new System.Drawing.Point(95, 308);
            this.btnNum2.Name = "btnNum2";
            this.btnNum2.Size = new System.Drawing.Size(60, 45);
            this.btnNum2.TabIndex = 22;
            this.btnNum2.TabStop = false;
            this.btnNum2.Text = "2";
            this.btnNum2.UseVisualStyleBackColor = true;
            this.btnNum2.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnNum3
            // 
            this.btnNum3.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum3.Location = new System.Drawing.Point(163, 308);
            this.btnNum3.Name = "btnNum3";
            this.btnNum3.Size = new System.Drawing.Size(60, 45);
            this.btnNum3.TabIndex = 23;
            this.btnNum3.TabStop = false;
            this.btnNum3.Text = "3";
            this.btnNum3.UseVisualStyleBackColor = true;
            this.btnNum3.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnSub
            // 
            this.btnSub.Font = new System.Drawing.Font("Symbol", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnSub.Location = new System.Drawing.Point(231, 308);
            this.btnSub.Name = "btnSub";
            this.btnSub.Size = new System.Drawing.Size(60, 45);
            this.btnSub.TabIndex = 24;
            this.btnSub.TabStop = false;
            this.btnSub.Text = "-";
            this.btnSub.UseVisualStyleBackColor = true;
            this.btnSub.Click += new System.EventHandler(this.btnOperator_Click);
            // 
            // btnEqual
            // 
            this.btnEqual.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnEqual.Location = new System.Drawing.Point(297, 308);
            this.btnEqual.Name = "btnEqual";
            this.btnEqual.Size = new System.Drawing.Size(60, 95);
            this.btnEqual.TabIndex = 25;
            this.btnEqual.TabStop = false;
            this.btnEqual.Text = "=";
            this.btnEqual.UseVisualStyleBackColor = true;
            this.btnEqual.Click += new System.EventHandler(this.btnEqual_Click);
            // 
            // btnNum0
            // 
            this.btnNum0.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnNum0.Location = new System.Drawing.Point(25, 358);
            this.btnNum0.Name = "btnNum0";
            this.btnNum0.Size = new System.Drawing.Size(130, 45);
            this.btnNum0.TabIndex = 26;
            this.btnNum0.TabStop = false;
            this.btnNum0.Text = "0";
            this.btnNum0.UseVisualStyleBackColor = true;
            this.btnNum0.Click += new System.EventHandler(this.btnNum_Click);
            // 
            // btnDot
            // 
            this.btnDot.Font = new System.Drawing.Font("Symbol", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnDot.Location = new System.Drawing.Point(163, 357);
            this.btnDot.Name = "btnDot";
            this.btnDot.Size = new System.Drawing.Size(60, 45);
            this.btnDot.TabIndex = 27;
            this.btnDot.TabStop = false;
            this.btnDot.Text = ".";
            this.btnDot.UseVisualStyleBackColor = true;
            this.btnDot.Click += new System.EventHandler(this.btnDot_Click);
            // 
            // btnAdd
            // 
            this.btnAdd.Font = new System.Drawing.Font("Symbol", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.btnAdd.Location = new System.Drawing.Point(231, 358);
            this.btnAdd.Name = "btnAdd";
            this.btnAdd.Size = new System.Drawing.Size(60, 45);
            this.btnAdd.TabIndex = 28;
            this.btnAdd.TabStop = false;
            this.btnAdd.Text = "+";
            this.btnAdd.UseVisualStyleBackColor = true;
            this.btnAdd.Click += new System.EventHandler(this.btnOperator_Click);
            // 
            // frmCalculator
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(384, 423);
            this.Controls.Add(this.btnAdd);
            this.Controls.Add(this.btnDot);
            this.Controls.Add(this.btnNum0);
            this.Controls.Add(this.btnEqual);
            this.Controls.Add(this.btnSub);
            this.Controls.Add(this.btnNum3);
            this.Controls.Add(this.btnNum2);
            this.Controls.Add(this.btnNum1);
            this.Controls.Add(this.btnInverse);
            this.Controls.Add(this.btnMul);
            this.Controls.Add(this.btnNum6);
            this.Controls.Add(this.btnNum5);
            this.Controls.Add(this.btnNum4);
            this.Controls.Add(this.btnPercent);
            this.Controls.Add(this.btnDiv);
            this.Controls.Add(this.btnNum9);
            this.Controls.Add(this.btnNum8);
            this.Controls.Add(this.btnNum7);
            this.Controls.Add(this.btnSqrt);
            this.Controls.Add(this.btnChangeSign);
            this.Controls.Add(this.btnClear);
            this.Controls.Add(this.btnClearEntry);
            this.Controls.Add(this.btnDel);
            this.Controls.Add(this.btnMemSub);
            this.Controls.Add(this.btnMemAdd);
            this.Controls.Add(this.btnMemStore);
            this.Controls.Add(this.btnMemRecall);
            this.Controls.Add(this.btnMemClear);
            this.Controls.Add(this.pnlView);
            this.KeyPreview = true;
            this.MaximizeBox = false;
            this.Name = "frmCalculator";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Standard Calculator ";
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.frmCalculator_KeyDown);
            this.pnlView.ResumeLayout(false);
            this.pnlView.PerformLayout();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Panel pnlView;
        private System.Windows.Forms.Button btnMemClear;
        private System.Windows.Forms.Button btnMemRecall;
        private System.Windows.Forms.Button btnMemStore;
        private System.Windows.Forms.Button btnMemAdd;
        private System.Windows.Forms.Button btnMemSub;
        private System.Windows.Forms.Button btnDel;
        private System.Windows.Forms.Button btnClearEntry;
        private System.Windows.Forms.Button btnClear;
        private System.Windows.Forms.Button btnChangeSign;
        private System.Windows.Forms.Button btnSqrt;
        private System.Windows.Forms.Button btnNum7;
        private System.Windows.Forms.Button btnNum8;
        private System.Windows.Forms.Button btnNum9;
        private System.Windows.Forms.Button btnDiv;
        private System.Windows.Forms.Button btnPercent;
        private System.Windows.Forms.Button btnNum4;
        private System.Windows.Forms.Button btnNum5;
        private System.Windows.Forms.Button btnNum6;
        private System.Windows.Forms.Button btnMul;
        private System.Windows.Forms.Button btnInverse;
        private System.Windows.Forms.Button btnNum1;
        private System.Windows.Forms.Button btnNum2;
        private System.Windows.Forms.Button btnNum3;
        private System.Windows.Forms.Button btnSub;
        private System.Windows.Forms.Button btnEqual;
        private System.Windows.Forms.Button btnNum0;
        private System.Windows.Forms.Button btnDot;
        private System.Windows.Forms.Button btnAdd;
        private System.Windows.Forms.ToolTip toolTip;
        private System.Windows.Forms.TextBox txtInput;
        private System.Windows.Forms.TextBox txtEquation;
    }
}

