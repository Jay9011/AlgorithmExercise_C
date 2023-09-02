#include <iostream>
#include <vector>
using namespace std;

long long result;

void solve(const vector<int>& arr, int s, int l, const int& e)
{

	for(int i = 0; i < (e - l); i++)
	{
		solve(arr, s + i, l - 1, e);
	}

	int minSize = arr[s];
	for(int i = s + 1; i < l; i++)
	{
		if (minSize > arr[i]) minSize = arr[i];
	}
	if (result < (minSize * l)) result = (minSize * l);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	while (true)
	{
		cin >> N;
		if (!N) return 0;

		vector<int> nums(N, 0);

		for(int i = 0; i < N; i++)
		{
			cin >> nums[i];
		}

		solve(nums, 0, N, N);
	}
}