#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,e;
    cout<<"Enter the number of nodes and edges : "<<endl;
    cin>>n>>e;
    int i,n1,n2,j;
    int a[n][n];
    memset(a,0,sizeof(a));
    for(i=0;i<e;i++)
    {
        cin>>n1>>n2;
        a[n1][n2]=1;
        a[n2][n1]=1;
    }
    vector<pair<int,int> >v;
    for(i=0;i<n;i++)
    {
        int cnt=0;
        for(j=0;j<n;j++)
        {
            if(a[i][j]==1)
           cnt++;
        }
        v.push_back(make_pair(i,cnt));
    }
    cout<<"The neighbor\n";
    for(auto t:v)
    {
        cout<<t.first<<" "<<t.second<<endl;
    }
}

