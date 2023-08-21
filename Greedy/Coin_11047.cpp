#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K, count = 0;
	cin >> N >> K;

	vector<int> coin(N);
	for (int i = N - 1; i >= 0; i--)
		cin >> coin[i];

	//가치가 큰 동전부터 계산한다.
	int remain = K;
	for (int i = 0; i < N; i++)
	{
		int quot = remain / coin[i];
		count += quot;
		remain -= coin[i] * quot;

		if (remain == 0) break;
	}

	cout << count;
}