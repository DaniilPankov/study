#include <iostream>
#include <string.h>
#include <string>
using namespace std;
void delspace( char string1[])
{
        for(int k=0;k<100;k++)//обрабатываем строку №1
    {
        for(int i=0;i <=strlen(string1);i++)
        {
        if((string1[i]==' ')&(string1[i+1]==' '))  
        for(int j=i+1;j<=strlen(string1);j++)
            {
            string1[j]=string1[j+1];
        }
        }
    } 
}
string point(char string2[])
{
    string ans;
    for(int i=0;i <=strlen(string2);i++)//обрабатываем строку №2
    {
       if((string2[i]>='A')&(string2[i]<='Z'))
       {
           ans=ans+".";
       }
        ans+=string2[i];
    }
    return(ans);
}


int main()
{
char *str1= new char[125];
char *str2=new char[125];
/////////////////////////
cout<<"Создать функции для удаления лишних пробелов в строке и во второй строке перед каждой заглавной буквой поставить точку"<<endl;
cout<<"Введите строку №1 на латинице:"<<endl;
cin.getline(str1, 125);
cout<<"Введите строку №2 на латинице:"<<endl;
cin.getline(str2, 125);
//getline(cin, string2);

delspace(str1);
cout<<"Исправленная строка №1:"<<str1<<endl;
cout<<"Исправленная строка №2:"<<point(str2)<<endl;
///////////////////////
delete [] str1;
delete [] str2;

}