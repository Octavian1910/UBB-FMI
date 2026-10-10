#include <iostream>
#include <fstream>
#include <vector>
#define inf 10e8
using namespace std;

ifstream fin("ex2.in");

struct Muchie
{
    int u,v,w;
};

void drum(int n,vector<int> p)
{
    if (p[n] == -1)
    {
        cout << n << " ";
    }
    else
    {
        drum(p[n],p);
        cout << n << " ";
    }
}

int main()
{
    int n,m,start,end;
    fin >> n >> m;
    fin >> start >> end;
    vector<Muchie> edges;
    vector<int> p(n+1,-1);
    vector<int> d(n+1,inf);
    for (int i = 1 ; i <= m ; ++i)
    {
        int x,y,z;
        fin >> x >> y >> z;
        edges.push_back({x,y,z});
    }

    d[start] = 0;
    for (int i = 1; i <= n-1 ; ++i)
    {
        for (auto m:edges)
        {
            if (d[m.u] != inf && d[m.v] > d[m.u] + m.w)
            {
                d[m.v] = d[m.u] + m.w;
                p[m.v] = m.u;
            }
        }
    }

    for (int i = 1; i <= n-1 ; ++i)
    {
        for (auto m:edges)
        {
            if (d[m.u] != inf && d[m.v] > d[m.u] + m.w)
            {
                cout << "Are cicluri negative";
                return 0;
            }
        }
    }

    cout << "Cost " << d[end] << endl;
    drum(end,p);

    return 0;
}