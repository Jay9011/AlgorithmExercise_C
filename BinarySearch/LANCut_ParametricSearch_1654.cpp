#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int cuttingLAN(const vector<int>& LANs, long long size)
{
	int result = 0;
	for(const int& LAN : LANs)
	{
		result += LAN / size;
	}
	return result;
}

long long findLength(const vector<int>& LANs, int n)
{
	long long min = 1, max = *max_element(LANs.begin(), LANs.end());
	long long result = 0;

	while(min <= max)
	{
		long long mid = (min + max) / 2;
		int num = cuttingLAN(LANs, mid);

		if(num < n)
		{
			max = mid - 1;
		}
		else
		{
			result = mid;
			min = mid + 1;
		}
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int K, N;
	cin >> K >> N;

	vector<int> LANs(K);
	for (int i = 0; i < K; i++)
		cin >> LANs[i];

	cout << findLength(LANs, N);
}