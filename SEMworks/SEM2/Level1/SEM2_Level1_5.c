#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 10


int main()
{
    srand(time(0));
    int a[N],s1=0,k1=0;
    printf("Исходный массив:");
    for(int i=0;i<N;i++)
    {
        a[i]=rand()%10;
        printf("%d\t",a[i]);
    }
    printf("\nИндексы повторяющихся элементов:");
    for(int i=0;i<N-1;i++)
        for(int j=i+1;j<N;j++)
        {
            if(a[i]==a[j])
            {
                printf("%d - %d\t",i,j);
                s1+=a[i]+a[j];
                k1+=2;
            }
        }
    printf("\nСумма повторяющихся элементов:%d",s1);
    printf("\nКоличество повторяющихся элементов:%d",k1);
}