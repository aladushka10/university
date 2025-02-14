#include <iostream>
#include <ctime>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    srand (time(NULL));
    unsigned int arr[5][5];
    cout << "матрица: " << endl;
    for(int i = 0; i < 5; i++)
        for(int j = 0; j < 5; j++)
            arr[i][j] = rand()%100;
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }
    int k = rand()%5;

    /*for(int i = 0; i < 5; i++)
        swap(arr[i][k], arr[k][i]);*/
    _asm
    {
        lea edi, arr// столбец
        lea esi, arr//строка
        mov eax, k
        mov ebx, 4
        mul ebx
        add edi, eax
        mov ebx, 5
        mul ebx
        add esi, eax
        mov ecx, 5
        cikl :
        mov ebx, [edi]
        push [esi]
        mov [esi], ebx
        pop ebx
        mov [edi], ebx
        add esi, 4
        add edi, 20
        loop cikl
    };
    cout << "матрица после перемены местами элементов " << k+1 << "ой строчки и " << k+1 << "го столбца" << endl;
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
            cout << arr[i][j] << "  ";
        cout << endl;
    }
    return 0;
};





