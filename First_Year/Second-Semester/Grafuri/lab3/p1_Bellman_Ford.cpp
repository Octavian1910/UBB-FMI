#include <iostream>
#include <fstream>
#include <vector>
#define inf 10e8
using namespace std;

struct Muchie
{
    int u,v,w;
};

//rulare :
//    g++ -Wall -Werror p1.cpp -o p1
 //   /p1 date.in date.out
int main(int argc,char* argv[])
{
    if (argc < 3)
    {
        cout << "Nr insuficient de argumente";
        return 1;
    }
    ifstream fin(argv[1]);
    ofstream fout(argv[2]);

    int V,E,S;
    vector<Muchie> muchii;
    fin >> V >> E >> S;
    for (int i = 0; i < E ; ++i)
    {
        int x,y,w;
        fin >> x >>y >> w;
        Muchie muchie = {x,y,w};
        muchii.push_back(muchie);
    }

    vector<int> d(V,inf);
    d[S] = 0;

    //BELLMAN-FORD
    for (int i = 1 ; i <= V - 1 ; ++i)
    {
        for (auto m:muchii)
        {
            if (d[m.u] != inf && d[m.v] > d[m.u] + m.w)
            {
                d[m.v] = d[m.u] + m.w;
            }
        }
    }

    for (int i = 0; i < V; i++) {
        if (d[i] == inf)
            fout << "INF ";
        else
            fout << d[i] << " ";
    }

    return 0;

}