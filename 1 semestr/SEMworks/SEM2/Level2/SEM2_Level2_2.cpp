#include <iostream>
#include <time.h>
using namespace std;
#define N1 10
#define N2 12
int maxint(int a, int b)
{
 if (a>b) return(a);
    else return(b);
}
int minint(int a, int b);
void initandprintarray(int array[], int a)
{
    for (int i=0;i<a;i++)
    {
        array[i]=rand()%100;
        cout<<array[i]<<"\t";
    }
}
void max(int a[], int b[], int c[], int i1,int i2)
{
    for(int i=0;i<minint(i1,i2);i++)
    {
        if(a[i]>b[i]) c[i]=a[i];
         else c[i]=b[i];
         cout<<c[i]<<"\t";
    }
    for(int i=minint(i1,i2);i<maxint(i1,i2);i++)
    {
        if(i1>i2) c[i]=a[i];
            else c[i]=b[i];
        cout<<c[i]<<"\t";    
    }
}
void min(int a[], int b[], int c[],int i1,int i2 )
{
    for(int i=0;i<minint(i1,i2);i++)
    {
        if(a[i]<b[i]) c[i]=a[i];
         else c[i]=b[i];
         cout<<c[i]<<"\t";
    }
     for(int i=minint(i1,i2);i<maxint(i1,i2);i++)
    {
        if(i1>i2)c[i]=a[i];
            else c[i]=b[i];
        cout<<c[i]<<"\t";    
    }
}

int minint(int a, int b)
{
 if (a<b) return a;
    else return b;
}

int main()
{
    srand(time(0));
    int A[N1],B[N2],C[N2],D[N2];
    cout<<"Массив A:\t  ";
    initandprintarray(A,N1);
    cout<<endl<<"Массив B:\t  ";
    initandprintarray(B,N2);
    cout<<endl<<"Массив максимумов:";
    max(A,B,C,N1,N2);
    cout<<endl<<"Массив минимумов: ";
    min(A,B,D,N1,N2);
}