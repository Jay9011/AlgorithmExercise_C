#include <iostream>
#include <vector>
using namespace std;

int solve(const vector<int>& coins, const int target)
{
	vector<int> dp(target + 1, 0);
	dp[0] = 1; // 0원을 만들 수 있는 경우의 수를 1가지로 가정합니다.

	// 동전을 한 종류씩 사용하면서 계산합니다.
	for (const int& coin : coins)
	{
		// 현재 동전으로 만들 수 있는 경우의 수를 더해나갑니다.
		for (int v = coin; v <= target; v++)
		{
			if (v - coin >= 0)
				dp[v] += dp[v - coin]; // 현재 동전을 사용하지 않은 경우의 수 + 현재 동전을 사용하면 만들어지는 경우의 수
		}
	}

	return dp[target];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<int> coins(N);
	for(int i = 0; i < N; i++)
		cin >> coins[i];

	cout << solve(coins, K);
}