#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

struct Edge
{
    int from, to, cost;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<Edge> edges(M);
    vector<long long> dist(N + 1, LLONG_MAX); // 최단 거리를 저장할 배열

    for (int i = 0; i < M; ++i) 
    {
        cin >> edges[i].from >> edges[i].to >> edges[i].cost;
    }

    dist[1] = 0; // 시작점은 0으로 설정

    // 벨만-포드 알고리즘
    for (int i = 1; i <= N; ++i) 
    {
        for (Edge e : edges) 
        {
            if (dist[e.from] == LLONG_MAX) continue; // 시작점에서 도달할 수 없는 경우

            if (dist[e.to] > dist[e.from] + e.cost) 
            {
                dist[e.to] = dist[e.from] + e.cost;
                if (i == N) // N번째 반복에서도 값이 갱신되면 음수 사이클 존재
                {
                    cout << "-1\n";
                    return 0;
                }
            }
        }
    }

    for (int i = 2; i <= N; ++i) 
    {
        if (dist[i] == LLONG_MAX) cout << "-1\n";
        else cout << dist[i] << "\n";
    }
}
