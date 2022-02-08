#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
    int a[N];
    srand(time(0));
    printf("Исходный массив:");
    for(int i=0;i<N;i++)
    {
        a[i]=rand()%10;
        printf("%d\t",a[i]);
    }
    ///////////////////
    printf("\nИндексы элементов, значение которых больше предыдущего:");
    for(int i=1;i<N;i++)
    {
        if(a[i]>a[i-1]) printf("%d\t",i);
    }
    printf("\nИндексы элементов, значение которых меньше предыдущего:");
    for(int i=1;i<N;i++)
    {
        if(a[i]<a[i-1]) printf("%d\t",i);
    }
    //////////////////
    printf("\nИндексы элементов, значение которых больше последущего:");
    for(int i=0;i<N-1;i++)
    {
        if(a[i]>a[i+1]) printf("%d\t",i);
    }
    printf("\nИндексы элементов, значение которых меньше последущего:");
    for(int i=0;i<N+1;i++)
    {
        if(a[i]<a[i+1]) printf("%d\t",i);
    }
}