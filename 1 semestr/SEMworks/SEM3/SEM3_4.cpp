#include <iostream>
using namespace std;

double function(double x )
{
    double y=x*x-2*x-15;
    return(y);
}
double min( int a, int b, double(*foo)(double))
{
    double minimum=100000;
    for(double x=a;x<=b;x=x+0.1)
    {
        if (foo(x)<=minimum)
        minimum=foo(x);
    }
    return(minimum);
}

int main()
{
 int a,b;
cout<<"Введите границы отрезка [a ; b] (сначала a, затем через пробел b):";
cin>>a;
cin>>b;
cout<<"Минимальное значение на отрезке:"<<min(a,b,function);

}