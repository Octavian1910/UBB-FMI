#include <iostream>
#include <vector>
#define inf 1e9
using namespace std;

void dijkstra(int n,int start,vector<vector<pair<int,int>>> &adj,vector<int> &dist,vector<int> &parent)
{
    vector<bool> used(n+1,false);

    //initializare
    for (int i = 1;i <= n;++i)
    {
        dist[i]=inf;
        parent[i]=0;
    }

    dist[start] = 0;

    for (int i = 1 ; i < n ; ++i)
    {
        int x = -1;

        //alegem nodul unde distanta este minima
        for (int j = 1; j <= n ; ++j)
            if (!used[j] && (x == -1 || dist[j] < dist[x]))
                x = j;

        used[x] = true;

        for (auto edge : adj[x])
        {
            int v=edge.first;
            int cost=edge.second;

            if (dist[v] > dist[x] + cost)
            {
                dist[v] = dist[x] + cost;
                parent[v] = x;
            }
        }
    }
}

int main()
{
    int n = 5 , m = 6, start = 1;

    vector<vector<pair<int,int>>> adj(n+1);

    //muchii
    adj[1].push_back({2,2});
    adj[1].push_back({3,4});
    adj[2].push_back({3,1});
    adj[2].push_back({4,7});
    adj[3].push_back({5,3});
    adj[4].push_back({5,1});

    vector<int> dist(n+1),parent(n+1);

    dijkstra(n,start,adj,dist,parent);

    //afisam
    for (int i = 1; i <= n ; ++i)
    {
        cout << "dist[" << i << "]= " << dist[i] << endl;
    }
    return 0;
}