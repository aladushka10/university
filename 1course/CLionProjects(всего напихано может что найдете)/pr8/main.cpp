#include <iostream>
#include <istream>
#include <set>
#include <algorithm>
#include <string>
#include <iterator>
using namespace std;
int main() {
    cout << "enter some strings\n";
    istream_iterator<srting> start(cin);
    istream_iterator<srting> end;
    set<string> s1(start, end);
    cin.clear();
    for_each(s1.begin(), s1.end(), print);
    cout << endl;
    for_each(s2.begin(), s2.end(), print);
    cout << endl;
        cout << "enter some more strings\n";
        set<string> s2(++start, end);
        set<string> setU;
        set<string> setInt;
        set<string> setDiff;
        set_union(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(setU, setU.begin()));
    for_each(setU.begin(), setU.end(), print);
    cout << endl;
    set_difference(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(setDiff, setDiff.begin()));
    for_each(setDiff.begin(), setDiff.end(), print);
    set_interation(s1.begin(), s1.end(), s2.begin(), s2.end(), inserter(setInt, setInt.begin()));
    for_each(setDiff.begin(), setDiff.end(), print);
    return 0;
}
