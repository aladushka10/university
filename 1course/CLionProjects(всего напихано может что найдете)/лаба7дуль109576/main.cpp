#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream inputFile, outputFile;
    string nameOfInputFile, nameOfOutputFile;
    cout << "Введите название входного и выходного файлов:" << endl;
    cin >> nameOfInputFile >> nameOfOutputFile;
    try{
        inputFile.open(nameOfInputFile, ios::in);
        outputFile.open(nameOfOutputFile, ios::out);
        if (!inputFile.is_open())
            throw 1;
        if (!outputFile.is_open())
            throw 2;
        string testString;
        inputFile >> testString;
        if (testString == "")
            throw 3;
        inputFile.close();
        outputFile.close();
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
                break;
            default:
                cout << "Возникла непредвиденная ошибка." << endl;
        }
        inputFile.close();
        outputFile.close();
        return 0;
    }
    catch(...)
    {
        cout << "Возникла непредвиденная ошибка." << endl;
        inputFile.close();
        outputFile.close();
        return 0;
    }

    inputFile.open(nameOfInputFile, ios::in);
    outputFile.open(nameOfOutputFile, ios::out);
    int number = 0, groupSize = 0, groupBegin = 0;
    while (!inputFile.eof())
    {
        number++;
        string curStr;
        getline(inputFile, curStr);
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
                outputFile << "Размер группы - " << groupSize << " Номер строки-начала группы - " << groupBegin << endl;
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
        outputFile << "Размер группы - " << groupSize << " Номер строки-начала группы - " << groupBegin << endl;
    return 0;
}




