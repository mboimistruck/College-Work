using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise
{
<<<<<<< HEAD
    abstract class Publication
    {
        private string title;
        private double price;
        private int copies;

        public string Title { get {return Title; } set {this.Title = Title; } }
        public string getTitle()
        {
            return title;
        }
        public void setTitle(string title)
        {
            this.title = title;
        }
        public double getPrice()
        {
            return price;
        }
        public void setPrice(double price)
        {
            this.price = price;
        }
        public int getCopies()
        {
            return copies;
        }
        public void setCopies(int copies)
        {
            this.copies = copies;
        }


        /*public string title { get; set; }
        public double price { get; set; }
        public int copies { get; set; }
=======
    public class Publication
    {
        private String title;
        private Double price;
        private int copies;

        public String Title {
            set { title = value; }
            get { return title; }
        }

        public String getTitle() { return title; }
        public void setTitle(String title) { this.title = title; }
        public int getCopies() { return copies; }
        public void setCopies(int copies) { this.copies = copies; }
        public Double getPrice() { return price; }
        public void setPrice(Double price) { this.price = price; }


>>>>>>> 937e080603bdfaefcb646f6718fe2efb7d46f8d8
        public Publication() {
            this.copies = 0;
            this.price = 0.0d;
            this.title = "No Title";
<<<<<<< HEAD
        }*/

        public override String ToString()
        {
            return title + " $" + price + " " + copies;
        }
        public void sellCopy()
        {
            Console.WriteLine("Hello World");
            Console.ReadKey();
            //temp
=======
        }
        override public string ToString() {
            return title + " $" + price + " " + copies;
        }

        public void sellCopy() {
            Console.WriteLine("Sell Copy");
>>>>>>> 937e080603bdfaefcb646f6718fe2efb7d46f8d8
        }
    }
}
