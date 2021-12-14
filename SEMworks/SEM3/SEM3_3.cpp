#include <iostream>
#include <stdio.h>
#include <string.h>
using namespace std;

int strend(char *str1,char *str2)
{
    int b = 0;
    int i, j;
    i = strlen(str1) - 1;
    j = strlen(str2) - 1;
    while (j >= 0) 
    {
        if (*(str1 + i) == *(str2 + j)) {
            b = 1;
        } else {
            b = 0;
            break;
        }
        i--;
        j--;
    }
    return b;

}

int main()
{
     char s[100],t[100];
    cout<<"Введите строку s(на английском):";
    cin>>s;
    cout<<"Введите строку t(на английском):";
    cin>>t;
    cout<<strend(s,t);
}