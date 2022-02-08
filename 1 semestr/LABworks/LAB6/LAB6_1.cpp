#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <unistd.h>
#include <string>
using namespace std;

int main()
{
setlocale(LC_ALL, "Russian");

struct deposid
{	
    int number; 			
	string surname;
    string name;
	double money;
};
int n;
int k=1;
struct deposid *a=new struct deposid[15];
tryagain:
cout<<"Меню:"<<endl;
cout<<"Добавить новый счет.....................................1\n";
cout<<"Распечатать информацию о счете в табличном виде.........2\n";
cout<<"Определить все счета с суммой больше заданной...........3\n";
cout<<"Найти все счета заданного клиента(по имени и фамилии)...4\n";
cout<<"Выход...................................................5\n";
cout<<"<------------------------------------------------------->\n";
cout<<"Введите номер функции:";
cin>>n;
switch(n)
{
case 1:
    a[k].number=k;
    cout<<"Фамилия(на английском):\n";cin>>a[k].surname;
    cout<<"Имя(на английском):\n";cin>>a[k].name;
    cout<<"Сумма на счёте"<<endl;
    cin>>a[k].money;
    
    k++;
    goto tryagain;
case 2:
    int numberofdeposid;
    cout<<"Введите номер счета\n";
    cin>>numberofdeposid;
    cout<<"Информация о счете:"<<endl;
    cout<<"Номер счета\tФамилия\tИмя\tCумма на счёте\n";
    cout<<a[numberofdeposid].number<<"\t\t";
    cout<<a[numberofdeposid].surname<<"\t";
    cout<<a[numberofdeposid].name<<"\t";
    cout<<a[numberofdeposid].money<<"\n";
    sleep(5);
    goto tryagain;
case 3:
    int s;
    cout<<"Введите контрольную сумму:"<<endl;;
    cin>>s;
    cout<<"Номер счета\tФамилия\tИмя\tCумма на счёте\n";
    for(int i=0;i<k+1;i++)
         if (a[i].money>s)
         {
            cout<<a[i].number<<"\t\t";
            cout<<a[i].surname<<"\t";
            cout<<a[i].name<<"\t";
            cout<<a[i].money<<"\n";
         } 
    sleep(5);
    goto tryagain;
case 4:
{
    string str1;
    string str2;
    cout<<"Фамилия(на английском):\n";cin>>str1;
    cout<<"Имя(на английском):\n";cin>>str2;
    cout<<"Номер счета\tФамилия\tИмя\tCумма на счёте\n";
    for(int i=0;i<k+1;i++)
    {
        if(str1==a[i].surname&&str2==a[i].name)
        {
            cout<<a[i].number<<"\t\t";
            cout<<a[i].surname<<"\t";
            cout<<a[i].name<<"\t";
            cout<<a[i].money<<"\n";
        }

    }
    sleep(5);
    goto tryagain;
}
case 5:
   
   delete [] a;
    return(0);
default:
    cout<<"Ошибка ввода! Введите корректное значение"<<endl;
    goto tryagain;
}
}


#include <iostream>
#include <fstream>
using namespace std;

int main()
{
ofstream fout;
fout.open("For LAB7.txt",ofstream::app);
if(!fout.is_open())
{
    cout<<"Файл не получилось открыть";
}
else 
{
cout<<"Файл успешно открыт"<<endl;
fout<<"Введите Пароль:";
fout<<"\n555\n";
fout<<"Новые данные:\n";
fout<<"Ну типо\n";
}
fout.close();

ifstream fin;
fin.open("For LAB7.txt");
if(!fin.is_open())
{
    cout<<"Файл не получилось открыть";
}
else 
{
cout<<"Файл успешно открыт";
char str[100];
fin.getline(str,100);
cout<<str;
}
fin.close();
}