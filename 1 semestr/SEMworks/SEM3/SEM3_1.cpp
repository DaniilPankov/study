#include <iostream>
using namespace std;
void copy(char *a, char *b)
{
    int i;
    while(a[i]!='\0')
    {
        b[i]=a[i];
        i++;
    }
}
int main()
{
    cout<<"Введите строчку t(на латинице): ";
    char s[100],t[100];
    cin>>t;
    copy(t, s);
    cout<<"Строчка s: "<<s;
}