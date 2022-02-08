#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 5

int main()
{
    int a[N],K,s=0;
    printf("Введите параметр K:\n");
    scanf("%d",&K);
    printf("Исходный массив:");
    srand(time(0));
    for(int i=0;i<N;i++)
    {
        a[i]=rand()%100;
        printf("%d\t",a[i]);
        if(a[i]%K==0) s+=a[i];
    }
    printf("\nОтвет:%d",s);
}