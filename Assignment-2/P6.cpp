#include <bits/stdc++.h>
using namespace std;



#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);
#define N 20005

const int INF = 10000000;

vector< pair<int,int> > G[N];
bool visited[N];
vector<int> d(N, INF);


void dijkstra(int source)
{
    memset(visited, false, sizeof visited);

    for (int i = 0; i < N; ++i)
    {
        d[i] = INF;
    }

    d[source] = 0;
    multiset< pair<int,int> > q;
    q.insert({0, source});

    while (!q.empty())
    {
        pair<int,int> next = *q.begin();
        q.erase(q.begin());

        int v = next.second, weight = next.first;

        if (visited[v])
            continue;
        visited[v] = true;

        for (int i = 0; i < G[v].size(); ++i)
        {
            pair<int,int>  child = G[v][i];

            int to = child.first, w = child.second;

            if (d[v] + w < d[to])
            {
                d[to] = d[v] + w;
                q.insert({d[to], to});
            }
        }
    }
    for (int i = 0; i < N; ++i)
    {
        G[i].clear();
    }
}

int main()
{
    IOS

      

    int n, to, from, m, w, source, destintion, t;
    cin >> t;
    int c = 1;
    while (t--)
    {
        cin >> n >> m >> source >> destintion;
        for (int i = 0; i < m; ++i)
        {
            cin >> from >> to >> w;
            G[from].push_back({to, w});
            G[to].push_back({from, w});
        }
        dijkstra(source);

        cout << "Case #" << c++ << ": ";
        if (d[destintion] != INF)
        {
            cout << d[destintion] << "\n";
        }
        else
        {
            cout << "unreachable\n";
        }
    }

    return 0;
}
