using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace Paint.Shapes
{
    class MyClosedCurve : MyCurve
    {
        public MyClosedCurve(Pen myPen, Brush myBrush) : base(myPen, myBrush)
        {
            LPoints = new List<Point>();
            Pen.StartCap = Pen.EndCap = LineCap.Round;
        }
        public override void Draw(Graphics gp)
        {
            //Closed Curve phải có tối thiểu 3 điểm để vẽ 
            //Nếu ít hơn 3 điểm, thì vẽ các điểm hiện có 
            if (LPoints.Count < 3)
            {
                using (var tmpBrush = new SolidBrush(Pen.Color))
                    LPoints.ForEach(p => gp.FillRectangle(tmpBrush, new Rectangle(p.X - 3, p.Y - 3, 6, 6)));
                return;
            }
            GPPaths.Reset();
            GPPaths.AddClosedCurve(LPoints.ToArray());
            if (IsFilled)
                gp.FillClosedCurve(Brush, LPoints.ToArray());
            if (IsDrawBorder)
                gp.DrawClosedCurve(Pen, LPoints.ToArray());
            if (IsSelected)
            {
                using (var brush = new SolidBrush(Color.Blue))
                    LPoints.ForEach(p => gp.FillRectangle(brush, new Rectangle(p.X - 3, p.Y - 3, 6, 6)));
            }
        }

        public override void AddPoint(Point p)
        {
            LPoints.Add(p);
        }

        public override void SelectPoint(Point eLocation)
        {
            base.SelectPoint(eLocation);
        }
    }
}
