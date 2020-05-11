using System.Collections.Generic;
using System.Drawing;

namespace Paint.Shapes
{
    public class MyCurve : MyShapes
    {
        protected int selectedPoint;
        public MyCurve(Pen myPen, Brush myBrush) : base(myPen, myBrush)
        {
            LPoints = new List<Point>();
            Pen.StartCap = Pen.EndCap = System.Drawing.Drawing2D.LineCap.Round;
        }

        public List<Point> LPoints;

        public override void AddPoint(Point p)
        {
            LPoints.Add(p);
        }

        public override void Draw(Graphics gp)
        {
            gp.DrawCurve(Pen, LPoints.ToArray());
            GPPaths.Reset();
            GPPaths.AddCurve(LPoints.ToArray());
            if (IsSelected)
            {
                using (var brush = new SolidBrush(Color.Blue))
                    LPoints.ForEach(p => gp.FillRectangle(brush, new Rectangle(p.X - 4, p.Y - 4, 8, 8)));
            }
        }

        public override void Move(Point firstPoint, Point eLocation)
        {
            int dx = eLocation.X - firstPoint.X;
            int dy = eLocation.Y - firstPoint.Y;
            for (int i = 0; i < LPoints.Count; i++)
                LPoints[i] = new Point(LPoints[i].X + dx, LPoints[i].Y + dy);
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