#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	vector<int> nums(N);
	vector<int> prefixSum(N + 1, 0);

	//구간합 미리 구해두기
	for(int i = 0; i < N; i++)
	{
		cin >> nums[i];
		prefixSum[i + 1] = prefixSum[i] + nums[i];
	}

	while(M--)
	{
		int i, j;
		cin >> i >> j;
		//두 구간의 구간합 차 사용
		cout << prefixSum[j] - prefixSum[i-1] << '\n';
	}
}