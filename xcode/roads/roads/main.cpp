#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class DSU
{
private:
    int components;
    vector <int> parent;
public:
    DSU(int size)
    {
        components = size;
        parent.resize(size + 1, -1);
    }
    int findSet(int a)
    {
        if(parent[a] < 0)
            return a;
        else
        {
            parent[a] = findSet(parent[a]);
            return parent[a];
        }
    }
    void Union(int a, int b)
    {
        int setA = findSet(a);
        int setB = findSet(b);
        if(setA != setB)
        {
            components--;
            if(parent[setA] < parent[setB])
            {
                parent[setA] += parent[setB];
                parent[setB] = setA;
            }
            else
            {
                parent[setB] += parent[setA];
                parent[setA] = setB;
            }
        }
    }
    int getComponents(){ return components;}
};

int main()
{
    ifstream fin("input.txt");
    ofstream fout("output.txt");
    int n, q, V, U;
    fin >> n >> q;
    DSU dsu(n);
    
    for (int i = 0; i < q; i++)
    {
        fin >> V >> U;
        dsu.Union(V, U);
        fout << dsu.getComponents() << endl;
    }
    return 0;
}
