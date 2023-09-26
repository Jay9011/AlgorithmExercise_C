#include <iostream>
#include <vector>
using namespace std;

void DFS(int vertex, const vector<vector<int>>& network, vector<bool>& visited, int& counter)
{
	visited[vertex] = true;
	counter++;

	for (int next : network[vertex])
	{
		if (!visited[next])
		{
			DFS(next, network, visited, counter);
		}
	}
}

int ConnectedCounter(int start, const vector<vector<int>>& network)
{
	int counter = 0;
	vector<bool> visited(network.size(), false);

	DFS(start, network, visited, counter);

	return counter - 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, E;
	cin >> N >> E;

	vector<vector<int>> network(N + 1);

	while (E--)
	{
		int u, v;
		cin >> u >> v;
		network[u].push_back(v);
		network[v].push_back(u);
	}

	cout << ConnectedCounter(1, network) << '\n';
}