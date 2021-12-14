#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <unistd.h>
#include <string>
#include <fstream>
#define NUMBEROFRECORDS 1
#define MAXNUMBEROFRECORDS 100
using namespace std;
struct DATE123 
{
    int day;
    char* month;
    int year;
};
struct CLASS
{
    int number;
    char letter;
};
struct school
{
    char* surname;
    char* name;
    char* sex;
    DATE123 date ;
    CLASS clas;
};
int main()
{
    school *pD;
    school*tw;
    FILE *pf;
    pD=new school[MAXNUMBEROFRECORDS];
    ////////////////////////////Загрузка данных
    if((pf = fopen("For SEM4_2.bin","rb+"))==NULL)
    {cout<<"Файла нет, необходима инициализация с клавиатуры !"<<endl;
        sleep(5);
    }
    char buff[80];
    if((pf = fopen("For SEM4_2.bin","rb"))==NULL)
        {
            perror("Ошибка открытия файла: режим load_bin");
        }
    for(tw=pD;!feof(pf);tw++)
    {
        fread (tw, sizeof(school),1, pf);	// чтение 1–ой структуры
    }
    fclose (pf); 
    if((pf = fopen("For SEM4_2.txt","r"))==NULL)
    {
        perror("Ошибка открытия файла: режим load_txt");
    }
    for(tw=pD;!feof(pf);tw++)
    {
        fscanf (pf,"%s\n", buff);//////////////////
        tw->surname=new char(strlen(buff)+1);//Фамилия
        strcpy (tw->surname, buff);////////////
        fscanf (pf,"%s\n", buff);//////////////////
        tw->name=new char(strlen(buff)+1);//Имя
        strcpy (tw->name, buff);////////////
        fscanf (pf,"%s\n", buff);//////////////////
        tw->sex=new char(strlen(buff)+1);//Пол
        strcpy (tw->sex, buff);////////////
        fscanf (pf,"%s\n", buff);//////////////////
        tw->date.month=new char(strlen(buff)+1);//Месяц
        strcpy (tw->date.month, buff);////////////
    }
    ///////////////////////////
    int n;
    int k=NUMBEROFRECORDS;
    cout<<"Добро пожаловать!"<<endl;
    main:
    cout<<"Меню:"<<endl;
    cout<<"Добавить данные об ученике...............................1\n";
    cout<<"Распечатать информацию о учениках........................2\n";
    cout<<"Количетство учеников по параметрам.......................3\n";
    cout<<"Выход....................................................4\n";
    cout<<"<-------------------------------------------------------->\n";
    cout<<"Введите номер функции:";
    cin>>n;
    switch(n)
    {
        case 1:
        {
            char buff[80];
            int len;
            school *tw;
            for(tw=pD;tw<pD+k;tw++)
            {
                cout<<"Фамилия(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->surname=new char[len];
                memcpy (tw->surname, buff,len);
                fflush(stdin);
                cout<<"Имя(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->name=new char(len);
                memcpy (tw->name, buff,len);
                fflush(stdin);
                cout<<"Пол(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->sex=new char(len);
                memcpy (tw->sex, buff,len);
                fflush(stdin);
                cout<<"День рождения(число):\n";
                cin>>tw->date.day;
                cout<<"День рождения(месяц на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->date.month=new char(len);
                memcpy (tw->date.month, buff,len);
                fflush(stdin);
                cout<<"День рождения(год):\n";
                cin>>tw->date.year;
                cout<<"Класс(цифра):\n";
                cin>>tw->clas.number;
                cout<<"Класс(буква):\n";
                cin>>tw->clas.letter;
            }
            
            goto main;
        }
        case 2:
        {
            char buff1[80];
            char buff2[80];
            char buff3[80];
            school *tw;
            cout<<"Фамилия  Имя Пол\tЧисло\tМесяц\tГод\tКласс\n";
            for(tw=pD;tw<pD+k;tw++)
            {
                strcpy(buff1,"");
                strcat (buff1,tw->surname);strcat (buff1," ");
                strcat (buff1,tw->name);strcat (buff1," "); 
                strcat (buff1,tw->sex); 
                strcpy(buff2,"");strcat (buff2,tw->date.month);strcat (buff2," ");
                fprintf(stdout,"%s\t%d\t%s%d\t%d%c\n",buff1,tw->date.day,buff2,tw->date.year,tw->clas.number,tw->clas.letter);
            }
            sleep(5);
            goto main;
        }
        case 3:
        {
            char buff1[80];
            char buff2[80];
            char buff3[80];
            int age,k1=0;
            char letter;
            school *tw;
            cout<<"Введите возраст ученика(полных лет):\n";
            cin>>age;
            cout<<"Введите букву класса:\n";
            cin>>letter;
            cout<<"Количество учеников: ";
            for(tw=pD;tw<pD+k;tw++)
            {
                if(age==2021-tw->date.year && letter==tw->clas.letter)
                {
                    k1++;
                }
            }
            cout<<k1;
            sleep(5);
            goto main;
        }
        case 4:
        {
            school *tw;
            FILE* pf;
            if((pf = fopen("For SEM4_2.bin","wb"))==NULL)
            {
                perror("Ошибка открытия файла: режим save_bin");
            }
            tw=pD; 
            fwrite (tw, sizeof(school),MAXNUMBEROFRECORDS, pf);	
            fclose (pf);
            if((pf = fopen("For SEM4_2.txt","w"))==NULL)
            {
                perror("Ошибка открытия файла: режим save_txt");
            }
            for (tw=pD; tw<pD+k; tw++)
            {
                fprintf (pf, "%s\n", tw->surname);
                fprintf (pf, "%s\n", tw->name);
                fprintf (pf, "%s\n", tw->sex);
                fprintf (pf, "%s\n", tw->date.month);
            }
            fclose (pf); 
            delete []pD;
            return 0;

        }
        default:
        {
            cout<<"Ошибка ввода! Введите корректное значение"<<endl;
            goto main;
        }
    }
}