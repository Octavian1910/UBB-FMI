#include <iostream>
#include <fstream>
#include <algorithm>

#define inf 10e8

//gcc ex3_ciclu_eulerian.cpp -o ex3
//  ./ex3 ex3.in ex3.out

using namespace std;

//https://www.youtube.com/watch?v=MG_EIgDEuQA best explanation

void Push(int** C,int** F,int* exces,int u,int v)// C-capcacitatea muchiei ; F-fluxul curent ; exces-cat flux are nodul in plus
{
    int capacitate_reziduala = C[u][v]-F[u][v]; //cat mai putem trimite
    int delta = min(exces[u],capacitate_reziduala); //cat pompam , nu putem trimite mai mult decat avem si nici mai mult decat permite muchia
    F[u][v] += delta;
    F[v][u] -= delta; //acum putem anula fluxul ,adica sa corectam decizii gresite

    exces[u] -= delta;
    exces[v] += delta; //pleaca din u ajunge in v

}

void Relabel(int V,int** C,int** F,int* h,int u) //inaltare
{
    int minim = inf;

    for (int v = 0; v < V; ++v)
    {
        if (C[u][v] - F[u][v] > 0) //vecini unde nu s au folosit muchiile la maxim deci mai exista capacitate reziduala
        {
            minim = min(minim,h[v]); //cautam cel mai mic vecin
        }
    }
    h[u] = minim + 1; //acum poate impinge in acest vecin
}


void Discharge(int V,int** C,int** F,int* exces,int* h,int* poz,int u) //descarcare
{
    while (exces[u] > 0) //cat timp nodul are exces incearca sa se scape de el
    {
        if (poz[u] < V) //daca mai avem vecini
        {
            int v = poz[u]; // vecinul curent

            if (C[u][v] - F[u][v] > 0 &&        //daca mai exista loc pe mmuchie
                                        h[u] > h[v]) //si daca vecinul este mai jos
            {
                Push(C,F,exces,u,v);
            }
            else
            {
                poz[u]++; //incearca urm vecin
            }
        }
        else //daca am terminat toti vecinii
        {
            Relabel(V,C,F,h,u); //ridicam nodul
            poz[u] = 0;         //reluam verificarea vecinilor
        }
    }
}

int pompare_topologica(int V,int** C,int** F,int sursa,int destinate)
{
    int* exces = new int[V];        //cat exces este intr un nod , algoritmul se termina cand exista exces doar in nodul sursa si/sau destinatie
    int* h = new int[V];        //inaltime
    int* poz = new int[V]; //vecini

    for (int i = 0 ; i < V ; ++i)
    {
        exces[i] = 0;
        h[i] = 0;
        poz[i] = 0;
    }

    int* L = new int[V-2]; // nodurule fara sursa si destinatie
    int len = 0;

    for (int i = 0 ; i < V ; ++i)
    {
        if (i != sursa && i != destinate)
        {
            L[len++] = i;
        }
    }

    //pregatim sursa
    h[sursa] = V;
    exces[sursa] = inf;


    //trimitem maxim din sursa la vecini
    for (int vecin = 0; vecin < V; ++vecin)
    {
        Push(C,F,exces,sursa,vecin);
    }

    int k = 0;
    while (k < V - 2)
    {
        int u = L[k]; // nodul pe care il descarci acum
        int veche_inaltime = h[u];
        Discharge(V,C,F,exces,h,poz,u);
        //daca nodul a fost inaltat
        if (h[u] > veche_inaltime) // daca s a inaltat il mutam la inceputul vectorului pt ca are sanse mai mari sa impinga
        {
            int x = L[k];
            for (int i = k ; i > 0 ; --i)
            {
                L[i] = L[i - 1];
            }
            L[0] = x;
            k = 0;
        }
        else
        {
            ++k;
        }
    }

    int flux_maxim = 0;
    for (int i = 0 ; i < V; ++i)
    {
        flux_maxim += F[sursa][i];
    }

    delete[] exces;
    delete[] h;
    delete[] poz;
    delete[] L;

    return flux_maxim;

}

int main(int argc,char* argv[])
{
    if (argc < 3)
    {
        cout << "Utilizare gresita!";
        return 0;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int V, E;

    fin >> V >> E;

    // matrice capacitati
    int** C = new int*[V];

    // matrice flux
    int** F = new int*[V];

    for (int i = 0; i < V; ++i)
    {
        C[i] = new int[V];
        F[i] = new int[V];
    }

    // initializare cu 0
    for (int i = 0; i < V; ++i)
    {
        for (int j = 0; j < V; ++j)
        {
            C[i][j] = 0;
            F[i][j] = 0;
        }
    }

    // citire muchii
    for (int i = 0; i < E; ++i)
    {
        int x, y, c;

        fin >> x >> y >> c;

        C[x][y] = c;
    }

    int sursa = 0;
    int destinatie = V - 1;

    int raspuns = pompare_topologica(V, C, F, sursa, destinatie);

    fout << raspuns << '\n';

    // eliberare memorie
    for (int i = 0; i < V; ++i)
    {
        delete[] C[i];
    }

    delete[] C;

    for (int i = 0; i < V; ++i)
    {
        delete[] F[i];
    }

    delete[] F;

    fin.close();
    fout.close();

    return 0;
}