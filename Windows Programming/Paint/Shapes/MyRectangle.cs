using System.Drawing;

namespace Paint.Shapes
{
    public class MyRectangle : MyShapes
    {
        /// <summary>
        /// Dùng để xác định hình chữ nhật bao quanh đối tượng shape 
        /// </summary>
        public Rectangle RectShape { get; set; }

        public MyRectangle(Pen myPen, Brush myBrush) : base(myPen, myBrush)
        {

        }

        public override void Draw(Graphics gp)
        {
            RectShape = DetectBound();
            GPPaths.Reset();
            GPPaths.AddRectangle(RectShape);
            if (IsFilled)
                gp.FillRectangle(Brush, RectShape);
            if (IsDrawBorder) gp.DrawRectangle(Pen, RectShape);
            if (IsSelected)
            {
                Brush brush = new SolidBrush(Color.Blue);
                gp.FillRectangle(brush, P1.X - 4, P1.Y - 4, 8, 8);
                gp.FillRectangle(brush, P1.X - 4, P2.Y - 4, 8, 8);
                gp.FillRectangle(brush, P2.X - 4, P1.Y - 4, 8, 8);
                gp.FillRectangle(brush, P2.X - 4, P2.Y - 4, 8, 8);
            }
        }

        public override void SelectPoint(Point eLocation)
        {
            SelectEdge(eLocation);
        }

        public override void AddPoint(Point p)
        {
            P2 = p;
        }

        public override void Zoom(Point firstPoint, Point eLocation)
        {
            ZoomEdge(firstPoint, eLocation);
        }

        public override void Move(Point firstPoint, Point eLocation)
        {
            MovePoint(firstPoint, eLocation);
        }
    }
}