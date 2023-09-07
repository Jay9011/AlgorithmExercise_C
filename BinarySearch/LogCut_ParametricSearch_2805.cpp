#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 최소한의 길이로 만족할 수 있는 길이를 찾아야 한다.
long long cuttingLog(const vector<int>& Logs, int height)
{
	long long result = 0;
	for (const int& log : Logs)
		if (log > height) result += (log - height);

	return result;
}

int findLength(const vector<int>& Logs, int need)
{
	int min = 1, max = *max_element(Logs.begin(), Logs.end());
	int result = 0;

	while(min <= max)
	{
		int mid = (min + max) / 2; // 통나무의 높이를 설정한다.
		long long tmp = cuttingLog(Logs, mid);

		if(tmp < need)
		{
			max = mid - 1; // mid로 자른 길이가 원하는 길이가 안되는 경우 왼쪽으로 이진 탐색을 한다.
		}
		else
		{
			result = mid;
			min = mid + 1; // mid로 자른 길이가 원하는 길이를 넘는 경우 오른쪽으로 이진 탐색을 한다.
		}
	}
	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, H;
	cin >> N >> H;

	vector<int> Logs(N);
	for (int i = 0; i < N; i++)
		cin >> Logs[i];

	cout << findLength(Logs, H);
}