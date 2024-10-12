#include<stdio.h>
#include<iostream>
#define max 100
using namespace std;
int n, arr[max];
class bubblesort{
   public:
    void input()
    {
        cout<<"Enter how many elements you want to enter :"<<endl;
        cin>>n;
        for(int i=0;i<n;i++)
        {
            cout<<"Enter element for "<<i+1<<" position :"<<endl;
            cin>>arr[i];
        }
        cout<<"The Insered Array is :"<<endl;
        output();
    }

    void bubblesor()
    {
        for(int i=0;i<n;i++)
        {
            
            for(int j=0;j<n-i-1;j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp =arr[j];
                    arr[j]=arr[j+1];
                    arr[j+1]=temp;
                }
                
            }
            cout<<"The Array after pass no "<<i+1<<" is:"<<endl;
            output();
        }
        cout<<"The Final sorted Array is:"<<endl;
        

    }
    void output()
    {
        for (int i = 0; i < n; i++) { 
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
int main()
{
    bubblesort sort;
    sort.input();
    sort.bubblesor();
    sort.output();
    return 0;
}
