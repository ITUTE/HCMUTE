using System.Collections.Generic;
using System.Drawing;

namespace Paint.Shapes
{
    public class MyPath : MyShapes
    {
        public List<Point> LPoints;
        protected int selectedPoint;

        public MyPath(Pen myPen, Brush myBrush) : base(myPen, myBrush)
        {
            LPoints = new List<Point>();
            Pen.StartCap = Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;
        }

        public override void AddPoint(Point p)
        {
            LPoints.Add(p);
        }

        public override void Draw(Graphics gp)
        {
            GPPaths.Reset();
            GPPaths.AddCurve(LPoints.ToArray());
            if (IsFilled)
                gp.FillPath(Brush, GPPaths);
            if (IsDrawBorder)
                gp.DrawPath(Pen, GPPaths);
            if (IsSelected)
            {
                using (Brush brush = new SolidBrush(Color.Blue))
                {
                    for (int i = 0; i < LPoints.Count; i += 4)
                        gp.FillRectangle(brush, LPoints[i].X - 4, LPoints[i].Y - 4, 8, 8);
                }
            }
        }

        public override void SelectPoint(Point eLocation)
        {
            for (int i = 0; i < LPoints.Count; i++)
            {
                if ((LPoints[i].X - 10 <= eLocation.X && eLocation.X <= LPoints[i].X + 10)
                    && (LPoints[i].Y - 10 <= eLocation.Y && eLocation.Y <= LPoints[i].Y + 10))
                {
                    selectedPoint = i;
                    return;
                }
            }
            selectedPoint = -1;
        }

        public override void Move(Point firstPoint, Point eLocation)
        {
            int dx = eLocation.X - firstPoint.X;
            int dy = eLocation.Y - firstPoint.Y;
            for (int i = 0; i < LPoints.Count; i++)
                LPoints[i] = new Point(LPoints[i].X + dx, LPoints[i].Y + dy);
        }

        public override void Zoom(Point firstPoint, Point eLocation)
        {
            if (selectedPoint < 0) return;
            int dx = eLocation.X - firstPoint.X;
            int dy = eLocation.Y - firstPoint.Y;
            for (int i = selectedPoint - 1; i <= selectedPoint + 1; i++)
            {
                if (i < 0 || i >= LPoints.Count) continue;
                else
                    LPoints[i] = new Point(LPoints[i].X + dx, LPoints[i].Y + dy);
            }
        }
    }
}