#include <iostream>
#include <cstring>
#include <string.h>
#include <unistd.h>
using namespace std;
#define max 10

int main()
{
    struct ORDER
    {
        char PLAT[15];
        char POL[15];
        double SUMMA;
    };
    ORDER spisok[max];
    int n, number;
    main:
    cout<<"Меню:\n";
    cout<<"Добавить информацию об операциях.............................1\n";
    cout<<"Вывести полную историю операций..............................2\n";
    cout<<"Информация о операции........................................3\n";
    cout<<"Выход........................................................4\n";
    cout<<"<------------------------------------------------------------>\n";
    cout<<"Введите номер функции:";
    cin>>n; 
    switch(n)
    {
        case 1:
        {
            cout<<"О скольких счетах вы хотите ввести информацию?\n";
            cin>>number;
            for(int i=0;i<number;i++)
            {
                cout<<"Введите расчетный счет плательщика:\n";
                getchar();
                cin.getline(spisok[i].PLAT,15);
                cout<<"Введите расчетный счет получателя:\n";
                getchar();
                cin.getline(spisok[i].POL,15);
                cout<<"Введите сумму:\n";
                cin>>spisok[i].SUMMA;
            }
            ORDER bigbuff;
            for(int i=0;i<number-1;i++)
            for(int j=i+1;i<number;i++)
            {
                if (_stricmp(spisok[i].PLAT, spisok[j].PLAT)>0)
                {
                    bigbuff = spisok[i]; 
				    spisok[i] = spisok[j];
				    spisok[j] = bigbuff;
                }
            }
            goto main;
        }
        case 2:
        {
            cout<<"Счёт плательщика\tСчёт получателя\tСумма\n";
            for(int i=0;i<number;i++)
            {
                cout<<spisok[i].PLAT<<"\t\t\t"<<spisok[i].POL<<"\t\t"<<spisok[i].SUMMA<<endl;
            }
            sleep(5);
            goto main;
        }
        case 3:
        {
            int summ;
            cout<<"Введите сумму:\n";
            cin>>summ;
            for(int i=0;i<number;i++)
            {
                if(summ==spisok->SUMMA)
                {
                    cout<<"Счёт плательщика\tСчёт получателя\tСумма\n";
                    cout<<spisok[i].PLAT<<"\t\t\t"<<spisok[i].POL<<"\t\t"<<spisok[i].SUMMA<<endl;
                }
                else
                {
                    cout<<"Такого счета нет=(";
                }
            }
        }
        case 4:
        {
            return 0;
        }
        default:
        {
            cout<<"Ошибка ввода! Введите корректное значение"<<endl;
            goto main;
        }
    }
}