#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

#define NUM 6
#define INF 2000000000

vector<pair<int, int>> edges[NUM + 1];
int cost[NUM + 1];

void Dijkstra(int start)
{
    cost[start] = 0;

    priority_queue<pair<int, int>> nodes;
    nodes.push(make_pair(start, 0));

    while (!nodes.empty())
    {
        int current = nodes.top().first;
        int currentDist = -nodes.top().second;
        nodes.pop();

        if (cost[current] < currentDist) continue;
        for (int i = 0; i < edges[current].size(); i++)
        {
            int next = edges[current][i].first;
            int nextDist = edges[current][i].second + currentDist;

            if (nextDist < cost[next])
            {
                cost[next] = nextDist;
                nodes.push(make_pair(next, -nextDist));
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
        cout << cost[i] << " "; // 0 2 3 1 2 4
    }

    return 0;
}