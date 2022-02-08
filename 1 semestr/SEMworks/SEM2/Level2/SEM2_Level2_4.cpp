#include <iostream>
#include <time.h>
using namespace std;
#define N1 10
#define N2 11
#define N3 12
void initandprintarray(int array[], int a)
{
    for (int i=0;i<a;i++)
    {
        array[i]=rand()%10;
        cout<<array[i]<<"\t";
    }
}

 int main()
 {
    int  A[N1],B[N2],C[N3],D[N1];
    srand(time(0));
    cout<<"Массив A:\n";
    initandprintarray(A,N1);
    cout<<"\nМассив B:\n";
    initandprintarray(B,N2);
    cout<<"\nМассив C:\n";
    initandprintarray(C,N3);
    cout<<"\nЭлементы, которые есть в M1[N1] и которых нет в M2[N2] и M3[N3]:\n";
    for(int i=0;i<N1;i++)
    {
        int k=0;
        for(int j=0;j<N2;j++) if (A[i]==B[j]) k++;
        for(int j=0;j<N3;j++) if (A[i]==C[j]) k++;
        if(k==0) cout<<A[i]<<"\t";
    }
 }