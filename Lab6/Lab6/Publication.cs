using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    public abstract class Publication : SaleableItem
    {
        private String title;
        private Double price;
        private int copies;
        public String Title
        {
            get { return title; }
            set { title = value; }
        }
        public Double Price
        {
            get { return price; }
            set { price = value; }
        }
        public int Copies
        {
            get { return copies; }
            set { copies = value; }
        }

        public Publication() {
            title = "No Title";
            price = 0.0d;
            copies = 10;
        }

        public abstract void sellCopy();
        public abstract double getPrice();
    }
}
