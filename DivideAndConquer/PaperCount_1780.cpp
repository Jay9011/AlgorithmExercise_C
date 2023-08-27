#include <iostream>
using namespace std;

int paper[2187][2187];
int numCnt[3];

void solve(int x, int y, int size)
{
	//데이터를 확인한다.
	int check = paper[x][y];
	for (int i = x; i < x + size; i++)
	{
		for (int j = y; j < y + size; j++)
		{
			if (check != paper[i][j])
			{
				//데이터가 서로 다르면 한 번 더 9칸으로 잘라야 한다.
				int nextSize = size / 3;
				for(int _x = 0; _x < 3; _x++)
				{
					for(int _y = 0; _y < 3; _y++)
					{
						solve(x + _x * nextSize, y + _y * nextSize, nextSize);
					}
				}
				return;
			}
		}
	}

	numCnt[check + 1]++;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}

	solve(0, 0, N);

	for(const int& n : numCnt)
		cout << n << '\n';
}