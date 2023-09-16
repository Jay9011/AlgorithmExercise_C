#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX = 2000000000;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> sizes(N + 1);
	vector<vector<int>> dp(N, vector<int>(N));

	for(int i = 0; i < N; i++)
		cin >> sizes[i] >> sizes[i + 1];

	// 행렬을 2개부터 여러 방법으로 결합해 풀어본다.
	for(int len = 2; len <= N; len++)
	{
		for(int i = 0; i <= N - len; i++)
		{
			int j = i + len - 1;
			dp[i][j] = MAX;

			// i번째 행렬부터 j번째 행렬까지 곱하는 방법 중 어느 순서로 결합하는지에 따른 최소값을 찾아서 저장
			for(int k = i; k < j; k++)
			{
				int cost = sizes[i] * sizes[k + 1] * sizes[j + 1];
				dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + cost);
			}
		}
	}

	cout << dp[0][N - 1] << '\n';
}