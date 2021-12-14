#include <bits\stdc++.h>
using namespace std;
#define N 3

void fillarray(int array[N][N],int k)
{
    int i,j;
    for(i=0;i<k;i++)
    for(j=0;j<k;j++) array[i][j]=rand()%10;
}
void printarray(int array[N][N], int k)
{
    int i,j;
    for(i=0;i<k;i++)
    {
        for(j=0;j<k;j++) cout<<array[i][j]<<"\t";
        cout<<endl;
    }
}
void findsum(int array[N][N], int k)
{
    int i,j,m;
    int b[N];
    for(i=0;i<k;i++) b[i]=0;
    for (i=0;i<k;i++)
    for(j=0;j<k;j+=2) b[j]+=array[i][j];
    for(m=0;m<20;m++)
    {
        for (i=0;i<k;i++) if((b[i]==0)&(b[i+1]!=0))
        {
            b[i]=b[i+1];
            b[i+1]=0;
        } 
    }
    int z;
    if(k%2==0) z=k/2; else z=k/2+1; 
    
    for(i=0;i<z;i++) cout<<b[i]<<"\t";
}
int main()
{
    srand(time(0));
    int a[N][N];
    fillarray(a, N);
    cout<<"Исходный массив:";
    cout<<endl;
    printarray(a, N);
    cout<<"Сумма элементов нечетных столбцов:"<<endl;
    findsum(a, N);
}