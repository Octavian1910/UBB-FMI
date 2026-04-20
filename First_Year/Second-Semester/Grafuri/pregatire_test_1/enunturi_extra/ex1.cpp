#include <iostream>
#include <fstream>
using namespace std;

const int INF = 1e9;

ifstream fin("extra.in");

int main()
{
    int n, m;
    fin >> n >> m;

    int a[101][101];

    // inițializare matrice
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = INF;

    int u, v, w;

    // citire muchii
    for (int i = 0; i < m; i++)
    {
        fin >> u >> v >> w;
        a[u][v] = w;
        a[v][u] = w;
    }

    int d[101], p[101];
    bool selected[101];

    for (int i = 1; i <= n; i++)
    {
        d[i] = INF;
        p[i] = -1;
        selected[i] = false;
    }

    int start = 1;
    d[start] = 0;

    for (int i = 1; i <= n; i++)
    {
        int min_u = -1;

        // aleg nodul cu cost minim
        for (int j = 1; j <= n; j++)
        {
            if (!selected[j] && (min_u == -1 || d[j] < d[min_u]))
                min_u = j;
        }

        selected[min_u] = true;

        // actualizare vecini
        for (int v = 1; v <= n; v++)
        {
            if (a[min_u][v] != INF && !selected[v] && a[min_u][v] < d[v])
            {
                d[v] = a[min_u][v];
                p[v] = min_u;
            }
        }
    }

    // afișare
    int cost = 0;
    for (int i = 1; i <= n; i++)
    {
        if (p[i] != -1)
        {
            cout << p[i] << " - " << i << " (cost " << d[i] << ")\n";
            cost += d[i];
        }
    }

    cout << "Cost total: " << cost;

    return 0;
}