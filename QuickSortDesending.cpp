
#include<bits/stdc++.h>
using namespace std;
int Partition(int a[],int l,int up)
{
    int pvt=a[l];
    int start=l;
    int end=up;
    while(start<end)
    {
        while(a[start]>=pvt)
        {
            start++;
        }
        while(a[end]<pvt)
        {
            end--;
        }
        if(start<=end)
        {
            swap(a[start],a[end]);
        }
    }
    swap(a[l],a[end]);
    return end ;
}
void QuickSort(int a[],int l,int up)
{
    if(l<up)
    {
        int loc=Partition(a,l,up);
        QuickSort(a,l,loc-1);
        QuickSort(a,loc+1,up);
    }
}
int main()
{
    cout<<"Enter the amount of number : "<<endl;
    int n;
    cin>>n;
    int a[n];
    int i;
    cout<<"Enter the element : "<<endl;
    for(i=0; i<n; i++)
    {
        cin>>a[i];
    }
    QuickSort(a,0,n-1);
    cout<<"Sorted element : "<<endl;
    for(i=0; i<n; i++)
    {
        cout<<a[i]<<" ";
    }
}
