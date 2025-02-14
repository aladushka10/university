#include <iostream>
#include <vector>
#include <fstream>
#include <map>
#include <set>
#include <algorithm>
#include <sstream>

using namespace std;
typedef map <string, vector <pair <string, int> > > m_sv;

int main() {
    m_sv dict;
    fstream fin, fout;
    fin.open("DATA.TXT", ios::in);
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
    m_sv::iterator im;
    vector <pair <string, int> >::iterator it;
    string str, word;
    int num = 0;
    while(getline(fin, str))
    {
        if (str != "" && isalpha(str[0]))
        {
            ++num;
            stringstream ss;
            ss << str;
            string city;
            getline(ss, city, ';');
            string hotelname;
            getline(ss, hotelname, ';');
            int stars;
            ss >> stars;
            dict[city].push_back({hotelname, stars});
        }
    }
    /*for (im = dict.begin(); im != dict.end(); ++im)
    {
        cout << (*im).first << endl;
        for(it = (*im).second.begin(); it != (*im).second.end(); ++it)
            cout << (*it).first << " " << (*it).second << endl;
    }*/
    ifstream fin1("QUERY.TXT");
    if (!fin1)
    {
        cerr << "not such file"<< endl;
        return 1;
    }
    if(!fin1.good())
    {
        cerr << "empty file" << endl;
        return 1;
    }
    fout.open("ANSWER.TXT", ios::out);
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
    while(getline(fin1, str))
    {
        if (str != "")
        {
            if(str[0] == '1')
            {
                str.erase(0, 2);
                fout << str << ":" << endl;
                for(it = dict[str].begin(); it != dict[str].end(); ++it)
                    fout << (*it).first << " " << (*it).second << endl;
            }
            if(str[0] == '2')
            {
                str.erase(0, 2);
                fout << str << ":" << endl;
                for(im = dict.begin(); im != dict.end(); ++im)
                {
                    for(it = (*im).second.begin(); it != (*im).second.end(); ++it)
                        if((*it).first == str)
                        {
                            fout << (*im).first << endl;
                        }
                }
            }
            if(str[0] == '3')
            {
                str.erase(0, 2);
                for(im = dict.begin(); im != dict.end(); ++im)
                {
                    set<int> count;
                    set<int>::iterator n;
                    for(it = (*im).second.begin(); it != (*im).second.end(); ++it)
                    {
                    count.insert((*it).second);
                    }
                    for(n = count.begin(); n != count.end(); ++n)
                        fout << (*im).first << " " <<  *n << endl;
                }
            }
        }
    }
    return 0;
}
