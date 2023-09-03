#include <iostream>
#include <vector>
using namespace std;

long long solve(const vector<int>& arr, int s, int e)
{
	// 기저사례: 하나의 직사각형의 크기
	if (s == e - 1) return arr[s];

	// 분할: 두 개의 부분으로 나눈다.
	int m = (s + e) / 2;

	// 정복: 두 부분 중 큰 사각형을 찾는다.
	long long result = max(solve(arr, s, m), solve(arr, m, e));

	// 결합: 두 부분을 결합한 후, 중앙에서 시작한 직사각형의 넓이 중 최대값을 찾는다.
	int l = m, r = m;
	long long height = arr[m];
	while(r - l < e - s)
	{
		// 경계까지 확장
		long long lp = s < l ? arr[l - 1] : -1;
		long long rp = r < e ? arr[r] : -1;

		// 좀 더 큰 영역으로 확장
		if(lp >= rp)
		{
			height = min(height, lp);
			l--;
		}
		else
		{
			height = min(height, rp);
			r++;
		}

		result = max(result, height * (r - l));
	}

	return result;
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

		cout << solve(nums, 0, N) << '\n';
	}
}