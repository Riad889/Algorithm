#include<bits/stdc++.h>
using namespace std;
void insertion_sort(int a[],int n)
{
    int i;
    for(i=1;i<n;i++)
    {
        int temp=a[i];
        int j=i-1;
        while(j>=0 and a[j]>temp)
        {
            a[j+1]=a[j];
            j--;
        }
        a[j+1]=temp;
    }
}
int main()
{
    cout<<"Enter the amount of number : \n";
    int n;
    cin>>n;
    int a[n+1];
    cout<<"Enter the unsorted array element : "<<endl;
    int i;
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    insertion_sort(a,n);
    cout<<"Sorted array is : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
