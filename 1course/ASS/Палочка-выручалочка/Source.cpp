
//�task1.cpp�
#include <iostream>
using namespace std;
extern "C" int __stdcall StrLen1(char*);
extern "C" int __cdecl StrLen2(char*);
extern "C" int __stdcall StrLen3(char*);
extern "C" int __cdecl StrLen4(char*);
extern "C" int __fastcall StrLen5(char*);

int main() {
	char s[100];
	cout << "Input string\n";
	cin.getline(s, 100);
	cout << StrLen1(s) << endl;
	cout << StrLen2(s) << endl;
	cout << StrLen3(s) << endl;
	cout << StrLen4(s) << endl;
	cout << StrLen5(s) << endl;
	system("Pause");
	return 0;
}




; ФProc1.asmФ
.386
PUBLIC _StrLen1@4
PUBLIC _StrLen2
PUBLIC StrLen3
PUBLIC StrLen4
PUBLIC @StrLen5@4

.model flat
.data
.code
        _StrLen1@4 proc
        push ebp
        mov ebp, esp
        mov ebx, [ebp + 8]
xor eax, eax
        for_ :
cmp byte ptr[ebx], 0
je end_
inc eax
inc ebx
jmp for_
end_ :
mov esp,ebp
pop ebp
ret 4
_StrLen1@4	endp

; *********************************************

_StrLen2 proc
push ebp
mov ebp, esp
mov ebx, [ebp + 8]
xor eax, eax
        for_ :
cmp byte ptr[ebx], 0
je end_
inc eax
inc ebx
jmp for_
end_ :
mov esp,ebp
pop ebp
ret
        _StrLen2	endp
; ***********************************************

StrLen3 	proc stdcall, s:dword
        mov ebx, s
        xor eax, eax
for_ :
cmp byte ptr[ebx], 0
je end_
inc eax
inc ebx
jmp for_
end_ :
ret	4
StrLen3	endp
; **************************************************

StrLen4 proc C, s:dword
        mov ebx, s
        xor eax, eax
for_ :
cmp byte ptr[ebx], 0
je end_
inc eax
inc ebx
jmp for_
end_ :
ret
        StrLen4	endp

; ********************************************************

@StrLen5@4 proc
        mov ebx, ecx
        xor eax, eax
for_ :
cmp byte ptr[ebx], 0
je end_
inc eax
inc ebx
jmp for_
end_ :
ret
@StrLen5@4	endp

        end
