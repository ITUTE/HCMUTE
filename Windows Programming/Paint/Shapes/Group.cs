using System;
using System.Collections.Generic;
using System.Drawing;

namespace Paint.Shapes
{
    public class Group : MyShapes
    {
        public List<MyShapes> shapesInGroup = new List<MyShapes>();

        /// <summary>
        /// Dùng để xác định hình chữ nhật bao quanh đối tượng shape 
        /// </summary>
        public Rectangle RectShape { get; set; }
        public int Count => shapesInGroup.Count;

        public Group()
        {
            Pen = new Pen(Color.Black);
        }
        public void Add(MyShapes shape)
        {
            shapesInGroup.Add(shape);
        }

        public override void SelectPoint(Point eLocation)
        {
            SelectEdge(eLocation);
        }

        public override void Zoom(Point firstPoint, Point eLocation)
        {
            shapesInGroup.ForEach(shape =>
            {
                shape.SelectedEdge = this.SelectedEdge;
                shape.Zoom(firstPoint, eLocation);
            });
        }

        public override void AddPoint(Point p)
        {

        }

        public override void Draw(Graphics gp)
        {
            FindGroupRegion();
            RectShape = DetectBound();
            using (var pen = new Pen(Color.Blue) { Width = 2, DashStyle = System.Drawing.Drawing2D.DashStyle.Dash })
            {
                gp.DrawRectangle(pen, RectShape);
                foreach (var shape in shapesInGroup)
                {
                    shape.IsSelected = this.IsSelected;
                    shape.IsFilled = this.IsFilled;
                    shape.IsDrawBorder = this.IsDrawBorder;
                    shape.Draw(gp);
                }
            }
        }

        public override void Move(Point firstPoint, Point eLocation)
        {
            shapesInGroup.ForEach(shape => shape.Move(firstPoint, eLocation));
        }

        public void FindGroupRegion()
        {
            int minX = Int32.MaxValue, maxX = Int32.MinValue, minY = Int32.MaxValue, maxY = Int32.MinValue;
            for (int i = 0; i < shapesInGroup.Count; i++)
            {
                MyShapes shape = shapesInGroup[i] as MyShapes;
                if (shape is MyCurve curve)
                {
                    FindCurveRegion(curve);
                }
                else if (shape is MyPolygon polygon)
                {
                    FindPolygonRegion(polygon);
                }
                if (shape.P1.X < minX) minX = shape.P1.X;
                if (shape.P2.X < minX) minX = shape.P2.X;
                if (shape.P1.Y < minY) minY = shape.P1.Y;
                if (shape.P2.Y < minY) minY = shape.P2.Y;
                if (shape.P1.X > maxX) maxX = shape.P1.X;
                if (shape.P2.X > maxX) maxX = shape.P2.X;
                if (shape.P1.Y > maxY) maxY = shape.P1.Y;
                if (shape.P2.Y > maxY) maxY = shape.P2.Y;
            }
            this.P1 = new Point(minX, minY);
            this.P2 = new Point(maxX, maxY);
        }

        private void FindPolygonRegion(MyPolygon polygon)
        {
            int minX = Int32.MaxValue, maxX = Int32.MinValue, minY = Int32.MaxValue, maxY = Int32.MinValue;
            polygon.LPoints.ForEach(p =>
            {
                if (minX > p.X) minX = p.X;
                if (minY > p.Y) minY = p.Y;
                if (maxX < p.X) maxX = p.X;
                if (maxY < p.Y) maxY = p.Y;
            });
            polygon.P1 = new Point(minX, minY);
            polygon.P2 = new Point(maxX, maxY);
        }

        private void FindCurveRegion(MyCurve curve)
        {
            int minX = Int32.MaxValue, maxX = Int32.MinValue, minY = Int32.MaxValue, maxY = Int32.MinValue;
            curve.LPoints.ForEach(p =>
            {
                if (minX > p.X) minX = p.X;
                if (minY > p.Y) minY = p.Y;
                if (maxX < p.X) maxX = p.X;
                if (maxY < p.Y) maxY = p.Y;
            });
            curve.P1 = new Point(minX, minY);
            curve.P2 = new Point(maxX, maxY);
        }

        public override bool Select(Point p)
        {
            if (p.X >= P1.X && p.X <= P2.X && p.Y >= P1.Y && p.Y <= P2.Y)
                return true;
            return false;
        }
    }
}