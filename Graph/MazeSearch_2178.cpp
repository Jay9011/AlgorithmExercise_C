#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

struct Coord
{
	int x;
	int y;
	int step;
};

int solveRtnStep(const vector<vector<bool>>& maze, Coord& start)
{
	vector<vector<bool>> visited(maze.size(), vector<bool>(maze[0].size(), false));
	queue<Coord> q;

	// 방향 설정
	int dx[4] = { -1, 1, 0, 0 };
	int dy[4] = { 0, 0, -1, 1 };

	// 시작 위치 설정
	visited[start.x][start.y] = true;
	q.push(start);

	// 탐색
	while (!q.empty())
	{
		Coord cur = q.front();
		q.pop();

		// 만약 도착했다면
		if (cur.x == maze.size() - 1 && cur.y == maze[0].size() - 1)
		{
			return cur.step + 1;
		}

		// 다음 미로 탐색
		for(int i = 0; i < 4; i++)
		{
			int nextX = cur.x + dx[i];
			int nextY = cur.y + dy[i];

			if(nextX >= 0 && nextX < maze.size() && nextY >= 0 && nextY < maze[0].size())
			{
				if(maze[nextX][nextY] && !visited[nextX][nextY]) // 미로가 1이고 방문하지 않았다면
				{
					Coord next = { nextX, nextY, cur.step + 1 }; // 다음 좌표와 거리 설정

					visited[nextX][nextY] = true;
					q.push(next);
				}
			}
		}
	}

	return 0;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<vector<bool>> maze(N, vector<bool>(M)); // 미로 만들기
	for (int i = 0; i < N; i++)
	{
		string input;
		cin >> input;
		for (int j = 0; j < M; j++)
		{
			maze[i][j] = (input[j] == '1');
		}
	}

	Coord start = { 0, 0, 0 };

	cout << solveRtnStep(maze, start);
}