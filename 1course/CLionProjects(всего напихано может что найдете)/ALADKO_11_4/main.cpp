#include <iostream>
#include <map>
#include <sstream>
#include <fstream>
#include <deque>
#include <algorithm>
#include <set>

using namespace std;
typedef deque < pair <string, int> > student_deque;
typedef map < string, student_deque > map_studentInfo;

int main() {
    map_studentInfo studentInfo;
    student_deque s_deque;
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
    string str;
    string subject;
    string student;
    string mark;
    while(getline(fin, str))
    {
        if(str != "" && isalpha(str[0]))
        {
            stringstream ss;
            ss << str;
            getline(ss, subject, ';');
            getline(ss, student, ';');
            getline(ss, mark, ';');
            int imark = stoi(mark);
            studentInfo[subject].push_back({student, imark});
        }
    }
    ifstream fin1("QUERY.TXT");
    if(!fin1)
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
    if(!fout)
    {
        cerr << "not such file" << endl;
        return 1;
    }
    if(!fout.good())
    {
        cerr << "empty file" << endl;
        return 1;
    }
    map_studentInfo::iterator im;
    student_deque::iterator it;
    set <pair<int, string>> markSubject;
    set <pair<int, string>>::iterator n;
    set < pair <int, string> > subj;
    while(getline(fin1, str))
    {
        if(str[0] == '1')
        {
            str.erase(0,2);
            for (it = studentInfo[str].begin(); it != studentInfo[str].end(); ++it)
            {
                if ((*it).second == 9 || (*it).second == 10)
                    fout << (*it).first << " with marks: " << (*it).second<< endl;
            }
        }
        if (str[0] == '2')
        {
            str.erase(0, 2);
            int cnt = 0;
            int sum = 0;
            for (im = studentInfo.begin(); im != studentInfo.end(); ++im)
                for (it = (*im).second.begin(); it != (*im).second.end(); ++it)
                    if ((*it).first == str)
                    {
                        cnt++;
                        sum += (*it).second;
                    }
            fout << str << ":" << endl;
            double ans = 1. * sum / (1. * cnt);
            fout << "Средний балл: " << ans << endl;
        }
        if (str[0] == '3')

        {
            subj.clear();
            fout << str << endl;
            for (im = studentInfo.begin(); im != studentInfo.end(); ++im)
                for (it = (*im).second.begin(); it != (*im).second.end(); ++it)
                    subj.insert({(*it).second, (*im).first});
            for (auto iter = subj.begin(); iter != subj.end(); ++iter)
                fout << (*iter).first << " " << (*iter).second << endl;
        }
    }
    return 0;
}