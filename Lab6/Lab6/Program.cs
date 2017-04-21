// Database side will only work with books, was not a requirement so I did not finish it for magazines


using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Lab6
{
    class Program
    {
        public static List<Book> books = new List<Book>();
        public static List<Magazine> magazines = new List<Magazine>();

        static void Main(string[] args)
        {
            while (true)
            {
                Console.WriteLine("\nMAIN\n_________________________\n");
                Console.WriteLine("1. Books\n2. Tickets\n3. Magazines\n4. Quit");
                int userInput = int.Parse(Console.ReadLine());

                if (userInput == 1)
                {
                    bookMenu();
                }
                else if (userInput == 2)
                {
                    ticketMenu();
                }
                else if (userInput == 3)
                {
                    magazineMenu();
                }
                else if (userInput == 4)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Invalid input");
                }
            }

            DBConnection db = new DBConnection();
            if (books.Count() > 0)
            {
                for (int i = 0; i < books.Count(); i++)
                {
                    db.insertBook(books[i]);

                }

                db.listBooks();
            }
            if (magazines.Count() > 0)
            {
                for (int i = 0; i < magazines.Count(); i++)
                {
                    db.insertMagazine(magazines[i]);

                }

                db.listMagazines();
            }
            Console.ReadKey();

        }
        static void bookMenu()
        {
            Book book = new Book();
            Console.WriteLine("Enter a title: ");
            book.Title = Console.ReadLine();

            Console.WriteLine("Enter an author: ");
            book.Author = Console.ReadLine();

            Console.WriteLine("Enter a price: ");
            book.Price = double.Parse(Console.ReadLine());
            books.Add(book);
        }
        static void ticketMenu()
        {
            Ticket ticket = new Ticket();
            Console.WriteLine("\nTICKETS\n_________________________\n");
            Console.WriteLine("1. Sell a Ticket\n2. Quit");
            while (true)
            {
                int userInput = int.Parse(Console.ReadLine());

                if (userInput == 1)
                {
                    ticket.sellCopy();
                    Console.WriteLine("Ticket sold!");
                }
                else if (userInput == 2)
                {
                    break;
                }
                else
                {
                    Console.WriteLine("Invalid input");
                }
            }
        }
        public static void magazineMenu()
        {
            
            Magazine magazine = new Magazine();
            Console.WriteLine("Enter a title: ");
            magazine.Title = Console.ReadLine();

            Console.WriteLine("Enter a price: ");
            magazine.Price = double.Parse(Console.ReadLine());
            magazines.Add(magazine);
        }
    }
}
