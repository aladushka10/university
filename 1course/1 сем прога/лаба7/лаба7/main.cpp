#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "rus");
    fstream fin, fout;
    string nameOfFin, nameOfFout;
    cout << "Введите название входного и выходного файлов:" << endl;
    cin >> nameOfFin >> nameOfFout;
    try{
        fin.open(nameOfFin, ios::in);
        fout.open(nameOfFout, ios::out);
        if (!fin.is_open())
            throw 1;
        if (!fout.is_open())
            throw 2;
        string testString;
        fin >> testString;
        if (testString == "")
            throw 3;
        fin.close();
        fout.close();
    }
    catch (int error)
    {
        switch(error)
        {
        case 1:
            cout << "Входной файл не найден!" << endl;
            break;
        case 2:
            cout << "Не удалось создать выходной файл." << endl;
            break;
        case 3:
            cout << "Входной файл пуст!" << endl;
                fin.close();
            break;
                // default
        }
        /*fin.close();
        fout.close();*/
        return 0;
    }
    catch(...)
    {
        cout << "Возникла непредвиденная ошибка." << endl;
      //  fin.close();
      // fout.close();
        return 0;
    }

    fin.open(nameOfFin, ios::in);
    fout.open(nameOfFout, ios::out);
    int number = 0, groupSize = 0, groupBegin = 0;
    while (!fin.eof())
    {
        number++;
        string str;
        getline(fin, str);
        bool isNumeric = true;
        for (int i = 0; i < str.size(); i++)
            if (str[i] < '0' || str[i] > '9')
            {
                isNumeric = false;
                break;
            }
        if (str.size() == 0)
            isNumeric = false;
        if (!isNumeric)
        {
            if (groupSize != 0)
                fout << "Размер группы - " << groupSize << " Номер строки-начала группы - " << groupBegin << endl;
            groupSize = 0;
        }
        else
        {
            if (groupSize == 0)
                groupBegin = number;
            groupSize++;
        }
    }
    if (groupSize != 0)
        fout << "Размер группы - " << groupSize << " Номер строки-начала группы - " << groupBegin << endl;
    return 0;
}
