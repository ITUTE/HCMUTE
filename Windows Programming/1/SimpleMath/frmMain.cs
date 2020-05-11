using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SimpleMath
{
    public partial class frmMain : Form
    {
        #region Fields
        private MyNum num1;
        private MyNum num2;
        #endregion
        #region Properties
        public MyNum Num1 { get => num1; set => num1 = value; }
        public MyNum Num2 { get => num2; set => num2 = value; }
        #endregion
        #region Constructor
        public frmMain()
        {
            InitializeComponent();
            Num1 = new MyNum(0);
            Num2 = new MyNum(0);
        }
        #endregion
        #region Events
        private void btnSum_Click(object sender, EventArgs e)
        {
            txtResult.Text = (Num1 + Num2).ToString();
        }

        private void btnDec_Click(object sender, EventArgs e)
        {
            txtResult.Text = (Num1 - Num2).ToString();
        }

        private void btnMul_Click(object sender, EventArgs e)
        {
            txtResult.Text = (Num1 * Num2).ToString();
        }

        private void btnDiv_Click(object sender, EventArgs e)
        {
            try
            {
                txtResult.Text = (Num1 / Num2).ToString();
            }
            catch (DivideByZeroException ex)
            {
                MessageBox.Show(ex.Message, "Error!");
                txtNum2.Clear();
                txtNum2.Focus();
            }
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show("Do you want to exit?", "Exit", MessageBoxButtons.YesNo, MessageBoxIcon.Question) == DialogResult.Yes)
            {
                Application.Exit();
            }
        }

        private void txtNum1_Leave(object sender, EventArgs e)
        {
            try
            {
                Num1 = new MyNum(txtNum1.Text);
                txtResult.Clear();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtNum1.Clear();
                txtNum1.Focus();
            }
        }

        private void txtNum2_Leave(object sender, EventArgs e)
        {
            try
            {
                Num2 = new MyNum(txtNum2.Text);
                txtResult.Clear();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                txtNum2.Clear();
                txtNum2.Focus();
            }
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            txtNum1.Clear();
            txtNum2.Clear();
            txtResult.Clear();
        }
        #endregion
    }
}
