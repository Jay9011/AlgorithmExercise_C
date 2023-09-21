#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, total_cost = 0;
	cin >> N >> M;

	vector<int> memorys(N);
	for (int i = 0; i < N; i++)
		cin >> memorys[i];

	vector<int> costs(N);
	for (int i = 0; i < N; i++)
	{
		cin >> costs[i];
		total_cost += costs[i];
	}

	vector<int> dp(total_cost + 1, 0);
	for (int i = 0; i < N; i++)
	{
		for (int j = total_cost; j >= costs[i]; j--)
		{
			dp[j] = max(dp[j], dp[j - costs[i]] + memorys[i]);
		}
	}

	for (int i = 0; i <= total_cost; i++)
	{
		if (dp[i] >= M)
		{
			cout << i;
			break;
		}
	}
}