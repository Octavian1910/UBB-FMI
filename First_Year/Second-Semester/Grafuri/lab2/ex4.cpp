#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#define inf 10e8

ifstream fin("graf.txt");

/*
 * 4. Pentru un graf dat să se afișeze pe ecran vârfurile descoperite de
 * algoritmul BFS și distanța față de vârful sursă (arborele descoperit).
 */

void bfs(int **a,int *l,int nr_noduri,int vf_sursa)
{
    for (int i = 0 ; i <= nr_noduri ; ++i)
        l[i] = inf;
    queue<int> q;
    q.push(vf_sursa);

    l[vf_sursa] = 0;

    while (q.size())
    {
        int x = q.front(); q.pop();
        for (int vecin = 1 ; vecin <= nr_noduri ; ++vecin)
        {
            if (a[x][vecin] == 1 and l[vecin] == inf)
            {
                l[vecin] = l[x] + 1;
                q.push(vecin);
            }
        }
    }
}

int main()
{
    int nr_vf,x,y,vf_sursa;
    fin >> nr_vf;
    int** a = new int*[nr_vf + 1];
    for (int i = 0; i <= nr_vf; i++)
    {
        a[i] = new int[nr_vf + 1];
    }

    for (int i = 0; i <= nr_vf; i++)
        for (int j = 0; j <= nr_vf; j++)
            a[i][j] = 0;

    int* l = new int[nr_vf + 1];

    while (fin >> x >> y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
    }

    cout << "Varf start : "; cin >> vf_sursa;
    bfs(a, l, nr_vf, vf_sursa);

    for (int i = 1; i <= nr_vf; i++)
    {
        cout << i << " - lungime : ";
        if (l[i] == inf)
            cout << "inf" << endl;
        else
            cout << l[i] << endl;
    }

    for (int i = 0; i <= nr_vf; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] l;

    return 0;
}

