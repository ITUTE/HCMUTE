using Paint.Shapes;
using System;
using System.Collections.Generic;
using System.Drawing;
using System.Drawing.Drawing2D;
using System.Linq;
using System.Windows.Forms;

namespace Paint
{
    public partial class FrmMain : Form
    {
        #region Properties
        private BufferedGraphics Gp { get; set; }
        private BufferedGraphicsContext Context { get; set; }

        /// <summary>
        /// Dùng để xác định điểm được chọn làm điểm neo hiện tại khi Zoom/Move 
        /// </summary>
        private Point FirstPoint { get; set; }

        /// <summary>
        /// Được dùng kèm với IsDrawRegion, dùng để xác định một vùng hình chữ nhật trống đang được chọn 
        /// </summary>
        private Rectangle SelectedRegion;

        /// <summary>
        /// Chứa đường dẫn đến hình ảnh được dùng cho TextFill hiện tại 
        /// </summary>
        private string ImgPath { get; set; } = @"Resources\heart_full.png";     //Hình TextFill mặc định 

        /// <summary>
        /// Chứa hình dạng đang được chọn 
        /// </summary>
        private MyShapes SelectedShape { get; set; }

        /// <summary>
        /// Chứa danh sách các đối tượng đang được vẽ 
        /// </summary>
        private List<MyShapes> DrawObj { get; set; } = new List<MyShapes>();

        /// <summary>
        /// Chứa các Label các hình trong menu Shape, dùng để phục vụ cho việc chọn Shape từ menu để vẽ  
        /// </summary>
        private List<Label> ShapeMenu { get; set; }

        /// <summary>
        /// Dùng để xác định Shape nào đang được vẽ 
        /// </summary>
        private SHAPES MyShape { get; set; }

        /// <summary>
        /// Dùng để xác định hành động hiện tại của người dùng 
        /// </summary>
        private ACTION CurrentACTION { get; set; }

        /// <summary>
        /// True nếu người dùng đang chọn chế độ Fill Shape 
        /// </summary>
        private bool Fill { get; set; } = false;

        /// <summary>
        /// True nếu người dùng đang nhấn giữ phím Ctrl 
        /// </summary>
        private bool IsCTRL_pressed { get; set; } = false;

        /// <summary>
        /// True nếu người dùng đang vẽ 1 vùng trống 
        /// </summary>
        private bool IsDrawRegion { get; set; } = false;

        /// <summary>
        /// True nếu người dùng đang Zoom đối tượng được chọn 
        /// </summary>
        private bool IsZooming { get; set; } = false;
        #endregion

        #region Constructor
        public FrmMain()
        {
            InitializeComponent();
            InitGraphics();
            InitMenu();
            Gp.Graphics.Clear(Color.White);
            pnlPaint.Focus();
        }

        /// <summary>
        /// Tạo các đối tượng phục vụ cho graphics 
        /// </summary>
        private void InitGraphics()
        {
            Context = BufferedGraphicsManager.Current;
            Context.MaximumBuffer = new Size(this.Width, this.Height);
            Gp = Context.Allocate(pnlPaint.CreateGraphics(), pnlPaint.DisplayRectangle);
            Gp.Graphics.SmoothingMode = SmoothingMode.AntiAlias;
            Fill = false;
        }

        /// <summary>
        /// Tạo các giá trị mặc định cho menu 
        /// </summary>
        private void InitMenu()
        {
            //Thêm các Items cho ComboBox cmbPenType 
            cmbPenType.Items.AddRange(new object[] { PenType.SolidColor, PenType.HatchFill, PenType.TextureFill, PenType.LinearGradient });
            //Thêm các Items cho ComboBox cmbHatchFill 
            for (int i = 0; i < 53; i++) cmbHatchFill.Items.Add((HatchStyle)i);
            //Mặc định cho cmbHatchFill là Items[0]
            cmbHatchFill.SelectedItem = cmbHatchFill.Items[0];
            //Thêm các đối tượng cho List ShapeMenu 
            //Thứ tự label trong shapeMenu phải tương ứng với enum SHAPE
            ShapeMenu = new List<Label> { lblLine, lblEllipse, lblRect, lblArc, lblCurve, lblClosedCurve, lblPolygon, lblPath };
            CurrentACTION = ACTION.SELECT;
            //Mặc định khi mở ứng dụng là ở chế độ Select 
            GetFocus(lblSelect, true);
            lblGroup.Tag = false;
            pnlPaint.Focus();
        }
        #endregion

        #region Events
        private void FrmMain_FormClosing(object sender, FormClosingEventArgs e)
        {
            DialogResult result = MessageBox.Show("Do you want to exit?", "Warning", MessageBoxButtons.YesNo, MessageBoxIcon.Warning);
            if (result == DialogResult.No)
                e.Cancel = true;
        }

        private void FrmMain_KeyDown(object sender, KeyEventArgs e)
        {
            IsCTRL_pressed = e.Control;
            lblGroup.Tag = false;
            GetFocus(lblGroup, false);
            pnlPaint.Focus();
            switch (e.KeyCode)
            {
                case Keys.Delete:
                case Keys.Back:
                    for (int i = 0; i < DrawObj.Count; i++)
                        if (DrawObj[i].IsSelected)
                            DrawObj.RemoveAt(i--);
                    break;
                case Keys.A:
                    if (IsCTRL_pressed)
                    {
                        GetFocus(lblSelect, true);
                        CurrentACTION = ACTION.SELECT;
                        DrawObj.ForEach(shape => shape.IsSelected = true);
                    }
                    break;
            }
            RePaint();
        }

        private void FrmMain_KeyUp(object sender, KeyEventArgs e)
        {
            IsCTRL_pressed = e.Control;
        }

        private void FrmMain_Leave(object sender, EventArgs e)
        {
            Gp.Dispose();
        }

        private void FrmMain_SizeChanged(object sender, EventArgs e)
        {
            Gp.Graphics.Clear(Color.Transparent);
            InitGraphics();
            RePaint();
        }

        /// <summary>
        /// Dùng để thiết lập giao diện cho các đối tượng ở menu 
        /// </summary>
        /// <param name="isActive">True nếu đối tượng đó được Focus</param>
        private void GetFocus(object sender, bool isActive)
        {
            if (isActive)
            {
                Label lbl = sender as Label;
                lbl.BackColor = SystemColors.MenuHighlight;
                lbl.BorderStyle = BorderStyle.Fixed3D;
                if ((Label)sender == lblFill) return;
                ShapeMenu.ForEach(shape =>
                {
                    shape.BackColor = Color.Transparent;
                    shape.BorderStyle = BorderStyle.None;
                });
            }
            else
            {
                Label lbl = sender as Label;
                lbl.BackColor = Color.Transparent;
                lbl.BorderStyle = BorderStyle.None;
            }
        }

        #region Menu New, Save, Select, Group, Zoom, Fill

        private void LblNew_Click(object sender, EventArgs e)
        {
            InitGraphics();
            GetFocus(lblFill, false);
            GetFocus(lblGroup, false);
            DrawObj.Clear();
            pnlPaint.Refresh();
        }

        private void LblSave_Click(object sender, EventArgs e)
        {
            Bitmap img = CreateImage();
            SaveFileDialog saveFile = new SaveFileDialog
            {
                Filter = "File PNG (*.png)|*.png|" +
                         "File BMP (*.bmp)|*.bmp|" +
                         "File JPEG (*.jpeg)|*.jpeg|" +
                         "File GIF (*.gif)|*.gif|" +
                         "File TIFF (*.tiff)|*.tiff",
                Title = "Save an Image file"
            };
            DialogResult dialog = saveFile.ShowDialog();
            if (dialog == DialogResult.OK)
            {
                if (saveFile.FileName != "")
                    img.Save(saveFile.FileName);
            }
        }

        /// <summary>
        /// Dùng để tạo ra 1 bitmap từ graphics 
        /// </summary>
        /// <returns>1 bitmap </returns>
        private Bitmap CreateImage()
        {
            DrawObj.ForEach(shape => shape.IsSelected = false);
            RePaint();
            Bitmap bitmap = new Bitmap(pnlPaint.Width, pnlPaint.Height);
            Graphics graph = Graphics.FromImage(bitmap);
            Rectangle rect = pnlPaint.RectangleToScreen(pnlPaint.ClientRectangle);
            graph.CopyFromScreen(rect.Location, Point.Empty, pnlPaint.Size);
            return bitmap;
        }

        private void LblSelect_Click(object sender, EventArgs e)
        {
            if (lblSelect.BackColor != SystemColors.ActiveCaption)
            {
                CurrentACTION = ACTION.SELECT;
                GetFocus(lblSelect, true);
                IsZooming = false;
                GetFocus(lblZoom, false);
                pnlLinearAngle.Visible = false;
                pnlHatchFill.Visible = false;
                pnlTextFill.Visible = false;
                pnlPenType.Visible = false;
                pnlPenWidth.Visible = true;
            }
        }

        private bool Group()
        {
            if (DrawObj.Count(shape => shape.IsSelected) > 1)
            {
                Group group = new Group();
                for (int i = 0; i < DrawObj.Count; i++)
                {
                    if (DrawObj[i].IsSelected)
                    {
                        group.Add(DrawObj[i]);
                        DrawObj.RemoveAt(i--);
                    }
                }
                group.IsSelected = true;
                DrawObj.Add(group);
                return true;
            }
            else
                return false;
        }

        private void UnGroup()
        {
            for (int i = 0; i < DrawObj.Count; i++)
            {
                if (DrawObj[i].IsSelected)
                    if (DrawObj[i] is Group)
                    {
                        Group myGroup = DrawObj[i] as Group;
                        //Chèn mỗi hình trong group vào lại trong List DrawObj
                        myGroup.shapesInGroup.ForEach(shape =>
                        {
                            DrawObj.Add(shape);
                            shape.IsSelected = true;
                        });
                        //Remove group khỏi list
                        DrawObj.Remove(myGroup);
                    }
            }
        }

        private void LblGroup_Click(object sender, EventArgs e)
        {
            //lblGroup.Tag = true nếu các hình được chọn là 1 group
            if (lblGroup.Tag.Equals(false))
            {
                if (Group() == true)
                {
                    GetFocus(lblGroup, true);
                    lblGroup.Tag = true;
                }
            }
            else
            {
                GetFocus(lblGroup, false);
                UnGroup();
                lblGroup.Tag = false;
            }
            RePaint();
        }

        private void LblZoom_Click(object sender, EventArgs e)
        {
            CurrentACTION = ACTION.SELECT;
            IsZooming = !IsZooming;
            GetFocus(lblZoom, IsZooming);
            GetFocus(lblSelect, !IsZooming);
        }

        private void LblFill_Click(object sender, EventArgs e)
        {
            pnlHatchFill.Visible = false;
            pnlLinearAngle.Visible = false;
            pnlTextFill.Visible = false;
            Fill = !Fill;
            if (Fill)
            {
                pnlPenWidth.Visible = false;
                ckbBorder.Enabled = true;
                pnlPenType.Visible = true;
                pnlBackColor.Visible = true;
                pnlForeColor.Visible = true;
                lblFill.BackColor = SystemColors.MenuHighlight;
                lblFill.BorderStyle = BorderStyle.Fixed3D;
                cmbPenType.SelectedItem = PenType.SolidColor;
            }
            else
            {
                pnlPenWidth.Visible = true;
                ckbBorder.Checked = true;
                ckbBorder.Enabled = false;
                pnlPenType.Visible = false;
                pnlBackColor.Visible = false;
                pnlForeColor.Visible = false;
                lblFill.BackColor = Color.Transparent;
                lblFill.BorderStyle = BorderStyle.None;
            }
            UpdateSelectedShape();
        }
        #endregion

        #region Style
        /// <summary>
        /// Tạo ra một Brush mới từ các giá trị thiết lập hiện tại của người dùng 
        /// </summary>
        /// <returns></returns>
        private Brush CreateBrush()
        {
            switch (cmbPenType.SelectedItem)
            {
                case PenType.TextureFill:
                    return new TextureBrush(Image.FromFile(ImgPath));
                case PenType.LinearGradient:
                    return new LinearGradientBrush(new Rectangle(10, 10, 10, 10), lblForeColor.BackColor, lblBackColor.BackColor, trbLinearAngle.Value);
                case PenType.HatchFill:
                    return new HatchBrush((HatchStyle)cmbHatchFill.SelectedIndex, lblForeColor.BackColor, lblBackColor.BackColor);
                case PenType.SolidColor:
                default:
                    return new SolidBrush(lblForeColor.BackColor);
            }
        }

        /// <summary>
        /// Xác định giá trị màu dùng cho BackColor/ForeColor 
        /// </summary>
        private void ChooseColor(object sender, EventArgs e)
        {
            if (colorDialog.ShowDialog() == DialogResult.OK)
                (sender as Label).BackColor = colorDialog.Color;
            UpdateSelectedShape();
        }

        private void TrbPenWidth_ValueChanged(object sender, EventArgs e)
        {
            lblWidth.Text = "Width: " + trbPenWidth.Value.ToString();
            UpdateSelectedShape();
        }

        private void CmbDashStyle_SelectedIndexChanged(object sender, EventArgs e)
        {
            DrawObj.ForEach(shape =>
            {
                if (shape.IsSelected)
                    shape.Pen.DashStyle = (DashStyle)cmbDashStyle.SelectedIndex;
            });
            RePaint();
        }

        private void CmbPenType_SelectedIndexChanged(object sender, EventArgs e)
        {
            pnlHatchFill.Visible = false;
            pnlTextFill.Visible = false;
            pnlLinearAngle.Visible = false;
            switch ((PenType)cmbPenType.SelectedIndex)
            {
                case PenType.HatchFill:
                    pnlHatchFill.Visible = true;
                    break;
                case PenType.PathGradient:
                case PenType.LinearGradient:
                    pnlLinearAngle.Visible = true;
                    break;
                case PenType.TextureFill:
                    pnlTextFill.Visible = true;
                    pnlPaint.Refresh();
                    break;
            }
            DrawObj.ForEach(shape =>
            {
                if (shape.IsSelected)
                    shape.Brush = CreateBrush();
            });
            UpdateSelectedShape();
            pnlPaint.Focus();
        }

        private void CmbHatchFill_SelectedIndexChanged(object sender, EventArgs e)
        {
            DrawObj.ForEach(shape =>
            {
                if (shape.IsSelected)
                    shape.Brush = new HatchBrush((HatchStyle)cmbHatchFill.SelectedIndex, Color.Blue);
            });
            UpdateSelectedShape();
            RePaint();
        }

        /// <summary>
        /// Dùng để chọn hình ảnh dùng cho TextFill 
        /// </summary>
        private void BtnBrowse_Click(object sender, EventArgs e)
        {
            OpenFileDialog file = new OpenFileDialog()
            {
                Filter = "Image (*.png)|*.png",
                Multiselect = false,
                InitialDirectory = Application.StartupPath + @"\Resources"
            };
            if (file.ShowDialog() == DialogResult.OK)
            {
                ImgPath = @file.FileName;
                picTextFill.BackgroundImage = Image.FromFile(ImgPath);
                UpdateSelectedShape();
            }
        }

        private void TrbAngle_ValueChanged(object sender, EventArgs e)
        {
            lblLinearAngle.Text = "Angle: " + trbLinearAngle.Value;
            UpdateSelectedShape();
        }

        private void TrbSweepAngle_ValueChanged(object sender, EventArgs e)
        {
            lblSweepAngle.Text = "SweepAngle: " + trbSweepAngle.Value;
            UpdateSelectedShape();
        }

        private void TrbStartAngle_ValueChanged(object sender, EventArgs e)
        {
            lblStartAngle.Text = "StartAngle: " + trbStartAngle.Value;
            UpdateSelectedShape();
        }

        private void CkbBorder_CheckedChanged(object sender, EventArgs e)
        {
            UpdateSelectedShape();
            if (ckbBorder.Checked)
                pnlDashStyle.Enabled = true;
            else pnlDashStyle.Enabled = false;
        }
        #endregion

        #region Shape
        /// <summary>
        /// Dùng để tạo mới một đối tượng hình ảnh, dựa vào giá trị thiết lập hiện tại của người dùng 
        /// </summary>
        private void AddShape()
        {
            Brush brush = CreateBrush();
            Pen pen = new Pen(color: lblBorderColor.BackColor, width: trbPenWidth.Value)
            {
                DashStyle = (DashStyle)cmbDashStyle.SelectedIndex,
            };
            switch (MyShape)
            {
                case SHAPES.LINE: DrawObj.Add(new MyLine(pen, brush)); break;
                case SHAPES.ELLIPSE: DrawObj.Add(new MyEllipse(pen, brush)); break;
                case SHAPES.RECTANGLE: DrawObj.Add(new MyRectangle(pen, brush)); break;
                case SHAPES.CURVE: DrawObj.Add(new MyCurve(pen, brush)); break;
                case SHAPES.CLOSEDCURVE: DrawObj.Add(new MyClosedCurve(pen, brush)); break;
                case SHAPES.POLYGON: DrawObj.Add(new MyPolygon(pen, brush)); break;
                case SHAPES.CUSTOM: DrawObj.Add(new MyPath(pen, brush)); break;
                case SHAPES.ARC: DrawObj.Add(new MyArc(pen, brush, trbStartAngle.Value, trbSweepAngle.Value)); break;
            }
            DrawObj[DrawObj.Count - 1].IsFilled = this.Fill;
            DrawObj[DrawObj.Count - 1].IsDrawBorder = ckbBorder.Checked;
        }

        /// <summary>
        /// Dùng để cập nhật lại các hình ảnh được chọn 
        /// </summary>
        private void UpdateSelectedShape()
        {
            DrawObj.ForEach((Action<MyShapes>)(shape =>
            {
                if (shape.IsSelected)
                {
                    shape.IsFilled = Fill;
                    shape.IsDrawBorder = ckbBorder.Checked;
                    shape.Brush = CreateBrush();
                    shape.Pen.Width = trbPenWidth.Value;
                    shape.Pen.DashStyle = (DashStyle)cmbDashStyle.SelectedIndex;
                    shape.Pen.Color = lblBorderColor.BackColor;
                    if (shape is MyArc arc)
                    {
                        arc.StartAngle = trbStartAngle.Value;
                        arc.SweepAngle = trbSweepAngle.Value;
                    }
                }
            }));
            RePaint();
        }

        /// <summary>
        /// Dùng để thiết lập các giá trị trên menu khi có một hình được chọn 
        /// </summary>
        private void Shape_Click(object sender, EventArgs e)
        {
            CurrentACTION = ACTION.DRAW;
            IsZooming = false;
            GetFocus(lblGroup, false);
            GetFocus(lblZoom, false);
            GetFocus(lblSelect, false);
            Label _sender = sender as Label;
            for (int i = 0; i < ShapeMenu.Count; i++)
            {
                if (ShapeMenu[i] == sender)
                {
                    ShapeMenu[i].BackColor = SystemColors.MenuHighlight;
                    ShapeMenu[i].BorderStyle = BorderStyle.Fixed3D;
                    //Gán giá trị cho MyShape là loại hình được vẽ 
                    MyShape = (SHAPES)i;
                }
                else
                {
                    ShapeMenu[i].BackColor = Color.Transparent;
                    ShapeMenu[i].BorderStyle = BorderStyle.None;
                }
            }
            //Nếu vẽ cung tròn, thì cần hiển thị thêm các thuộc tính về StartAngle và SweepAngle (nằm trong TableLayoutPanel tbArcAngle)
            if (MyShape == SHAPES.ARC)
                tbArcAngle.Visible = true;
            else
                tbArcAngle.Visible = false;
            //Unselected all shapes
            DrawObj.ForEach(shape => shape.IsSelected = false);
        }

        private MyShapes SelectShape(Point p)
        {
            int index = -1;
            for (int i = 0; i < DrawObj.Count; i++)
            {
                DrawObj[i].IsSelected = false;
                if (DrawObj[i].Select(p))
                {
                    DrawObj[i].IsSelected = true;
                    index = i;
                }
            }
            return index >= 0 ? DrawObj[index] : null;
        }

        /// <summary>
        /// Dùng để cập nhật thông tin về hình được chọn lên menu
        /// </summary>
        private void UpdateInfo()
        {
            if (SelectedShape is Group)
            {
                lblGroup.Tag = true;
                GetFocus(lblGroup, true);
            }
            else
            {
                lblGroup.Tag = false;
                GetFocus(lblGroup, false);
            }
            GetFocus(lblSelect, true);
            GetFocus(lblFill, SelectedShape.IsFilled);
        }
        #endregion

        #region pnlPaint Event
        /// <summary>
        /// Dùng để vẽ lại screen bằng cách vẽ chồng từng lớp graphics lên nhau 
        /// </summary>
        private void RePaint()
        {
            using (Brush brush = new SolidBrush(Color.White))
            {
                Gp.Graphics.FillRectangle(brush, 0, 0, pnlPaint.Width, pnlPaint.Height);
                DrawObj.ForEach(shape => shape.Draw(Gp.Graphics));
                if (IsDrawRegion)
                    using (Pen pen = new Pen(Color.Black) { DashStyle = DashStyle.Dash })
                    {
                        Gp.Graphics.DrawRectangle(pen, SelectedRegion);
                    }
                pnlPaint.Focus();
                Gp.Render();
            }
        }

        #region PnlPaint_MouseDown
        private void MouseDown_Select(Point eLocation)
        {
            //Nếu nhấn phím CTRL, sẽ chọn đồng thời nhiều shape. Nếu hình đã chọn mà chọn lần 2, sẽ thành bỏ chọn
            if (IsCTRL_pressed)
            {
                DrawObj.ForEach((Action<MyShapes>)(shape =>
                {
                    if (shape.Select(eLocation))
                        shape.IsSelected = !shape.IsSelected;
                }));
            }
            //Nếu không nhấn CTRL, chỉ có thể chọn duy nhất 1 hình rồi return 
            else
            {
                SelectedShape = SelectShape(eLocation);
                FirstPoint = eLocation;
                if (SelectedShape != null)
                {
                    UpdateInfo();
                    if (IsZooming) SelectedShape.SelectPoint(eLocation);
                    IsDrawRegion = false;
                }
                else    //Draw a rectangle region
                {
                    IsDrawRegion = true;
                    SelectedRegion = new Rectangle(eLocation, new Size(0, 0));
                }
            }
            RePaint();
        }

        private void MouseDown_Drawing(MouseEventArgs e)
        {
            switch (e.Button)
            {
                case MouseButtons.Left:
                    if (DrawObj.Count < 1) return;
                    DrawObj[DrawObj.Count - 1].AddPoint(e.Location);
                    break;
                case MouseButtons.Right:
                    CurrentACTION = ACTION.DRAW;
                    break;
            }
        }

        private void PnlPaint_MouseDown(object sender, MouseEventArgs e)
        {
            lblGroup.Tag = false;
            GetFocus(lblGroup, false);
            switch (CurrentACTION)
            {
                case ACTION.SELECT:
                    MouseDown_Select(e.Location);
                    break;
                case ACTION.DRAW:
                    AddShape();
                    DrawObj[DrawObj.Count - 1].P1 = e.Location;
                    DrawObj[DrawObj.Count - 1].AddPoint(e.Location);
                    DrawObj[DrawObj.Count - 1].AddPoint(e.Location);
                    CurrentACTION = ACTION.DRAWING;
                    break;
                case ACTION.DRAWING:
                    MouseDown_Drawing(e);
                    break;
            }
        }
        #endregion

        #region PnlPaint_MouseMove
        private void MouseMove_Drawing(Point eLocation)
        {
            if (DrawObj.Count <= 0) return;
            //Cập nhật các điểm để vẽ
            //Hình dáng mouse
            pnlPaint.Cursor = Cursors.Cross;
            //Đối với cách hình thông thường
            if (MyShape != SHAPES.CURVE && MyShape != SHAPES.POLYGON && MyShape != SHAPES.CLOSEDCURVE)
                DrawObj[DrawObj.Count - 1].AddPoint(eLocation);
            //Đối với Curve và Polygon
            else
            {
                if (MyShape == SHAPES.CURVE)
                {
                    var shape = (DrawObj[DrawObj.Count - 1] as MyCurve);
                    int i = shape.LPoints.Count;
                    shape.LPoints[i - 1] = eLocation;
                }
                else if (MyShape == SHAPES.POLYGON)
                {
                    var shape = (DrawObj[DrawObj.Count - 1] as MyPolygon);
                    int i = shape.LPoints.Count;
                    shape.LPoints[i - 1] = eLocation;
                }
                else if (MyShape == SHAPES.CLOSEDCURVE)
                {
                    var shape = (DrawObj[DrawObj.Count - 1] as MyClosedCurve);
                    int i = shape.LPoints.Count;
                    shape.LPoints[i - 1] = eLocation;
                }
            }
            RePaint();
        }

        private void MouseMove_Select(Point eLocation)
        {
            #region Mouse
            if (DrawObj.Exists(shape => shape.Select(eLocation)))
                pnlPaint.Cursor = Cursors.SizeAll;
            else pnlPaint.Cursor = Cursors.Cross;
            #endregion

            //Nếu đang vẽ 1 region để chọn hình, thì thay đổi kích thước của region đó
            if (SelectedShape != null)
            {
                if (IsZooming)
                    SelectedShape.Zoom(FirstPoint, eLocation);
                else
                    SelectedShape.Move(FirstPoint, eLocation);
                FirstPoint = eLocation;     //Cập nhật lại FirstPoint 
            }
            else
            {
                //Vẽ 1 rectangle trống 
                int minX = Math.Min(FirstPoint.X, eLocation.X);
                int minY = Math.Min(FirstPoint.Y, eLocation.Y);
                int dx = Math.Abs(eLocation.X - FirstPoint.X);
                int dy = Math.Abs(eLocation.Y - FirstPoint.Y);
                SelectedRegion.Location = new Point(minX, minY);
                SelectedRegion.Width = dx;
                SelectedRegion.Height = dy;
            }
            RePaint();
        }

        private void PnlPaint_MouseMove(object sender, MouseEventArgs e)
        {
            switch (CurrentACTION)
            {
                case ACTION.DRAWING:
                    MouseMove_Drawing(e.Location);
                    break;
                case ACTION.SELECT:
                    MouseMove_Select(e.Location);
                    break;
            }
        }
        #endregion

        private void PnlPaint_MouseUp(object sender, MouseEventArgs e)
        {
            if (CurrentACTION == ACTION.DRAWING)
            {
                if (MyShape == SHAPES.CURVE || MyShape == SHAPES.POLYGON || MyShape == SHAPES.CLOSEDCURVE) 
                    return;
                else CurrentACTION = ACTION.DRAW;
            }
            //Select
            else if (CurrentACTION == ACTION.SELECT)
            {
                SelectedShape = null;
                //Cập nhật các hình được chọn vào list DrawObj
                if (IsDrawRegion)
                {
                    IsDrawRegion = false;                    //Dung de xoa vung rectangle region
                    DrawObj.ForEach(shape => shape.IsSelected = false);
                    DrawObj.ForEach((Action<MyShapes>)(shape =>
                    {
                        if (shape.P1.X >= SelectedRegion.X
                        && shape.P2.X <= SelectedRegion.X + SelectedRegion.Width
                        && shape.P1.Y >= SelectedRegion.Y
                        && shape.P2.Y <= SelectedRegion.Y + SelectedRegion.Height)
                        {
                            shape.IsSelected = true;
                        }
                    }));
                    SelectedRegion = new Rectangle();       //Dat lai gia tri rectangle region
                    RePaint();
                }
            }
        }

        /// <summary>
        /// Được dùng khi vẽ các hình có hình dạng phức tạp. Khi DoubleClick sẽ hoàn thành hình đang được vẽ 
        /// </summary>
        private void PnlPaint_DoubleClick(object sender, EventArgs e)
        {
            if (CurrentACTION == ACTION.DRAWING)
                CurrentACTION = ACTION.DRAW;
        }
        #endregion

        #endregion
    }
}