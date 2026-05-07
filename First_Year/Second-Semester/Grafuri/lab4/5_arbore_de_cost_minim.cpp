
#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
using namespace std;

struct Muchie
{
    int x,y,cost;
};

bool cmp(Muchie a, Muchie b)
{
    return a.cost < b.cost;
}

vector<Muchie> v;
int parent[5005];

int find_set(int x)
{
    if (parent[x] == x)
        return x;

    else
    {
        int radacina = find_set(parent[x]);
        parent[x] = radacina;
        return radacina;
    }
}

void union_set(int a,int b)
{
    a = find_set(a);
    b = find_set(b);
    if (a != b)
    {
        parent[b] = a;
    }
}

int main(int argc,char* argv[])
{
    if (argc != 3)
    {
        cout << "Nr insuficient de argumente!";
        return 1;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int V,E;
    fin >> V >> E;

    for (int i = 0 ; i < V; ++i)
        parent[i] = i;

    for (int i = 0; i < E ; ++i)
    {
        Muchie m;
        fin >> m.x >> m.y >> m.cost;
        v.push_back(m);
    }

    sort(v.begin(),v.end(),cmp);
    int cost_total = 0;

    vector<Muchie> sol;
    for (auto m : v)
    {
        if (find_set(m.x) != find_set(m.y))
        {
            union_set(m.x,m.y);
            cost_total += m.cost;
            sol.push_back(m);
        }
    }

    fout << cost_total << "\n";
    fout << sol.size() << "\n";

    for (auto m:sol)
        fout << m.x << " " << m.y << "\n";

    return 0;
}
