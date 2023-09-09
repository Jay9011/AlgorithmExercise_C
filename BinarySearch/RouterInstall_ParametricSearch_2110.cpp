#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool check(vector<int>& houses, int routerCnt, int m)
{
	int cnt = 1;
	int last_house = houses[0];

	for(int i = 1; i < houses.size(); i++)
	{
		if(houses[i] - last_house >= m)
		{
			cnt++;
			last_house = houses[i];
		}
	}

	return routerCnt <= cnt;
}

int maxLength(vector<int>& houses, int routerCnt)
{
	int result = 0;
	int min = 1;
	int max = houses.back() - houses.front();

	while (min <= max)
	{
		int mid = (min + max) / 2;
		if(check(houses, routerCnt, mid))
		{
			result = mid;
			min = mid + 1;
		}
		else
		{
			max = mid - 1;
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, C;
	cin >> N >> C;

	vector<int> houses(N);
	for (int i = 0; i < N; i++)
		cin >> houses[i];

	sort(houses.begin(), houses.end());

	cout << maxLength(houses, C);
}