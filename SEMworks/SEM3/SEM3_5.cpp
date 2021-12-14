#include <iostream>
using namespace std;

double function(double x )
{
    double y=x*x-2*x-15;
    return(y);
}
double mean( int a, int b, int n, double(*foo)(double))
{
    double mean;
    double s=0;
    for(double x=a;x<=b;x=x+(double)(b-a)/n)
    {
        s+=foo(x);
    }
    return((double)s/n);
}

int main()
{
 int a,b,n;
cout<<"Введите границы отрезка [a ; b] (сначала a, затем через пробел b):";
cin>>a;
cin>>b;
cout<<"Введите n:";
cin>>n;
cout<<"Среднее значение:"<<mean(a,b,n,function);

}