#include <bits\stdc++.h>
using namespace std;
#define N 5
void fillarray(int array[N][N], int k)
{
    int i,j;
    for(i=0;i<k;i++)
    for(j=0;j<k;j++) array[i][j]=rand()%100;
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
void findminmax(int array[N][N], int k,int *p_min,int *p_max)
{
int i,j,s=0;
for(i=0;i<k;i++)
for(j=0;j<=i;j++)
{
    if(array[i][j]>*p_max) *p_max=array[i][j];
    if(array[i][j]<*p_min) *p_min=array[i][j];
}
}



int main()
{
    srand(time(0));
    int A[N][N];
    int min=100;
    int max=0;
    fillarray(A, N);
    cout<<"Матрица А:"<<endl;
    printarray(A, N);
    findminmax(A, N,&min,&max);
    cout<<"MAX="<<max<<endl;
    cout<<"MIN="<<min;
}
