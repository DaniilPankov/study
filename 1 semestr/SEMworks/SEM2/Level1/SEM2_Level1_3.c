#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
    int k,a[N];
    srand(time(0));
    printf("Введите эталон:\n");
    scanf("%d",&k);
    printf("Исходный массив:");
    for(int i=0;i<N;i++)
    {
        a[i]=rand()%1000;
        printf("%d\t",a[i]);
    }
    printf("\nОтвет(индексы элементов):");
    for(int i=0;i<N;i++)
    {
        if(a[i]>k)
        {
            printf("%d\t",i);
        }
    }
}