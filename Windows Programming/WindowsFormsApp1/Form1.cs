using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp1
{
    public partial class Form1 : Form
    {
        Graphics gp; Color myColor;
        Pen myPen;
        bool bLine = true;
        List<clsDrawObject> lstObject = new List<clsDrawObject>();
        bool isPress = false;
        public Form1()
        {
            InitializeComponent();
            gp = this.pnMain.CreateGraphics();
            myColor = Color.Red;
            myPen = new Pen(myColor);
        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }

        private void pnMain_Paint(object sender, PaintEventArgs e)
        {
            for (int i = 0; i < this.lstObject.Count; i++)
            {
                this.lstObject[i].Draw(this.gp, this.myPen);
            }
        }

        private void pnMain_MouseDown(object sender, MouseEventArgs e)
        {
            this.isPress = true;
            clsDrawObject myObj;
            myObj = new clsLine();
            myObj.p1 = e.Location;
            this.lstObject.Add(myObj);
        }

        private void pnMain_MouseMove(object sender, MouseEventArgs e)
        {
            if (this.isPress == true)
            {
                this.lstObject[this.lstObject.Count - 1].p2 = e.Location;
                this.pnMain.Refresh();
            }
        }

        private void pnMain_MouseUp(object sender, MouseEventArgs e)
        {
            this.isPress = false;
            this.lstObject[this.lstObject.Count - 1].p2 = e.Location;
            this.pnMain.Refresh();
            this.bLine = false;
        }
    }
    public abstract class clsDrawObject
    {
        public Point p1;
        public Point p2;
        public abstract void Draw(Graphics myGp, Pen myPen);
    };
    public class clsLine : clsDrawObject
    {
        public override void Draw(Graphics myGp, Pen myPen)
        {
            myGp.DrawLine(myPen, this.p1, this.p2);
        }
    };

}
