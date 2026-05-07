#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

struct Nod
{
    char c;
    int freq;
    Nod* st;
    Nod* dr;
};

bool cmp(Nod* a, Nod* b)
{
    if(a->freq != b->freq)
        return a->freq < b->freq;
    return a->c < b->c;
}

void dfs(Nod* nod, string cod, map<char,string>& mp)
{
    if(nod->st == NULL && nod->dr == NULL) //literele sunt doar in frunza
    {
        mp[nod->c] = cod;
        return;
    }

    dfs(nod->st, cod + "0", mp);
    dfs(nod->dr, cod + "1", mp);
}

int main(int argc, char* argv[])
{
    if(argc != 3)
    {
        cout << "Argumente insuficiente!";
        return 1;
    }

    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    string text;
    fin >> text;

    map<char,int> frecv;

    for(char c : text)
        frecv[c]++;

    fout << frecv.size() << "\n";

    //afisam frecventele
    for(auto it : frecv)
        fout << it.first << " " << it.second << "\n";

    vector<Nod*> q;

    for(auto it : frecv)
    {
        Nod* x = new Nod;
        x->c = it.first;
        x->freq = it.second;
        x->st = NULL;
        x->dr = NULL;

        q.push_back(x);
    }

    while(q.size() > 1) // tot combinam cele mai mici 2 pana cand ajunge la o singura valoare
    {
        sort(q.begin(), q.end(), cmp);

        Nod* a = q[0];
        Nod* b = q[1];

        Nod* nou = new Nod;
        nou->c = min(a->c, b->c);
        nou->freq = a->freq + b->freq;
        nou->st = a;
        nou->dr = b;
        //stergem primele 2 pt ca le am folosit
        q.erase(q.begin());
        q.erase(q.begin());
        q.push_back(nou);
    }

    Nod* radacina = q[0];

    map<char,string> cod;
    dfs(radacina, "", cod);

    string rezultat = "";

    for(char c : text)
        rezultat += cod[c]; //mergem litera cu litera si atribuim codul respectiv literei

    fout << rezultat << "\n";

    return 0;
}