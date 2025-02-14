#include <iostream>
#include <fstream>
#include <stack>

using namespace std;

int main()
{
    //ifstream fin("input.txt");
    //ofstream fout("output.txt");
    int n;
    cin >> n;
    stack <int> s;
    for (int i = 0; i < n; ++i)
    {
        double x, y;
        int type;
        cin >> x >> y >> type;
        if (!s.empty())
            if (s.top() == type)
                s.pop();
            else
                s.push(type);
        else
            s.push(type);
    }
    if (s.size() > 1)
        cout << "No";
    else
        cout << "Yes";
    return 0;
}
