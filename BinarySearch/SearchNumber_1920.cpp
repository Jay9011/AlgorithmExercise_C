#include <iostream>
#include <algorithm>
using namespace std;

int nums[100000];

bool findNums(int n, int s, int e)
{
	if (s >= e) return false;

	int m = s + (e - s) / 2;

	if (nums[m] == n) return true;

	if (nums[m] < n)
		return findNums(n, m + 1, e);
	else
		return findNums(n, s, m);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, tmp;
	cin >> N;

	for (int i = 0; i < N; i++)
		cin >> nums[i];

	sort(nums, nums + N);

	cin >> M;
	for (int i = 0; i < M; i++)
	{
		cin >> tmp;
		cout << findNums(tmp, 0, N) << '\n';
	}
}