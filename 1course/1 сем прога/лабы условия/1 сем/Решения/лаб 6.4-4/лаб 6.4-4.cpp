#include <iostream>
#include <string>
char* fu(char* strch, char* strchc) {
    int n = 0;
    for (int i = 0; strch[i] != '\0'; ++i) {
        ++n;
    }
    int nc = 0;
    for (int i = 0; strchc[i] != '\0'; ++i) {
        ++nc;
    }
    for (int i = 0; i < nc; ++i) {
        strchc[i] = strch[i];
        if (i == (n + 1)) {
            for (i = (n + 1); i < nc; ++i) {
                strchc[i] = '\0';
            }
            break;
        }
    }
    return strchc;
}
int main() {
    setlocale(LC_ALL, "rus");
    std::cout << "Введите строку, которую нужно скопировать: \n";
    char* strch = new char[1000];
    std::cin.getline(strch, 1000);

    std::cout << "Введите строку, в которую нужно скопировать: \n";
    char* strchc = new char[1000];
    std::cin.getline(strchc, 1000);

    std::cout << fu(strch, strchc);
    delete[] strch;
    delete[] strchc;
    return 0;
}