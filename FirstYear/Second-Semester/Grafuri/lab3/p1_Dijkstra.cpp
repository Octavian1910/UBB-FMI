#include <iostream>
#include <fstream>
#include <vector>
#define inf 10e8
using namespace std;


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

    fin >> V >> E >> S;
    vector<vector<pair<int,int>>> adj(V);
    for (int i = 0; i < E ; ++i)
    {
        int x,y,w;
        fin >> x >>y >> w;
        adj[x].push_back({y,w});
    }

    vector<int> d(V,inf);
    vector<bool> used(V+1,false);
    d[S] = 0;

   for (int i = 0 ; i < V  ; ++i)
   {
       int x = -1;
       for (int j = 0 ; j < V ; ++j)
       {
           if ( !used[j] && ( x == -1 || d[j] < d[x]))
           {
               x = j;
           }
       }
       if (x == -1 || d[x] == inf)
           break;

       used[x] = true;

       for (auto edge: adj[x])
       {
           int v=edge.first;
           int cost=edge.second;
           if (d[v] > d[x] + cost)
           {
               d[v] = d[x] + cost;
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