#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void dfs(int R, int& cnt, vector<vector<int>>& adj, vector<int>& visited, vector<int>& order)
{
	visited[R] = true;	// 시작 정점 R을 방문 했다고 표시한다.
	order[R] = cnt++;	// 방문 순서 저장

	// 인접 정점을 방문
	for (int x : adj[R])
		if (!visited[x]) dfs(x, cnt, adj, visited, order);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, R;
	cin >> N >> M >> R;

	vector<vector<int>> adj(N + 1, vector<int>());	// 인접 리스트
	vector<int> visited(N + 1, false);
	vector<int> order(N + 1, 0);

	for (int i = 0; i < M; ++i)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	// 인접 리스트를 오름차순으로 정렬
	for (int i = 1; i <= N; ++i)
		sort(adj[i].begin(), adj[i].end());

	int cnt = 1;
	dfs(R, cnt, adj, visited, order);

	for (int i = 1; i <= N; ++i)
		cout << order[i] << '\n';
}
