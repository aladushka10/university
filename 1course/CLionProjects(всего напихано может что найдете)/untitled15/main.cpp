#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map<string, long, less<string> > multimap_dict;
int main() {
    multimap_dict d1;
    string name = "John";

    d1.insert(make_pair(name,222222));
    d1.insert(make_pair(name,111111));
    d1.insert(make_pair(name,22234352));
    d1.insert(make_pair("ann", 777777));

    multimap_dict::iterator it;
    for(it=d1.begin(); it != d1.end(); ++it)
        cout<<(*it).first<<" "<<it->second<<endl;
  cout<<endl;
  cout<<d1.count(name)<< endl;
  pair<multimap_dict::iterator, multimap_dict::iterator> p;
  p = d1.equal_range(name);
    cout<<p.first->first<<" "<<p.first->second<<endl;
    p.second--;
    cout<<p.second->first<<" "<<p.second->second<<endl;
    system("pause");
    return 0;
}
