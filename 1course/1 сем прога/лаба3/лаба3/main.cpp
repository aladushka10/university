#include <iostream>
using namespace std;
int main() {
    setlocale(LC_ALL, "Russian");
    int arrSize;
    cout << "введите размер массива(не меньше нуля): "<< " ";
    cin >> arrSize;
    while(arrSize < 1){
        cout << "ошибка, введите снова:" << endl;
        cin >> arrSize;
    }
    cout << "массив: " << " ";
    int * a;
    a = new int [arrSize];
    for(int i = 0; i < arrSize; i++){
        cout << "[" << i + 1 << "]" << ": ";
        cin >> a[i];
    }
    int p = 1;
    for(int i = 0;  i < arrSize; i++)
        if(i % 2 == 1){
            p *= a[i];
        }
    if (arrSize == 1){
        cout << "произведение невозможно подсчитать" << endl;
    }
    else{
        cout << "произведение в четных позициях: " << p << endl;
    }
    for( int i = 0; i<n; i++)
       {
           if(arr[i]%2!=0)
           {
               arr[i]=arr[i]+i;
           }

    int first = -1, last = -1, sum = 0;
    for(int i = 0;  i < arrSize; i++) {
        if (a[i] == 0) {
            if (first == -1)
                first = i;
            else
                last = i;
        }
    }
    for (int i = first + 1; i < last; i++)
    {
        sum += a[i];
    }
    if (first == -1 || last == -1)
        cout << "сумма элементов массива, расположенных между первым и последним нулевыми элементами невозможна"<<endl;

             else
                 cout << "сумма элементов массива, расположенных между первым и последним нулевыми элементами: " << sum << endl;
            
    for (int i = 0; i < arrSize; i++) {
           for (int j = 0; j < arrSize - 1; j++) {
               if (a[j] <= 0)
                  swap(a[j], a[j + 1]);
           }
               }
           cout << "правильный массив: ";
       for (int i = 0; i < arrSize; i++) {
           cout << a[i] << ' ';
       }
       delete[] a;
       return 0;
       }
