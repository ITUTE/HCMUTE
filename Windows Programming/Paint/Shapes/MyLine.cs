using System;
using System.Drawing;

namespace Paint.Shapes
{
    public class MyLine : MyShapes
    {
        private int selectedPoint;
        public MyLine(Pen myPen, Brush myBrush) : base(myPen, myBrush)
        {
            Pen.StartCap = Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;
        }

        public override void Draw(Graphics gp)
        {
            gp.DrawLine(Pen, P1, P2);
            GPPaths.Reset();
            GPPaths.AddLine(P1, P2);
            if (IsSelected)
            {
                Brush brush = new SolidBrush(Color.Blue);
                gp.FillRectangle(brush, P1.X - 3, P1.Y - 3, 6, 6);
                gp.FillRectangle(brush, P2.X - 3, P2.Y - 3, 6, 6);
            }
        }

        public override void AddPoint(Point p)
        {
            P2 = p;
        }

        public override void Zoom(Point firstPoint, Point eLocation)
        {
            if (selectedPoint == 1)
            {
                P1.X += eLocation.X - firstPoint.X;
                P1.Y += eLocation.Y - firstPoint.Y;
            }
            else
            {
                P2.X += eLocation.X - firstPoint.X;
                P2.Y += eLocation.Y - firstPoint.Y;
            }
        }

        public override void SelectPoint(Point eLocation)
        {
            double d1 = Math.Pow(eLocation.X - P1.X, 2) + Math.Pow(eLocation.Y - P1.Y, 2);
            double d2 = Math.Pow(eLocation.X - P2.X, 2) + Math.Pow(eLocation.Y - P2.Y, 2);
            if (d1 < d2)
                selectedPoint = 1;
            else
                selectedPoint = 2;
        }

        public override void Move(Point firstPoint, Point eLocation)
        {
            MovePoint(firstPoint, eLocation);
        }
    }
}