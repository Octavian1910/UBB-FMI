#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

ifstream fin("date.in");
int a[150][150];
int rez[150][150];

int main()
{
    int n,nr_muchii=0;
    fin >> n;
    vector<pair<int,int>> edges;
     for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
        {
            fin >> a[i][j];
            if (i < j and a[i][j] == 1)
            {
                edges.push_back({i,j});
                nr_muchii++;
            }
        }

    for (int i = 0 ; i < nr_muchii ; ++i)
    {
        int v1 = edges[i].first;
        int v2 = edges[i].second;
        rez[v1][i+1] = 1;
        rez[v2][i+1] = 1;
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        for (int j = 1 ; j <= nr_muchii ; ++j)
        {
            cout << rez[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}