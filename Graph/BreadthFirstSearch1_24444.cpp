#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

void bfs(vector<vector<int>>& E, int R, vector<int>& order)
{
    vector<bool> visited(E.size(), false);
    queue<int> Q;
    int counter = 1;

    visited[R] = true;
    // 시작 정점 R을 큐에 삽입한다.
    Q.push(R);
    order[R] = counter++;

    while (!Q.empty())
    {
        // 현재 방문 요소(큐의 맨 앞)를 큐에서 삭제한다.
        int u = Q.front();
        Q.pop();

        // 정점 u의 인접 정점 집합을 순회한다.
        for (int v : E[u])
        {
            // 정점 v를 방문하지 않았다면
            if (!visited[v])
            {
                visited[v] = true;
                // 큐 맨 뒤에 정점 v를 추가한다.
                Q.push(v);
                order[v] = counter++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M, R;
    cin >> N >> M >> R;

    vector<vector<int>> adj(N + 1);
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

    bfs(adj, R, order);

    for (int i = 1; i <= N; ++i)
        cout << order[i] << '\n';
}