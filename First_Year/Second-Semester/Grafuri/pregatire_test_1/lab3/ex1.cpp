#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

const int inf = 1e9;

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
    vector<vector<pair<int,int>>> v(V+1);
    vector<int> d(V+1,inf);
    d[S] = 0;
    vector<bool> visited(V+1,false);
    for (int i = 0 ; i < E ; ++i)
    {
        fin >> x >> y >> z;
        v[x].push_back({y,z});
    }

    for (int i = 1 ; i <= V ; ++i)
    {
        int x = -1;
        for (int j = 0 ; j < V ; ++j)
        {
            if (!visited[j] && (x == -1 || d[x] > d[j]))
            {
                x = j;
            }
        }

        if (x == -1 || d[x] == inf)
        {
            break;
        }
        visited[x] = true;
        for (auto m:v[x])
        {
            int vecin = m.first;
            int cost = m.second;
            if (d[vecin] > d[x] + cost)
                d[vecin] = d[x] + cost;
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