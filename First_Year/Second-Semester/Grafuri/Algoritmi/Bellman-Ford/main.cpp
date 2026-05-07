#include <iostream>
#include <fstream>
#include <vector>
#define inf 10e7
using namespace std;

ifstream fin("bellmanford.in");
ofstream fout("bellmanford.out");

struct Muchie
{
    int u,v,w;
};

int main()
{
    int n,m;
    fin >> n >> m;
    vector<struct Muchie> edges;
    for (int i = 1 ; i <= m ; ++i)
    {
        int x,y,z;
        fin >> x >> y >> z;
        edges.push_back({x,y,z});
    }

    vector<int> d(n+1,inf);
    d[1] = 0;

    for (int i = 1 ; i <= n - 1 ; ++i)
    {
        for (auto m:edges)
        {

            if (d[m.u] != inf and d[m.v] > d[m.u] + m.w)
                d[m.v] = d[m.u] + m.w;
        }
    }

    for (int i = 1 ; i <= n - 1 ; ++i)
    {
        for (auto m:edges)
        {

            if (d[m.u] != inf and d[m.v] > d[m.u] + m.w)
            {
                fout << "Ciclu negativ!";
                return 0;
            }
        }
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        fout << d[i] << " ";
    }

    return 0;
}