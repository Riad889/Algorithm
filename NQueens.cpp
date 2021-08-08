#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool Safe(int** a,int x,int col,int n)
{
    for(int row=0; row<x; row++)
    {
        if(a[row][col]==1)
        {

            return false;
        }
    }
    int row=x;
    int column=col;
    while(row>=0 and column>=0)
    {
        if(a[row][column]==1)
        {
            return false;
        }
        row--;
        column--;
    }
    row=x;
    column=col;
    while(row>=0 and column<n)
    {
        if(a[row][column]==1)
        {

            return false;
        }
        row--;
        column++;
    }
    return true;
}
bool Queens(int** a,int x,int n)
{
    int i,j;
    if(x>=n)
    {
        for(i=0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                cout<<a[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n\n";
    }
    //return true;
    for(int col=0; col<n; col++)
    {
        if(Safe(a,x,col,n))
        {
            a[x][col]=1;
            if(Queens(a,x+1,n))
            {
                for(i=0; i<n; i++)
                {
                    for(int j=0; j<n; j++)
                    {
                        cout<<a[i][j]<<" ";
                    }
                    cout<<"\n";
                }
                //return true;
            }
            a[x][col]=0;
        }
    }
    return false;
}
int main()
{
    cout<<"Enter the number of Queens : \n";
    int n;
    cin>>n;
    int** a=new int*[n];
    int i;
    for(i=0; i<n; i++)
    {
        a[i]=new int[n];
        for(int j=0; j<n; j++)
        {
            a[i][j]=0;
        }
    }

    if(Queens(a,0,n))
    {

    }
}
