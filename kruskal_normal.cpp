#include <bits/stdc++.h>
using namespace std;
#define  Hello cout<<"Hello\n";
int find(int i,vector<int>&parent)
{
    while (parent[i] != i)
        i = parent[i];
    return i;
}

int main()
{
    int n,m;
    cin>>n>>m;
    int i,j;
    long long c[10000][10000]={INT_MAX};
    for(i=0;i<=n+1;i++)
    {
        for(j=0;j<=n+1;j++)
        {
            c[i][j]=INT_MAX;
        }
        //cout<<endl;
    }

    for(int i = 0; i<m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        c[u][v]=wt;
        c[v][u]=wt;

    }

    /*for(i=0;i<=n;i++)
    {
        for(j=0;j<=n;j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<endl;
    }*/
    auto t1 = chrono::steady_clock::now();
    vector<int> parent(n+1000);
    for(int i = 0; i<n+1000; i++)
        parent[i] = i;
    int minicost = 0;


    int edge_count = 0;
    while (edge_count < m)
    {
        int min = INT_MAX, a = -1, b = -1;
        for (int i = 0; i <=n; i++)
        {
            for (int j = 0; j <=n; j++)
            {
                if (find(i,parent) != find(j,parent) && c[i][j] < min)
                {
                    min = c[i][j];
                    a = i;
                    b = j;
                }
            }
        }
        int aa = find(a,parent);
        int bb = find(b,parent);
        parent[a] = b;
        edge_count++;
        minicost += min;
        //

    }
     auto t2 = chrono::steady_clock::now();
      double diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t2-t1).count());
    cout<<"Execution time  is: "<<diff1/1000000<<" milliseconds"<<endl;


    printf("Minimum cost= %d \n", minicost);


    return 0;
}

