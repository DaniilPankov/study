#include <iostream>
#include <time.h>
#define NUMBER1 5
#define NUMBER2 4
using namespace std;
void initarray(int array[], int a)
{
    for (int i=0;i<a;i++) array[i]=rand()%100-30;
}
void printarray(int array[],int a)
{
    for (int i=0;i<a;i++) cout<<array[i]<<"\t";
}
double mean(int array[],int a)
{
int i;
int index;
double s=0;
for (i=0;i<a;i++) if(array[i] < 0)
    {
        index=i;
        break;
    }
for (i=index+1;i<a;i++) s+=array[i];
return(double(s/(a-index-1)));
}
int main()
{
    srand(time(0));
    int A[NUMBER1];
    initarray(A,NUMBER1);
    cout<<"A:";
    printarray(A,NUMBER1);
    cout<<endl<<"Mean:"<<mean(A,NUMBER1);
    cout<<endl;
    int B[NUMBER2];
    initarray(B,NUMBER2);
    cout<<"B:";
    printarray(B,NUMBER2);
    cout<<endl<<"Mean:"<<mean(B,NUMBER2);
    
}