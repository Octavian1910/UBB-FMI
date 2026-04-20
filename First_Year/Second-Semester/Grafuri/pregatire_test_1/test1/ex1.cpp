#include <iostream>
#include <fstream>
#include <vector>
#define len 150

using namespace std;

ifstream fin("date.in");

int v[len][len];
int rez[len][len];

int main()
{
    int x,y,nr_vf;
    fin >> nr_vf;
    int edge_number = 0;
    vector<pair<int,int>> edges;
    while (fin >> x >> y) //lista muchiilor
    {
        ++edge_number;
        rez[x][edge_number] = 1;
        rez[y][edge_number] = 1;
    }

    for (int i = 1 ; i <= nr_vf ; ++i , cout << endl)
        for (int j = 1 ; j <= edge_number ; ++j)
        {
            cout << rez[i][j] << " " ;
        }



    return 0;
}
