#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
#define N1 10
#define N2 11
#define z 10//Разрядность чисел;
void initandprintarray(int array[], int a)
{
    for (int i=0;i<a;i++)
    {
        array[i]=rand()%z;
        cout<<array[i]<<"\t";
    }
}
int main()
{
    int  A[N1],B[N2],C[N1],index, k=0;
    srand(time(0));
    cout<<"Массив A:\n";
    initandprintarray(A,N1);
    cout<<"\nМассив B:\n";
    initandprintarray(B,N2);
    sort(begin(A),end(A));
    sort(begin(B),end(B));
    cout<<"\nОтсортированный массив A:\n";
    for(int i=0;i<N1;i++)
    {
        cout<<A[i]<<"\t";
    }
    cout<<"\nОтсортированный массив B:\n";
    for(int i=0;i<N2;i++)
    {
        cout<<B[i]<<"\t";
    }
    ////////////////
    for(int i=0;i<N1;i++)
    {
        for(int j=0;j<N2;j++) 
        if(A[i]==B[j])
         {
            if (A[i]==0) A[i]=-10;
            C[i]=A[i];
            index=i;
         };
    }


    cout<<"\nПересечение множеств:\n";
     for(int i=0;i<=index;i++)
    {
        if(C[i]!=0&&C[i]<z&&C[i]!=C[i+1])
        {
            if(C[i]==-10) C[i]=0;
            cout<<C[i]<<"\t";
        }

            
    }
    


    
}