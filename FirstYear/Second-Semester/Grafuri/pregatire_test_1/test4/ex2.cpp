#include <iostream>
#include <fstream>
#include <vector>
#define inf 10e7
using namespace std;

ifstream fin("test4ex2.in");

void drum(int nod,vector<int> p)
{
    if (p[nod] == 0)
    {
        cout << nod << " ";
    }
    else
    {
        drum(p[nod],p);
        cout << nod << " ";
    }
}

int a[100][100];

int main()
{
    int n,m,x,y,z,start,end;

    fin >> n >> m;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            a[i][j] = inf;

    for (int i = 1 ; i <= m ; ++i)
    {
        fin >> x >> y >> z;
        a[x][y] = z;
    }

    fin >> start >> end;

    vector<int> d(n+1,inf);
    vector<bool> visited(n+1,false);
    vector<int> p(n+1,0);
    d[start] = 0;


    for (int i = 1 ; i  <= n ; ++i)
    {
        int x = -1;
        for (int j = 1 ; j <= n ; ++j)
        {
            if (!visited[j] && (x == -1 || d[j] < d[x]))
            {
                x = j;
            }
        }

        if (x == -1 || d[x] == inf)
        {
            break;
        }

        visited[x] = true;
        for (int j = 1 ; j <= n ; ++j)
        {
            if (a[x][j] != inf and d[j] > d[x] + a[x][j])
            {
                d[j] = d[x] + a[x][j];
                p[j] = x;
            }
        }
    }

    if (d[end] == inf)
    {
        cout << "Nu exista drum";
    }
    else
    {
        cout << d[end] << endl;
        drum(end,p);
    }

    return 0;
}