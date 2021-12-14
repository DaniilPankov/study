#include <iostream>
using namespace std;
void max(double &a, double &b,double &c)
{
    double max1=0;
    if(a>b) max1=a;else max1=b;
    if (c>max1) max1=c;
    if (max1==a) a=(double)(a+b+c)/3;
    if (max1==b) b=(double)(a+b+c)/3;
    if (max1==c) c=(double)(a+b+c)/3;
}
int main()
{
    double a,b,c;
    cout<<"Введите строчку из трех чисел черз пробел:a b c: ";
    cin>>a>>b>>c;
    max(a,b,c);
    cout<<"Ответ:"<<a<<" "<<b<<" "<<c;
}