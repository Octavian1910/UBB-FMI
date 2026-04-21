#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#define len 150
#define inf 10e8
using namespace std;
ifstream fin("moore.in");

int p[150],l[150],a[150][150],nrNodes,nrEdges,start,x,y;


void Moore(int start)
{
    for (int i = 1 ; i <= nrNodes ; ++i)
    {
        p[i] = 0;
        l[i] = inf;
    }
    p[start] = 0;
    l[start] = 0;
    queue<int> q;
    q.push(start);
    while (!q.empty())
    {
        int current = q.front();q.pop();
        for (int neighbour = 1 ; neighbour <= nrNodes ; ++neighbour)
        {
            if (l[neighbour] == inf and a[current][neighbour] == 1)
            {
                l[neighbour] = l[current] + 1;
                p[neighbour] = current;
                q.push(neighbour);
            }
        }
    }
}

void moore_drum(int drum[],int nod)
{
    int lenght = l[nod];
    drum[lenght] = nod;
    while ( lenght > 0 )
    {
        drum[lenght - 1] = p[drum[lenght]];
        lenght -= 1;
    }
}

int main()
{
    int drum[15];
    fin >> nrNodes >> nrEdges >> start;
    for (int i = 1 ; i <= nrEdges ; ++i)
    {
        fin >> x >> y;
        a[x][y]=1;
        a[y][x]=1;
    }
    Moore(start);
    moore_drum(drum,4);
    for (int i = 0 ; i <= l[4] ; ++i)
    {
        cout << drum[i] << " -> ";
    }
    return 0;
}