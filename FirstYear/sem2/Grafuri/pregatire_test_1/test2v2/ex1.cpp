#include <cstring>
#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

ifstream fin("test2v2.txt");
int rez[101][101];

int main()
{
    int n;
    fin >> n;
    int a[101][101];

    int nr_muchii = 0;
    vector<pair<int,int>> edges((n*(n-1)/2) + 2);
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
        {
            fin >> a[i][j];
            if (a[i][j] == 1 and i < j)
            {
                edges[++nr_muchii]={i,j};
            }
        }

    for (int i = 1 ; i <= nr_muchii ; ++i)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        rez[u][i] = 1;
        rez[v][i] = 1;
    }


    for (int i = 1 ; i <= n ; ++i,cout << endl)
        for (int j = 1 ; j <= nr_muchii ; ++j)
            cout<<rez[i][j] << " ";


    return 0;
}