#include <iostream>
#include <vector>
#include <fstream>
using namespace std;


int main()
{
    ifstream fin("graf.in");
    int n,m;
    fin>>n>>m;
    vector<pair<int,int>> v;
    int c[100][100];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            c[i][j]=999999;

    for(int i=1;i<=m;i++)
    {
        int x,y,cost;
        fin>>x>>y>>cost;

        c[x][y]=cost;
        c[y][x]=cost;
    }

    int viz[100]={0};

    viz[0]=1; // pornesc din nodul 1

    int total=0;

    for(int pas=1;pas<=n-1;pas++)
    {
        int minim=999999;
        int a,b;

        for(int i=0;i<n;i++)
        {
            if(viz[i])
            {
                for(int j=0;j<n;j++)
                {
                    if(!viz[j] && c[i][j]<minim)
                    {
                        minim=c[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        v.push_back({a,b});

        viz[b]=1;
        total+=minim;
    }

    cout<<total << "\n";
    cout<<v.size() << "\n";
    for (auto edge:v)
    {
        cout<< edge.first << " " << edge.second <<"\n";
    }

    return 0;
}