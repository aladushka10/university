#include <iostream>
#include <fstream>
#include <string>
using namespace std;
int main() {
    setlocale(LC_ALL, "rus");
    fstream fin, fout;
    try{
        fin.open("Untitled:/Пользователи/test/Документы/1 сем прога/нулевой варик кр1/in.txt");
        fout.open("Untitled:/Пользователи/test/Документы/1 сем прога/нулевой варик кр1/out.txt");
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

    fin.open("in.txt");
    fout.open("out.txt");
    int number = 0;
    int res, count;
   /*    int count_nums[n];
    while (!fin.eof())
    {
        number++;
        string num;
        getline(fin, num);
        for(int i = 0; i < num.size(); i++){
            count_nums[num[i] - '0']++;
        }
        res = 0;
        count = count_nums[0];
        for(int i = 1; i < n; i++){
            if(count < count_nums[i]){
                res = i;
                count = count_nums[i];
            }
    }
        fout << res << ":" << count << endl;
    }
       */
  //  sprintf(number, maxNumber, "%s : %s");
    return 0;
}
