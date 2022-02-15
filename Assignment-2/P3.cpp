#include <bits/stdc++.h>
using namespace std;



#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);

#define N 10005
const int INF = 10000000;


struct Edge
{
    int from, to, weight;
    bool operator<(Edge const &obj)
    {
       
        return weight < obj.weight;
    }
};

int n, to, from, m, w, source, destintion, t;

vector<Edge> G;
bool selected[N];
vector<int> d(N, INF);
vector<int> parent(N);







// to detecte cycle
int root(int node)
{
    while(parent[node] != node)
    {
        parent[node] = parent[parent[node]];
        node = parent[node];
    }
    return node;

}

void UNION(int a, int b)
{
    int x = root(a);
    int y = root(b);
    parent[x] = parent[y];
}
long long Kruskal()
{
    long long Min_cost = 0, weight;

    for (int i = 0; i <= n; ++i)
    {
        parent[i] = i;
    }
    sort(G.begin(), G.end());
    int v,u;
    for (Edge edge: G)
    {
        v = edge.from;
        u = edge.to;
        weight = edge.weight;
        
        // check if taken edge will make cycle
        if(root(v) != root(u))
        {
            Min_cost += weight;
            UNION(v,u);
        }
    }

        return Min_cost;
}
int main()
{
    IOS
     

    cin >> n >> m;
    for (int i = 0; i < m; ++i)
    {
        cin >> from >> to >> w;
        Edge e;
        e.from = from;
        e.to = to;
        e.weight = w;
        G.push_back(e);
    }

    long long cost = Kruskal();

    cout << cost << "\n";

    return 0;
}
