#include <iostream>
#include <fstream>
using namespace std;

struct Node
{
    int key;
    long long minValue;
    long long maxValue;
};

bool isSearching(const vector <Node> &tree)
{
    for(int i = 0; i < tree.size(); i++)
        if(tree[i].key < tree[i].minValue || tree[i].key >= tree[i].maxValue)
            return false;
    return true;
}

int main()
{
    //ifstream fin("bst.in");
    //ofstream fout("bst.out");
    long long max = INT_MAX;
    max += 2;
    int n, m, p = 0;
    cin >> n;
    vector <Node> tree(n);
    cin >> m;
    tree[0].key = m;
    tree[0].maxValue = max;
    tree[0].minValue = -max;
    char c;
    for(int i = 1; i < n; i++)
    {
        cin >> tree[i].key;
        cin >> p;
        cin >> c;
        if(c == 'L')
        {
            tree[i].maxValue = tree[p - 1].key;
            tree[i].minValue = tree[p - 1].minValue;
        }
        else
        {
            tree[i].maxValue = tree[p - 1].maxValue;
            tree[i].minValue = tree[p - 1].key;
        }
    }
    
    if(isSearching(tree))
        cout << "YES";
    else
        cout << "NO";
    return 0;
}
