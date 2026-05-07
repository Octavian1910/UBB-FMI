#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int inf = 1e9;

struct Muchie
{
    int u,v,w;
};

int main(int argc, char * argv[])
{
    if (argc < 3)
    {
        cout << "Nr insfucient de argumente!";
        return 0;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    //varianta 1 dijkstra

    int V, E, S;
    int x, y, z;
    fin >> V >> E >> S;
    vector<Muchie> edges;
    vector<int> d(V+1,inf);
    for (int i = 0 ; i < E ; ++i)
    {
        fin >> x >> y >> z;
        edges.push_back({x,y,z});
    }

    d[S] = 0;
    for (int i = 1 ; i <= V - 1 ; ++i)
    {
        for (auto m:edges)
        {
            if (d[m.u] != inf && d[m.v] > d[m.u] + m.w)
                d[m.v] = d[m.u] + m.w;
        }
    }

    for (int i = 0 ; i < V ; ++i)
    {
        if (d[i] == inf)
        {
            cout << "inf ";
        }
        else
        {
            cout << d[i] << " ";
        }
    }


    return 0;
}