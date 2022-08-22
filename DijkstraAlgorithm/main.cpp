#include <iostream>
#include <vector>
#include <queue>

#define INF 2100000000
#define NUM 6

using namespace std;

vector<pair<int, int>> edges[NUM + 1];
int cost[NUM + 1];

void Dijkstra(int start)
{
    cost[start] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(start, 0));

    while (!pq.empty())
    {
        int current = pq.top().first;
        int distance = -pq.top().second;
        pq.pop();

        if (cost[current] < distance) continue;
        for (int i = 0; i < edges[current].size(); i++)
        {
            int next = edges[current][i].first;
            int nextDistance = distance + edges[current][i].second;

            if (nextDistance < cost[next])
            {
                cost[next] = nextDistance;
                pq.push(make_pair(next, -nextDistance));
            }
        }
    }
}

int main()
{
    for (int i = 0; i < NUM + 1; i++)
    {
        cost[i] = INF;
    }

    edges[1].push_back(make_pair(2, 2));
    edges[1].push_back(make_pair(3, 5));
    edges[1].push_back(make_pair(4, 1));

    edges[2].push_back(make_pair(1, 2));
    edges[2].push_back(make_pair(3, 3));
    edges[2].push_back(make_pair(4, 2));

    edges[3].push_back(make_pair(1, 5));
    edges[3].push_back(make_pair(2, 3));
    edges[3].push_back(make_pair(4, 3));
    edges[3].push_back(make_pair(5, 1));
    edges[3].push_back(make_pair(6, 5));

    edges[4].push_back(make_pair(1, 1));
    edges[4].push_back(make_pair(2, 2));
    edges[4].push_back(make_pair(3, 3));
    edges[4].push_back(make_pair(5, 1));

    edges[5].push_back(make_pair(3, 1));
    edges[5].push_back(make_pair(4, 1));
    edges[5].push_back(make_pair(6, 2));

    edges[6].push_back(make_pair(3, 5));
    edges[6].push_back(make_pair(5, 2));

    Dijkstra(1);

    for (int i = 1; i < NUM + 1; i++)
    {
        cout << cost[i] << " ";
    }

    return 0;
}