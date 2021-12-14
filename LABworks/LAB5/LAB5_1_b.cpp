#include <time.h>
#include <iostream>
using namespace std;
int main()
{	
    int rows, cols;
    cout<<"Введите параметр N"<<endl;
    cin>>rows;
    cout<<"Введите параметр M"<<endl;
    cin>>cols;
    cout<<"Матрица:"<<endl;
    srand(time(0));
    int **arr=new int* [rows];
    for(int i=0;i<rows;i++)
    {
        arr[i] = new int[cols];
    }
    ////////////////////////////
    for (int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
        {
            arr[i][j]=rand()%10;
            cout<<arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    int min=10;
    for(int i=0;i<rows/2;i++)
    {
        for(int j=cols/2;j<cols;j++)
        {
        if(arr[i][j]<min) min=arr[i][j];
        }
    }
     for(int i=rows/2;i<rows;i++)
    {
        for(int j=0;j<cols/2;j++)
        {
        if(arr[i][j]<min) min=arr[i][j];
        }
    }
    cout<<"Минимальное значение:"<<"\t"<<min;

    ///////////////////////////
    for(int i=0;i<rows;i++)
    {
        delete [] arr[i];
    }
    delete [] arr;


}
