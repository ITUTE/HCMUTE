using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Calculator
{
    public partial class frmCalculator : Form
    {
        #region Fields
        private double result = 0;
        private double memoryValue = 0;
        private string op = "";
        #endregion
        public frmCalculator()
        {
            InitializeComponent();
        }
        #region Methods
        private void Calc()
        {
            switch (op)
            {
                case "+": result += Convert.ToDouble(txtInput.Text); break;
                case "-": result -= Convert.ToDouble(txtInput.Text); break;
                case "*": result *= Convert.ToDouble(txtInput.Text); break;
                case "/": result /= Convert.ToDouble(txtInput.Text); break;
            }
        }
        #endregion
        #region Events
        #region Memory
        private void btnMemClear_Click(object sender, EventArgs e)
        {
            memoryValue = 0;
        }

        private void btnMemRecall_Click(object sender, EventArgs e)
        {
            txtInput.Text = memoryValue.ToString();
        }

        private void btnMemStore_Click(object sender, EventArgs e)
        {
            memoryValue = Convert.ToDouble(txtInput.Text);
            //txtInput.Text = "0";
        }

        private void btnMemAdd_Click(object sender, EventArgs e)
        {
            memoryValue += Convert.ToDouble(txtInput.Text);
            //txtInput.Text = "0";
        }

        private void btnMemSub_Click(object sender, EventArgs e)
        {
            memoryValue -= Convert.ToDouble(txtInput.Text);
            //txtInput.Text = "0";
        }
        #endregion
        #region Clear
        private void btnDel_Click(object sender, EventArgs e)
        {
            if (txtInput.Text != "0")
                txtInput.Text = txtInput.Text.Remove(txtInput.Text.Length - 1);
            if (txtInput.Text == "")
                txtInput.Text = "0";
        }

        private void btnClearEntry_Click(object sender, EventArgs e)
        {
            txtInput.Text = "0";
        }

        private void btnClear_Click(object sender, EventArgs e)
        {
            txtInput.Text = "0";
            txtEquation.Text = "0";
            result = 0;
            op = "";
        }
        #endregion
        private void btnChangeSign_Click(object sender, EventArgs e)
        {
            if (txtInput.Text!="0")
            {
                if (txtInput.Text[0] == '-')
                    txtInput.Text = txtInput.Text.Substring(1);
                else txtInput.Text = "-" + txtInput.Text;
            }
        }

        private void btnSqrt_Click(object sender, EventArgs e)
        {
            txtInput.Text = (Math.Sqrt(Convert.ToDouble(txtInput.Text))).ToString();
        }

        private void btnDot_Click(object sender, EventArgs e)
        {
            if (!txtInput.Text.Contains("."))
                txtInput.Text += ".";
        }

        private void btnInverse_Click(object sender, EventArgs e)
        {
            if (txtInput.Text != "0")
                txtInput.Text = (1.0 / Convert.ToDouble(txtInput.Text)).ToString();
            else if (txtInput.Text == "0")
                MessageBox.Show("Divided by zero!", "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
            else if (txtEquation.Text.Contains("="))
            {
                result = 1.0 / result;
                txtInput.Text = result.ToString();
                txtEquation.Text = txtInput.Text + "=";
            }
        }

        private void btnEqual_Click(object sender, EventArgs e)
        {
            if (op != "")
            {
                Calc();
                if (txtEquation.Text == "0")
                    txtEquation.Text = txtInput.Text + "=";
                else txtEquation.Text += txtInput.Text + "=";
                txtInput.Text = result.ToString();
            }
            else txtEquation.Text = txtInput.Text + "=";
            op = "=";
        }

        private void frmCalculator_KeyDown(object sender, KeyEventArgs e)
        {
            switch (e.KeyCode)
            {
                case Keys.D0: case Keys.NumPad0:    btnNum_Click(btnNum0, e);  break;
                case Keys.D1: case Keys.NumPad1:    btnNum_Click(btnNum1, e);   break;
                case Keys.D2: case Keys.NumPad2:    btnNum_Click(btnNum2, e);   break;
                case Keys.D3: case Keys.NumPad3:    btnNum_Click(btnNum3, e);   break;
                case Keys.D4: case Keys.NumPad4:    btnNum_Click(btnNum4, e);   break;
                case Keys.D5: case Keys.NumPad5:    btnNum_Click(btnNum5, e);   break;
                case Keys.D6: case Keys.NumPad6:    btnNum_Click(btnNum6, e);   break;
                case Keys.D7: case Keys.NumPad7:    btnNum_Click(btnNum7, e);   break;
                case Keys.D8: case Keys.NumPad8:    btnNum_Click(btnNum8, e);   break;
                case Keys.D9: case Keys.NumPad9:    btnNum_Click(btnNum9, e);   break;
                case Keys.Back:                     btnDel_Click(btnDel, e);    break;
                case Keys.Enter:                    btnEqual_Click(btnEqual, e);break;
                case Keys.Delete:       btnClearEntry_Click(btnClearEntry, e);  break;
            }
        }
        #endregion

        private void btnOperator_Click(object sender, EventArgs e)
        {
            Button button = sender as Button;
            if (op=="" || op=="=")
            {
                op = button.Text;
                result = Convert.ToDouble(txtInput.Text);
                txtEquation.Text = txtInput.Text + button.Text;
                txtInput.Text = "0";
            }
            else
            {
                op = button.Text;
                txtEquation.Text = txtEquation.Text.Substring(0, txtEquation.Text.Length - 1) + op;
            }
        }

        #region Numbers
        private void btnNum_Click(object sender, EventArgs e)
        {
            Button button = sender as Button;
            if (txtInput.Text == "0" || op == "=")
            {
                txtInput.Text = button.Text;
                if (op == "=")
                {
                    op = "";
                    txtEquation.Text = "0";
                    result = 0;
                }
            }
            else if (txtInput.Text == "-" && button.Text == "0")
            { }
            else
            {
                try
                {
                    Convert.ToDouble(txtInput.Text + button.Text);
                    txtInput.Text += button.Text;
                }
                catch (OverflowException over)
                {
                    MessageBox.Show(over.Message);
                }
            }
        }
        #endregion

        private void btnPercent_Click(object sender, EventArgs e)
        {
            txtInput.Text = (Convert.ToDouble(txtInput.Text) / 100).ToString();
        }

        private void btnMem_MouseHover(object sender, EventArgs e)
        {
            toolTip.SetToolTip(btnMemAdd, $"Memory Add\nM={memoryValue}");
            toolTip.SetToolTip(btnMemSub, $"Memory Subtract\nM={memoryValue}");
            toolTip.SetToolTip(btnMemClear, $"Clear Memory\nM={memoryValue}");
            toolTip.SetToolTip(btnMemRecall, $"Memory Recall\nM={memoryValue}");
            toolTip.SetToolTip(btnMemStore, $"Memory Store\nM={memoryValue}");
        }
    }
}
