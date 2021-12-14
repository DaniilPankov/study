#include <iostream>
#include <time.h>
#include <algorithm>
using namespace std;
#define N 10

int main()
{
    setlocale(LC_ALL,"ru");
    srand(time(0));
    double a[N+1],A;
    cout<<"Исходный массив:"<<endl;
    for(int i=0;i<N;i++)
    {
        a[i]=rand()*0.01;
        cout<<a[i]<<"\t";
    }
    sort(begin(a),end(a)-1);
    cout<<endl<<"Отсортированный массив:"<<endl;
     for(int i=0;i<N;i++)
        {
            cout<<a[i]<<"\t";
        }
    cout<<"\nВведите число:"<<endl;
    cin>>a[N];
    sort(begin(a),end(a));
    cout<<"Ответ:"<<endl;
     for(int i=0;i<N+1;i++)
    {
        cout<<a[i]<<"\t";
    }
    system("pause");
}