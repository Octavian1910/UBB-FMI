

#include <iostream>
#include <fstream>

using namespace std;

ifstream fin("input.txt");

bool visited[150];
int a[150][150];
int n,m;
void DFS(int x)
{
    visited[x] = 1;
    cout << x << " ";
    for (int i = 1 ; i <= n ; ++i)
    {
        if (a[x][i] == 1 and visited[i] == false)
        {
            DFS(i);
        }
    }
}


int main()
{
    int x,y;
    fin >> n  >> m;
    for (int i = 1 ; i <= m ; ++i)
    {
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    ///DFS
    for (int i = 1 ; i <= n ;++i)
    {
        if (!visited[i])
        {
            DFS(i);
            cout << endl;
        }
    }

    return 0;


}