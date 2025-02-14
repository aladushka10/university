#include <iostream>
using namespace std;
int main() {
    int n;
    int i, j;
    bool x;
    cout << "введите размер матрицы: ";
    cin >> n;

    int **arr = new int *[n];
    for (i = 0; i < n; i++) {
        arr[i] = new int[n + 1];
    }
    cout << "введите матрицу: ";
    for (i = 0; i < n; i++)
        for (j = 0; j < n; j++)
            cin >> arr[i][j];
    for (i = 0; i < n; i++) {
        for (j = 0; j < n; j++)
            cout << arr[i][j] << "   ";
        cout << endl;
        cout << endl;
    }
    for (j = 0; j < n; j++) {
        int sum = 0;
        x = true;
        for (i = 0; i < n; i++)
            if (arr[i][j] < 0) {
                x = false;
            }
        if (x == true) {
            for (i = 0; i < n; i++)
                sum += arr[i][j];
            cout << "сумма элементов в тех столбцах, которые не содержат отрицательных элементов: " << sum << endl;
        }
    }
    int sum,k = 0, min = 0;
    sum = arr[n - 1][0];
    for (i = n ; i > 0; i--)
    {
        for (j = 0; j < n - i + 1; j++)
            sum += (abs(arr[n - i - j][j]));
        k++;
        if(sum < min || min == 0)
            min = sum;
    }

    for (i = 1; i < n - 1; i++)
    {
        sum = 0;
        for (j = n - 1; j >= i; j--)
            sum += (abs(arr[n - 1 + i - j][j]));
        k++;
        if(sum < min || min == 0)
            min = sum;
    }

    cout << "минимум среди сумм модулей элементов диагоналей, параллельных побочной диагонали матрицы: " << min << endl;

    for ( i = 0; i < n; i++)
        delete[] arr[i];
    delete[] arr;
    return 0;
}