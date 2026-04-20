#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

ifstream fin("input.txt");

int n,m;
int a[100][100];
bool visited[100];
void DFS(int nod)
{
    visited[nod] = 1;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (visited[i] == 0 and a[i][nod] == 1)
            DFS(i);
    }


}


int main()
{
    int x,y,v1,v2;
     fin >> n >> m;
     for (int i = 1 ; i <= m ; ++i)
     {
         fin >> x >> y;
         a[x][y] = 1;
         a[y][x] = 1;
     }
     cout << "Oras 1 :"; cin >> v1;
     cout << "Oras 2 :"; cin >> v2;
    a[v1][v2] = 0;
    a[v2][v1] = 0;
    DFS(n);

    for (int i = 1; i <= n ; ++i)
    {
        if (visited[i] == false)
        {
            cout << "Nu";
            return 0;
        }
    }
    cout << "Da";
    return 0;

}