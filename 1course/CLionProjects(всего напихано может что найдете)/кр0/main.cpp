#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;
int main()
{
    ifstream finput("in.txt");
    ofstream foutput("out.txt");
    string str;
    vector<string> s;
    while (!finput.eof())
    {
        getline(finput, str);
        if (str == "")
            break;
        bool find = false;
        for (int i = 0; i < s.size(); i++)
            if (s[i] == str)
                find = true;
        if (!find)
            s.push_back(str);
    }

    if (s.size() == 0 || s[0] == "")
        return 0;
    for (int i = 0; i < s.size(); i++)
        for (int j = 0; j < s.size() - 1; j++)
            if (stoi(s[j + 1]) > stoi(s[j]))
                swap(s[j], s[j + 1]);
    for (int i = 0; i < s.size(); i++)
    {
        int zeroLast = 0;
        for (int j = 0; j < s[i].size(); j++)
            if (s[i][j] == '0')
                zeroLast = j;
        int sum = 0;
        for (int j = zeroLast; j < s[i].size(); j++)
            sum += s[i][j] - '0';
        foutput << s[i] << ":" << sum << endl;
    }
    return 0;
}