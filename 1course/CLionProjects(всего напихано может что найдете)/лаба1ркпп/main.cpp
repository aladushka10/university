#include <iostream>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

class Author{
private:
    string name;
    string surname;
    string patronymic;
public:
    Author(){name = "Ivan"; surname = "Ivanov"; patronymic = "Ivanovich";}
    Author(string n, string s, string p){name = n; surname = s; patronymic = p;}
    bool operator < (const Author& a) const{
        return surname < a.surname;
    }
    bool operator == (const Author& a) const{
        return (name == a.name && surname == a.surname && patronymic == a.patronymic);
    }
    string getName() { return name; }
    string getSurname() { return surname; }
    string getPatronymic() { return patronymic; }
    friend istream& operator >>(istream& in, Author& a);
    friend class Book;
};

class Book{
private:
    int number;
    set <Author> authorList;
    string title;
    int year;
public:
    Book(){}
    Book(int n, set <Author> a, string t, int y){number = n; authorList = a; title = t, year = y;}
    bool operator < (const Book& b) const{
        return title < b.title;
    }
    bool operator == (const Book& b) const{
        return (number == b.number && authorList == b.authorList && title == b.title && year == b.year);
    }
    void delAuthor(const Author& a)
    {
        authorList.erase(a);
        return ;
    }
    void addAuthor(const Author& a)
    {
        authorList.insert(a);
        return ;
    }
    string getTitle() { return title; }
    friend istream& operator >>(istream& in, Book& b);
    friend ostream& operator <<(ostream& out, const Book& b);
    friend class Library;
};

class Library{
private:
    map <Book, int> bookList;
public:
    Library(){}
    Library(map <Book, int> b){bookList = b;}
    void  add(const Book& b){
        if (bookList.find(b) != bookList.end())
        {
            bookList[b]++;
        }
        else
        {
            bookList.insert({b, 1});
        }
        return ;
    }
    void del(const Book& b){
        if (bookList.find(b) != bookList.end())
        {
            if (bookList[b] > 1)
                bookList[b]--;
            else
                bookList.erase(b);
        }
        return ;
    }
    map <Book, int> searchByTitle(string t)
    {
        map <Book, int> ans;
        for (auto now = bookList.begin(); now != bookList.end(); now++)
        {
            if ((*now).first.title == t)
            {
                ans.insert(*now);
            }
        }
        return ans;
    }
    map <Book, int> searchByAuthor(const Author& a)
    {
        map <Book, int> ans;
        for (auto now = bookList.begin(); now != bookList.end(); now++)
        {
            for (auto it = (*now).first.authorList.begin(); it != (*now).first.authorList.end(); it++)
            {
                if (*it == a)
                {
                    ans.insert(*now);
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
            int temp = bookList[b];
            bookList.erase(b);
            bookList.insert({c, temp});
        }
        return ;
    }
    void addAuthor(const Book &b, const Author& a)
    {
        if (bookList.find(b) != bookList.end())
        {
            Book c = b;
            c.authorList.insert(a);
            int temp = bookList[b];
            bookList.erase(b);
            bookList.insert({c, temp});
        }
        return ;
    }
    friend ostream& operator <<(ostream& out, const Library& l);
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

ostream& operator <<(ostream& out, const Book& b)
{
    out << b.number << endl;
    out << b.authorList.size() << endl;
    for (auto now = b.authorList.begin(); now != b.authorList.end(); now++)
    {
        Author a = *now;
        out << a.getSurname() << " " << a.getName() << " " << a.getPatronymic() << endl;
    }
    out << b.title << endl;
    out << b.year << endl;
    return out;
}

ostream& operator <<(ostream& out, const Library& l)
{
    for (auto now = l.bookList.begin(); now != l.bookList.end(); now++)
        out << (*now).first << "Количество экземпляров: " << (*now).second << endl;
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
    int n; //колво книг
    fin >> n;
    Library l;
    Book c;
    string t;
    for (int i = 0; i < n; i++)
    {
        Book b;
        fin >> b;
        l.add(b);
        if (i == 0)
            c = b;
        if(i == 1)
            t = b.getTitle();
    }
    fout << n << endl;
    fout << l << endl;
    fout << endl;
    Author a("Evgeniy", "Roflo", "Evgenievich");
    l.delAuthor(c, a);
    c.delAuthor(a);
    Author newA("Vitaliy", "Sladkiy", "Leonidovich");
    l.addAuthor(c, newA);
    fout << n << endl;
    fout << l << endl;
    fout << endl;
    map <Book, int> s2 = l.searchByTitle(t);
    fout << "Search by title: " << endl;
    for (auto now = s2.begin(); now != s2.end(); now++)
    {
        fout << (*now).first << "Количество экземпляров: " << (*now).second << endl;
    }
    fout << endl;
    map <Book, int> s3 = l.searchByAuthor(newA);
    fout << "Search by name: " << endl;
    for (auto now = s3.begin(); now != s3.end(); now++)
    {
        fout << (*now).first << "Количество экземпляров: " << (*now).second << endl;
    }
    fin.close();
    fout.close();
    return 0;
}
