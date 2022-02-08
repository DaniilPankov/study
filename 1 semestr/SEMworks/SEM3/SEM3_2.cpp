#include <iostream>
using namespace std;
void strcat(char *a,char *b)
{
    int i, j;
    i = j = 0;
    while (a[i] != '\0') /* находим конец s */
        i++;
    while ((a[i++] = b[j++]) != '\0'); /* копируем t */
}
int main()
{
    char s[100],t[100];
    cout<<"Введите строку s(на английском):";
    cin>>s;
    cout<<"Введите строку t(на английском):";
    cin>>t;
    strcat(s,t);
    cout<<"Строка s: "<<s;
}