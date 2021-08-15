#include<bits/stdc++.h>
using namespace std;
struct node
{
    int u;
    int ver;
    int wt;
    node(int first, int second, int weight)
    {
        u = first;
        ver = second;
        wt = weight;
    }
};

bool compare(node a, node b)
{
    return a.wt < b.wt;
}

int findParent(int u, vector<int> parent)
{
    if(u == parent[u]) return u;
    return parent[u] = findParent(parent[u], parent);
}

void unionno(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(u, parent);
    v = findParent(v, parent);
    if(rank[u] < rank[v])
    {
        parent[u] = v;
    }
    else if(rank[v] < rank[u])
    {
        parent[v] = u;
    }
    else
    {
        parent[v] = u;
        rank[u]++;
    }
}
int main()
{
    int n,m;
    cin >> n >> m;
    vector<node> edges;
    for(int i = 0; i<m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
        edges.push_back(node(u, v, wt));
    }
     auto t1 = chrono::steady_clock::now();
    sort(edges.begin(), edges.end(), compare);

    vector<int> parent(n);
    for(int i = 0; i<n; i++)
        parent[i] = i;
    vector<int> rank(n, 0);

    int cost = 0;
    vector<pair<int,int>> mst;
    for(auto it : edges)
    {
        if(findParent(it.ver, parent) != findParent(it.u, parent))
        {
            cost += it.wt;
            mst.push_back({it.u, it.ver});
            unionno(it.u, it.ver, parent, rank);
        }
    }
    auto t2 = chrono::steady_clock::now();
    double diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t2-t1).count());
    cout<<"Execution time is: "<<diff1/1000000<<" milliseconds"<<endl;
    cout <<"Minimum = "<< cost << endl;

    return 0;
}
