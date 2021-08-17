#include<bits/stdc++.h>
using namespace std;
int color[100];
#define White 1
#define Grey 2
#define Black 3
int n,e;
int a[100][100];
void dfs_visit(int x)
{
    color[x]=Grey;
    int i;
    for(i=0;i<n;i++)
    {
        if(a[x][i]==1)
        {
            if(color[i]==White)
            {
                dfs_visit(i);
            }
        }
    }
    color[x]=Black;
}

void dfs()
{
    int i;
    for(i=0;i<n;i++)
    {
        color[i]=White;
    }
    for(i=0;i<n;i++)
    {
        if(color[i]==White)
        {
            dfs_visit(i);
        }
    }
}
int main()
{

    cout<<"Enter the number of nodes and edges : "<<endl;
    cin>>n>>e;
    int i,n1,n2,j;

    memset(a,0,sizeof(a));
    for(i=0;i<e;i++)
    {
        cin>>n1>>n2;
        a[n1][n2]=1;
        a[n2][n1]=1;
    }
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
}


