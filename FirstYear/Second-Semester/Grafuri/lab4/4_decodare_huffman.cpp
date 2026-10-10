#include <algorithm>
#include <vector>
#include <iostream>
#include <fstream>

using namespace std;

struct Nod
{
    char c;
    int freq;
    Nod* st;
    Nod* dr;
};

bool cmp(const Nod* a,const Nod* b)
{
    if (a->freq != b->freq)
        return a->freq < b->freq;
    //altfel pt egalitate alfabetic
    return a->c < b->c;
}

int main(int argc,char* argv[])
{
    if(argc != 3)
    {
        cout << "Argumente insuficiente!";
        return 1;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int N;
    fin >> N;

    vector<Nod*> q;

    for (int i = 0 ; i < N ; ++i)
    {
        char c;
        int f;
        fin >> c >> f;

        Nod* x = new Nod;
        x->c = c;
        x->freq = f;
        x->st = x->dr = NULL;

        q.push_back(x);
    }

    while (q.size() > 1) //construim arborele
    {
        sort(q.begin(),q.end(),cmp);

        Nod* a = q[0];
        Nod* b = q[1];
        Nod* nou = new Nod;
        nou->c = '#';
        nou->freq = a->freq + b->freq;
        nou->st = a;
        nou->dr = b;

        q.erase(q.begin());
        q.erase(q.begin());
        q.push_back(nou);
    }

    Nod* rad = q[0];
    Nod* cur = rad;

    string s;
    fin >> s;//codul care trb decodat

    for (char bit:s)
    {
        if (bit == '0')
            cur = cur->st;
        else
            cur = cur->dr;

        if (cur->st == NULL && cur->dr == NULL) //daca e frunza inseamna ca e litera
        {
            fout << cur->c;
            cur = rad; //revenim la radacina
        }
    }
    return 0;
}