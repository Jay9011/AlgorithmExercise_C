#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
		return a.first < b.first;

	return a.second < b.second;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, count = 0;
	cin >> N;

	vector<pair<int, int>> times(N);

	for (int i = 0; i < N; i++)
		cin >> times[i].first >> times[i].second;

	sort(times.begin(), times.end(), compare);

	int endTime = 0;
	for (pair<int, int>& time : times)
	{
		if (time.first >= endTime)
		{
			endTime = time.second;
			count++;
		}
	}

	cout << count;
}