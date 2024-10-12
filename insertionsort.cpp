#include<stdio.h>
#include<iostream>
#define max 100
using namespace std;
int n, arr[max];
class insertionsort{
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

    void insert()
    {
        int i,j,key;
        for(i=1;i<n;i++){
            key=arr[i];
            j=i-1;
            while (j>=0 && arr[j]>key)
            {
                arr[j+1]=arr[j];
                arr[j]=key;
                j--;
            }
            cout<<"The Array after pass no "<<i<<" is:"<<endl;
            output();
        }
        cout<<"The Final Sorted Array is:"<<endl;
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
    insertionsort sort;
    sort.input();
    sort.insert();
    sort.output();
    return 0;
}
