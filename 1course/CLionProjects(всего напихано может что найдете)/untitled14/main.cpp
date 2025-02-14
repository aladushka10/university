#include <iostream>
#include <map>
#include <string>
using namespace std;
typedef map< string, long, less<string> > map_dict;
int main() {
    map_dict d1,d2;
    string name;
    long num;
    cout<<"enter name and phone mumber\n";
    for(int i=0; i < 3; ++i)
    {
        cin>>name;
        cin>>num;
        d1[name=num];
    }
    d1["Gary Ross"] = 1234567;
    map_dict::iterator it;
    for(it=d1.begin(); it != d1.end(); ++it)
        cout<<(*it).first<<" "<<it->second<<endl;
    d1.insert(make_pair("Koen",438549));
    cout<<(*it).first<<" "<<it->second<<endl;
  it=d1.begin();
  d2.insert(*it);
  name="ann";
  it=d1.find(name);
  if (it == d1.end())
      cout<<"not found\n";
  else
      cout<<(*it).first<<" "<<it->second<<endl;
  d2.swap(d1);
        system("pause");
    return 0;
}
