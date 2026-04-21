#include <iomanip>
#include <iostream>
#include <fstream>
#include <string.h>
#include <queue>
#define len 400
#define inf 10e8
using namespace std;

ifstream fin("labirint_1.txt");
int x_start,y_start,x_final,y_final;
int v[len][len];
char linie[len];
int n; //nr linii
int m; //nr coloane


/*3. Să se scrie un program care găsește o soluție pentru unul din următoarele labirinturi:
 *labirint_1.txt, labirint_2.txt, labirint_cuvinte.txt. Pentru labirintul 1 si 2 punctul de pornire este indicat
 *de litera S și punctul de oprire este indicat de litera F, spre deosebire de labirintul 1 și 2, labirintul 3 nu are o soluție unică.
 *
 */
void citire_fisier_si_creare_matrice()
{
    while (fin.getline(linie,len))
    {
        m = strlen(linie);
        n += 1;
        for (int i = 0 ; i < strlen(linie); ++i)
        {
            if (linie[i] == '1')
                v[n][i + 1] = -1;
            else if (linie[i] == ' ')
            {
                v[n][i + 1] = inf;
            }
            else if(linie[i] == 'S')
            {
                v[n][i + 1] = 1;
                x_start = n;
                y_start = i + 1;
            }
            else if (linie[i] == 'F')
            {
                x_final = n;
                y_final = i + 1;
                v[n][i + 1] = inf;
            }

        }
    }
}

bool valid(int x,int y)
{
    if (x < 1 || x > n || y < 1 || y > m)
        return false;
    if (v[x][y] == -1)
        return false;
    return true;
}



void Lee()
{
    v[x_start][y_start] = 1;
    int di[4] = {1,-1,0,0};
    int dj[4] = {0,0,1,-1};
    queue<pair<int,int>> q;
    q.push(make_pair(x_start,y_start));
    while (q.size() > 0)
    {
        int lin = q.front().first;
        int col = q.front().second;
        q.pop();
        for (int i = 0 ; i <= 3 ; ++i)
        {
            int nlin = lin + di[i];
            int ncol = col + dj[i];
            if (valid(nlin,ncol) && v[lin][col] + 1 < v[nlin][ncol])
            {
                v[nlin][ncol] = v[lin][col] + 1;
                q.push(make_pair(nlin,ncol));
            }
        }
    }
}



void drum()
{
    int x = x_final;
    int y = y_final;

    int di[4] = {1,-1,0,0};
    int dj[4] = {0,0,1,-1};

    while (!(x == x_start && y == y_start))
    {
        for (int k = 0; k < 4; k++)
        {
            int nx = x + di[k];
            int ny = y + dj[k];

            if (valid(nx,ny) == true)
            {
                if (v[nx][ny] == v[x][y] - 1)
                {

                    // marcăm drumul (atenție să nu strici startul)
                    if (!(x == x_start && y == y_start))
                        v[x][y] = -2;
                    x = nx;
                    y = ny;

                    break;
                }
            }
        }
    }
}

int main()
{
    citire_fisier_si_creare_matrice();
    Lee();
    if (v[x_final][y_final] == inf)
    {
        cout << "Nu exista drum!";
    }
    else
    {
        drum();

        for (int i = 1 ; i <= n ; ++i, cout << endl)
        {
            for (int j = 1 ; j <= m ; ++j)
            {
                if (v[i][j] == -1)
                    cout << setw(2) << "1";
                else if (v[i][j] == -2)
                    cout << setw(2) << "*";
                else
                    cout << setw(2) << v[i][j];

                cout <<" ";
            }
        }

    }

    return 0;
}

