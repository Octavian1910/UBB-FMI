#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("lab3ex1.txt");

int main()
{
    int n,a[20][20];
    vector<pair<int,int>> edges;
    fin >> n;
    for (int i = 1 ; i <= n ; ++i)
        for (int j = 1 ; j <= n ; ++j)
        {
            fin >> a[i][j];
            if (a[i][j] == 1 and i < j)
            {
                edges.push_back({i,j});
            }
        }

    for (auto edge:edges)
    {
        cout << edge.first << " " << edge.second << endl;
    }
    return 0;
}