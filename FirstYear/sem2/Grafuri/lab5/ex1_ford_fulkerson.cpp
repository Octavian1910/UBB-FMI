#include <iostream>
#include <fstream>
#include <queue>
#include <limits.h>

using namespace std;

bool BFS(int G[100][100], int nr_V, int s, int d, int parinte[])
{
    bool viz[100] = {false};

    queue<int> Q;

    Q.push(s);
    viz[s] = true;
    parinte[s] = -1;

    while(!Q.empty())
    {
        int u = Q.front();
        Q.pop();

        for(int v = 0; v < nr_V; v++)
        {
            if(viz[v] == false && G[u][v] > 0)
            {
                Q.push(v);
                viz[v] = true;
                parinte[v] = u;
            }
        }
    }

    return viz[d];
}

int Ford_Fulkerson(int G[100][100], int nr_V, int s, int d)
{
    int u,v;

    int rG[100][100]; //graf rezidual

    for(u = 0; u < nr_V; u++)
        for(v = 0; v < nr_V; v++)
            rG[u][v] = G[u][v];

    int parinte[100];

    int flux_maxim = 0;

    while(BFS(rG, nr_V, s, d, parinte))
    {
        int flux_cale = INT_MAX;

        for(v = d; v != s; v = parinte[v])
        {
            u = parinte[v];

            flux_cale = min(flux_cale, rG[u][v]);
        }

        for(v = d; v != s; v = parinte[v])
        {
            u = parinte[v];

            rG[u][v] -= flux_cale;
            rG[v][u] += flux_cale;
        }

        flux_maxim += flux_cale;
    }

    return flux_maxim;
}

int main(int argc, char* argv[])
{
    ifstream fin;
    ofstream fout;

    if(argc == 3)
    {
        fin.open(argv[1]);
        fout.open(argv[2]);
    }
    else
    {
        fin.open("in.txt");
        fout.open("out.txt");
    }

    int V,E;
    int x,y,c;

    int G[100][100] = {0};

    fin >> V >> E;

    for(int i = 0; i < E; i++)
    {
        fin >> x >> y >> c;
        G[x][y] = c;
    }

    int flux_maxim = Ford_Fulkerson(G, V, 0, V - 1);

    fout << flux_maxim;

    fin.close();
    fout.close();

    return 0;
}