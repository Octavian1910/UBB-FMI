#include <iostream>
#include <fstream>
#include <queue>
#define len 150
using namespace std;
ifstream fin("BFS.in");
ofstream fout("BFS.out");

int nrNodes, nrEdges, start, a[len][len];
bool visited[len];

//Breadth First Search

void BFS(int a[][len], int start)
{
	cout << start << " ";
	visited[start] = true;
	queue<int> q;
	q.push(start);
	while (!q.empty())
	{
		int current = q.front(); q.pop();
		for (int node = 1; node <= nrNodes; ++node)
		{
			if (a[current][node] == 1 and visited[node] == false)
			{
				cout << node << " ";
				visited[node] = true;
				q.push(node);
			}
		}
	}
}

int main()
{
	int x, y;
	fin >> nrNodes >> nrEdges >> start;
	while (fin >> x >> y)
	{
		a[x][y] = 1;
		a[y][x] = 1;
	}
	BFS(a,start);
	return 0;
}