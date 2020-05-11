namespace Paint
{
    partial class FrmMain
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.pnlPaint = new System.Windows.Forms.Panel();
            this.colorDialog = new System.Windows.Forms.ColorDialog();
            this.btnNew = new System.Windows.Forms.Button();
            this.btnSave = new System.Windows.Forms.Button();
            this.lblSelect = new System.Windows.Forms.Label();
            this.pnlMenu = new System.Windows.Forms.Panel();
            this.lblFill = new System.Windows.Forms.Label();
            this.lblZoom = new System.Windows.Forms.Label();
            this.lblGroup = new System.Windows.Forms.Label();
            this.lblForeColor = new System.Windows.Forms.Label();
            this.cmbHatchFill = new System.Windows.Forms.ComboBox();
            this.trbPenWidth = new System.Windows.Forms.TrackBar();
            this.cmbPenType = new System.Windows.Forms.ComboBox();
            this.cmbDashStyle = new System.Windows.Forms.ComboBox();
            this.toolTip = new System.Windows.Forms.ToolTip(this.components);
            this.btnBrowse = new System.Windows.Forms.Button();
            this.lblBackColor = new System.Windows.Forms.Label();
            this.lblBorderColor = new System.Windows.Forms.Label();
            this.picTextFill = new System.Windows.Forms.PictureBox();
            this.ckbBorder = new System.Windows.Forms.CheckBox();
            this.lblClosedCurve = new System.Windows.Forms.Label();
            this.lblCurve = new System.Windows.Forms.Label();
            this.lblArc = new System.Windows.Forms.Label();
            this.lblLine = new System.Windows.Forms.Label();
            this.lblPolygon = new System.Windows.Forms.Label();
            this.lblRect = new System.Windows.Forms.Label();
            this.lblPath = new System.Windows.Forms.Label();
            this.lblEllipse = new System.Windows.Forms.Label();
            this.pnlContainer = new System.Windows.Forms.Panel();
            this.tableLayoutPanel2 = new System.Windows.Forms.TableLayoutPanel();
            this.pnlLinearAngle = new System.Windows.Forms.Panel();
            this.trbLinearAngle = new System.Windows.Forms.TrackBar();
            this.lblLinearAngle = new System.Windows.Forms.Label();
            this.pnlTextFill = new System.Windows.Forms.Panel();
            this.lblTextFill = new System.Windows.Forms.Label();
            this.pnlHatchFill = new System.Windows.Forms.Panel();
            this.label7 = new System.Windows.Forms.Label();
            this.pnlPenType = new System.Windows.Forms.Panel();
            this.label1 = new System.Windows.Forms.Label();
            this.pnlPenWidth = new System.Windows.Forms.Panel();
            this.lblWidth = new System.Windows.Forms.Label();
            this.pnlDashStyle = new System.Windows.Forms.Panel();
            this.label6 = new System.Windows.Forms.Label();
            this.tbColor = new System.Windows.Forms.TableLayoutPanel();
            this.pnlBackColor = new System.Windows.Forms.Panel();
            this.lblBack = new System.Windows.Forms.Label();
            this.pnlForeColor = new System.Windows.Forms.Panel();
            this.lblFore = new System.Windows.Forms.Label();
            this.tbArcAngle = new System.Windows.Forms.TableLayoutPanel();
            this.trbSweepAngle = new System.Windows.Forms.TrackBar();
            this.lblStartAngle = new System.Windows.Forms.Label();
            this.lblSweepAngle = new System.Windows.Forms.Label();
            this.trbStartAngle = new System.Windows.Forms.TrackBar();
            this.tableLayoutPanel1 = new System.Windows.Forms.TableLayoutPanel();
            this.label8 = new System.Windows.Forms.Label();
            this.tableLayoutPanel3 = new System.Windows.Forms.TableLayoutPanel();
            this.pnlMenu.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trbPenWidth)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.picTextFill)).BeginInit();
            this.pnlContainer.SuspendLayout();
            this.tableLayoutPanel2.SuspendLayout();
            this.pnlLinearAngle.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trbLinearAngle)).BeginInit();
            this.pnlTextFill.SuspendLayout();
            this.pnlHatchFill.SuspendLayout();
            this.pnlPenType.SuspendLayout();
            this.pnlPenWidth.SuspendLayout();
            this.pnlDashStyle.SuspendLayout();
            this.tbColor.SuspendLayout();
            this.pnlBackColor.SuspendLayout();
            this.pnlForeColor.SuspendLayout();
            this.tbArcAngle.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trbSweepAngle)).BeginInit();
            ((System.ComponentModel.ISupportInitialize)(this.trbStartAngle)).BeginInit();
            this.tableLayoutPanel1.SuspendLayout();
            this.tableLayoutPanel3.SuspendLayout();
            this.SuspendLayout();
            // 
            // pnlPaint
            // 
            this.pnlPaint.BackColor = System.Drawing.Color.White;
            this.pnlPaint.Cursor = System.Windows.Forms.Cursors.Cross;
            this.pnlPaint.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlPaint.Font = new System.Drawing.Font("Microsoft Sans Serif", 14F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.pnlPaint.Location = new System.Drawing.Point(169, 3);
            this.pnlPaint.Name = "pnlPaint";
            this.pnlPaint.Size = new System.Drawing.Size(1218, 696);
            this.pnlPaint.TabIndex = 2;
            this.pnlPaint.DoubleClick += new System.EventHandler(this.PnlPaint_DoubleClick);
            this.pnlPaint.MouseDown += new System.Windows.Forms.MouseEventHandler(this.PnlPaint_MouseDown);
            this.pnlPaint.MouseMove += new System.Windows.Forms.MouseEventHandler(this.PnlPaint_MouseMove);
            this.pnlPaint.MouseUp += new System.Windows.Forms.MouseEventHandler(this.PnlPaint_MouseUp);
            // 
            // colorDialog
            // 
            this.colorDialog.AnyColor = true;
            this.colorDialog.FullOpen = true;
            // 
            // btnNew
            // 
            this.btnNew.Dock = System.Windows.Forms.DockStyle.Left;
            this.btnNew.FlatAppearance.BorderColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnNew.FlatAppearance.BorderSize = 0;
            this.btnNew.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnNew.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnNew.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnNew.Location = new System.Drawing.Point(0, 0);
            this.btnNew.Name = "btnNew";
            this.btnNew.Size = new System.Drawing.Size(64, 24);
            this.btnNew.TabIndex = 19;
            this.btnNew.Text = "New";
            this.toolTip.SetToolTip(this.btnNew, "Create new graphic");
            this.btnNew.Click += new System.EventHandler(this.LblNew_Click);
            // 
            // btnSave
            // 
            this.btnSave.Dock = System.Windows.Forms.DockStyle.Left;
            this.btnSave.FlatAppearance.BorderColor = System.Drawing.SystemColors.ActiveCaption;
            this.btnSave.FlatAppearance.BorderSize = 0;
            this.btnSave.FlatAppearance.MouseDownBackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnSave.FlatAppearance.MouseOverBackColor = System.Drawing.SystemColors.ButtonFace;
            this.btnSave.FlatStyle = System.Windows.Forms.FlatStyle.Flat;
            this.btnSave.Location = new System.Drawing.Point(64, 0);
            this.btnSave.Name = "btnSave";
            this.btnSave.Size = new System.Drawing.Size(64, 24);
            this.btnSave.TabIndex = 20;
            this.btnSave.Text = "Save";
            this.toolTip.SetToolTip(this.btnSave, "Save graphic to file");
            this.btnSave.Click += new System.EventHandler(this.LblSave_Click);
            // 
            // lblSelect
            // 
            this.lblSelect.Dock = System.Windows.Forms.DockStyle.Left;
            this.lblSelect.Location = new System.Drawing.Point(128, 0);
            this.lblSelect.Name = "lblSelect";
            this.lblSelect.Size = new System.Drawing.Size(64, 24);
            this.lblSelect.TabIndex = 21;
            this.lblSelect.Text = "Select";
            this.lblSelect.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblSelect.Click += new System.EventHandler(this.LblSelect_Click);
            // 
            // pnlMenu
            // 
            this.pnlMenu.BackColor = System.Drawing.SystemColors.ActiveCaption;
            this.pnlMenu.Controls.Add(this.lblFill);
            this.pnlMenu.Controls.Add(this.lblZoom);
            this.pnlMenu.Controls.Add(this.lblGroup);
            this.pnlMenu.Controls.Add(this.lblSelect);
            this.pnlMenu.Controls.Add(this.btnSave);
            this.pnlMenu.Controls.Add(this.btnNew);
            this.pnlMenu.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlMenu.Font = new System.Drawing.Font("Microsoft Sans Serif", 10F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.pnlMenu.Location = new System.Drawing.Point(0, 0);
            this.pnlMenu.Name = "pnlMenu";
            this.pnlMenu.Size = new System.Drawing.Size(1218, 24);
            this.pnlMenu.TabIndex = 0;
            // 
            // lblFill
            // 
            this.lblFill.Dock = System.Windows.Forms.DockStyle.Left;
            this.lblFill.Location = new System.Drawing.Point(320, 0);
            this.lblFill.Name = "lblFill";
            this.lblFill.Size = new System.Drawing.Size(64, 24);
            this.lblFill.TabIndex = 39;
            this.lblFill.Text = "Fill";
            this.lblFill.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblFill.Click += new System.EventHandler(this.LblFill_Click);
            // 
            // lblZoom
            // 
            this.lblZoom.Dock = System.Windows.Forms.DockStyle.Left;
            this.lblZoom.Location = new System.Drawing.Point(256, 0);
            this.lblZoom.Name = "lblZoom";
            this.lblZoom.Size = new System.Drawing.Size(64, 24);
            this.lblZoom.TabIndex = 38;
            this.lblZoom.Text = "Zoom";
            this.lblZoom.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblZoom.Click += new System.EventHandler(this.LblZoom_Click);
            // 
            // lblGroup
            // 
            this.lblGroup.Dock = System.Windows.Forms.DockStyle.Left;
            this.lblGroup.Location = new System.Drawing.Point(192, 0);
            this.lblGroup.Name = "lblGroup";
            this.lblGroup.Size = new System.Drawing.Size(64, 24);
            this.lblGroup.TabIndex = 24;
            this.lblGroup.Text = "Group";
            this.lblGroup.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.lblGroup.Click += new System.EventHandler(this.LblGroup_Click);
            // 
            // lblForeColor
            // 
            this.lblForeColor.BackColor = System.Drawing.Color.Red;
            this.lblForeColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblForeColor.ForeColor = System.Drawing.Color.Red;
            this.lblForeColor.Location = new System.Drawing.Point(0, 16);
            this.lblForeColor.Name = "lblForeColor";
            this.lblForeColor.Size = new System.Drawing.Size(71, 24);
            this.lblForeColor.TabIndex = 40;
            this.lblForeColor.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblForeColor, "Choosr forecolor");
            this.lblForeColor.Click += new System.EventHandler(this.ChooseColor);
            // 
            // cmbHatchFill
            // 
            this.cmbHatchFill.AutoCompleteMode = System.Windows.Forms.AutoCompleteMode.Suggest;
            this.cmbHatchFill.Dock = System.Windows.Forms.DockStyle.Top;
            this.cmbHatchFill.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.cmbHatchFill.FormattingEnabled = true;
            this.cmbHatchFill.Location = new System.Drawing.Point(0, 20);
            this.cmbHatchFill.Name = "cmbHatchFill";
            this.cmbHatchFill.Size = new System.Drawing.Size(154, 21);
            this.cmbHatchFill.TabIndex = 12;
            this.cmbHatchFill.Text = "Horizontal";
            this.toolTip.SetToolTip(this.cmbHatchFill, "Choose HatchFill style");
            this.cmbHatchFill.SelectedIndexChanged += new System.EventHandler(this.CmbHatchFill_SelectedIndexChanged);
            // 
            // trbPenWidth
            // 
            this.trbPenWidth.AutoSize = false;
            this.trbPenWidth.Dock = System.Windows.Forms.DockStyle.Top;
            this.trbPenWidth.Location = new System.Drawing.Point(0, 20);
            this.trbPenWidth.Minimum = 1;
            this.trbPenWidth.Name = "trbPenWidth";
            this.trbPenWidth.Size = new System.Drawing.Size(154, 24);
            this.trbPenWidth.TabIndex = 47;
            this.toolTip.SetToolTip(this.trbPenWidth, "PenWidth");
            this.trbPenWidth.Value = 3;
            this.trbPenWidth.ValueChanged += new System.EventHandler(this.TrbPenWidth_ValueChanged);
            // 
            // cmbPenType
            // 
            this.cmbPenType.Dock = System.Windows.Forms.DockStyle.Top;
            this.cmbPenType.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.cmbPenType.FormattingEnabled = true;
            this.cmbPenType.Location = new System.Drawing.Point(0, 20);
            this.cmbPenType.Name = "cmbPenType";
            this.cmbPenType.Size = new System.Drawing.Size(154, 21);
            this.cmbPenType.TabIndex = 42;
            this.cmbPenType.Text = "Solid Color";
            this.toolTip.SetToolTip(this.cmbPenType, "Choose PenType");
            this.cmbPenType.SelectedIndexChanged += new System.EventHandler(this.CmbPenType_SelectedIndexChanged);
            // 
            // cmbDashStyle
            // 
            this.cmbDashStyle.DisplayMember = "Choose DashStyle";
            this.cmbDashStyle.Dock = System.Windows.Forms.DockStyle.Top;
            this.cmbDashStyle.Font = new System.Drawing.Font("Microsoft Sans Serif", 8F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.cmbDashStyle.FormattingEnabled = true;
            this.cmbDashStyle.Items.AddRange(new object[] {
            "Solid",
            "Dash",
            "DashDot",
            "DashDotDot"});
            this.cmbDashStyle.Location = new System.Drawing.Point(0, 20);
            this.cmbDashStyle.Name = "cmbDashStyle";
            this.cmbDashStyle.Size = new System.Drawing.Size(154, 21);
            this.cmbDashStyle.TabIndex = 41;
            this.cmbDashStyle.Text = "Solid";
            this.toolTip.SetToolTip(this.cmbDashStyle, "Dash Style");
            this.cmbDashStyle.ValueMember = "Choose DashStyle";
            this.cmbDashStyle.SelectedIndexChanged += new System.EventHandler(this.CmbDashStyle_SelectedIndexChanged);
            // 
            // btnBrowse
            // 
            this.btnBrowse.Dock = System.Windows.Forms.DockStyle.Top;
            this.btnBrowse.Location = new System.Drawing.Point(0, 120);
            this.btnBrowse.Name = "btnBrowse";
            this.btnBrowse.Size = new System.Drawing.Size(154, 23);
            this.btnBrowse.TabIndex = 50;
            this.btnBrowse.Text = "Browse ...";
            this.toolTip.SetToolTip(this.btnBrowse, "Browse an image");
            this.btnBrowse.UseVisualStyleBackColor = true;
            this.btnBrowse.Click += new System.EventHandler(this.BtnBrowse_Click);
            // 
            // lblBackColor
            // 
            this.lblBackColor.BackColor = System.Drawing.Color.LightSeaGreen;
            this.lblBackColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblBackColor.ForeColor = System.Drawing.Color.Gray;
            this.lblBackColor.Location = new System.Drawing.Point(0, 16);
            this.lblBackColor.Name = "lblBackColor";
            this.lblBackColor.Size = new System.Drawing.Size(71, 24);
            this.lblBackColor.TabIndex = 41;
            this.lblBackColor.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblBackColor, "Choose backcolor");
            this.lblBackColor.Click += new System.EventHandler(this.ChooseColor);
            // 
            // lblBorderColor
            // 
            this.lblBorderColor.BackColor = System.Drawing.Color.Black;
            this.lblBorderColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblBorderColor.ForeColor = System.Drawing.Color.Gray;
            this.lblBorderColor.Location = new System.Drawing.Point(80, 0);
            this.lblBorderColor.Name = "lblBorderColor";
            this.lblBorderColor.Size = new System.Drawing.Size(71, 24);
            this.lblBorderColor.TabIndex = 42;
            this.lblBorderColor.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblBorderColor, "Choose border color");
            this.lblBorderColor.Click += new System.EventHandler(this.ChooseColor);
            // 
            // picTextFill
            // 
            this.picTextFill.BackgroundImage = global::Paint.Properties.Resources.heart_full;
            this.picTextFill.BackgroundImageLayout = System.Windows.Forms.ImageLayout.Center;
            this.picTextFill.Dock = System.Windows.Forms.DockStyle.Top;
            this.picTextFill.Location = new System.Drawing.Point(0, 20);
            this.picTextFill.Name = "picTextFill";
            this.picTextFill.Size = new System.Drawing.Size(154, 100);
            this.picTextFill.SizeMode = System.Windows.Forms.PictureBoxSizeMode.CenterImage;
            this.picTextFill.TabIndex = 0;
            this.picTextFill.TabStop = false;
            this.picTextFill.Tag = "";
            this.toolTip.SetToolTip(this.picTextFill, "Image to fill");
            // 
            // ckbBorder
            // 
            this.ckbBorder.AutoSize = true;
            this.ckbBorder.Checked = true;
            this.ckbBorder.CheckState = System.Windows.Forms.CheckState.Checked;
            this.ckbBorder.Dock = System.Windows.Forms.DockStyle.Fill;
            this.ckbBorder.Enabled = false;
            this.ckbBorder.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.5F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.ckbBorder.Location = new System.Drawing.Point(3, 3);
            this.ckbBorder.Name = "ckbBorder";
            this.ckbBorder.Size = new System.Drawing.Size(71, 19);
            this.ckbBorder.TabIndex = 0;
            this.ckbBorder.Text = "Border";
            this.toolTip.SetToolTip(this.ckbBorder, "Check if you want to draw a border of the shape");
            this.ckbBorder.UseVisualStyleBackColor = true;
            this.ckbBorder.CheckedChanged += new System.EventHandler(this.CkbBorder_CheckedChanged);
            // 
            // lblClosedCurve
            // 
            this.lblClosedCurve.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblClosedCurve.Location = new System.Drawing.Point(80, 51);
            this.lblClosedCurve.Margin = new System.Windows.Forms.Padding(0);
            this.lblClosedCurve.Name = "lblClosedCurve";
            this.lblClosedCurve.Size = new System.Drawing.Size(79, 24);
            this.lblClosedCurve.TabIndex = 14;
            this.lblClosedCurve.Text = "Closed Curve";
            this.lblClosedCurve.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblClosedCurve, "Draw a closed curve");
            this.lblClosedCurve.Click += new System.EventHandler(this.Shape_Click);
            // 
            // lblCurve
            // 
            this.lblCurve.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblCurve.Location = new System.Drawing.Point(80, 76);
            this.lblCurve.Margin = new System.Windows.Forms.Padding(0);
            this.lblCurve.Name = "lblCurve";
            this.lblCurve.Size = new System.Drawing.Size(79, 24);
            this.lblCurve.TabIndex = 13;
            this.lblCurve.Text = "Curve";
            this.lblCurve.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblCurve, "Draw a curve");
            this.lblCurve.Click += new System.EventHandler(this.Shape_Click);
            // 
            // lblArc
            // 
            this.lblArc.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblArc.Location = new System.Drawing.Point(1, 76);
            this.lblArc.Margin = new System.Windows.Forms.Padding(0);
            this.lblArc.Name = "lblArc";
            this.lblArc.Size = new System.Drawing.Size(78, 24);
            this.lblArc.TabIndex = 12;
            this.lblArc.Text = "Arc";
            this.lblArc.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblArc, "Draw an arc");
            this.lblArc.Click += new System.EventHandler(this.Shape_Click);
            // 
            // lblLine
            // 
            this.lblLine.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblLine.Location = new System.Drawing.Point(1, 1);
            this.lblLine.Margin = new System.Windows.Forms.Padding(0);
            this.lblLine.Name = "lblLine";
            this.lblLine.Size = new System.Drawing.Size(78, 24);
            this.lblLine.TabIndex = 3;
            this.lblLine.Text = "Line";
            this.lblLine.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblLine, "Draw a line");
            this.lblLine.Click += new System.EventHandler(this.Shape_Click);
            // 
            // lblPolygon
            // 
            this.lblPolygon.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblPolygon.Location = new System.Drawing.Point(80, 1);
            this.lblPolygon.Margin = new System.Windows.Forms.Padding(0);
            this.lblPolygon.Name = "lblPolygon";
            this.lblPolygon.Size = new System.Drawing.Size(79, 24);
            this.lblPolygon.TabIndex = 6;
            this.lblPolygon.Text = "Polygon";
            this.lblPolygon.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblPolygon, "Draw a polygon");
            this.lblPolygon.Click += new System.EventHandler(this.Shape_Click);
            // 
            // lblRect
            // 
            this.lblRect.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblRect.Location = new System.Drawing.Point(1, 26);
            this.lblRect.Margin = new System.Windows.Forms.Padding(0);
            this.lblRect.Name = "lblRect";
            this.lblRect.Size = new System.Drawing.Size(78, 24);
            this.lblRect.TabIndex = 7;
            this.lblRect.Text = "Rectangle";
            this.lblRect.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblRect, "Draw a rectangle");
            this.lblRect.Click += new System.EventHandler(this.Shape_Click);
            // 
            // lblPath
            // 
            this.lblPath.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblPath.Location = new System.Drawing.Point(80, 26);
            this.lblPath.Margin = new System.Windows.Forms.Padding(0);
            this.lblPath.Name = "lblPath";
            this.lblPath.Size = new System.Drawing.Size(79, 24);
            this.lblPath.TabIndex = 11;
            this.lblPath.Text = "Path";
            this.lblPath.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblPath, "Draw a path");
            this.lblPath.Click += new System.EventHandler(this.Shape_Click);
            // 
            // lblEllipse
            // 
            this.lblEllipse.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblEllipse.Location = new System.Drawing.Point(1, 51);
            this.lblEllipse.Margin = new System.Windows.Forms.Padding(0);
            this.lblEllipse.Name = "lblEllipse";
            this.lblEllipse.Size = new System.Drawing.Size(78, 24);
            this.lblEllipse.TabIndex = 8;
            this.lblEllipse.Text = "Ellipse";
            this.lblEllipse.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            this.toolTip.SetToolTip(this.lblEllipse, "Draw an ellipse");
            this.lblEllipse.Click += new System.EventHandler(this.Shape_Click);
            // 
            // pnlContainer
            // 
            this.pnlContainer.Controls.Add(this.tableLayoutPanel2);
            this.pnlContainer.Controls.Add(this.tableLayoutPanel1);
            this.pnlContainer.Controls.Add(this.label8);
            this.pnlContainer.Dock = System.Windows.Forms.DockStyle.Fill;
            this.pnlContainer.Location = new System.Drawing.Point(3, 3);
            this.pnlContainer.Name = "pnlContainer";
            this.pnlContainer.Size = new System.Drawing.Size(160, 696);
            this.pnlContainer.TabIndex = 3;
            // 
            // tableLayoutPanel2
            // 
            this.tableLayoutPanel2.AutoSize = true;
            this.tableLayoutPanel2.ColumnCount = 1;
            this.tableLayoutPanel2.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel2.Controls.Add(this.pnlLinearAngle, 0, 7);
            this.tableLayoutPanel2.Controls.Add(this.pnlTextFill, 0, 6);
            this.tableLayoutPanel2.Controls.Add(this.pnlHatchFill, 0, 5);
            this.tableLayoutPanel2.Controls.Add(this.pnlPenType, 0, 4);
            this.tableLayoutPanel2.Controls.Add(this.pnlPenWidth, 0, 3);
            this.tableLayoutPanel2.Controls.Add(this.pnlDashStyle, 0, 2);
            this.tableLayoutPanel2.Controls.Add(this.tbColor, 0, 0);
            this.tableLayoutPanel2.Controls.Add(this.tbArcAngle, 0, 7);
            this.tableLayoutPanel2.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel2.Location = new System.Drawing.Point(0, 125);
            this.tableLayoutPanel2.Name = "tableLayoutPanel2";
            this.tableLayoutPanel2.RowCount = 9;
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel2.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Absolute, 20F));
            this.tableLayoutPanel2.Size = new System.Drawing.Size(160, 571);
            this.tableLayoutPanel2.TabIndex = 0;
            // 
            // pnlLinearAngle
            // 
            this.pnlLinearAngle.AutoSize = true;
            this.pnlLinearAngle.Controls.Add(this.trbLinearAngle);
            this.pnlLinearAngle.Controls.Add(this.lblLinearAngle);
            this.pnlLinearAngle.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlLinearAngle.Location = new System.Drawing.Point(3, 520);
            this.pnlLinearAngle.Name = "pnlLinearAngle";
            this.pnlLinearAngle.Size = new System.Drawing.Size(154, 48);
            this.pnlLinearAngle.TabIndex = 0;
            this.pnlLinearAngle.Visible = false;
            // 
            // trbLinearAngle
            // 
            this.trbLinearAngle.AutoSize = false;
            this.trbLinearAngle.Dock = System.Windows.Forms.DockStyle.Bottom;
            this.trbLinearAngle.Location = new System.Drawing.Point(0, 16);
            this.trbLinearAngle.Maximum = 180;
            this.trbLinearAngle.Name = "trbLinearAngle";
            this.trbLinearAngle.Size = new System.Drawing.Size(154, 32);
            this.trbLinearAngle.TabIndex = 1;
            this.trbLinearAngle.ValueChanged += new System.EventHandler(this.TrbAngle_ValueChanged);
            // 
            // lblLinearAngle
            // 
            this.lblLinearAngle.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblLinearAngle.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lblLinearAngle.Location = new System.Drawing.Point(0, 0);
            this.lblLinearAngle.Name = "lblLinearAngle";
            this.lblLinearAngle.Size = new System.Drawing.Size(154, 20);
            this.lblLinearAngle.TabIndex = 0;
            this.lblLinearAngle.Text = "Angle: 0";
            this.lblLinearAngle.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // pnlTextFill
            // 
            this.pnlTextFill.AutoSize = true;
            this.pnlTextFill.Controls.Add(this.btnBrowse);
            this.pnlTextFill.Controls.Add(this.picTextFill);
            this.pnlTextFill.Controls.Add(this.lblTextFill);
            this.pnlTextFill.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlTextFill.Location = new System.Drawing.Point(3, 271);
            this.pnlTextFill.Name = "pnlTextFill";
            this.pnlTextFill.Size = new System.Drawing.Size(154, 143);
            this.pnlTextFill.TabIndex = 0;
            this.pnlTextFill.Visible = false;
            // 
            // lblTextFill
            // 
            this.lblTextFill.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblTextFill.Font = new System.Drawing.Font("Microsoft Sans Serif", 9F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lblTextFill.Location = new System.Drawing.Point(0, 0);
            this.lblTextFill.Name = "lblTextFill";
            this.lblTextFill.Size = new System.Drawing.Size(154, 20);
            this.lblTextFill.TabIndex = 0;
            this.lblTextFill.Text = "TextFill";
            this.lblTextFill.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // pnlHatchFill
            // 
            this.pnlHatchFill.AutoSize = true;
            this.pnlHatchFill.Controls.Add(this.cmbHatchFill);
            this.pnlHatchFill.Controls.Add(this.label7);
            this.pnlHatchFill.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlHatchFill.Location = new System.Drawing.Point(3, 224);
            this.pnlHatchFill.Name = "pnlHatchFill";
            this.pnlHatchFill.Size = new System.Drawing.Size(154, 41);
            this.pnlHatchFill.TabIndex = 0;
            this.pnlHatchFill.Visible = false;
            // 
            // label7
            // 
            this.label7.Dock = System.Windows.Forms.DockStyle.Top;
            this.label7.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.label7.Location = new System.Drawing.Point(0, 0);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(154, 20);
            this.label7.TabIndex = 48;
            this.label7.Text = "HatchFill";
            this.label7.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // pnlPenType
            // 
            this.pnlPenType.AutoSize = true;
            this.pnlPenType.Controls.Add(this.cmbPenType);
            this.pnlPenType.Controls.Add(this.label1);
            this.pnlPenType.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlPenType.Location = new System.Drawing.Point(3, 177);
            this.pnlPenType.Name = "pnlPenType";
            this.pnlPenType.Size = new System.Drawing.Size(154, 41);
            this.pnlPenType.TabIndex = 0;
            this.pnlPenType.Visible = false;
            // 
            // label1
            // 
            this.label1.Dock = System.Windows.Forms.DockStyle.Top;
            this.label1.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.label1.Location = new System.Drawing.Point(0, 0);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(154, 20);
            this.label1.TabIndex = 0;
            this.label1.Text = "PenType";
            this.label1.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // pnlPenWidth
            // 
            this.pnlPenWidth.AutoSize = true;
            this.pnlPenWidth.Controls.Add(this.trbPenWidth);
            this.pnlPenWidth.Controls.Add(this.lblWidth);
            this.pnlPenWidth.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlPenWidth.Location = new System.Drawing.Point(3, 127);
            this.pnlPenWidth.Name = "pnlPenWidth";
            this.pnlPenWidth.Size = new System.Drawing.Size(154, 44);
            this.pnlPenWidth.TabIndex = 0;
            // 
            // lblWidth
            // 
            this.lblWidth.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblWidth.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lblWidth.Location = new System.Drawing.Point(0, 0);
            this.lblWidth.Name = "lblWidth";
            this.lblWidth.Size = new System.Drawing.Size(154, 20);
            this.lblWidth.TabIndex = 47;
            this.lblWidth.Text = "Width: 3";
            this.lblWidth.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // pnlDashStyle
            // 
            this.pnlDashStyle.AutoSize = true;
            this.pnlDashStyle.Controls.Add(this.cmbDashStyle);
            this.pnlDashStyle.Controls.Add(this.label6);
            this.pnlDashStyle.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlDashStyle.Location = new System.Drawing.Point(3, 80);
            this.pnlDashStyle.Name = "pnlDashStyle";
            this.pnlDashStyle.Size = new System.Drawing.Size(154, 41);
            this.pnlDashStyle.TabIndex = 1;
            // 
            // label6
            // 
            this.label6.Dock = System.Windows.Forms.DockStyle.Top;
            this.label6.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.label6.Location = new System.Drawing.Point(0, 0);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(154, 20);
            this.label6.TabIndex = 0;
            this.label6.Text = "DashStyle";
            this.label6.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // tbColor
            // 
            this.tbColor.AutoSize = true;
            this.tbColor.ColumnCount = 2;
            this.tbColor.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tbColor.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tbColor.Controls.Add(this.lblBorderColor, 0, 0);
            this.tbColor.Controls.Add(this.ckbBorder, 0, 0);
            this.tbColor.Controls.Add(this.pnlBackColor, 0, 1);
            this.tbColor.Controls.Add(this.pnlForeColor, 0, 1);
            this.tbColor.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tbColor.Location = new System.Drawing.Point(3, 3);
            this.tbColor.Name = "tbColor";
            this.tbColor.RowCount = 2;
            this.tbColor.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tbColor.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tbColor.Size = new System.Drawing.Size(154, 71);
            this.tbColor.TabIndex = 0;
            // 
            // pnlBackColor
            // 
            this.pnlBackColor.AutoSize = true;
            this.pnlBackColor.Controls.Add(this.lblBackColor);
            this.pnlBackColor.Controls.Add(this.lblBack);
            this.pnlBackColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlBackColor.Location = new System.Drawing.Point(80, 28);
            this.pnlBackColor.Name = "pnlBackColor";
            this.pnlBackColor.Size = new System.Drawing.Size(71, 40);
            this.pnlBackColor.TabIndex = 1;
            this.pnlBackColor.Visible = false;
            // 
            // lblBack
            // 
            this.lblBack.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblBack.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lblBack.Location = new System.Drawing.Point(0, 0);
            this.lblBack.Name = "lblBack";
            this.lblBack.Size = new System.Drawing.Size(71, 16);
            this.lblBack.TabIndex = 0;
            this.lblBack.Text = "BackColor";
            this.lblBack.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // pnlForeColor
            // 
            this.pnlForeColor.AutoSize = true;
            this.pnlForeColor.Controls.Add(this.lblForeColor);
            this.pnlForeColor.Controls.Add(this.lblFore);
            this.pnlForeColor.Dock = System.Windows.Forms.DockStyle.Top;
            this.pnlForeColor.Location = new System.Drawing.Point(3, 28);
            this.pnlForeColor.Name = "pnlForeColor";
            this.pnlForeColor.Size = new System.Drawing.Size(71, 40);
            this.pnlForeColor.TabIndex = 0;
            this.pnlForeColor.Visible = false;
            // 
            // lblFore
            // 
            this.lblFore.Dock = System.Windows.Forms.DockStyle.Top;
            this.lblFore.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lblFore.Location = new System.Drawing.Point(0, 0);
            this.lblFore.Name = "lblFore";
            this.lblFore.Size = new System.Drawing.Size(71, 16);
            this.lblFore.TabIndex = 1;
            this.lblFore.Text = "ForeColor";
            this.lblFore.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tbArcAngle
            // 
            this.tbArcAngle.AutoSize = true;
            this.tbArcAngle.ColumnCount = 1;
            this.tbArcAngle.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tbArcAngle.Controls.Add(this.trbSweepAngle, 0, 3);
            this.tbArcAngle.Controls.Add(this.lblStartAngle, 0, 0);
            this.tbArcAngle.Controls.Add(this.lblSweepAngle, 0, 2);
            this.tbArcAngle.Controls.Add(this.trbStartAngle, 0, 1);
            this.tbArcAngle.Dock = System.Windows.Forms.DockStyle.Top;
            this.tbArcAngle.Location = new System.Drawing.Point(3, 420);
            this.tbArcAngle.Name = "tbArcAngle";
            this.tbArcAngle.RowCount = 4;
            this.tbArcAngle.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tbArcAngle.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tbArcAngle.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tbArcAngle.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tbArcAngle.Size = new System.Drawing.Size(154, 94);
            this.tbArcAngle.TabIndex = 0;
            this.tbArcAngle.Visible = false;
            // 
            // trbSweepAngle
            // 
            this.trbSweepAngle.AutoSize = false;
            this.trbSweepAngle.Dock = System.Windows.Forms.DockStyle.Top;
            this.trbSweepAngle.Location = new System.Drawing.Point(3, 63);
            this.trbSweepAngle.Maximum = 360;
            this.trbSweepAngle.Name = "trbSweepAngle";
            this.trbSweepAngle.Size = new System.Drawing.Size(148, 28);
            this.trbSweepAngle.TabIndex = 3;
            this.trbSweepAngle.Value = 200;
            this.trbSweepAngle.ValueChanged += new System.EventHandler(this.TrbSweepAngle_ValueChanged);
            // 
            // lblStartAngle
            // 
            this.lblStartAngle.AutoSize = true;
            this.lblStartAngle.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblStartAngle.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lblStartAngle.Location = new System.Drawing.Point(3, 0);
            this.lblStartAngle.Name = "lblStartAngle";
            this.lblStartAngle.Size = new System.Drawing.Size(148, 13);
            this.lblStartAngle.TabIndex = 0;
            this.lblStartAngle.Text = "StartAngle: 90";
            this.lblStartAngle.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // lblSweepAngle
            // 
            this.lblSweepAngle.AutoSize = true;
            this.lblSweepAngle.Dock = System.Windows.Forms.DockStyle.Fill;
            this.lblSweepAngle.Font = new System.Drawing.Font("Microsoft Sans Serif", 8.25F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.lblSweepAngle.Location = new System.Drawing.Point(3, 47);
            this.lblSweepAngle.Name = "lblSweepAngle";
            this.lblSweepAngle.Size = new System.Drawing.Size(148, 13);
            this.lblSweepAngle.TabIndex = 1;
            this.lblSweepAngle.Text = "SweepAngle: 200";
            this.lblSweepAngle.TextAlign = System.Drawing.ContentAlignment.MiddleLeft;
            // 
            // trbStartAngle
            // 
            this.trbStartAngle.AutoSize = false;
            this.trbStartAngle.Dock = System.Windows.Forms.DockStyle.Top;
            this.trbStartAngle.Location = new System.Drawing.Point(3, 16);
            this.trbStartAngle.Maximum = 180;
            this.trbStartAngle.Name = "trbStartAngle";
            this.trbStartAngle.Size = new System.Drawing.Size(148, 28);
            this.trbStartAngle.TabIndex = 2;
            this.trbStartAngle.Value = 90;
            this.trbStartAngle.ValueChanged += new System.EventHandler(this.TrbStartAngle_ValueChanged);
            // 
            // tableLayoutPanel1
            // 
            this.tableLayoutPanel1.AutoSize = true;
            this.tableLayoutPanel1.BackColor = System.Drawing.SystemColors.Control;
            this.tableLayoutPanel1.CellBorderStyle = System.Windows.Forms.TableLayoutPanelCellBorderStyle.Single;
            this.tableLayoutPanel1.ColumnCount = 2;
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle(System.Windows.Forms.SizeType.Percent, 50F));
            this.tableLayoutPanel1.Controls.Add(this.lblClosedCurve, 1, 2);
            this.tableLayoutPanel1.Controls.Add(this.lblCurve, 1, 3);
            this.tableLayoutPanel1.Controls.Add(this.lblArc, 0, 3);
            this.tableLayoutPanel1.Controls.Add(this.lblLine, 0, 0);
            this.tableLayoutPanel1.Controls.Add(this.lblPolygon, 1, 0);
            this.tableLayoutPanel1.Controls.Add(this.lblRect, 0, 1);
            this.tableLayoutPanel1.Controls.Add(this.lblPath, 1, 1);
            this.tableLayoutPanel1.Controls.Add(this.lblEllipse, 0, 2);
            this.tableLayoutPanel1.Dock = System.Windows.Forms.DockStyle.Top;
            this.tableLayoutPanel1.Location = new System.Drawing.Point(0, 24);
            this.tableLayoutPanel1.Name = "tableLayoutPanel1";
            this.tableLayoutPanel1.RowCount = 4;
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.RowStyles.Add(new System.Windows.Forms.RowStyle());
            this.tableLayoutPanel1.Size = new System.Drawing.Size(160, 101);
            this.tableLayoutPanel1.TabIndex = 0;
            // 
            // label8
            // 
            this.label8.Dock = System.Windows.Forms.DockStyle.Top;
            this.label8.Font = new System.Drawing.Font("Eras Bold ITC", 12F, System.Drawing.FontStyle.Bold, System.Drawing.GraphicsUnit.Point, ((byte)(254)));
            this.label8.Location = new System.Drawing.Point(0, 0);
            this.label8.Name = "label8";
            this.label8.Size = new System.Drawing.Size(160, 24);
            this.label8.TabIndex = 49;
            this.label8.Text = "Shape";
            this.label8.TextAlign = System.Drawing.ContentAlignment.MiddleCenter;
            // 
            // tableLayoutPanel3
            // 
            this.tableLayoutPanel3.ColumnCount = 2;
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.ColumnStyles.Add(new System.Windows.Forms.ColumnStyle());
            this.tableLayoutPanel3.Controls.Add(this.pnlPaint, 0, 0);
            this.tableLayoutPanel3.Controls.Add(this.pnlContainer, 0, 0);
            this.tableLayoutPanel3.Dock = System.Windows.Forms.DockStyle.Fill;
            this.tableLayoutPanel3.Location = new System.Drawing.Point(0, 24);
            this.tableLayoutPanel3.Name = "tableLayoutPanel3";
            this.tableLayoutPanel3.RowCount = 1;
            this.tableLayoutPanel3.RowStyles.Add(new System.Windows.Forms.RowStyle(System.Windows.Forms.SizeType.Percent, 100F));
            this.tableLayoutPanel3.Size = new System.Drawing.Size(1218, 702);
            this.tableLayoutPanel3.TabIndex = 0;
            // 
            // FrmMain
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1218, 726);
            this.Controls.Add(this.tableLayoutPanel3);
            this.Controls.Add(this.pnlMenu);
            this.DoubleBuffered = true;
            this.KeyPreview = true;
            this.Name = "FrmMain";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Paint";
            this.toolTip.SetToolTip(this, "Create by 18110377");
            this.WindowState = System.Windows.Forms.FormWindowState.Maximized;
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.FrmMain_FormClosing);
            this.SizeChanged += new System.EventHandler(this.FrmMain_SizeChanged);
            this.KeyDown += new System.Windows.Forms.KeyEventHandler(this.FrmMain_KeyDown);
            this.KeyUp += new System.Windows.Forms.KeyEventHandler(this.FrmMain_KeyUp);
            this.Leave += new System.EventHandler(this.FrmMain_Leave);
            this.pnlMenu.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.trbPenWidth)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.picTextFill)).EndInit();
            this.pnlContainer.ResumeLayout(false);
            this.pnlContainer.PerformLayout();
            this.tableLayoutPanel2.ResumeLayout(false);
            this.tableLayoutPanel2.PerformLayout();
            this.pnlLinearAngle.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.trbLinearAngle)).EndInit();
            this.pnlTextFill.ResumeLayout(false);
            this.pnlHatchFill.ResumeLayout(false);
            this.pnlPenType.ResumeLayout(false);
            this.pnlPenWidth.ResumeLayout(false);
            this.pnlDashStyle.ResumeLayout(false);
            this.tbColor.ResumeLayout(false);
            this.tbColor.PerformLayout();
            this.pnlBackColor.ResumeLayout(false);
            this.pnlForeColor.ResumeLayout(false);
            this.tbArcAngle.ResumeLayout(false);
            this.tbArcAngle.PerformLayout();
            ((System.ComponentModel.ISupportInitialize)(this.trbSweepAngle)).EndInit();
            ((System.ComponentModel.ISupportInitialize)(this.trbStartAngle)).EndInit();
            this.tableLayoutPanel1.ResumeLayout(false);
            this.tableLayoutPanel3.ResumeLayout(false);
            this.ResumeLayout(false);

        }

        #endregion
        private System.Windows.Forms.Panel pnlPaint;
        private System.Windows.Forms.ColorDialog colorDialog;
        private System.Windows.Forms.Button btnNew;
        private System.Windows.Forms.Button btnSave;
        private System.Windows.Forms.Label lblSelect;
        private System.Windows.Forms.Panel pnlMenu;
        private System.Windows.Forms.ComboBox cmbPenType;
        private System.Windows.Forms.ComboBox cmbDashStyle;
        private System.Windows.Forms.Label lblForeColor;
        private System.Windows.Forms.Label lblFill;
        private System.Windows.Forms.ToolTip toolTip;
        private System.Windows.Forms.TrackBar trbPenWidth;
        private System.Windows.Forms.ComboBox cmbHatchFill;
        private System.Windows.Forms.Label lblZoom;
        private System.Windows.Forms.Panel pnlContainer;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel1;
        private System.Windows.Forms.Label lblRect;
        private System.Windows.Forms.Label lblLine;
        private System.Windows.Forms.Label lblPolygon;
        private System.Windows.Forms.Label lblClosedCurve;
        private System.Windows.Forms.Label lblCurve;
        private System.Windows.Forms.Label lblArc;
        private System.Windows.Forms.Label lblPath;
        private System.Windows.Forms.Label lblEllipse;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.Label lblWidth;
        private System.Windows.Forms.PictureBox picTextFill;
        private System.Windows.Forms.Label lblTextFill;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label8;
        private System.Windows.Forms.Panel pnlTextFill;
        private System.Windows.Forms.Panel pnlPenWidth;
        private System.Windows.Forms.Panel pnlHatchFill;
        private System.Windows.Forms.Panel pnlDashStyle;
        private System.Windows.Forms.Panel pnlPenType;
        private System.Windows.Forms.Button btnBrowse;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel2;
        private System.Windows.Forms.Label lblBackColor;
        private System.Windows.Forms.Panel pnlBackColor;
        private System.Windows.Forms.Label lblBack;
        private System.Windows.Forms.Panel pnlForeColor;
        private System.Windows.Forms.Label lblFore;
        private System.Windows.Forms.TableLayoutPanel tbColor;
        private System.Windows.Forms.Label lblGroup;
        private System.Windows.Forms.Panel pnlLinearAngle;
        private System.Windows.Forms.TrackBar trbLinearAngle;
        private System.Windows.Forms.Label lblLinearAngle;
        private System.Windows.Forms.TableLayoutPanel tbArcAngle;
        private System.Windows.Forms.Label lblStartAngle;
        private System.Windows.Forms.Label lblSweepAngle;
        private System.Windows.Forms.TrackBar trbSweepAngle;
        private System.Windows.Forms.TrackBar trbStartAngle;
        private System.Windows.Forms.TableLayoutPanel tableLayoutPanel3;
        private System.Windows.Forms.Label lblBorderColor;
        private System.Windows.Forms.CheckBox ckbBorder;
    }
}

