#include <iostream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    string s, poly;
    int counter = 0;
    cout << "Введите строку s: " << endl;
    getline(cin, s);
    s += " ";
    while (s.find("  ") != -1)
    {
        int ind = s.find("  ");
        s.erase(ind, 1);
    }
    if (s==" ") {
        cout << "Введена пустая строка.";
        return 0;
    }
    if (s[0] == ' ')
        s.erase(0, 1);
    bool isFind = false;
    while (s.find(" ") != -1)
    {
        int ind = s.find(" ");
        string currentWord;
        currentWord = s.substr(0, ind);
        s.erase(0, ind + 1);
        bool isNumber = true;
        bool isPoly = true;
        for (int i = 0; i < currentWord.size(); i++)
            if (not isdigit(currentWord[i]))
            {
                isNumber = false;
                break;
            }
        if (isNumber)
        {
            for (int i = 0; i < (currentWord.size() / 2); i++)
                if (currentWord[i] != currentWord[currentWord.size() - 1 - i]) {
                    isPoly = false;
                }
            if ((isPoly == true) && (counter < 2)) {
                counter++;
                poly = currentWord;
            }
        }
    }
    if (poly.empty() == true)
        cout << "Палиндромов нет." << endl;
    else if (counter == 1)
        cout << "В ряду один палиндром: " << poly << endl;
    else
        cout << "Второй палиндром в ряду: " << poly;
    return 0;
}