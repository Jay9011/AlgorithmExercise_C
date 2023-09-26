#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int ConnectedCounter(int start, const vector<vector<int>>& network)
{
	int counter = 0;
	vector<bool> visited(network.size(), false);
	queue<int> Q;

	// 시작 정점을 방문합니다.
	Q.push(start);
	visited[start] = true;

	while (!Q.empty())
	{
		int curr = Q.front();
		Q.pop();

		for(int next : network[curr])
		{
			if (!visited[next])
			{
				Q.push(next);
				visited[next] = true;
				counter++;
			}
		}
	}

	return counter;
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