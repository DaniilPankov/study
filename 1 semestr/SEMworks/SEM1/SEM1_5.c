#include <stdio.h>
int main()
{
    printf("Введите параметр A и N в строчку через пробел\n");
    int A,N;
    scanf("%d%d",&A,&N);
    int ans=1;
    for(int i=0;i<N;i++)
    {
        ans=ans*A;
    }
    printf("Ответ:%d",ans);
}