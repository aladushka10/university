#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>
#include <fstream>

using namespace std;

class Author
{
public:
    string name;
    string surname;
    string patronymic;
    Author() {name = "Ivan"; surname = "Ivanov"; patronymic = "Ivanovich";}
    Author(string n, string s, string p) {name = n; surname = s; patronymic = p;}
    bool operator < (const Author& a) const
    {
        return name < a.name;
    }
    bool operator ==(const Author& a) const
    {
        return (name == a.name && surname == a.surname && patronymic == a.patronymic);
    }
};

class Book
{
public:
    int number;
    set <Author> authorList;
    string title;
    int year;
    Book() {}
    Book(int n, set <Author> a, string t, int y) {number = n; authorList = a; title = t; year = y;}
    bool operator < (const Book& b) const
    {
        return title < b.title;
    }
    bool operator ==(const Book& b) const
    {
        return (number == b.number && authorList == b.authorList && title == b.title && year == b.year);
    }
};

class Library
{
public:
    set <Book> bookList;
    Library() {}
    Library (set <Book> b) {bookList = b;}
    void add(Book b)
    {
        bookList.insert(b);
        return ;
    }
    void del(Book b)
    {
        bookList.erase(b);
        return ;
    }
    set <Book> searchByTitle(string t)
    {
        set <Book> ans;
        for (auto now : bookList)
        {
            if (now.title == t)
            {
                ans.insert(now);
            }
        }
        return ans;
    }
    set <Book> searchByAuthor(const Author& a)
    {
        set <Book> ans;
        for (auto now : bookList)
        {
            for (auto it : now.authorList)
            {
                if (it == a)
                {
                    ans.insert(now);
                    break;
                }
            }
        }
        return ans;
    }
    void delAuthor(const Book &b, const Author& a)
    {
        if (bookList.find(b) != bookList.end())
        {
            Book c = b;
            c.authorList.erase(a);
            bookList.erase(b);
            bookList.insert(c);
        }
        return ;
    }
    void addAuthor(const Book &b, const Author& a)
    {
        if (bookList.find(b) != bookList.end())
        {
            Book c = b;
            c.authorList.insert(a);
            bookList.erase(b);
            bookList.insert(c);
        }
        return ;
    }
};

istream& operator >>(istream& in, Author& a)
{
    in >> a.surname >> a.name >> a.patronymic;
    return in;
}

istream& operator >>(istream& in, Book& b)
{
    in >> b.number;
    int cnt; in >> cnt;
    for (int i = 0; i < cnt; i++)
    {
        Author a;
        in >> a;
        b.authorList.insert(a);
    }
    string tit;
    getline(in, tit);
    getline(in, tit);
    b.title = tit;
    int y; in >> y;
    b.year = y;
    return in;
}

ostream& operator <<(ostream& out, Book& b)
{
    out << b.number << endl;
    out << b.authorList.size() << endl;
    for (auto now : b.authorList)
    {
        out << now.surname << " " << now.name << " " << now.patronymic << endl;
    }
    out << b.title << endl;
    out << b.year << endl;
    return out;
}

int main()
{
    fstream fin, fout;
    try
    {
        fin.open("in.txt", ios::in);
        if (!fin.is_open())
            throw 1;
        fout.open("out.txt", ios::out);
        if (!fout.is_open())
            throw 2;
        if (fin.peek() == EOF)
            throw 3;
    }
    catch(int error)
    {
        switch(error)
        {
        case 1:
            cout << "Input file isn't open";
            break;
        case 2:
            cout << "Output file isn't open";
            fin.close();
            break;
        case 3:
            cout << "Input file is empty";
            fin.close();
            fout.close();
            break;
        default:
            cout << "Unexpected error";
            fin.close();
            fout.close();
            break;
        }
    }
    int n;
    fin >> n;
    Library l;
    for (int i = 0; i < n; i++)
    {
        Book b;
        fin >> b;
        l.add(b);
    }
    fout << n << endl;
    for (auto now : l.bookList)
    {
        fout << now << endl;
    }
    return 0;
}
