#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char *argv[])
{
    if (argc < 3)
        return 1;

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int m;
    fin >> m;

    int k[100];            // cod_prufer
    int nr_aparitii[101] = {0};  // frecvențe
    int p[101];            // parinti

    int n = m + 2;         // nr noduri total


    for (int i = 0; i < m; i++)
    {
        fin >> k[i];
        nr_aparitii[k[i]]++;
    }

    for (int i = 0; i < n; i++)
        p[i] = -1;

    // decodare
    for (int i = 0; i < m; i++)
    {
        int x = k[i];  // nodul din cod

        // cautam cea mai mica frunza care nu apare in cod
        int y = -1;
        for (int j = 0; j < n; j++)
        {
            if (nr_aparitii[j] == 0)
            {
                y = j;
                break;
            }
        }

        //legam frunza la parintele ei
        p[y] = x;

        nr_aparitii[x]--; //am folosit o aparitie a tatalui
        nr_aparitii[y] = -1;  //l am folosit nu mai poate sa fie frunza din nou
    }

    //pt ultimele 2 noduri ramase
    int a = -1, b = -1;
    for (int i = 0; i < n; i++)
    {
        if (nr_aparitii[i] == 0)
        {
            if (a == -1) a = i;
            else b = i;
        }
    }

    p[a] = b;

    fout << n << "\n";
    for (int i = 0; i < n; i++)
        fout << p[i] << " ";

    return 0;
}