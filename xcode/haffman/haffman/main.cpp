#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

long long minimum(const vector<long long>& arr, const vector<long long>& buff, int& indArr, int& indBuff)
{
    long long minX;
    if(indArr != arr.size() && indBuff != buff.size())
    {
        minX = min(arr[indArr], buff[indBuff]);
        if(minX == arr[indArr])
            indArr++;
        else
            indBuff++;
    }
    else
    {
        if(indArr == arr.size())
        {
            minX = buff[indBuff];
            indBuff++;
        }
        else
        {
            minX = arr[indArr];
            indArr++;
        }
    }
    return minX;
}

long long huffman(const vector<long long>& arr)
{
    vector <long long> buff;
    int indArr = 0, indBuff = 0;
    long long min1, min2;
    for(int i = 0; i < arr.size() - 1; i++)
    {
        min1 = minimum(arr, buff, indArr, indBuff);
        min2 = minimum(arr, buff, indArr, indBuff);
        buff.push_back(min1 + min2);
    }
    long long summ = 0;
    for(int i = 0; i < buff.size(); i++)
        summ += buff[i];
    return summ;
}

int main() {
    //ifstream fin("huffman.in");
    //ofstream fout("huffman.out");
    int n;
    cin >> n;
    vector <long long> arr(n);
    for(int i = 0; i < n; i++)
        cin >> arr[i];
    cout << huffman(arr) << endl;
    return 0;
}
