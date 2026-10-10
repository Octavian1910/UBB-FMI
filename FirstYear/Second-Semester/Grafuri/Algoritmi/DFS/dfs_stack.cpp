#include <iostream>
#include <fstream>
#include <stack>
#include <vector>
#define len 150
using namespace std;
ifstream fin("dfs.in");
ofstream fout("dfs.out");

int nrNodes, nrEdges, start;
bool visited[len];

//Depth First Search

void DFS(vector<vector<int>> &adj, int start)
{
	stack<int> s;
	visited[start] = true;
	s.push(start);
	while (!s.empty())
	{
		int u = s.top(); s.pop();
		cout << u << " ";
		for (const auto v : adj[u])
		{
			if (visited[v] == false)
			{
				visited[v] = true;
				s.push(v);
			}
		}
	}
}


int main()
{
	int x, y;
	fin >> nrNodes >> nrEdges >> start;
    vector<vector<int>> adj(nrNodes + 1);;
	while (fin >> x >> y)
	{
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	DFS(adj, start);
	return 0;
}