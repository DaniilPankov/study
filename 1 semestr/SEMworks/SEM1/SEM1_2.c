#include <stdio.h>

 int main()
 {
     printf("Введите 10 чисел через пробел\n");
     int a, S=0; 
     for(int i=0;i<10;i++)
     {
        scanf("%d",&a); 
        S+=a;
     }
     double Mean;
     Mean=(double)S/10;
     printf("Среднее значение:%f",Mean);
 }