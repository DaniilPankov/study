#include <iostream>
#include <cstring>
#include <string.h>
#include <unistd.h>
using namespace std;
#define maxrecords 20
int main()
{
    struct time
    {
        int hours;
        int minutes;
    };
    struct TRAIN
    {
        char NAZN[40];
        int NUMR;
        time TIME;
    };
    int n, number;
    TRAIN a[maxrecords];
    main:
    cout<<"Меню:\n";
    cout<<"Добавить поезда в расписание..............................................1\n";
    cout<<"Вывести полное расписание(сортировка).....................................2\n";
    cout<<"Информация о поездах, отправляющихся позже заданного времени..............3\n";
    cout<<"Выход.....................................................................4\n";
    cout<<"<----------------------------------------->\n";
    cout<<"Введите номер функции:";
    cin>>n; 
    switch(n)
    {
        case 1:
        {
            cout<<"О скольких поездах вы хотите ввести информацию?\n";
            cin>>number;
            for(int i=0;i<number;i++)
            {
                char buff[40];
                cout<<"Введите название поезда:\n";
                getchar();
                cin.getline(a[i].NAZN, 40,'\n');
                cout<<"Введите номер состава:\n";
                cin>>a[i].NUMR;
                cout<<"Введите время отправления(разделитель между часами и минутами - пробел):\n";
                cin>>a[i].TIME.hours;
                cin>>a[i].TIME.minutes;
            }
            TRAIN bigbuff;
            for(int i=0;i<number-1;i++)
            for(int j=i+1;i<number;i++)
            {
                if (_stricmp(a[i].NAZN, a[j].NAZN)>0)
                {
                    bigbuff = a[i]; 
				    a[i] = a[j];
				    a[j] = bigbuff;
                }
            }
            goto main;
        }
        case 2:
        {
            cout<<"Название поезда\tНомер состава\tВремя отправления\n";
            for(int i=0;i<number;i++)
            {
                cout<<a[i].NAZN<<"\t\t"<<a[i].NUMR<<"\t\t"<<a[i].TIME.hours<<":"<<a[i].TIME.minutes<<endl;
            }
            sleep(5);
            goto main;
        }
        case 3:
        {
            time now;
            cin>>now.hours;
            cin>>now.minutes;
            cout<<"Введите время(разделитель между часами и минутами - пробел):\n";
            for(int i=0;i<number;i++)
            {
                if(a[i].TIME.hours>now.hours)
                {
                    cout<<"Название поезда\tНомер состава\tВремя отправления\n";
                    cout<<a[i].NAZN<<"\t\t"<<a[i].NUMR<<"\t\t"<<a[i].TIME.hours<<":"<<a[i].TIME.minutes<<endl;
                }
                else
                {
                    if(a[i].TIME.hours==now.hours&&a[i].TIME.minutes>now.minutes)
                    {
                        cout<<"Название поезда\tНомер состава\tВремя отправления\n";
                        cout<<a[i].NAZN<<"\t\t"<<a[i].NUMR<<"\t\t"<<a[i].TIME.hours<<":"<<a[i].TIME.minutes<<endl; 
                    }
                    else
                    cout<<"Таких поездов нет=(\n";
                    sleep(5);
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
