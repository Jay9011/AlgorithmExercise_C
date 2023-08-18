#include <iostream>
using namespace std;

int sum[1025][1025];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	// 2차원 정수 입력 받으며 합산하기
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			cin >> sum[i][j];
			sum[i][j] += sum[i][j - 1] + sum[i-1][j] - sum[i-1][j-1];
		}
	}

	//범위 계산
	while (M--)
	{
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << (sum[x2][y2] - sum[x1 - 1][y2] - sum[x2][y1 - 1] + sum[x1-1][y1 - 1]) << '\n';
	}
}