#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
srand(time(0));
int a[N];
int min=1000;
int index;
printf("Исходный массив:");
for(int i=0;i<N;i++)//Инициализация массива
    {
        a[i]=rand()%10;
        printf("%d\t",a[i]);
    }
for(int i=0;i<N;i++)//Поиск минимума
{
    if(a[i]<min) 
    {
        min=a[i];
        index=i;
    }
}
a[index]=index;//Замена минимального элемента на его индекс
printf("\nОтвет:\t\t");
for(int i=0;i<N;i++)//Печать ответа
{
    printf("%d\t",a[i]);
}
return(0);
}