#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <windows.h>
#include <unistd.h>
#include <string>
#include <fstream>
#define NUMBEROFRECORDS 3
#define MAXNUMBEROFRECORDS 100
using namespace std;
struct disk
{
    char* name;
    int year;
    char* productby;
    int numberofsongs;
    double price;
};
int main()
{
    disk *pD;
    disk*tw;
    FILE *pf;
    pD=new disk[MAXNUMBEROFRECORDS];
    ////////////////////////////Загрузка данных
    if((pf = fopen("For SEM4_1.bin","rb+"))==NULL)
    {cout<<"Файла нет, необходима инициализация с клавиатуры !"<<endl;
        sleep(5);
    }
    char buff[80];
    if((pf = fopen("For SEM4_1.bin","rb"))==NULL)
        {
            perror("Ошибка открытия файла: режим load_bin");
        }
    for(tw=pD;!feof(pf);tw++)
    {
        fread (tw, sizeof(disk),1, pf);	// чтение 1–ой структуры
    }
    fclose (pf); 
    if((pf = fopen("For SEM4_1.txt","r"))==NULL)
    {
        perror("Ошибка открытия файла: режим load_txt");
    }
    for(tw=pD;!feof(pf);tw++)
    {
        fscanf (pf,"%s\n", buff);//////////////////
        tw->name=new char(strlen(buff)+1);//Название
        strcpy (tw->name, buff);////////////
        fscanf (pf,"%s\n", buff);//////////////////
        tw->productby=new char(strlen(buff)+1);//Имя
        strcpy (tw->productby, buff);////////////
    }
    ///////////////////////////
    int n;
    int k=NUMBEROFRECORDS;
    cout<<"Добро пожаловать!"<<endl;
    main:
    cout<<"Меню:"<<endl;
    cout<<"Добавить новыx 3 диска...................................1\n";
    cout<<"Распечатать информацию о дисках..........................2\n";
    cout<<"Найти информацию о диске по названию.....................3\n";
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
            disk*tw;
            for(tw=pD;tw<pD+k;tw++)
            {
                cout<<"Название(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->name=new char[len];
                memcpy (tw->name, buff,len);
                fflush(stdin);
                cout<<"Год выпуска:\n";
                cin>>tw->year;
                cout<<"Название фирмы-производителя(на английском):\n";
                fscanf (stdin,"%s",buff);
                len=strlen(buff)+1; 
                tw->productby=new char[len];
                memcpy (tw->productby, buff,len);
                fflush(stdin);
                cout<<"Количество песен на диске:\n";
                cin>>tw->numberofsongs;
                cout<<"Цена диска:\n";
                cin>>tw->price;
            }
            
            goto main;
        }
        case 2:
        {
            char buff1[80];
            char buff2[80];
            disk *tw;
            cout<<"Название диска\tГод выпуска\tПроизводитель\tКоличество песен\tЦена\n";
            for(tw=pD;tw<pD+k;tw++)
            {
                strcpy(buff1,"");strcat (buff1,tw->name);strcat (buff1," "); 
                strcpy(buff2,"");strcat (buff2,tw->productby);strcat (buff2," ");
                fprintf(stdout,"%-19s %-12d%-22s%-18d%f\n",buff1,tw->year,buff2,tw->numberofsongs,tw->price);
            }
            sleep(5);
            goto main;
        }
        case 3:
        {
            int s;
            char buff[80];
            char buff1[80];
            char buff2[80];
            string str1;
            disk *tw;
            int len;
            cout<<"Введите название диска:\n";
            cin>>str1;
            cout<<"Название диска\tГод выпуска\tПроизводитель\tКоличесвто песен\tЦена\n";
            for(tw=pD;tw<pD+k;tw++)
            {
                if(str1==tw->name)
                {
                    strcpy(buff1,"");strcat (buff1,tw->name);strcat (buff1," "); 
                    strcpy(buff2,"");strcat (buff2,tw->productby);strcat (buff2," ");
                    fprintf(stdout,"%-19s %-12d%-22s%-18d%f\n",buff1,tw->year,buff2,tw->numberofsongs,tw->price);  
                }
            }
            sleep(5);
            goto main;
        }
        case 4:
        {
            disk *tw;
            FILE* pf;
            if((pf = fopen("For SEM4_1.bin","wb"))==NULL)
            {
                perror("Ошибка открытия файла: режим save_bin");
            }
            tw=pD; 
            fwrite (tw, sizeof(disk),MAXNUMBEROFRECORDS, pf);	
            fclose (pf);
            if((pf = fopen("For SEM4_1.txt","w"))==NULL)
            {
                perror("Ошибка открытия файла: режим save_txt");
            }
            for (tw=pD; tw<pD+k; tw++)
            {
                fprintf (pf, "%s\n", tw->name);
                fprintf (pf, "%s\n", tw->productby);
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