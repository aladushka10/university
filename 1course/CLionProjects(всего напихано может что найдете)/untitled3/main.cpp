#include <iostream>
#include <string>
using namespace std;

int main()
{
    setlocale(LC_ALL, "RUSSIAN");
    string s;
    cout << " input a string s:";
    getline(cin,s);
    s +=" ";
    while (s.find("  ") != -1)
    {
        int a = s.find("  ");
        s.erase(a, 1);
    }

    if (s[0] == ' ')
        s.erase(0, 1);

    bool find = false;
    while (s.find( " " ) != -1)
    {
        int a = s.find(" ");
        string currentWord;
        currentWord = s.substr(0, a);
        s.erase(0, a+1);
        bool sort = true;
        for (int i = 0; i < currentWord.size()-1; i++)
            if (s[i+1] < s[i])
            {
                sort = false;
                break;
            }
        if (sort)
        {
            cout << " слово,в котором символы идут в строгом возрастании их кодов: " << currentWord << endl;
            find = true;
            break;
        }
    }
    if (!find)
        cout << "нет слов,в которых символы идут в строгом возрастании их кодов ";
    return 0;
}