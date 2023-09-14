#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX = 2000000000;

void solve(int K, vector<int>& sumy, vector<vector<int>>& dp)
{
	// K가 2개인 부분 문제부터 차근차근 해결한다.
	for (int len = 2; len <= K; len++)
	{
		for (int i = 0; i <= K - len; i++)
		{
			int j = i + len - 1;

			// 부분 문제를 위해 중간 크기인 m을 잡아야 한다.
			for (int m = i; m < j; m++)
			{
				int cost = dp[i][m] + dp[m + 1][j] + sumy[j] - (i > 0 ? sumy[i - 1] : 0);
				dp[i][j] = min(dp[i][j], cost);
			}
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int T;
	cin >> T;
	while(T--)
	{
		int K;
		cin >> K;

		vector<int> sizes(K);
		vector<int> sumy(K);
		vector<vector<int>> dp(K, vector<int>(K, MAX));

		for(int i = 0; i < K; i++)
		{
			cin >> sizes[i];
			sumy[i] = sizes[i] + (i > 0 ? sumy[i - 1] : 0);
			dp[i][i] = 0;
		}

		solve(K, sumy, dp);
		cout << dp[0][K - 1] << '\n';
	}
}