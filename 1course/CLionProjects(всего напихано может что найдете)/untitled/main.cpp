#include <iostream>
using namespace std;

int main()
{
    int k, M, acc;
    cout <<"Vvedite razmer x massiva: "<<endl;
    cin >> k ;
    int mass[k];
    int ans[k];
    for (int i=0; i< k; i++)
    {
        for (int j=0; j<k; j++)
        {
            cout <<"Vedite "<<i+1<<","<<j+1<<"-ii element massiva: "<<endl;
            cin >> mass[i] [j];
        }
    }
    for (int i=0; i < k; i++)
    {
        ans[i] = mass[i];
    }
    for (int i=0; i < k; i++)
    {
        cout <<ans[i]<<" ";
    }

    return 0;
}