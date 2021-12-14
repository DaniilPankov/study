/*Напишите функцию, которая получает в качестве аргумента указатель
на функцию double (*f)(double x) и возвращает минимальное значение
функции f на отрезке [a, b].*/
#include <iostream>
//f(x)=x^2
double f(double x)
{
    return (x - 4);
}
double mini(double a, double b, double (*foo)(double)) // Объявить указатель на функцию
{
    const double dx = 0.1;
    double x = a, min = foo(x);
    while (x <= b)
    {
        double y = foo(x);
        if (y < min)
            min = y;
        x += dx;
    }
    return min;
}
int main()
{
    double a, b;
    std::cout << "a = "; std::cin >> a;
    std::cout << "b = "; std::cin >> b;
    std::cout << "Min = " << mini(a, b, f); // Указать на функцию f
    return 0;
}