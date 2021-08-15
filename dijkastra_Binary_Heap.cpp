#include<bits/stdc++.h>
using namespace std;
# define INF 0x3f3f3f3f
int p,q;



int H[50],H2[50];
int size = -1;
int getroot(int i)
{

    return (i - 1) / 2;
}

int getLeftNode(int i)
{

    return ((2 * i) + 1);
}

int getRightNode(int i)
{

    return ((2 * i) + 2);
}

void Up(int i)
{
    while (i > 0 && H2[getroot(i)] > H2[i])
    {
        swap(H[getroot(i)], H[i]);
        swap(H2[getroot(i)], H2[i]);
        i = getroot(i);
    }
}

void Down(int i)
{
    int maxIndex = i;


    int l = getLeftNode(i);

    if (l <= size && H2[l] < H2[maxIndex])
    {
        maxIndex = l;
    }


    int r = getRightNode(i);

    if (r <= size && H2[r] < H2[maxIndex])
    {
        maxIndex = r;
    }


    if (i != maxIndex)
    {
        swap(H[i], H[maxIndex]);
        swap(H2[i], H2[maxIndex]);

        Down(maxIndex);
    }
}

void push(int p,int q)
{
    size = size + 1;
    H[size] = p;
    H2[size] = q;

    Up(size);
}

pair<int,int> pop()
{
    int result1 = H[0];
    int result2 = H2[0];
    pair<int,int>chu=make_pair(result1,result2);

    H[0] = H[size];
    H2[0] = H2[size];

    size = size - 1;

    Down(0);
    return chu;

}





typedef pair<int, int> iPair;


class Node
{
    int V;
    list< pair<int, int> > *adj;

public:
    Node(int V);


    void addEdge(int u, int v, int w);


    void shortestPath(int s);
};


Node::Node(int V)
{
    this->V = V;
    adj = new list<iPair> [V];
}

void Node::addEdge(int u, int v, int w)
{
    adj[u].push_back(make_pair(v, w));
    adj[v].push_back(make_pair(u, w));
}
void Node::shortestPath(int src)
{

  size=-1;

    vector<int> dist(V, INF);


    push(0,src);
    dist[src] = 0;


    while (size>=0)
    {

        pair<int,int>p=pop();
        int u = p.first;
        list< pair<int, int> >::iterator i;
        for (i = adj[u].begin(); i != adj[u].end(); ++i)
        {

            int v = (*i).first;
            int weight = (*i).second;


            if (dist[v] > dist[u] + weight)
            {

                dist[v] = dist[u] + weight;
                push(v,dist[v]);
            }
        }
    }
}
int main()
{


    int n,m;
    cin >> n >> m;
     Node g(n);

    for(int i = 0; i<m; i++)
    {
        int u, v, wt;
        cin >> u >> v >> wt;
          g.addEdge(u-1, v-1, wt);

    }
    auto t1 = chrono::steady_clock::now();

    g.shortestPath(0);
    auto t2 = chrono::steady_clock::now();
     double diff1 = double(chrono::duration_cast <chrono::nanoseconds> (t2-t1).count());
    cout<<"Execution time  is: "<<diff1/1000000<<" milliseconds"<<endl;

    return 0;
}
