#include <iostream>
using namespace std;

int accSum;
int totalRest[1001];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M;
	long long result = 0;
	cin >> N >> M;

	//누적 합에 대한 나머지 개수 저장
	totalRest[0] = 1;
	for(int i = 1; i <= N; i++)
	{
		int tmp;
		cin >> tmp;
		accSum = (accSum + tmp) % M;
		totalRest[accSum]++;
	}

	//누적 나머지 개수에 대한 부분 구간 조합 구하기
	for (int i = 0; i < M; i++)
	{
		if(totalRest[i] >= 2)
			result += static_cast<long long>((totalRest[i] * 0.5) * (totalRest[i] - 1));
	}

	cout << result;
}