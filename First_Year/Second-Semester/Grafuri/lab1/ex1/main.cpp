#include <iostream>
#include <fstream>
#include <vector>
#define len 150

using namespace std;

ifstream fin("in.txt");

struct muchie{
    int st;
    int dr;
};

void afisare_matrice(int **a,int dim)
{
    /*
        Functia afiseaza matricea a cu dimensiunea dim
        :param a: un vector de inturi
        :param dim: un int reprezentand dimensiunea matricii
        :pre: a e alocata corect si contine o matrice de dimensiunea dim x dim
        :post: se afiseaza in consola matricea a
        :returns: -
    */
    cout << "\nMatricea de adiacenta este :\n";
    for(int i = 1 ; i <= dim ; ++i)
    {
        for(int j = 1 ; j <= dim ; ++j)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }

}

void afisare_lista(const vector<vector<int>> &adj, int dim)
{
    /*Functia afiseaza o lista
     * pre : adj este lista de adiacenta
     * post : dim este nr de noduri
     */
    cout << "\nLista de adicenta este :\n";
    for(int i = 1 ; i <= dim ; ++i)
    {
        cout << i << ": ";
        for(auto vecin : adj[i])
        {
            cout << vecin << " ";
        }
        cout << endl;
    }
}

void afisare_matrice_incidenta(int **b,int nr_noduri,int nr_muchii)
{
    /*
     * Funnctia afiseaza matricea de incidenta
     * nr_noduri = nr de noduri
     * nr_muchii = numarul de muchii
     */
    cout << "\nMatricea de incidenta este : \n";
    for(int i = 1 ; i <= nr_noduri ; ++i,cout << endl)
        for(int j = 1 ; j <= nr_muchii ; ++j)
        {
            cout << b[i][j] << " ";
        }
}

void initializare_matrice(int **a,int dim)
{
    /*
     * Metoda initializeaza elemente din matrice cu 0
     * pro: dim >= 0
     * post : toate elem vor fi 0
     */
    for (int i = 0 ; i <= dim ; ++i)
        for (int j = 0 ; j <= dim ; ++j)
        {
            a[i][j] = 0;
        }
}

int citire_elemente_matrice_adicaneta(int **a,int dim)
{
    /*
     * Functia citeste si creeaza matricea de adiacenta
     * :param a: matricea de adicenta
     * :param dim: nr de noduri
     * pre: dim >= 0
     * post : returneaza nr muchiilor
     */
    int x,y,nr_muchii = 0;
    while (fin >> x >> y)
    {
        a[x][y] = 1;
        a[y][x] = 1;
        nr_muchii += 1;
    }
    return nr_muchii;
}

void creeare_lista_adiacenta_din_matrice_adiacenta(int **a, vector<vector<int>> &adj,int dim)
{
    /*
     * Functia creeaza lista de adiacneta
     * :param a: matricea de adiacenta
     * :param adj: lista de adiacenta
     * :param dim: nr de noduri
     * pre: matricea a este completata corespunzator iar adj este vida , dim >= 0
     * post: se completeaza corect matricea adj
    */
    for(int i = 1 ; i <= dim ; ++i)
        for(int j = i + 1 ; j <= dim ; ++j)
        {
            if(a[i][j] == 1)
            {
                adj[i].push_back(j);
                adj[j].push_back(i);
            }
        }
}

void creare_matrice_incidenta_din_lista_adiacenta(const vector<vector<int>> &adj, int **b, int nr_noduri,int nr_muchii)
{
    /*
     * Functia creeaza matricea de incidenta din lista de adiacenta
     * :param adj2: lista de adiacenta , de tip <vector <vector<int>>>
     * :param b: b: b este o matrice cu dimensiunea nr_noduri x nr_noduri
     * :param nr_noduri: un int
     * :param nr_muchii: un int
     * pre : adj lista de adiacenta a grafului , b este declarata corect , nr_noduri > 0
     * post : matricea b devine matricea de incidenta a grafului
     * :returns: -
     */
    vector<struct muchie> vector_muchii;
    for(int i = 1 ; i <= nr_noduri ; ++i)
        for(auto vecin : adj[i]) // creeam muchiile
        {
            if(vecin < i)
            {
                struct muchie temp_muchie;
                temp_muchie.st = i;
                temp_muchie.dr = vecin;
                vector_muchii.push_back(temp_muchie);
            }
        }
    for(int i = 1 ; i <= nr_muchii ; ++i) // construim matricea de incidenta
    {
        struct muchie curent = vector_muchii[i - 1];
        b[curent.st][i] = 1;
        b[curent.dr][i] = 1;
    }
}

void creeare_lista_adiacenta_din_matrice_incidenta(int **b,vector<vector<int>> &adj2,int nr_noduri,int nr_muchii)
{
    /*
     * Functia creeaza lista de adiacenta din matricea de incidenta
     * :param b: matricea de incidenta , de tip **
     * :param adj2: lista de adiacenta , de tip <vector <vector<int>>>
     * :param nr_noduri: int
     * :param nr_muchii: int
     * :pre: b este matricea de incidenta a grafului , adj2 e declarata corect , nr_noduri > 0
     */
    int second = 0 , first = 0;
    for(int i = 1 ; i <= nr_muchii ; i++) //mergem pe coloane
    {
        for(int j = 1 ; j <= nr_noduri ; ++j)
        {

            if(b[j][i] == 1)///cautam cele 2 elemente care au valoarea 1
            {
                second = first;
                first = j;
            }
        }
        adj2[first].push_back(second);
        adj2[second].push_back(first);
    }
}

void creeare_matrice_adicaneta_din_lista_adiacenta(vector<vector<int>> &adj2,int **c,int nr_noduri)
{
    /*
     * Functia creeaza matricea de adiacneta din lista de adacenta
     * :param adj: un vector<vector<int>> , este lista de adiacenta
     * :param c: un int ** reprezentand matricea de adiacenta
     * :param nr_noduri: un int > 0 reprezinta nr de noduri
     */
    for(int i = 1 ; i <= nr_noduri; ++i)
        for(auto j:adj2[i])
        {
            c[i][j] = 1;
            c[j][i] = 1;
        }
}


int main()
{
    ///Definire variabile
    int nr_muchii = 0,nr_noduri = 0, first,second;

    fin >> nr_noduri;

    ///Initializarea vectorilor
    int **a=new int*[nr_noduri+1];
    int **b=new int*[nr_noduri+1];
    int **c=new int*[nr_noduri+1];

    for (int i = 0 ; i <= nr_noduri ; ++i)
    {
        a[i] = new int[nr_noduri + 1];
        b[i] = new int[nr_noduri + 1];
        c[i] = new int[nr_noduri + 1];
    }

    initializare_matrice(a,nr_noduri);
    initializare_matrice(b,nr_noduri);
    initializare_matrice(c,nr_noduri);

    ///Matrice de adiacenta a
    nr_muchii = citire_elemente_matrice_adicaneta(a,nr_noduri);
    afisare_matrice(a,nr_noduri);

    ///Lista de adiacenta adj
    vector<vector<int>> adj(nr_noduri + 1);
    creeare_lista_adiacenta_din_matrice_adiacenta(a, adj, nr_noduri);
    afisare_lista(adj,nr_noduri);

    ///Matrice de incidenta b
    creare_matrice_incidenta_din_lista_adiacenta(adj,b,nr_noduri,nr_muchii);
    afisare_matrice_incidenta(b,nr_noduri,nr_muchii);

    ///Lista adiacenta adj2
    vector<vector<int>> adj2(nr_noduri + 1);
    creeare_lista_adiacenta_din_matrice_incidenta(b,adj2,nr_noduri,nr_muchii);
    afisare_lista(adj2,nr_noduri);

    ///Matrice adiacenta c
    creeare_matrice_adicaneta_din_lista_adiacenta(adj2,c,nr_noduri);
    afisare_matrice(c,nr_noduri);

    //Lista adiacenta
    vector<vector<int>> adj3(nr_noduri + 1);
    creeare_lista_adiacenta_din_matrice_adiacenta(c,adj3,nr_noduri);
    afisare_lista(adj3,nr_noduri);


    ///eliberare memorie
    for (int i = 0 ; i <= nr_noduri ; ++i)
    {
        delete[] a[i];
        delete[] b[i];
        delete[] c[i];

    }

    delete[] a;
    delete[] b;
    delete[] c;

    return 0;
}
