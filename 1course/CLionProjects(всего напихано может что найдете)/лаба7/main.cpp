#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    fstream fileIn, fileOut;
    string nameOfInFile, nameOfOutFile;
    cout << "Введите название входного и выходного файлов:" << endl;
    cin >> nameOfInFile >> nameOfOutFile;
    try{
        fileIn.open(nameOfInFile, ios::in);
        fileOut.open(nameOfOutFile, ios::out);
        if (!fileIn.is_open())
            throw 1;
        if (!fileOut.is_open())
            throw 2;
        string testString;
        fileIn >> testString;
        if (testString == "")
            throw 3;
        fileIn.close();
        fileOut.close();
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
                fileIn.close();
                break;
            default:
                cout << "Возникла непредвиденная ошибка." << endl;
        }
        return 0;
    }
    catch(...)
    {
        cout << "Возникла непредвиденная ошибка." << endl;
        return 0;
    }

    fileIn.open(nameOfInFile, ios::in);
    fileOut.open(nameOfOutFile, ios::out);
    int number = 0, groupSize = 0, groupBegin = 0;
    while (!fileIn.eof())
    {
        number++;
        string curStr;
        getline(fileIn, curStr);
        bool isNumeric = true;
        for (int i = 0; i < curStr.size(); i++)
            if (curStr[i] < '0' || curStr[i] > '9')
            {
                isNumeric = false;
                break;
            }
        if (curStr.size() == 0)
            isNumeric = false;
        if (!isNumeric)
        {
            if (groupSize != 0)
                fileOut << "размер группы - " << groupSize << " номер строки-начала группы - " << groupBegin << endl;
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
        fileOut << "размер группы - " << groupSize << " номер строки-начала группы - " << groupBegin << endl;
    return 0;
}