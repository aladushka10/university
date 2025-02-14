#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <list>
using namespace std;
typedef list<pair <string, string>> list_bookList ;
typedef map <int, list_bookList> map_booksInfo;
int main() {
    map_booksInfo booksInfo;
    list_bookList bookList;
    fstream fin, fout;
    fin.open("DATA.TXT", ios:: in);
    if(!fin)
    {
        cerr << "not such file" << endl;
        return 1;
    }
    if(!fin.good())
    {
        cerr << "empty file" << endl;
        return 1;
    }
    string str, word;
    string year;
    string book;
    string author;
    while(getline(fin, str))
    {
        if(str != "" && isalpha(str[0]))
        {
            stringstream ss;
            ss << str;
            getline(ss, year, ';');
            getline(ss, book, ';');
            getline(ss, author, ';');
            int iyear = stoi(year);
            booksInfo[iyear].push_back({book, author});
        }
    }
   ifstream fin1("QUERY.TXT");
    if(!fin)
    {
        cerr << "not such file" << endl;
        return 1;
    }
    if(!fin1.good())
    {
        cerr << "empty file" << endl;
        return 1;
    }
    fout.open("ANSWER.TXT");
    if (!fout)
    {
        cerr << "not such file"<< endl;
        return 1;
    }
    if(!fout.good())
    {
        cerr << "empty file" << endl;
        return 1;
    }
    map_booksInfo::iterator im;
    list_bookList::iterator it;
    while(getline(fin, str))
    {
        if(str[0] == '1')
        {
            str.erase(0,2);
            fout << ";" << endl;

        }
    }
    return 0;
}
