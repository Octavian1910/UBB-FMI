#include <iostream>
#include <fstream>
#include <queue>

using namespace std;

#define inf 10e8

ifstream fin("graf.txt");

/*
 * 2. Sa se determine închiderea transitivă a unui graf orientat. (Închiderea tranzitivă poate fi reprezentată
 * ca matricea care descrie, pentru fiecare vârf în parte, care sunt vârfurile accesibile din acest vârf. Matricea
 * inchiderii tranzitive arată unde se poate ajunge din fiecare vârf.) ex. figura inchidere_tranzitiva.png - pentru
 * graful de sus se construieste matricea de jos care arata inchiderea tranzitiva.
 */

void bfs(int **a,int** transitiva,int nr_noduri,int vf_sursa)
{
    int* visited = new int[nr_noduri + 1];
    for (int i = 0 ; i <= nr_noduri ; ++i)
        visited[i] = false;
    queue<int> q;
    q.push(vf_sursa);

    visited[vf_sursa] = true;

    while (q.size())
    {
        int x = q.front(); q.pop();
        for (int vecin = 1 ; vecin <= nr_noduri ; ++vecin)
        {
            if (a[x][vecin] == 1 and visited[vecin] == false)
            {
                visited[vecin] = true;
                transitiva[vf_sursa][vecin] = 1;
                q.push(vecin);
            }
        }
    }
    delete[] visited;
}

int main()
{
    int nr_vf,x,y,vf_sursa;
    fin >> nr_vf;
    int** a = new int*[nr_vf + 1];
    int** transitiva = new int*[nr_vf + 1];
    for (int i = 0; i <= nr_vf; i++)
    {
        a[i] = new int[nr_vf + 1];
        transitiva[i] = new int[nr_vf + 1];

    }

    for (int i = 0; i <= nr_vf; i++)
        for (int j = 0; j <= nr_vf; j++)
        {
            a[i][j] = 0;
            transitiva[i][j] = 0;
            if ( i == j)
                transitiva[i][j] = 1;
        }


    while (fin >> x >> y)
    {
        a[x][y] = 1;
    }

    //facem bfs incepand de la fiecare nod in parte
    for (int i = 1; i <= nr_vf; i++)
        bfs(a,transitiva, nr_vf, i);

    for (int i = 1; i <= nr_vf; i++, cout << endl)
     for (int j = 1; j <= nr_vf; j++)
    {
      cout << transitiva[i][j] << " ";
    }

    for (int i = 0; i <= nr_vf; i++)
    {
        delete[] a[i];
        delete[] transitiva[i];
    }
    delete[] a;
    delete[] transitiva;

    return 0;
}

