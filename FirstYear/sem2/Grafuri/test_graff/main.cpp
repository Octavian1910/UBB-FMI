#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

/*a)
 * Algoritmul porneste dintr un nod.La fiecare pas alege o muchia cu cost minim care are un vecin
 * vizitat iar pe celalalt nu.
 * Astfel are nevoie de n-1 iteratii pentru a crea un arbore minim de acoperire.
 *
 * b)
 * Un caz real este daca de ex am fii soferul unui autobuz de elevi.Autobuzul
 * pleaca de la scoala pentru a ii duce acasa.
 * El trb sa treaca prin toate satele pentru a l lasa pe fiecare elev,
 * astfel cea mai eficienta cale este tocmai algoritmul lui Prim.
 *
 */

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

    viz[0]=1; // pornim din nodul 1

    int total=0;

    for(int pas=1;pas<=n-1;pas++) //facem cele n-1 muchii
    {
        int minim=999999;
        int a,b;

        for(int i=0;i<n;i++)
        {
            if(viz[i]) //un capat vizitat
            {
                for(int j=0;j<n;j++)
                {
                    if(!viz[j] && c[i][j]<minim) //celalt capat nu trb sa fie vizitat
                    {
                        minim=c[i][j];
                        a=i;
                        b=j;
                    }
                }
            }
        }

        v.push_back({a,b}); //am ales doar muchia minima care respecta cerinta

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