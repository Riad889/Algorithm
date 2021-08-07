#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define White 1
#define Gray 2
#define Black 3
int main()
{
    cout<<"Enter the number of vertices: "<<endl;
    int n,e,n1,n2;
    cin>>n;
    int adj[n+1][n+1];
    int i,j;
    for(i=1;i<=n;i++)
    {
       for(j=1;j<=n;j++)
       {
           cin>>adj[i][j];
       }
    }
    int color[n+5];
    for(i=1;i<=n+5;i++)
    {
        color[i]=White;
    }
    queue<int>q;
    cout<<"Enter the starting node : " <<endl;
    int startNode;
    cin>>startNode;
    q.push(startNode);
    cout<<"The Node which are reachable: "<<endl;
    set<int>s;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        if(x!=startNode)
            cout<<x<<" ";
        //s.insert(x);
        color[x]=Gray;
        for(i=1;i<=n;i++)
        {
            if(adj[x][i]==1)
            {

                if(color[i]==White)
                {
                    color[i]=Gray;
                    q.push(i);
                }
            }
        }
        color[x]=Black;

    }
    /*for(auto t:s)
    {
        cout<<t<<" ";
    }
    cout<<endl;*/

}

/*


0   1   1   1
0   0   0   1
0   0   0   0
0   0   1   0


*/
