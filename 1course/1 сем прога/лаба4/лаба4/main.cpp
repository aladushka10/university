#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int n, sum = 0, sum1, sum2;
    bool x;
    cout << "введите размер матрицы: ";
    cin >> n;
    while ((n >= 20) || (n <= 1)) {
        cout << "ошибка, введите снова:" << endl;
        cin >> n;
    }
    int **  arr = new int* [n];
    for (int i = 0; i < n; i++) {
        arr[i] = new int[n];
    }
    cout << "введите матрицу: ";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++)
            cout << arr[i][j] << "   ";
        cout << endl;
        cout << endl;
    }
            sum = arr[0][n - 1];
    for (int i = 1; i < n; i++)
    {
        sum1 = sum2 = 0;
        for (int j = 0; j < n - i; j++)
        {
            sum1 += arr[i + j][j];
            sum2 += arr[j][i + j];
        }
        if (sum1 < sum) {
            sum = sum1;

        }
        if (sum2 < sum) {
            sum = sum2;
        }
    }
    cout << "минимум среди сумм элементов диагоналей, параллельных главной диагонали матрицы: " << sum << endl;
    for (int i = 0; i < n; i++)
    {
        int mult = 1;
        x = true;
        for (int j = 0; j < n; j++)
            if (arr[i][j] < 0) {
                x = false;
            }
        if (x == true) {
            for (int j = 0; j < n; j++)
                mult *= arr[i][j];
            cout << "произведение элементов в тех строках, которые не содержат отрицательных элементов: " << mult << endl;
        }
    }

    for (int i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}


  
