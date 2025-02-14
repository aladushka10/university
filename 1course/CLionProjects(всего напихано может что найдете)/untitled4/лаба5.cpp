#include <iostream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "RUSSIAN");
    string s;
    cout << "Введите строку: ";
    getline(cin, s);
    s += " ";
    while (s.find("  ") != -1)
    {
        int a = s.find("  ");
        s.erase(a, 1);
    }
    if (s == " ") {
        cout << "Введена пустая строка.";
        return 0;
    }
    if (s[0] == ' ')
        s.erase(0, 1);

    int minDif = s.size();
    string minStr = "";
    while (s.find( " " ) != -1) {

        int a = s.find(" ");
        string currentWord;
        currentWord = s.substr(0, a);
        s.erase(0, a + 1);
        int difCount = 1;
        for (int i = 0; i < currentWord.size() - 1; i++)
        {
            if (currentWord[i] != currentWord[i + 1])
            {
                bool isChecked = false;
                for (int j = 0; j <= i; j++)
                    if (currentWord[j] == currentWord[i + 1])
                    {
                        isChecked = true;
                        break;
                    }
                if (!isChecked)
                    difCount++;
            }
        }

        if (difCount < minDif)
        {
            minDif = difCount;
            minStr = currentWord;
        }
    }
    cout << "Первое слово с минимальным количеством символов: " << minStr << endl;
    return 0;
}
