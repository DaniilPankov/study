#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <unistd.h>
#include <string>
#include <fstream>
using namespace std;
struct FIO
{
    string surname;
    string name;
    string father;
};
struct DATE123 
{
    int day;
    string month;
    int year;
}; 
struct deposid
{
    int number;
    FIO fio;
    DATE123 date;
    int money;
};
int translate(string a);
void output(deposid a[], int i);
int main()
{
    struct deposid *a=new struct deposid[15];
    int n;
    int k=1;
    cout<<"Добро пожаловать!"<<endl;
    main:
    cout<<"Меню:"<<endl;
    cout<<"Добавить новый счет......................................1\n";
    cout<<"Распечатать информацию о счете в табличном виде..........2\n";
    cout<<"Определить все счета с суммой больше заданной............3\n";
    cout<<"Найти все счета клиента(по фамилии имени и отчеству).....4\n";
    cout<<"Поиск клиентов со счетом, открытым позже заданной даты...5\n";
    cout<<"Выход....................................................6\n";
    cout<<"<-------------------------------------------------------->\n";
    cout<<"Введите номер функции:";
    cin>>n;
    switch(n)
    {
        case 1:
        {
            a[k].number=k;
            cout<<"Фамилия(на английском):\n";cin>>a[k].fio.surname;
            cout<<"Имя(на английском):\n";cin>>a[k].fio.name;
            cout<<"Отчество(на английском):\n";cin>>a[k].fio.father;
            cout<<"Дата создания счёта:(Число Месяц(с Большой буквы на английском) Год(вводить все через пробел)):\n"; 
            cin>>a[k].date.day;
            cin>>a[k].date.month;
            cin>>a[k].date.year; 
            cout<<"Сумма на счёте:"<<endl;cin>>a[k].money;
            k++;
            goto main;
        }
        case 2:
        {
            int numberofdeposid;
            cout<<"Введите номер счета\n";
            cin>>numberofdeposid;
            cout<<"Информация о счете:"<<endl;
            output(a, numberofdeposid);
            sleep(5);
            goto main;
        }
        case 3:
        {
            int s;
            cout<<"Введите контрольную сумму:"<<endl;;
            cin>>s;
            for(int i=0;i<k+1;i++)
                if (a[i].money>s)
                {
                    output(a,i);
                } 
            sleep(5);
            goto main;
        }
        case 4:
        {
            string str1, str2, str3;

            cout<<"Фамилия(на английском):\n";cin>>str1;
            cout<<"Имя(на английском):\n";cin>>str2;
            cout<<"Отчество(на английском):\n";cin>>str3;
            for(int i=0;i<k+1;i++)
            {
                if(str1==a[i].fio.surname&&str2==a[i].fio.name&&str3==a[i].fio.father)
                {
                    output(a, i); 
                }

            }
            sleep(5);
            goto main;
        }
        case 5:
        {
            DATE123 today;
            cout<<"Введите дату:(Число Месяц(с Большой буквы на английском) Год(вводить все через пробел))\n";
            cin>>today.day;
            cin>>today.month;
            cin>>today.year;
            for(int i=1;i<k+1;i++)
            {
                if(a[i].date.year>today.year)
                {
                  output(a, i);
                  break;
                }
                else
                {
                    if(translate(a[i].date.month)>translate(today.month))
                    {
                        output(a, i);
                        break;
                    }
                    else
                    {
                        if (a[i].date.day>today.day)
                        {
                            output(a, i);
                            break;
                        }
                        else
                        {
                            cout<<"Таких клиентов нету\n";
                        }
                    }
                }
            }
            sleep(5);
            goto main;
        }
        case 6:
        {
            delete [] a;
            return 0;
        }
        default:
        {
            cout<<"Ошибка ввода! Введите корректное значение"<<endl;
            goto main;
        }
    }
}
int translate(string str)
{
    if(str=="January") return(1);
    if(str=="February") return(2);
    if(str=="March") return(3);
    if(str=="April") return(4);
    if(str=="May") return(5);
    if(str=="June") return(6);
    if(str=="July") return(7);
    if(str=="August") return(8);
    if(str=="September") return(9);
    if(str=="October") return(10);
    if(str=="November") return(11);
    if(str=="December") return(12);
    return(0);

}
void output(deposid a[],int i)
{
    cout<<"Номер счета\tФамилия\tИмя\tОтчество\tЧисло\tМесяц\tГод\tCумма на счёте\n";
    cout<<a[i].number<<"\t\t";
    cout<<a[i].fio.surname<<"\t";
    cout<<a[i].fio.name<<"\t";
    cout<<a[i].fio.father<<"\t";
    cout<<a[i].date.day<<"\t";
    cout<<a[i].date.month<<"\t";
    cout<<a[i].date.year<<"\t";
    cout<<a[i].money<<"\t\n"; 
}