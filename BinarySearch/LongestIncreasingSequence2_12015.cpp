#include <iostream>
#include <vector>
using namespace std;

inline void elemInLIS(vector<int>& InLIS, int num)
{
	int s = 0, e = InLIS.size() - 1;
	
	while(s < e)
	{
		int m = s + (e - s) / 2;

		if(num <= InLIS[m])
			e = m; // 중간의 요소가 num보다 크거나 같은 경우 위치를 유지합니다.
		else
			s = m + 1; // 중간의 요소가 num보다 작은 경우 오른쪽 탐색을 한다.
	}
	InLIS[e] = num;
}

int countLIS(const vector<int>& arr)
{
	if (arr.empty()) return 0;

	vector<int> lis;
	lis.push_back(arr.front());

	// 순차적으로 숫자를 가져와서 숫자를 비교한다.
	for(int i = 1; i < arr.size(); i++)
	{
		// 현재 요소가 LIS의 마지막 요소보다 작다면 이진 탐색을 시작합니다.
		if(arr[i] <= lis.back())
			elemInLIS(lis, arr[i]);
		else
			lis.push_back(arr[i]);
	}

	return lis.size();
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N);
	for(int i = 0; i < N; i++)
		cin >> arr[i];

	cout << countLIS(arr);
}