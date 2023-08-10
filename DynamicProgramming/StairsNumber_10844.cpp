#include <iostream>
using namespace std;
constexpr int MOD = 1e9;
int stairs[101][10];
void stairNumCnt(int N)
{
	//길이가 1인 경우 초기화
	for(int i = 1; i <= 9; i++)
		stairs[1][i] = 1;

	//길이가 2 부터 N 까지 초기화
	for(int i = 2; i <= N; i++)
	{
		for(int j = 0; j <= 9; j++)
		{
			if (j == 0) 
				stairs[i][j] = stairs[i - 1][1] % MOD; //끝이 0으로 끝나는 경우 1밖에 못온다.
			else if (j == 9) 
				stairs[i][j] = stairs[i - 1][8] % MOD; //역시 끝이 9로 끝나는 경우 8밖에 못온다.
			else
				stairs[i][j] = (stairs[i - 1][j - 1] + stairs[i - 1][j + 1]) % MOD;
		}
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	stairNumCnt(N);

	int sum = 0;
	for (int i = 0; i <= 9; i++)
		sum = (sum + stairs[N][i]) % MOD;

	cout << sum;
}