#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <unistd.h>
#include <string>
#include <fstream>
#define NUMBEROFRECORDS 2
#define MAXNUMBEROFRECORDS 100
using namespace std;
struct FIO
{
    char* surname;
    char* name;
    char* father;
};
struct DATE123 
{
    int day;
    char* month;
    int year;
}; 
struct deposid
{
    int number;
    FIO fio;
    DATE123 date;
    int money;
};
int translate(char* str);
int main()
{
    deposid *pD;
    deposid *tw;
    FILE *pf;
    pD=new deposid[MAXNUMBEROFRECORDS];
    ////////////////////////////Загрузка данных
    if((pf = fopen("For LAB7.bin","rb+"))==NULL)
    {cout<<"Файла нет, необходима инициализация с клавиатуры !"<<endl;
        sleep(5);
    }
    char buff[80];
    if((pf = fopen("For LAB7.bin","rb"))==NULL)
        {
            perror("Ошибка открытия файла: режим load_bin");
        }
    for(tw=pD;!feof(pf);tw++)
    {
        fread (tw, sizeof(deposid),1, pf);	// чтение 1–ой структуры
    }
    fclose (pf); 
    if((pf = fopen("For LAB7.txt","r"))==NULL)
    {
        perror("Ошибка открытия файла: режим load_txt");
    }
    for(tw=pD;!feof(pf);tw++)
    {
        fscanf (pf,"%s\n", buff);//////////////////
        tw->fio.surname=new char(strlen(buff)+1);//Фамилия
        strcpy (tw->fio.surname, buff);////////////
        fscanf (pf,"%s\n", buff);//////////////////
        tw->fio.name=new char(strlen(buff)+1);//Имя
        strcpy (tw->fio.name, buff);////////////
        fscanf (pf,"%s\n", buff);//////////////////
        tw->fio.father=new char(strlen(buff)+1);//Отчество
        strcpy (tw->fio.father, buff);////////////
    }
    if((pf = fopen("Month.txt","r"))==NULL)
    {
        perror("Ошибка открытия файла: режим load_txt");
    }
    for(tw=pD;!feof(pf);tw++)
    {
        fscanf (pf,"%s\n", buff);//////////////////
        tw->date.month=new char(strlen(buff)+1);//Фамилия
        strcpy (tw->date.month, buff);////////////
    }    
    ///////////////////////////
    int n;
    int k=NUMBEROFRECORDS;
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
            char buff[80];
            int len;
            deposid *tw;
            for(tw=pD;tw<pD+k;tw++)
            {
                cout<<"Фамилия(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->fio.surname=new char[len];
                memcpy (tw->fio.surname, buff,len);
                fflush(stdin);
                cout<<"Имя(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->fio.name=new char(len);
                memcpy (tw->fio.name, buff,len);
                fflush(stdin);
                cout<<"Отчество(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->fio.father=new char(len);
                memcpy (tw->fio.father, buff,len);
                fflush(stdin);
                cout<<"Дата создания счёта:Число\n";
                cin>>tw->date.day;
                cout<<"Дата создания счёта:Месяц(с Большой буквы на английском)\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->date.month=new char(len);
                memcpy (tw->date.month, buff,len);
                fflush(stdin);
                cout<<"Дата создания счёта:Год\n";
                cin>>tw->date.year;
                cout<<"Сумма на счету:\n";
                cin>>tw->money;
            }
            
            goto main;
        }
        case 2:
        {
            char buff1[80];
            char buff2[80];
            deposid *tw;
            cout<<"Фамилия Имя Отчество\tЧисло\tМесяц\tГод\tCумма на счёте\n";
            for(tw=pD;tw<pD+k;tw++)
            {
                strcpy(buff1,"");	
                strcat (buff1,tw->fio.surname);strcat (buff1," "); 
                strcat (buff1,tw->fio.name);strcat (buff1," "); 
                strcat (buff1,tw->fio.father); 
                strcpy(buff2,"");strcat (buff2,tw->date.month);strcat (buff2," ");
                fprintf(stdout,"%-25s %-5d%-9s%-8d%d\n",buff1,tw->date.day,buff2,tw->date.year,tw->money);
            }
            sleep(5);
            goto main;
        }
        case 3:
        {
            int s;
            char buff1[80];
            char buff2[80];
            deposid *tw;
            cout<<"Введите контрольную сумму:"<<endl;;
            cin>>s;
            cout<<"Фамилия Имя Отчество\tЧисло\tМесяц\tГод\tCумма на счёте\n";
            for(tw=pD;tw<pD+k;tw++)
            {
                if(tw->money>s)
                {
                    strcpy(buff1,"");	
                    strcat (buff1,tw->fio.surname);strcat (buff1," "); 
                    strcat (buff1,tw->fio.name);strcat (buff1," "); 
                    strcat (buff1,tw->fio.father); 
                    strcpy(buff2,"");strcat (buff2,tw->date.month);strcat (buff2," ");
                    fprintf(stdout,"%-25s %-5d%-9s%-8d%d\n",buff1,tw->date.day,buff2,tw->date.year,tw->money);
                }
               
            }
            sleep(5);
            goto main;
        }
        case 4:
        {
            int s;
            char buff[80];
            char buff1[80];
            char buff2[80];
            string str1;
            string str2;
            string str3;
            deposid *tw;
            int len;
            cout<<"Фамилия(на английском):\n";
            cin>>str1;
            cout<<"Имя(на английском):\n";
            cin>>str2;
            cout<<"Отчество(на английском):\n";
            cin>>str3;
            cout<<"Фамилия Имя Отчество\tЧисло\tМесяц\tГод\tCумма на счёте\n";
            for(tw=pD;tw<pD+k;tw++)
            {
                if(str1==tw->fio.surname&&str2==tw->fio.name&&str3==tw->fio.father)
                {
                    strcpy(buff1,"");	
                    strcat (buff1,tw->fio.surname);strcat (buff1," "); 
                    strcat (buff1,tw->fio.name);strcat (buff1," "); 
                    strcat (buff1,tw->fio.father); 
                    strcpy(buff2,"");strcat (buff2,tw->date.month);strcat (buff2," ");
                    fprintf(stdout,"%-25s %-5d%-9s%-8d%d\n",buff1,tw->date.day,buff2,tw->date.year,tw->money);  
                }
            }
            sleep(5);
            goto main;
        }
        case 5:
        {
            DATE123 today;
            int len;
            char buff[80];
            char buff1[80];
            char buff2[80];
            deposid *tw;
            cout<<"Дата создания счёта:Число\n";
            cin>>today.day;
            cout<<"Дата создания счёта:Месяц(с Большой буквы на английском)\n";
            fscanf (stdin,"%s",buff);
            len=strlen(buff)+1; 
            today.month=new char(len);
            memcpy (today.month, buff,len);
            fflush(stdin);
            cout<<"Дата создания счёта:Год\n";
            cin>>today.year;
            cout<<"Фамилия Имя Отчество\tЧисло\tМесяц\tГод\tCумма на счёте\n";
            for(tw=pD;tw<pD+k;tw++)
            {
                if(tw->date.year>today.year)
                {
                    strcpy(buff1,"");	
                    strcat (buff1,tw->fio.surname);strcat (buff1," "); 
                    strcat (buff1,tw->fio.name);strcat (buff1," "); 
                    strcat (buff1,tw->fio.father); 
                    strcpy(buff2,"");strcat (buff2,tw->date.month);strcat (buff2," ");
                    fprintf(stdout,"%-25s %-5d%-9s%-8d%d\n",buff1,tw->date.day,buff2,tw->date.year,tw->money);
                }
                else
                {
                    if(translate(tw->date.month)>translate(today.month))
                    {
                        strcpy(buff1,"");	
                        strcat (buff1,tw->fio.surname);strcat (buff1," "); 
                        strcat (buff1,tw->fio.name);strcat (buff1," "); 
                        strcat (buff1,tw->fio.father); 
                        strcpy(buff2,"");strcat (buff2,tw->date.month);strcat (buff2," ");
                        fprintf(stdout,"%-25s %-5d%-9s%-8d%d\n",buff1,tw->date.day,buff2,tw->date.year,tw->money);
                    }
                    else
                    {
                        if(tw->date.day>today.day)
                        {
                            strcpy(buff1,"");	
                            strcat (buff1,tw->fio.surname);strcat (buff1," "); 
                            strcat (buff1,tw->fio.name);strcat (buff1," "); 
                            strcat (buff1,tw->fio.father); 
                            strcpy(buff2,"");strcat (buff2,tw->date.month);strcat (buff2," ");
                            fprintf(stdout,"%-25s %-5d%-9s%-8d%d\n",buff1,tw->date.day,buff2,tw->date.year,tw->money);
                        }
                    }
                }
            }
            sleep(5);
            goto main;
        }
        case 6:
        {
            deposid *tw;
            FILE* pf;
            if((pf = fopen("For LAB7.bin","wb"))==NULL)
            {
                perror("Ошибка открытия файла: режим save_bin");
            }
            tw=pD; 
            fwrite (tw, sizeof(deposid),MAXNUMBEROFRECORDS, pf);	
            fclose (pf);
            if((pf = fopen("For LAB7.txt","w"))==NULL)
            {
                perror("Ошибка открытия файла: режим save_txt");
            }
            for (tw=pD; tw<pD+k; tw++)
            {
                fprintf (pf, "%s\n", tw->fio.surname);
                fprintf (pf, "%s\n", tw->fio.name);
                fprintf (pf, "%s\n", tw->fio.father);
            }
            fclose (pf); 
            if((pf = fopen("Month.txt","w"))==NULL)
            {
                perror("Ошибка открытия файла: режим save_txt");
            }
            for (tw=pD; tw<pD+k; tw++)
            {
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
int translate(char* str)
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