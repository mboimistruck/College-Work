using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Program
    {
        public static List<Book> items = new List<Book>();

        static void Main(string[] args)
        {
            string check = "y";
            while(check == "y")
            {
                gatherBook();
                Console.WriteLine("Add another book? (y/n): ");
                check = Console.ReadLine();
                Console.WriteLine("");

            }

            DBConnection db = new DBConnection();
            for(int i = 0; i < items.Count(); i++)
            {
                db.insertBook(items[i]);

            }

            db.listBooks();
            Console.ReadKey();

        }
        static void gatherBook()
        {
            Book book = new Book();
            Console.WriteLine("Enter a title: ");
            book.Title = Console.ReadLine();
            Console.WriteLine("Enter an author: ");
            book.Author = Console.ReadLine();
            Console.WriteLine("Enter a price: ");
            book.Price = double.Parse(Console.ReadLine());
            items.Add(book);
        }
    }
}
