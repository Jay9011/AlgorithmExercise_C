#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Info // 현재 위치와 주사위를 굴린 횟수를 저장
{
	int pos;
	int cnt;
};

void makeBoard(vector<int>& board)
{
	// 사다리나 뱀이 있는 칸 설정
	int N, M;
	cin >> N >> M;
	for (int i = 0; i < N + M; i++)
	{
		int start, end;
		cin >> start >> end;
		board[start] = end;
	}
}

int search(const vector<int>& board)
{
	queue<Info> q;
	// 방문 여부를 저장한다.
	// 뱀 칸을 이용해 이전 칸으로 이동하면 어차피 최소 횟수가 아니기 때문에 반복 계산할 필요가 없다.
	vector<bool> visited(101, false);

	// 첫 번째 칸에서 시작
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty())
	{
		Info cur = q.front();
		q.pop();

		// 만약 도착했다면 종료
		if(cur.pos == 100)
		{
			return cur.cnt;
		}

		// 모든 주사위의 경우의 수를 탐색
		for(int dice = 1; dice <= 6; dice++)
		{
			int nextPos = cur.pos + dice;

			// 범위를 벗어나거나 방문했다면
			if(nextPos > 100 || visited[nextPos])
				continue;

			// 사다리가 있다면
			if (board[nextPos] != 0)
				nextPos = board[nextPos]; // 사다리를 타고 이동

			visited[nextPos] = true;
			q.push({ nextPos, cur.cnt + 1 });
		}
	}

	return -1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<int> board(101);
	makeBoard(board);

	cout << search(board);
}