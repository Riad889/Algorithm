#include<bits/stdc++.h>
using namespace std;
void merge(int a[],int l,int mid,int up)
{
    int b[up];
    int i=l;
    int j=mid+1;
    int k=l;
    while(i<=mid && j<=up)
    {
        if(a[i]<=a[j])
        {
            b[k++]=a[i++];
        }
        else
        {
            b[k++]=a[j++];
        }
    }
    if(i>mid)
    {
        while(j<=up)
        {
            b[k++]=a[j++];
        }
    }
    else
    {
        while(i<=mid)
        {
            b[k++]=a[i++];
        }
    }
    for(int p=l;p<=up;p++)
    {
        a[p]=b[p];
    }
}
void mergeSort(int a[],int l,int up)
{

    int mid;
    if(l<up)
    {
        mid=(l+up)/2;
        mergeSort(a,l,mid);
        mergeSort(a,mid+1,up);
        merge(a,l,mid,up);

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
    for(i=0;i<n;i++)
    {
        cin>>a[i];
    }
    mergeSort(a,0,n-1);
    cout<<"Sorted element : "<<endl;
    for(i=0;i<n;i++)
    {
        cout<<a[i]<<" ";
    }
    cout<<endl;

}
