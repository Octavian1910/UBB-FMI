#include <iostream>
#include <fstream>
#define len 150
using namespace std;


ifstream fin("date.in");

void creeare_matrice_adiacneta(int** a,int nr_noduri)
{
    /*
     * Functia creeaza matricea de adiacenta in functie de datele din fisier
     * :param a: matricea bidimensionala de inturi
     * :param nr_noduri: un int reprezentand nr de noduri
     * :pre: a este matricea de adiacenta , nr_noduri  >= 0
     * :post: a o sa fie initializata cu valorile potrivite
     * :returns: -
     */
    for(int i = 0 ; i <= nr_noduri ; ++i)
        for(int j = 0 ; j <= nr_noduri; ++j)
            a[i][j] = 0;
    int x,y;
    while(fin >> x >> y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
    }
}

void gradul_nodurilor(int **a,int grad_nod[len],int nr_noduri)
{
    /*
     * Functia determina nodul fiecarui graf si l pune in vectorul grad_nod
     * :param a: matricea de adicaneta
     * :param grad)_nod: un vector care reprezinta gradul fiecarui nod
     * :param nr_noduri: nr_noduri , un int
     */
    for(int i = 1 ; i <= nr_noduri ; ++i)
    {
        grad_nod[i] = 0;
    }

    for(int i = 1 ; i <= nr_noduri ; ++i)
    {
        for(int j = 1 ; j <= nr_noduri ; ++j)
        {
            if(a[i][j] == 1)
            {
                grad_nod[i] += 1;
            }

        }
    }
}

bool este_graful_regular(const int *grad_nod,int nr_noduri)
{
    /*
     * Determina daca graful este regular
     * :param grad_nod: un vector de inturi reprezentand gradul fiecarui nod
     * :param nr_noduri: un int reprezentand nr de noduri
     * :returns: True daca este, False altfel
     */
    int grad_unu = grad_nod[1];
    for(int i = 2 ; i <= nr_noduri ; ++i)
    {
        if(grad_unu != grad_nod[i])
            return false;
    }
    return true;
}

void afisare_grad_noduri(int grad_nod[],int nr_noduri)
{
    /*
     * Functia fiseaza gradul nodurilor
     * :param grad_nod: un vector de int
     * :param nr_noduri: un int
     */
    for(int i = 1 ; i <= nr_noduri ; ++i)
    {
        cout << i << " - " << grad_nod[i] << "\n";
    }
}


void creeare_matricea_distantelor(int **a, int **d,int nr_noduri)
{
    /*
     * Functia creeaza matricea distantelor
     * :param a: matricea de adicenta , matrice de inturi
     * :param d: matricea distantelor , matrice de inturi
     * :param nr_noduri: un int
     */
    for (int i = 1 ; i <= nr_noduri ; ++i)
        for (int j = 1 ; j <= nr_noduri ; ++j)
            if ( i == j)
                d[i][j] = 0;
            else if (a[i][j] == 1)
                d[i][j] = 1;
            else
                d[i][j] = INT_MAX;
    for (int k = 1 ; k <= nr_noduri ; ++k)
        for (int i = 1 ; i <= nr_noduri ; ++i)
            for (int j = 1 ; j <= nr_noduri ; ++j)
                    if (i != j and j != i and i != k)
                    {
                        if ( (d[i][k] + d[k][j] < d[i][j]) && (d[i][k] != INT_MAX && d[k][j] != INT_MAX))
                        {
                            d[i][j] = d[i][k] + d[k][j];
                        }
                    }
}

void afisare_matricea_distantelor(int **d,int nr_noduri)
{   /*
    *Functia afiseaza matricea distantelor
    *:param d: matricea distantelor
    *:param nr_noduri: un int reprezntand nr de noduri
    */
    for (int i = 1 ; i <= nr_noduri ; ++i,cout << "\n")
        for (int j = 1 ; j <= nr_noduri ; ++j)
    {
        cout << d[i][j] << " ";
    }
}

void dfs(int nod,int nr_noduri,int **a,int *viz)
{
    /*
     * Functie de parcurgere in adancime(Depth First Search)
     * :param nod: un int, nodul curent
     * :param nr_noduri: un int reprezentand nr de noduri
     * :param viz: un vector de caracteristici
     */
    viz[nod] = 1;
    for (int i = 1 ; i <= nr_noduri ; ++i)
    {
        if (a[nod][i] == 1 and viz[i] == 0)
            dfs(i,nr_noduri,a,viz);
    }
}

bool este_conex(int nr_noduri,int **a,int *viz)
{
    /*
     * Functia determina daca graful este conex
     * :param nr_noduri: un int reprezentand nr de noduri
     * :param a: matricea de adicaneta
     * :param viz: un vector caracteristic
     * :returns: -
     */
    int nod = 1;
    dfs(nod,nr_noduri,a,viz);
    for (int i = 1 ; i <= nr_noduri ; ++i)
        if (viz[i] == 0)
        {
            return false;
        }
    return true;
}

int main()
{
    int nr_noduri,nr_muchii;

    fin >> nr_noduri;

    int **d = new int*[nr_noduri + 1];
    int **a = new int*[nr_noduri + 1];
    int *grad_nod = new int[nr_noduri + 1];
    int *viz = new int[nr_noduri + 1];
    for (int i = 0 ; i <= nr_noduri ; ++i)
    {
        viz[i] = 0;
        a[i] = new int[nr_noduri + 1];
        d[i] = new int[nr_noduri + 1];
    }

    //creeare matrice
    creeare_matrice_adiacneta(a,nr_noduri);

    //Gradul nodurilor
    gradul_nodurilor(a,grad_nod,nr_noduri);
    afisare_grad_noduri(grad_nod,nr_noduri);

    //Este regular
    if(este_graful_regular(grad_nod,nr_noduri) == true)
        cout << "E regular \n";
    else
        cout << "Nu e regular \n";

    ///Matricea distantelor
    creeare_matricea_distantelor(a,d,nr_noduri);
    afisare_matricea_distantelor(d,nr_noduri);


    ///Este conex?
    if (este_conex(nr_noduri,a,viz) == true)
    {
        cout << "Este conex \n";
    }
    else
        cout << "Nu Este conex \n";


    for (int i = 0 ; i <= nr_noduri ; ++i)
    {
        delete[] d[i];
        delete[] a[i];
    }

    delete[] a;
    delete[] d;
    delete[] grad_nod;
    delete[] viz;

    return 0;

}
