#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <fstream>
using namespace std;
#define maxsize 100

int main()
{
    int n;
    main:
    cout<<"Меню:\n";
    cout<<"Ввести значения в бинарный файл...........1\n";
    cout<<"Найти количество максимальных элементов...2\n";
    cout<<"<----------------------------------------->\n";
    cout<<"Введите номер функции:";
    cin>>n; 
    switch(n)
    {
        case 1:
        {
            FILE *pf;
            int number;
            int a[maxsize];
            int *buff=a;

            if((pf=fopen("For SEM4_4.bin","wb+"))==NULL)
            {
                perror("Ошибка открытия файла!");
            }
            cout<<"Сколько чисел хотите ввести?\n";
            cin>>number;
            cout<<"<-------------------------->\n";
            for(int i=0;i<number;i++)
            {
                cin>>a[i];
            }
            fwrite (buff, sizeof(int),number, pf);
            fclose(pf);
            goto main;
        }
        case 2:
        {
            FILE *pf;
            int i=0;
            int k=0;
            int maximum=-10000;
            int *a;
            a=new int[maxsize];
            int *tw;
            if((pf=fopen("For SEM4_4.bin","rb+"))==NULL)
            {
                perror("Ошибка открытия файла!");
            }
            for(tw=a;!feof(pf);tw++)
            {
                fread (tw, sizeof(int),1, pf);
                i++;
            }
            for(int j=0;j<i-1;j++)
            {
                if(a[j]>maximum) maximum=a[j];
            }
            for(int j=0;j<i-1;j++)
            {
                if(a[j]==maximum) k++;
            }
            cout<<"Количество максимумов: "<<k;
            fclose(pf);
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