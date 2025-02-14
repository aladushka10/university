#include <iostream>
#include <map>
#include <set>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;
typedef set<int, less<int> > set_i;
typedef map <string, set_i> map_ss;
bool wordRead(string&, string&);

int main()
{
    ifstream fin("in.txt");
    if (!fin)
    {
        cerr << "not such file"<< endl;
        return 1;
    }
    if(!fin.good())
    {
        cerr << "empty file" << endl;
        return 1;
    }

    fin.seekg(0, ios::beg); //считываем с начала
    map_ss m;
    map_ss::iterator im;
    set_i::iterator is,isbegin, isend;
    string str, word;
    int num = 0;
    while(getline(fin, str))
    {
        ++num;
        while(wordRead(str, word))
        {
            if(word != "" && isalpha(word[0]))
            {
                for(unsigned i=0; i < word.size(); ++i)
                    word[i] = tolower(word[i]);
                im = m.find(word);
                if (im == m.end())
                   im = m.insert(map_ss::value_type(word, set_i())).first;
                (*im).second.insert(num);
            }
        }
    }
    for (im = m.begin(); im != m.end(); im++)
    {
        cout << setiosflags(ios::left)<< setw(15)
        << im->first.c_str();
        isbegin = (*im).second.begin();
        isend = im->second.end();
        for (is = isbegin; is != isend; ++is)
            cout << " " << *is << endl;
    }
    fin.close();
    return 0;
}
bool wordRead(string& str, string& word)
{
    word = "";
    int k = str.find_first_of(" .,;:()"); //ищет что-то одно из перечисленного
    if(k != string::npos)//ни одного не встретила
    {
        word = str.substr(0, k);
        str.erase(0, k+1);
    }
    else
    {
        word = str;
        str = "";
    }
    return (str != "");
}