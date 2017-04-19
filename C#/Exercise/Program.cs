using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Exercise
{
    class Program
    {
<<<<<<< HEAD
        static void Main(string[] args)
        {

            Book book = new Book();
            book.author = "Helo";
            book.setTitle("world");
            book.setCopies(12);
            book.setPrice(100.00d);

            Console.WriteLine(book);
            Console.ReadKey();
=======
        static List<Publication> list = new List<Publication>();

        static void Main(string[] args)
        {
            Console.WriteLine("Hello World");
            Publication pub = new Publication();
            pub.setTitle("I love Programming");
            pub.setPrice(10.99);
            pub.setCopies(10);

            Book book = new Exercise.Book();
            book.Author = "Fred Carella";

            book.setTitle("I love linux");
            book.Title = "Joe's Awesome";
            book.setCopies(12);
            book.setPrice(100d);

            list.Add(pub);
            list.Add(book);

            foreach (Publication p in list) {
                Console.WriteLine(p);
            }



//            Console.WriteLine(pub);
//            Console.WriteLine(book);
>>>>>>> 937e080603bdfaefcb646f6718fe2efb7d46f8d8
        }
    }
}
