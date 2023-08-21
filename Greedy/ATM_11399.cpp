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
		result += times[i] * (N - i); // ���� ���� �̿��Ͽ� ������ ��� �ο��� ���� �ð��� ���� �߰��Ѵ�.
	}

	cout << result;
}