#include <iostream>
#include <fstream>
#define len 150
using namespace std;
int nr_fii[len]; //cnt de fii
int p[len]; // vector de parinti
int drum[len]; // vectorul unde tinem minte drumul

//g++ 1_codare_prufer.cpp -o ex1
//./ex1 ex1.in ex1.out

void codarePrufer(int n,int& nr)
{
    int nr_folosite = 0;
    int min_frunza = 0;
    while (nr_folosite < n - 1)
    {
        for (int i = 0 ; i < n ; ++i)
        {
            if (nr_fii[i] == 0)
            {
                nr_folosite++;
                min_frunza = i;
                nr_fii[i]--;

                if (p[i] != -1)
                    nr_fii[p[i]]--;

                drum[nr++] = p[min_frunza];
                break;
            }
        }

    }
}


int main(int argc,char* argv[])
{
    if (argc < 3)
    {
        return 1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);
    int n,x;
    fin >> n;

    for (int i = 0 ; i < n ; ++i)
    {
        fin >> x;
        p[i] = x;
        if (x != -1)
        {
            nr_fii[x]++;
        }
    }
    int nr_drum = 0;
    codarePrufer(n,nr_drum);
    fout << nr_drum << "\n";
    for (int i = 0 ; i < nr_drum; i++)
    {
        cout << drum[i] << " ";
        fout << drum[i] << " ";
    }

    return 0;
}

