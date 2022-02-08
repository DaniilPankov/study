#include <stdio.h>

int main()
{
    printf("Введите параметры k x y в одну строчку через пробел\n");
    int k,x,y;
    scanf("%d%d%d",&k,&x,&y);

    if(y==k*x+1) printf("Точка лежит на прямой");
        else printf("Точка НЕ лежит на прямой");

}