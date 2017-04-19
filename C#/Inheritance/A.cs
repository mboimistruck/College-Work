using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
   
    public class A
    {
        private int x;
        private int y;
        public int getX() {
            return x;
        }

        public int getY() {
            return y;
        }

        public void setX(int x)
        {
            this.x = x;
        }
        public void setY(int y)
        {
            this.y = y;
        }

        // properties
        public int X
        {
            get { return x; }
            set { x = value; }
        }
        public int Y
        {
            get { return y; }
            set { y = value; }
        }
        public A() {
            x = 10;
            y = 20;
            Console.WriteLine("In A Constructor");
            Console.WriteLine("x=" + getX() + " y=" + getY());
        }
    }
    
}
