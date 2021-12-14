#include <iostream>
#include <time.h>
using namespace std;
#define n1 6
#define n2 5
void fillarray(int array[], int k)
{
    int *p_a;
    for(p_a=array;p_a<array+k;p_a++)
    {
        *p_a=rand()%100;
    }

}

void printarray(int array[], int k)
{
    int *p_a;
    for(p_a=array;p_a<array+k;p_a++)
    {
        cout<<*p_a<<"\t";
    }
}
int findindex(int array[], int k)
{
int d=0,max=0;
int *p_a;
for(p_a=array;p_a<array+k;p_a++)
{
    if(*p_a>max)
    {
        max=*p_a;
        d=p_a-array;
    }
}
return(d);
}

int main()
{
    srand(time(0));
    int A[n1];
    fillarray(A, n1);
    cout<<"A:";
    printarray(A, n1);
    cout<<endl<<"MAX= ";
    cout<<findindex(A, n1);
    
    int B[n2];
    fillarray(B, n2);
    cout<<endl;
    cout<<"B:";
    printarray(B, n2);
    cout<<endl<<"MAX= ";
    cout<<findindex(B, n2);
    cout<<endl;
if (findindex(A, n1)>findindex(B, n2))
{
    cout<<"В массиве А максимум находится ближе, чем в массиве В ";
    if (findindex(A, n1)==findindex(B, n2)) cout<<"Максимумы находятся на одинаковом расстоянии";
} else cout<<"В массиве B максимум находится ближе, чем в массиве A";
}