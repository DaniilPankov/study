#include <bits\stdc++.h>
using namespace std;
#define N 8
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
void findsum(int array[N][N], int k)
{
int i,j,s=0;
for(i=0;i<k;i++)
for(j=0;j<=i;j++) s+=array[i][j];
cout<<s;
}



int main()
{
    srand(time(0));
    int A[N][N];
    fillarray(A, N);
    cout<<"Матрица А:"<<endl;
    printarray(A, N);
    cout<<"Сумма:";
    findsum(A, N);
}
