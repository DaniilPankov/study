#include <stdio.h>

 int main()
 {
     printf("Введите параметры r и h через пробел\n");
     int r,h;
     scanf("%d%d",&r,&h);
     double pi=3.14;
     double V;
     V=pi*r*r*h;
     printf("Объем равен:%f",V);
 }