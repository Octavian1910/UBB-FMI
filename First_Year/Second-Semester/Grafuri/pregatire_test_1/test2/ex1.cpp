#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("date2.in");

int n,m,x,y;
int a[150][150];

int main()
{
    fin >> n >> m;
    for (int i =1 ; i  <= m ; ++i)
    {
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int i = 1 ; i <= n ; ++i,cout << endl)
        for (int j = 1 ; j <= n ; ++j)
    {
        cout << a[i][j] << " ";
    }

}