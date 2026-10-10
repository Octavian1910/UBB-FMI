#include <iostream>
#include <fstream>

using namespace std;
ifstream fin("eulerian.txt");
int n,m,p=0,k,x,y,A[100][100],L[100];

//Algoritmul lui Carl Hierholzer

void Euler(int k)
{
    for (int i = 0 ; i < n ; ++i)
    {
     if (A[k][i] == 1)
     {
         A[k][i] = A[i][k] = 0;
         Euler(i);
     }
    }
    L[p] = k;
    p++;
}

int main()
{
    fin >> n >> m;

    while (fin >> x >> y)
    {
        A[x][y] = A[y][x] = 1;
    }
    Euler(0);

    for (int i = 0 ; i <= p-1 ; ++i)
    {
        std::cout << L[i] << ' ';
    }
    return 0;
}