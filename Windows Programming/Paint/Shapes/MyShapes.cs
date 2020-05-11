using System;
using System.Drawing;
using System.Drawing.Drawing2D;

namespace Paint.Shapes
{
    public abstract class MyShapes
    {
        #region Properties
        public Pen Pen { get; set; }
        public Brush Brush { get; set; }
        public Point P1 = new Point();
        public Point P2 = new Point();

        /// <summary>
        /// Dùng để chứa đường bao của hình 
        /// </summary>
        public GraphicsPath GPPaths { get; set; } = new GraphicsPath();

        /// <summary>
        /// True nếu hình là một hình được tô 
        /// </summary>
        public bool IsFilled { get; set; }

        /// <summary>
        /// True nếu như lựa chọn vẽ luôn cả đường viền của hình dạng 
        /// </summary>
        public bool IsDrawBorder { get; set; }

        /// <summary>
        /// True nếu hình được người dùng chọn 
        /// </summary>
        public bool IsSelected { get; set; }

        /// <summary>
        /// Dùng để xác định cạnh nào của biên của hình đang được chọn 
        /// </summary>
        public Edge SelectedEdge { get; set; }
        #endregion

        #region Constructors
        public MyShapes()
        {

        }

        public MyShapes(Pen myPen, Brush myBrush)
        {
            this.Pen = myPen;
            this.Brush = myBrush;
        }
        #endregion

        #region Methods 
        /// <summary>
        /// Dùng để xác định một hình có được chọn hay không 
        /// </summary>
        /// <param name="p">Vị trí điểm được xét có thuộc hình hay không </param>
        /// <returns>True nếu hình được chọn </returns>
        public virtual bool Select(Point p)
        {
            if (IsFilled) return GPPaths.IsVisible(p);
            return GPPaths.IsOutlineVisible(p, Pen);
        }

        /// <summary>
        /// Dùng để di chuyển một điểm được chon 
        /// </summary>
        /// <param name="firstPoint">Tọa độ làm mốc </param>
        /// <param name="eLocation">Điểm cần di chuyển </param>
        protected void MovePoint(Point firstPoint, Point eLocation)
        {
            int dx = eLocation.X - firstPoint.X;
            int dy = eLocation.Y - firstPoint.Y;
            P1 = new Point(P1.X + dx, P1.Y + dy);
            P2 = new Point(P2.X + dx, P2.Y + dy);
        }

        /// <summary>
        /// Dùng để xác định đường bao của những hình dạng được vẽ bên trong một hình chữ nhật 
        /// </summary>
        /// <returns></returns>
        protected Rectangle DetectBound()
        {
            int X = Math.Min(P1.X, P2.X);
            int Y = Math.Min(P1.Y, P2.Y);
            int dx = Math.Abs(P1.X - P2.X);
            int dy = Math.Abs(P1.Y - P2.Y);
            return new Rectangle(X, Y, dx, dy);
        }

        /// <summary>
        /// Dùng để xác định điểm đang chọn thuộc cảnh nào của bound mỗi hình 
        /// </summary>
        /// <param name="eLocation">Điểm được click </param>
        protected void SelectEdge(Point eLocation)
        {
            if (P1.X - 20 <= eLocation.X && eLocation.X <= P1.X + 20)
                SelectedEdge = Edge.Left;
            else if (P2.X - 20 <= eLocation.X && eLocation.X <= P2.X + 20)
                SelectedEdge = Edge.Right;
            else if (P1.Y - 20 <= eLocation.Y && eLocation.Y <= P1.Y + 20)
                SelectedEdge = Edge.Top;
            else if (P2.Y - 20 <= eLocation.Y && eLocation.Y <= P2.Y + 20)
                SelectedEdge = Edge.Bottom;
            else
                SelectedEdge = Edge.None;
        }

        /// <summary>
        /// Dùng để zoom hình với cạnh được chọn 
        /// </summary>
        /// <param name="firstPoint"></param>
        /// <param name="eLocation"></param>
        protected void ZoomEdge(Point firstPoint, Point eLocation)
        {
            switch (SelectedEdge)
            {
                case Edge.Left:
                    P1.X += eLocation.X - firstPoint.X;
                    break;
                case Edge.Right:
                    P2.X += eLocation.X - firstPoint.X;
                    break;
                case Edge.Top:
                    P1.Y += eLocation.Y - firstPoint.Y;
                    break;
                case Edge.Bottom:
                    P2.Y += eLocation.Y - firstPoint.Y;
                    break;
            }
        }
        #endregion

        #region Abstract Methods
        /// <summary>
        /// Thêm 1 điểm vào hình, nếu hình đó được vẽ bằng cách nối nhiều điểm (do người dùng chọn) lại với nhau 
        /// </summary>
        /// <param name="p">Point được thêm vào hình </param>
        public abstract void AddPoint(Point p);

        /// <summary>
        /// Dùng để vẽ hình 
        /// </summary>
        /// <param name="gp">Đối tượng graphics dùng để vẽ </param>
        public abstract void Draw(Graphics gp);

        /// <summary>
        /// Dùng khi click chuột, nhằm xác định điểm được chọn thuộc điểm nào hoặc cạnh nào của hình
        /// </summary>
        /// <param name="eLocation">Vị trí hiện tại của trỏ chuột, nơi sự kiện Click sinh ra </param>
        public abstract void SelectPoint(Point eLocation);

        /// <summary>
        /// Dùng để Zoom đối tượng được chọn 
        /// </summary>
        /// <param name="firstPoint">Điểm dùng để làm mốc </param>
        /// <param name="eLocation">Vị trí hiện tại của trỏ chuột </param>
        public abstract void Zoom(Point firstPoint, Point eLocation);

        /// <summary>
        /// Moves selected shape
        /// </summary>
        /// <param name="firstPoint"></param>
        /// <param name="eLocation"></param>
        public abstract void Move(Point firstPoint, Point eLocation);
        #endregion

        /// <summary>
        /// Enum dùng để chứa định nghĩa các cạnh của một hình, dùng cho các hình được vẽ dựa trên một hình chữ nhật chuẩn 
        /// </summary>
        public enum Edge
        {
            Left,
            Right,
            Top,
            Bottom,
            None
        }
    }
}