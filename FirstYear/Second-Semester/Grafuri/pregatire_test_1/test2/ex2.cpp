
#include <complex>
#include <iostream>
#include <vector>
#include <fstream>
#define inf 10e9
using namespace std;

ifstream fin("test2ex2.txt");



int main()
{
    int n,m,x,y,start,end;
    fin >> n >> m;
    fin >> start >> end;
    vector<std::pair<int,int>> nod(n+1);
    vector<bool> visited(n+1,false);
    vector<int> d(n+1,inf);
    vector<vector<pair<int,int>>> vecini(n+1);
    for (int i = 1 ; i <= n ; ++i)
    {
        fin >> x >> y;
        nod[i] = {x,y};
    }

    for (int i = 1 ; i <= m ; ++i)
    {
        fin >> x >> y;
        int dist = sqrt(pow(nod[x].first+nod[y].first,2) + pow(nod[x].second+nod[y].second,2));

        vecini[x].push_back({y,dist});
        vecini[y].push_back({x,dist});

    }

    d[start] = 0;

    for (int i = 1 ; i <= n ;++i)
    {
        int x = -1;
        for (int j = 1 ; j <= n ;++j)
        {
            if (!visited[j] && (x==-1 || d[j] < d[x]))
                x = j;
        }

        visited[x] = true;

        for (auto vecin:vecini[x])
        {
            int v = vecin.first;
            int cost = vecin.second;
            if (d[v] > d[x] + cost )
                d[v] = d[x] + cost;
        }

    }

    cout << d[end];

    return 0;
}
