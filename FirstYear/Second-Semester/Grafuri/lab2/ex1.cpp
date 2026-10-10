#include <iostream>
#include <fstream>
#include <queue>

using namespace std;
#define inf 1000000000


ifstream fin("graf.txt");

/*
 * 1. Implementați algoritmul lui Moore pentru un graf orientat neponderat (algoritm bazat pe Breath-first search, vezi
 * cursul 2). Datele sunt citete din fisierul graf.txt. Primul rând din graf.txt conține numărul vârfurilor, iar
 * următoarele rânduri conțin muchiile grafului. Programul trebuie să afiseze lanțul cel mai scurt dintr-un vârf
 * (vârful sursa poate fi citit de la tastatura).
 */

void Moore(int **a,int *l,int* p,int nr_noduri,int vf_sursa)
{
    for (int i = 0 ; i <= nr_noduri ; ++i)
        l[i] = inf , p[i] = -1;;
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
                p[vecin] = x;
                l[vecin] = l[x] + 1;
                q.push(vecin);
            }
        }
    }
}

void moore_drum(int *l,int* p,int* drum,int nod)
{
    int k = l[nod];
    drum[k] = nod;
    while (k != 0)
    {
        nod = p[nod];
        drum[k - 1] = nod;

        k -= 1;
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
    int* drum = new int[nr_vf + 1];
    int* p = new int[nr_vf + 1];


    while (fin >> x >> y)
    {
        a[x][y] = 1;
    }

    cout << "Varf start : "; cin >> vf_sursa;
    Moore(a, l, p, nr_vf, vf_sursa);
    for (int i = 1 ; i <= nr_vf ; ++i)
    {
        cout << vf_sursa << " - " << i << " : ";
        if (l[i] == inf)
        {
            cout << "Nu exista drum" << endl;
            continue;
        }
        moore_drum(l,p,drum,i);
        for (int j = 0 ; j <= l[i] ; ++j)
        {
            cout << drum[j] << " ";
        }
        cout << endl;
    }

    for (int i = 0; i <= nr_vf; i++)
    {
        delete[] a[i];
    }
    delete[] a;
    delete[] l;
    delete[] p;
    delete[] drum;

    return 0;
}