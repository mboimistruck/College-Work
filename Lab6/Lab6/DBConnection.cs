// Credit to user on StackOverflow for the base of this class

using MySql.Data;
using System.Collections.Generic;
using MySql.Data.MySqlClient;
using System;

namespace Lab6
{
    class DBConnection
    {
        public DBConnection()
        {
        }

        private string databaseName = string.Empty;
        public string DatabaseName
        {
            get { return databaseName; }
            set { databaseName = value; }
        }

        public string Password { get; set; }
        private MySqlConnection connection = null;
        public MySqlConnection Connection
        {
            get { return connection; }
        }

        private static DBConnection _instance = null;
        public static DBConnection Instance()
        {
            if (_instance == null)
                _instance = new DBConnection();
            return _instance;
        }

        public bool IsConnect()
        {
            bool result = true;
            if (Connection == null)
            {
                if (string.IsNullOrEmpty(databaseName))
                {
                    result = false;
                }
                string connstring = string.Format("Server=127.0.0.1; database=lab6; UID=root; password=itstudies12345", databaseName);
                connection = new MySqlConnection(connstring);
                connection.Open();
                result = true;
            }

            return result;
        }

        public void Close()
        {
            connection.Close();
        }

        public void listBooks()
        {
            Console.WriteLine("\n*List of Books*\n");
            var dbCon = DBConnection.Instance();
            dbCon.DatabaseName = "lab6";
            if (dbCon.IsConnect())
            {
                string query = "SELECT * FROM book";
                var cmd = new MySqlCommand(query, dbCon.Connection);
                var reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    string idColumn = reader.GetString(0);
                    string titleColumn = reader.GetString(1);
                    string authorColumn = reader.GetString(2);
                    string priceColumn = reader.GetString(3);
                    Console.WriteLine(idColumn + ", " + titleColumn + ", " + authorColumn + ", " + priceColumn);
                }
                reader.Close();
            }
        }

        public void listMagazines()
        {
            Console.WriteLine("\n*List of Magazines*\n");
            var dbCon = DBConnection.Instance();
            dbCon.DatabaseName = "lab6";
            if (dbCon.IsConnect())
            {
                string query = "SELECT * FROM magazine";
                var cmd = new MySqlCommand(query, dbCon.Connection);
                var reader = cmd.ExecuteReader();
                while (reader.Read())
                {
                    string idColumn = reader.GetString(0);
                    string titleColumn = reader.GetString(1);
                    string priceColumn = reader.GetString(2);
                    Console.WriteLine(idColumn + ", " + titleColumn + ", " + priceColumn);
                }
                reader.Close();
            }
        }
        public void insertBook(Book book)
        {
            var dbCon = DBConnection.Instance();
            dbCon.DatabaseName = "lab6";
            if (dbCon.IsConnect())
            {
                //string query = "INSERT INTO book(BookTitle, BookAuthor, BookPrice) VALUES ('" + book.Title + "', '" + book.Author + "', '" + book.Price + "')";
                string query = "INSERT INTO book(BookTitle, BookAuthor, BookPrice, Type) VALUES (@Title, @Author, @Price, @Type)";

                var cmd = new MySqlCommand(query, dbCon.Connection);
                cmd.Parameters.Add("@Title", MySqlDbType.VarChar).Value = book.Title;
                cmd.Parameters.Add("@Author", MySqlDbType.VarChar).Value = book.Author;
                cmd.Parameters.Add("@Price", MySqlDbType.Double).Value = book.Price;
                cmd.Parameters.Add("@Type", MySqlDbType.VarChar).Value = "Book";
                cmd.ExecuteNonQuery();

            }
        }
        public void insertMagazine(Magazine magazine)
        {
            var dbCon = DBConnection.Instance();
            dbCon.DatabaseName = "lab6";
            if (dbCon.IsConnect())
            {
                //string query = "INSERT INTO book(BookTitle, BookAuthor, BookPrice) VALUES ('" + book.Title + "', '" + book.Author + "', '" + book.Price + "')";
                string query = "INSERT INTO magazine(MagazineTitle, MagazinePrice, Type) VALUES (@Title, @Price, @Type)";

                var cmd = new MySqlCommand(query, dbCon.Connection);
                cmd.Parameters.Add("@Title", MySqlDbType.VarChar).Value = magazine.Title;
                cmd.Parameters.Add("@Price", MySqlDbType.Double).Value = magazine.Price;
                cmd.Parameters.Add("@Type", MySqlDbType.VarChar).Value = "Magazine";
                cmd.ExecuteNonQuery();

            }
        }
    }
}
