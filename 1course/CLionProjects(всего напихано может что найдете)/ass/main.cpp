/*
////////является ли число палиндромом
#include <iostream>

using namespace std;

int main()
{
    int a = 123321;
    bool flag = false;
    __asm
    {
        mov eax, a
        xor ebx, ebx
    while1:
        cmp eax, 0
        je zero

        mov ecx, 10
        xor edx, edx
        div ecx

        imul ebx, 10
        add ebx, edx

        jmp while1
    zero:
        cmp a, ebx
        jne skip
    mov flag, 1
    skip:
    }
    if (flag)
        cout << "palindrome" << endl;
    else
        cout << "non palindrome" << endl;
    return 0;
}*/

************************************************************************************

/*
/////////сумма кого-то там 1 пример
#include <iostream>

using namespace std;

int main()
{
  int res = 0;
  _asm
  {
    mov esi, 2 ///текущее значение счётчика, начинаем с 2
    mov ecx, 16 ///количество слагаемых (17 - 2 + 1 = 16)
    xor ebx, ebx ///сюда будем суммировать
  m1:
    mov eax, esi /// в eax наш счётчик
    sub eax, 4 ///отнимаем 4
    imul eax ///возводим в квадрат
    add ebx, eax ///суммируем
    inc esi ///увеличиваем счётчик
    loop m1
    mov res, ebx ///записываем ответ
  }
  cout << res */

/*
/////////сумма кого-то там 2 пример
#include <iostream>
using namespace std;

int main() {
    int res = 0;
    int n = 8;
    _asm
    {
        mov ecx, n
        xor edx, edx
    m1:
        mov eax, 5
        mul ecx
        mov ebx, 3
        add eax, ebx
        mul eax
        add edx, eax
        loop m1
    end:
        mov res, edx
    }
    return 0;
}*/

************************************************************************************


/*
 /////подсчет колва единиц в представлении числа в регистре СХ/////
#include <iostream>
using namespace std;

int main() {
    short x = 23;
    int ans;
    _asm
    {
        mov cx, x
        xor esi, esi
        cmp cx, 0
        jle end
    m1:
        mov ax, cx
        mov bx, 2
        xor dx, dx
        div bx
        cmp dx, 1
        jne _next
        inc esi
    _next:
        mov cx, ax
        cmp cx, 0
        jg m1
    end:
        mov ans, esi
    }
    cout << ans;
    return 0;
}

*/

************************************************************************************

/*
///////срденее арифметическое наибольшей и наименьшей цифры модуля числа////
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    int average = 0;
    _asm
    {
        mov ecx, 9
        mov esi, 0
        mov eax, a
    m1 :
        cmp eax, 0
        je endd
        mov ebx, 10
        xor edx, edx
        div ebx
        cmp edx, ecx
        jg m2
        mov ecx, edx
    m2 :
        cmp edx, esi
        jl m1
        mov esi, edx
        jmp m1

    endd:
        mov eax, ecx
        add eax, esi
        mov ebx, 2
        xor edx, edx
        div ebx
        mov average, eax
    }
    cout << "" << average;
    return 0;
}
*/

************************************************************************************

/*
  /////////сумма цифр модуля числа
#include <iostream>
using namespace std;

int main() {
    int a;
    cin >> a;
    int sum = 0;
    _asm
    {
        xor ecx, ecx
        mov eax, a
        cmp eax, 0
        jg m1
        imul eax, -1
    m1:
        cmp eax, 0
        je endd
        mov ebx, 10
        xor edx, edx
        div ebx
        add ecx,edx
        jmp m1
    endd:
        mov sum, ecx
    }
    cout << "сумма цифр модуля числа" << sum;
    return 0;
}
*/


/*
/////////вычислить явл ли число степенью 2, если да то какой
#include <iostream>
using namespace std;

int main() {
    int a = 32;
    int flag = 0;
    _asm{
        xor edx, edx
        xor ecx, ecx
        mov eax, a
        cmp eax, 0
        je odd
        jg m1
        imul eax, -1
    m1:
        cmp eax, 1
        je true1
        inc ecx
        mov ebx, 2
        div ebx
        cmp edx, 0
        jg odd
        jmp m1
    true1:
        mov flag, ecx
        jmp endd
    odd:
        mov flag, -1
    endd:
    }
if(flag == -1)
    cout<< "модуль числа не степень 2";
else
    cout<< "модуль числа 2 в степени "<< flag;
    return 0;
}
*/