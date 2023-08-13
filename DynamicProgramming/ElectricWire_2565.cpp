#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	vector<pair<int, int>> connected(N);
	vector<int> length(N, 1);

	for(int i = 0; i < N; i++)
	{
		cin >> connected[i].first >> connected[i].second;
	}

	//전봇대 A의 연결 순서로 정렬
	sort(connected.begin(), connected.end());

	//LIS로 계산
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (connected[i].second > connected[j].second)
				length[i] = max(length[i], length[j] + 1);
		}
	}

	cout << N - *max_element(length.begin(), length.end());
}