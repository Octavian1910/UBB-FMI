#include <iostream>
#include <vector>
#include <fstream>
#define inf 10e9

using namespace std;

ifstream fin("test1ex2.txt");

int main()
{
    int x,y,l,n,start,end;
    fin >> n; //nr_noduri;
    fin >> start >> end;
    vector<vector<std::pair<int,int>>> edges(n+1);
    vector<bool> used(n+1,false);
    vector<int> d(n+1,inf);
    while (fin >> x >> y >> l)
    {
        edges[x].push_back({y,l});
    }

    d[start] = 0;

    for (int i = 1 ; i <= n ; ++i)
    {
        int x = -1;
        for (int j = 1 ; j <= n ; ++j)
        {
            if (!used[j] && (x == -1 || d[j] < d[x]))
            {
                x = j;
            }
        }

            if (x == -1 || d[x] == inf)
            {
                break;
            }

            used[x] = true;
            for ( auto const &edge:edges[x])
            {
                int v = edge.first;
                int cost = edge.second;
                if (d[v] > d[x] + cost)
                    d[v] = d[x] + cost;
            }
    }

    cout << d[end];

    return 0;
}
