#include <iostream>
using namespace std;

double function(double x )
{
    double y=x*x;
    return(y);
}
double diffrence( int a, int b, double(*foo)(double))
{
    double minimum=100000;
    double maximum=0;
    for(double x=a;x<=b;x=x+0.1)
    {
        if (foo(x)<=minimum) minimum=foo(x);
        if (foo(x)>=maximum) maximum=foo(x);
    }
    return(maximum-minimum);
}

int main()
{
 int a,b;
cout<<"Введите границы отрезка [a ; b] (сначала a, затем через пробел b):";
cin>>a;
cin>>b;
cout<<"Разница между max и min:"<<diffrence(a,b,function);

}