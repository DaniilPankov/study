#include <stdio.h>

int main()
{
    printf("Введите координаты точки x y через пробел:\n");
    int x,y;
    scanf("%d%d",&x,&y);
    printf("Ответ:");
    if (x==0||y==0) printf("Точка лежит на одной из осей\n");
    if (x>0&&y>0) printf("I координатная четверть\n");
    if (x<0&&y>0) printf("II координатная четверть\n");
    if (x<0&&y<0) printf("III координатная четверть\n");
    if (x>0&&y<0) printf("IV координатная четверть\n");
    
    return 0;

}