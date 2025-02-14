#include <iostream>
#include <map>
#include <string>
using namespace std;
class Person {
    string FN;
    string LN;
public:
    Person(const string &f, const string &n) : FN(f), LN(n) {}

    Person(const Person &p) : FN(p.FN), LN(p.LN) {}

    string getFN() const { return FN; }

    string getLN() const { return LN; }

    friend class PersonLessThan;
};
class PersonLessThan
{
public:
    bool operator() (const Person& p1, const Person& p2)
    {
        if(p1.LN < p2.LN)
            return true;
        if(p1.LN == p2.LN)
            return (p1.FN < p2.FN);
        return false;
    }
};
typedef map<Person, string, PersonLessThan> map_dict;
int main() {
    map_dict dict;
    Person p1("billy", "silly"),
            p2("john"," will"),
            p3("frank", "stank"),
            p4("ann","will");
    dict[p1]= "cool";
    dict[p2]="not cool";
    dict[p3]="not cool";
    dict[p4]="cool";
    map_dict::iterator it;
    for(it=dict.begin(); it != dict.end(); ++it)
        cout<<(*it).first.getFN()<<" "<<it->first.getLN()<<" "<<it->second<<endl;
    system("pause");
    return 0;
}
