#include <iostream>
#include <time.h>
#include <string>
using namespace std;
#define N1 10
#define N2 12
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
    int A[N1],B[N2],C[N1];
    for(int i=0;i<N1;i++)
    {
        C[i]=-1000;
    }
    srand(time(0));
    cout<<"Массив A:\n";
    initandprintarray(A,N1);
    cout<<"\nМассив B:\n";
    initandprintarray(B,N2);
    cout<<"\nЭлементы, которые входят только в один массив:\n";
    for(int i=0;i<N1;i++)
    {
        int k=0;
        for(int j=0;j<N2;j++)
        {
            if(A[i]==B[j])
            {
                k++;
                break;
            }
        }
        if (k==0) C[i]=A[i];
    }
   for(int i=0;i<N2;i++)
    {
        int k=0;
        for(int j=0;j<N1;j++)
        {
            if(B[i]==A[j])
            {
                k++; 
                break;
            } 
        }
        if (k==0) C[i]=B[i];
    } 
    for(int i=0;i<N1-1;i++)
    {
        int k=0;
        for(int j=i+1;j<N1;j++)
        {
            if(C[i]==C[j]) k++;
        }
        if(k==0&&C[i]!=-1000) cout<<C[i]<<"\t";
    }
}