using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace QuadraticEquation
{
    public class QuadEquation
    {
        #region Fields
        private double numA;
        private double numB;
        private double numC;
        #endregion
        #region Properties
        public double NumA { get => numA; set => numA = value; }
        public double NumB { get => numB; set => numB = value; }
        public double NumC { get => numC; set => numC = value; }
        public List<double> Result = new List<double>();
        public ResultCase Case;
        public enum ResultCase
        {
            NoRoot,
            OneRoot,
            TwoRoot,
            InfRoot
        }
        #endregion
        #region Constructors
        public QuadEquation()
        {
            NumA = NumB = NumC = 0;
        }
        public QuadEquation(double a, double b, double c)
        {
            NumA = a;
            NumB = b;
            NumC = c;
        }
        public QuadEquation(string a, string b, string c)
        {
            if (a == "") NumA = 0f; else NumA = Convert.ToDouble(a);
            if (b == "") NumB = 0f; else NumB = Convert.ToDouble(b);
            if (c == "") NumC = 0f; else NumC = Convert.ToDouble(c);
        }
        #endregion
        #region Methods
        public string Solve()
        {
            if (NumA == 0)
            {
                if (NumB==0)
                {
                    if (NumC == 0)
                    {
                        Case = ResultCase.InfRoot;
                        return "InfRoot.";
                    }
                    else
                    {
                        Case = ResultCase.NoRoot;
                        return "No Root.";
                    }
                }
                else
                {
                    Case = ResultCase.OneRoot;
                    Result.Add(-NumC / NumB);
                    return $"Root = {Result[0]}";
                }
            }
            else
            {
                double delta = NumB * NumB - 4 * NumA * NumC;
                if (delta < 0)
                {
                    Case = ResultCase.NoRoot;
                    return "No Root.";
                }
                else if (delta == 0)
                {
                    Case = ResultCase.OneRoot;
                    Result.Add(-NumB / (2 * NumA));
                    return $"Root = {Result[0]}";
                }
                else
                {
                    Case = ResultCase.TwoRoot;
                    Result.Add((-NumB + Math.Sqrt(delta)) / (4 * NumA));
                    Result.Add((-NumB - Math.Sqrt(delta)) / (4 * NumA));
                    return $"First root = {Result[0]}\r\nSecond root = {Result[1]}";
                }
            }
        }
        #endregion
    }
}