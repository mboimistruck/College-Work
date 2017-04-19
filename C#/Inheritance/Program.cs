using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Inheritance
{
    class Program
    {
        static void Main(string[] args)
        {
            A classA = new A();
            B classB = new B();
            classB.X = 100;
            classB.Y = 200;
            Console.WriteLine("x="+classB.X+" y="+classB.Y);
        }
    }
}
