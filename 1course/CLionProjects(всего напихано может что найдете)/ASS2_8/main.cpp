
























/*#include <iostream>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    int n;
    cout << "Введите длину последовательности: ";
    cin >> n;
    cout << "Введите последовательность из цифр: " << endl;
    int* sequence = new int[n];
    for (int i = 0; i < n; i++)
        cin >> sequence[i];
    cout << "Введите кол-во чисел: ";
    int n2;
    cin >> n2;
    cout << "Введите числа: " << endl;
    int* a = new int[n2];
    for (int i = 0; i < n2; i++)
        cin >> a[i];
    cout << "Числа, содержащие заданную последовательность: " << endl;
    int y = 0;
    int iMin1 = -1, iMin2 = -1;
    _asm
    {
        mov ecx, n2
        xor esi, esi ///смещение относительно начала массива
        cikl1:
        mov ebx, a
        mov eax, [ebx][esi]
        mov edi, n
        dec edi ///edi - на последний член последовательности
        cikl2:
        cmp eax, 0
        je skip
        mov ebx, 10
        xor edx, edx
        div ebx ///edx-цифра a[i]
        mov ebx, sequence
        cmp edx, [ebx][4*edi]
        je yes
        ///не совпадение
        mov edi, n
        dec edi
        jmp cikl2
        yes:
        ///совпадение цифр ???
        cmp edi, 0 ///если совпало с ласт цифрой послед значит была значит работает
        je outt ///тогда выводим
        dec edi ///если нет тогда просто сдвигаем на 1 влево
        jmp cikl2
        skip:
        add esi, 4
        loop cikl1
        jmp stop
        outt:
        mov edi, n
        dec edi
        mov ebx, a
        mov eax, [ebx][esi]
        mov y, eax
        cmp iMin1, -1
        je first
        cmp [ebx][iMin1], eax
        jg minimum2
        first : mov iMin1, esi
        minimum2 : cmp iMin2, -1
        je true2
        cmp [ebx][iMin1], [ebx][iMin2]
        jl less
        true2: mov iMin2, iMin1
        mov edi, iMin2
        mov iMin1,esi
        less: mov iMin1, iMin2
        push esi
        push ecx

    }
    cout << y << " ";
    _asm
    {
        pop ecx
        pop esi
        add esi, 4
        loop cikl1
        stop:
    }
    return 0;
}*/
/*
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int *a = new int[n];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int iMin1 = -1, iMin2 = -1;
    for (int i = 0; i < n; i++) {
        if (iMin1 == -1)
        {
            iMin1 = i;
        }
        else {
            if (a[iMin1] > a[i])
            {
                if (iMin2 == -1)
                {
                    iMin2 = iMin1;
                }
                else
                {
                    if (a[iMin2] > a[iMin1])
                    {
                        iMin2 = iMin1;
                    }
                }
                iMin1 = i;
            }
            else
            {
                if (iMin2 == -1)
                {
                    iMin2 = i;
                }
                else
                {
                    if (a[iMin2] > a[i])
                    {
                        iMin2 = i;
                    }
                }
            }
        }
    }
    cout << iMin1 << " " << iMin2 << endl;
    return 0;
}*/