using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Book : Publication
    {
        private String author;
            
        public String Author {
            get { return author; }
            set { author = value; }
        }

        override public void sellCopy()
        {

        }
        override public Double getPrice()
        {
            return Price;
        }
        public Book() {

        }
        public override string ToString()
        {
           return "Im a book";
        }
    }
}
