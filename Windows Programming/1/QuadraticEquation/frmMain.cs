using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace QuadraticEquation
{
    public partial class frmMain : Form
    {
        public frmMain()
        {
            InitializeComponent();
        }

        private void btnSolve_Click(object sender, EventArgs e)
        {
            QuadEquation equation = new QuadEquation(txtNumA.Text, txtNumB.Text, txtNumC.Text);
            txtResult.Text = equation.Solve();
        }

        private void btnDel_Click(object sender, EventArgs e)
        {
            txtNumA.Clear();
            txtNumB.Clear();
            txtNumC.Clear();
            txtResult.Clear();
        }

        private void btnExit_Click(object sender, EventArgs e)
        {
            if (MessageBox.Show(
                "Do you want to exit?",
                "Exit",
                MessageBoxButtons.YesNo,
                MessageBoxIcon.Question
                ) == DialogResult.Yes)
            {
                Application.Exit();
            }
        }

        private void txtNumA_Leave(object sender, EventArgs e)
        {
            if (txtNumA.Text != "")
            {
                try
                {
                    Convert.ToDouble(txtNumA.Text);
                    txtResult.Clear();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    txtNumA.Clear();
                    txtNumA.Focus();
                }
            }
        }

        private void txtNumB_Leave(object sender, EventArgs e)
        {
            if (txtNumB.Text != "")
            {
                try
                {
                    Convert.ToDouble(txtNumB.Text);
                    txtResult.Clear();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    txtNumB.Clear();
                    txtNumB.Focus();
                }
            }
        }

        private void txtNumC_Leave(object sender, EventArgs e)
        {
            if (txtNumC.Text != "")
            {
                try
                {
                    Convert.ToDouble(txtNumC.Text);
                    txtResult.Clear();
                }
                catch (Exception ex)
                {
                    MessageBox.Show(ex.Message, "Error", MessageBoxButtons.OK, MessageBoxIcon.Error);
                    txtNumC.Clear();
                    txtNumC.Focus();
                }
            }
        }
    }
}
