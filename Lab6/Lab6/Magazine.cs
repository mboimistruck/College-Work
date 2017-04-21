using System;

namespace Lab6
{

    class Magazine : Publication
    {
        private int orderQty = 10;

        public Magazine()
        {

        }

        public void adjustQty(int n)
        {
            this.orderQty = n;
        }


        override public void sellCopy()
        {

        }

        override public double getPrice()
        {
            return getPrice();
        }

    }
}