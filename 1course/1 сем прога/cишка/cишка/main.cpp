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

    /*int summin1, summin2, sum;
    for (i = 0; i < n - 2; i++) {
        summin1 = 0;
        for (j = 0; j < n; j++) {
            summin1 += (abs(arr[i][j]));
        }
        if (abs(summin1) < sum)
            sum = summin1;
    }
    for (i = 0; i < n - 1; i++) {
        summin2 = 0;
    for (j = 1; j < n; j++) {
        summin2 += (abs(arr[i][j]));
    }
    if (abs(summin2) < sum)
       sum = summin2;
}
    cout << "минимум среди модулей сумм элементов диагоналей, параллельных побочной диагонали матрицы: " << sum << endl;*/

    int sum1, sum2, sumD;
    sumD = arr[0][n - 1];
    for (i = 0; i < n - 2; i++){
            sum1 = sum2 = 0;
            for (j = 0; j < n; j++) {
                sum1 += arr[i - j][j];
                sum2 += arr[j][i - j];
            }
        
            if (sum1 < sumD)
                sumD = sum1;

            if (sum2 < sumD)
                sumD = sum2;
    }
     cout << "минимум среди модулей сумм элементов диагоналей, параллельных побочной диагонали матрицы: " << sumD << endl;

        for ( i = 0; i < n; i++)
            delete[] arr[i];
        delete[] arr;
        return 0;
    }


