#include <iostream>
#include <bitset>
#include <fstream>
#define len 200
using namespace std;


/*5. Pentru un graf dat să se afișeze pe ecran vârfurile descoperite de apelul recursiv al procedurii DFS_VISIT(G, u).
 *
 */

ifstream fin("ex5.txt");


bitset<200> viz;
int a[len][len];




void dfsVisit(int nod,int n)
{
    viz[nod] = 1;
    cout << nod << " ";
    for (int i = 1 ; i <= n ; ++i)
    {
        if (a[nod][i] == 1 && viz[i] == false)
            dfsVisit(i,n);
    }
}

void dfs(int n)
{
    for (int i = 1 ; i <= n ; ++i)
    {
        if (viz[i] == 0)
            dfsVisit(i,n);
    }
}



int main()
{
    int x,y,n;
    fin >> n;
    while (fin >> x >> y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
    }
    dfs(n);
    return 0;
}