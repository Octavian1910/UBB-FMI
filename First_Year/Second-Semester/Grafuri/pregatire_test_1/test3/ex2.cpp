#include <complex>
#include <iostream>
#include <vector>
#include <fstream>
#define inf 10e9
using namespace std;

ifstream fin("test3ex2.txt");


void afisare_drum(int nod,vector<int> p)
{
    if (p[nod] == 0)
    {
        cout << nod << " ";
        return;
    }
    afisare_drum(p[nod],p);
    cout << nod << " ";

}

int main()
{
    int n,m,start,end;
    fin >> n >> m;
    int a[100][100];
    vector<pair<int,int>> orase(n+1);
    vector<bool> visited(n+1,false);
    vector<int> d(n+1,inf);
    vector<int> p(n+1,-1);
    vector<vector<pair<int,int>>> adj(n+1);
    for (int i = 1 ; i <= n ; ++i)
    {
        int x,y;
        fin >> x >> y;
        orase[i] = {x,y};
    }

    for (int i = 1 ; i <= m ; ++i)
    {
        int x,y;
        fin >> x >> y;
        auto ors1 = orase[x];
        auto ors2 = orase[y];
        int dist = sqrt(pow(ors1.first - ors2.first,2) + pow(ors1.second - ors2.second,2));
        a[x][y]=dist;
        adj[x].push_back({y,dist});
    }

    cout << "Start :" ; cin >> start;
    cout << "End :" ; cin >> end;

    d[start] = 0;
    p[start] = 0;

    for (int i = 1 ; i <= n ; ++i)
    {
        int x = -1;
        for (int j = 1 ; j <= n ; ++j)
        {
            if (!visited[j] && ( x == -1 || d[j] < d[x] ))
            {
                x = j;
            }
        }

        if (x == -1 || d[x] == inf)
            break;

        visited[x] = true;

        for (auto vecin:adj[x])
        {
            int nod = vecin.first;
            int cost = vecin.second;
            if (d[nod] > d[x] + cost)
            {
                d[nod] = d[x] + cost;
                p[nod] = x;
            }
        }
    }

    cout << d[end] << endl;

    afisare_drum(end,p);
    return 0;
}
