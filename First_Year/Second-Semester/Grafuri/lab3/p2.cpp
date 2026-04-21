#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#define INF 10e7
using namespace std;

struct Muchie
{
    int u,v,w;
};

//rulare :
//    gcc -Wall -Werror p1.cpp -o p2
//   /p2 date2.in date2.out

int main(int argc, char** argv)
{
    if (argc < 3)
    {
        cout << "Nr insuficient de argumente";
        return 0;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int V,E,x,y,z;
    fin >> V >> E;

    vector<Muchie> edges;

    for (int i = 0 ; i < E ; ++i)
    {
        fin >> x >> y >> z;
        edges.push_back({x,y,z});
    }

    int s = V;

    for (int i = 0 ; i < V ; ++i)
        edges.push_back({s,i,0});

    vector<int> d(V+1,INF);
    d[s] = 0;

    // Bellman-Ford
    for (int i = 0 ; i < V -1 + 1 ; ++i)
    {
        for (auto m : edges)
        {
            if (d[m.u] != INF && d[m.v] > d[m.u] + m.w)
                d[m.v] = d[m.u] + m.w;
        }
    }

    // ciclu negativ
    for (auto m : edges)
    {
        if (d[m.u] != INF && d[m.v] > d[m.u] + m.w)
        {
            fout << -1;
            return 0;
        }
    }

    // reponderare
    vector<Muchie> newEdges;
    for (auto m : edges)
    {
        if (m.u == s) continue;

        int new_w = m.w + d[m.u] - d[m.v];
        newEdges.push_back({m.u,m.v,new_w});
    }

    sort(newEdges.begin(), newEdges.end(), [](Muchie a, Muchie b){
        if (a.u != b.u) return a.u < b.u;
        return a.v < b.v;
    });

    // afisare muchii
    for (auto m : newEdges)
        fout << m.u << " " << m.v << " " << m.w << "\n";

    // lista adiacenta
    vector<vector<pair<int,int>>> adj(V);
    for (auto m : newEdges)
        adj[m.u].push_back({m.v, m.w});

    // Dijkstra simplu pentru fiecare nod
    for (int src = 0; src < V; src++)
    {
        vector<int> dist(V, INF);
        vector<bool> used(V,false);

        dist[src] = 0;

        for (int i = 0; i < V; i++)
        {
            int x = -1;

            for (int j = 0; j < V; j++)
            {
                if (!used[j] && (x == -1 || dist[j] < dist[x]))
                    x = j;
            }

            if (x == -1 || dist[x] == INF) break;

            used[x] = true;

            for (auto it : adj[x])
            {
                int v = it.first;
                int w = it.second;

                if (dist[v] > dist[x] + w)
                    dist[v] = dist[x] + w;
            }
        }

        // corectie + afisare
        for (int j = 0; j < V; j++)
        {
            if (dist[j] == INF)
                fout << "INF ";
            else
                fout << dist[j] + d[j] - d[src] << " ";
        }

        fout << "\n";
    }

    return 0;
}