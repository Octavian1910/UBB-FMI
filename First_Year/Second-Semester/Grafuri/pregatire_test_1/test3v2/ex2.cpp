#include <iostream>
#include <fstream>

using namespace std;

ifstream fin ("ciclic.txt");
//ifstream fin ("aciclic.txt");

bool visited[100];
int a[100][100];
int n,m;

bool DFS(int nod,int parinte)
{
    visited[nod] = true;
    for (int i = 1 ; i <= n ; ++i)
    {
        if (a[i][nod] == 1)
        {
            if (visited[i] == false)
            {
                if (DFS(i,nod))
                    return true;
            }
            else if (visited[i] and i != parinte)
                return true;


        }
    }
    return false;
}

int main()
{
    fin >> n >> m;
    for (int i = 1 ; i <= m ; ++i)
    {
        int x,y;
        fin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 1;
    }

    for (int i = 1 ; i <= n ; ++i)
    {
        if (visited[i] == false)
        {
            if (DFS(i,-1) == true)
            {
                cout << "Nu";
                return 0;
            }
        }
    }

    cout << "Da";
    return 0;
}