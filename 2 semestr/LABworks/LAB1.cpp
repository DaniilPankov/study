#include <stdio.h>
#include <unistd.h>
using namespace std;
struct bread
{
    char* fam;
    int type;
    double weight;
    int quant;
    double cost;
};

int main()
{
    char line[255];
    FILE *fp =fopen("For_LAB1.txt","r");
    fprintf(fp,"some new text\n123");
    fprintf(fp,"\ngfr");
    fgets(line,255,fp);
    printf(line);
    fgets(line,255,fp);
    printf(line);
    fgets(line,255,fp);
    printf(line);
   
    //////////////////////////////
    int n;
    printf("\nДобро пожаловать!\n");
    main:
    sleep(1);
    printf("Меню:\n");
    printf("Добавить новое изделие................1\n");
    printf("Распечатать информацию об изделии.....2\n");
    printf("Поиск изделий по названию.............3\n");
    printf("Фильтр по типу изделия................4\n");
    printf("Сортировать по уменьшению стоимости...5\n");
    printf("Выход.................................6\n");
    scanf("%d",&n);

    switch(n)
    {
        case 1:
        {
            
            goto main;
        }
        case 2:
        {
            
            goto main;
        }
        case 3:
        {
            
            goto main;
        }
        case 4:
        {
            
            goto main;
        }
        case 5:
        {
            
            goto main;
        }
        case 6:
        {
            
            return 0;
        }

    }
}