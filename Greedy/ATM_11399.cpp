#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, result = 0;
	cin >> N;

	vector<int> times(N);
	for (int i = 0; i < N; i++)
		cin >> times[i];

	sort(times.begin(), times.end());

	for (int i = 0; i < N; i++)
	{
		result += times[i] * (N - i); // 누적 합을 이용하여 나머지 대기 인원에 현재 시간을 전부 추가한다.
	}

	cout << result;
}