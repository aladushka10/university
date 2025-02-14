#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n;
    cout << "input size of an array: ";
    cin >> n;
    int *A = new int [n];
    cout << "\ninput elements of an array: ";
    for (int i = 0; i<n; i++)
        cin >> A[i];
    cout << "\narray: {";
    for (int i = 0; i<n; i++)
    {
        if (i == n-1)
            cout << A[i] << "}\n";
    }
    for (int i = 0; i<n; i++)
    {
        for (int j = i; j < n-2; j++)
        {
            if (A[j] > A[j+2])
                swap(A[j], A[j+2]);
        }
    }
    for (int i = 0; i<n; i++)
    {
        cout << A[i] << ' ';
    }
    return 0;
}