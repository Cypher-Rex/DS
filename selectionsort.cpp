#include<stdio.h>
#include<iostream>
#define max 100
using namespace std;
int n, arr[max];
class selectionsort{
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
        cout<<"The Given Array is :"<<endl;
        output();
    }

    void insert()
    {
        for(int i=n-1;i>0;i--){
            int maxind=0;
            for(int j=1;j<=i;j++)
            {
                if(arr[j]>arr[maxind]){
                    maxind=j;
                }
            }
            if(maxind != i)
            {
                int temp=arr[i];
                arr[i]=arr[maxind];
                arr[maxind]=temp;
            }
            cout<<"The Array after pass no "<<n-i<<" is:"<<endl;
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
    selectionsort sort;
    sort.input();
    sort.insert();
    sort.output();
    return 0;
}
