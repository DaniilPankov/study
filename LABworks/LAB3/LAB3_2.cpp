#include <iostream>
#include <time.h>
#define NUMBER1 6
using namespace std;

void initmatr(int array[NUMBER1][NUMBER1], int k)//Инициаизируем массив
{
    int i,j;
    for(i=0;i<k;i++)
    for(j=0;j<k;j++)
    {
        array[i][j]=rand()%2;
    }
}
void printarray(int array[NUMBER1][NUMBER1], int k)//Печатаем массив
{
    int i,j;
    for(i=0;i<k;i++)
    {
    for(j=0;j<k;j++)
    {
    cout<<array[i][j]<<"\t";
    }
    cout<<endl;
    }
}
void numberofzeros(int array[NUMBER1][NUMBER1], int k);//Считаем количество нулей

int main()
{
    srand(time(0));
    int A[NUMBER1][NUMBER1];
    initmatr(A,NUMBER1);
    cout<<"Массив:"<<endl;
    printarray(A,NUMBER1);
    cout<<"Количество нулей:"<<endl;
    numberofzeros(A,NUMBER1);
}
void numberofzeros(int array[NUMBER1][NUMBER1], int k)//Считаем количество нулей
{
    int i,j,ans;
    for(i=0;i<k/2;i++)
    {
        ans=0;
        for(j=i;j<k-i;j++) if (array[i][j]==0) ans++;
        cout<<ans<<endl;
    }
    for(i=k/2;i<k;i++)
    {
        ans=0;
        for(j=k-i-1;j<i+1;j++) if(array[i][j]==0) ans++;
        cout<<ans<<endl;
    }
}