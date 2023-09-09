#include <iostream>
#include <cmath>
using namespace std;

long long countLess(int N, long long num)
{
	long long cnt = 0;
	for (int i = 1; i <= N; i++)
	{
		cnt += min(num / i, (long long)N);
		if (num / i == 0) break;
	}
	return cnt;
}

long long searchK(int N, long long K)
{
	long long min = 1, max = (long long)N * N;

	while (min <= max)
	{
		long long mid = (min + max) / 2;

		if (K <= countLess(N, mid)) // mid보다 작거나 같은 수가 K보다 많다면
		{
			max = mid - 1;
		}
		else // mid보다 작거나 같은 수가 K보다 적다면
		{
			min = mid + 1;
		}
	}

	return min;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	long long k;
	cin >> N >> k;

	cout << searchK(N, k);
}
