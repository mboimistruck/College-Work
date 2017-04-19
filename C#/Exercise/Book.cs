using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise
{
<<<<<<< HEAD
    class Book:Publication
    {
        public string author {
            get { return author; }
            set { this.author = author; }
        }
        public void orderCopies(int copies) { setCopies(copies); }

        public Book()
        {
            author = "Me";
            setCopies(5);
        }
        public override string ToString()
        {
=======
    public class Book:Publication
    {
        private String author;
        public void orderCopies(int copies) { setCopies(copies); }

        // properties
        public String Author {
            get { return author; }
            set { this.author = value; }
        }

        public Book() {
            author = "Me";
            setCopies(5);
        }

        override public String ToString() {
>>>>>>> 937e080603bdfaefcb646f6718fe2efb7d46f8d8
            return author + " " + base.ToString();
        }
    }
}
