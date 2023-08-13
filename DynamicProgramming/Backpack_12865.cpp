#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, K;
	cin >> N >> K;

	vector<pair<int, int>> thing(N);
	int value[100001] = { 0, };

	for(int i = 0; i < N; i++)
	{
		cin >> thing[i].first >> thing[i].second;
	}

	sort(thing.begin(), thing.end(), greater<pair<int, int>>());

	//모든 물품에 대해 탐색을 한다.
	for(int i = 0; i < N; i++)
	{
		//현재 무게까지의 최적 해를 탐색한다.
  		for(int j = K; j >= thing[i].first; j--)
		{
			//이전에 구한 최적해들에 대해서 현재 물품을 추가하거나 추가하지 않았을 때의 최적해를 다시 구한다.
			value[j] = max(value[j], value[j - thing[i].first] + thing[i].second);
		}
	}

	cout << value[K];
}