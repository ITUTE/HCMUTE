using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Windows.Forms;

namespace SimpleMath
{
    public class MyNum
    {
        #region Fields
        private decimal value;
        #endregion
        #region Properties
        public decimal Value { get => value; set => this.value = value; }
        #endregion
        #region Constructors
        public MyNum()
        {
            Value = 0;
        }
        public MyNum(string str)
        {
            Value = Convert.ToDecimal(str);
        }
        public MyNum(decimal num)
        {
            Value = num;
        }
        #endregion
        #region Operators
        public static MyNum operator +(MyNum num1, MyNum num2) => new MyNum(num1.Value + num2.Value);
        public static MyNum operator -(MyNum num1, MyNum num2) => new MyNum(num1.Value - num2.Value);
        public static MyNum operator *(MyNum num1, MyNum num2) => new MyNum(num1.Value * num2.Value);
        public static MyNum operator /(MyNum num1, MyNum num2)
        {
            if (num2.Value == 0)
                throw new DivideByZeroException();
            return new MyNum(num1.Value / num2.Value);
        }
        public static MyNum operator -(MyNum num) => new MyNum(-num.Value);
        #endregion

        public override string ToString()
        {
            return Value.ToString();
        }
    }
}