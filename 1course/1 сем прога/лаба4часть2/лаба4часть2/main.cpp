#include <iostream>
using namespace std;
int main()
{
    setlocale(LC_ALL, "rus");
    int row, column;
    cout << "Введите количество строк матрицы: ";
    cin >> row;
    while ((row >= 20) || (row <= 1)) {
        cout << "ошибка, введите снова:" << endl;
        cin >> row;
    }
    cout << "Введите количество столбцов матрицы: ";
    cin >> column;
    while ((column >= 20) || (column <= 1)) {
        cout << "ошибка, введите снова:" << endl;
        cin >> column;
    }
    
    int  **arr = new int* [row];
    for (int i = 0; i < row; i++)
        arr[i] = new int[column];
    cout << "Введите элементы матрицы: " << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cin >> arr[i][j];
    }
    for (int i = 0; i < row; i++){
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
   
    int* characteristic = new int [column];
    for (int i = 0; i < column; i++)
      for (int j = 0; j < row; j++)
            if (arr[j][i] == 0)
                characteristic[i]++;
    for (int i = 0; i < column; i++)
        for (int j = 0; j < column - 1; j++)
            if (characteristic[j] > characteristic[j + 1])
            {
                swap(characteristic[j], characteristic[j + 1]);
                for (int k = 0; k < row; k++)
                    swap(arr[k][j], arr[k][j + 1]);
            }
    cout << "Исправленная матрица: " << endl << endl;
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < column; j++)
            cout << arr[i][j] << " ";
        cout << endl;
    }
    cout << endl;
    int p;
    int count = 0;
    for (int i = 0; i < row; i++)
        {
            p=0;
            for (int j = 0; j < column ; j++)
            {
                for (int k = 0; k < column; k++)
                    if (j!=k && arr[i][j] == arr[i][k]){
                        p = 1;
                        count++;
                        break;
                        
                    }
                if (p==1)
                    break;
            }
        }

    cout << "count = " << count << endl;
    for (int i = 0; i < row; i++)
    {
        delete[] arr[i];
    }
    delete[] arr;
   delete[] characteristic ;
    
    return 0;
}

  
