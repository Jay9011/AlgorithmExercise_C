#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> InitMatrix = { {1, 1}, {1, 0} };
constexpr int MOD = 1000000007;

void mulMatrix(vector<vector<int>>& A, const vector<vector<int>>& B)
{
	int _a = ((long long)A[0][0] * B[0][0] + (long long)A[0][1] * B[1][0]) % MOD;
	int _b = ((long long)A[0][0] * B[0][1] + (long long)A[0][1] * B[1][1]) % MOD;
	int _c = ((long long)A[1][0] * B[0][0] + (long long)A[1][1] * B[1][0]) % MOD;
	int _d = ((long long)A[1][0] * B[0][1] + (long long)A[1][1] * B[1][1]) % MOD;

	A[0][0] = _a;
	A[0][1] = _b;
	A[1][0] = _c;
	A[1][1] = _d;
}

void makeMatrix(vector<vector<int>>& A, long long n)
{
	if (n <= 1) return;

	makeMatrix(A, n / 2); // 절반으로 계속 나누다가

	mulMatrix(A, A); // (A^(1/2))^2 으로 계산합니다.

	if(n & 1)
	{
		// 만약 n이 홀수였다면, A * (A^(1/2))^2 으로 계산되어야 합니다.
		mulMatrix(A, InitMatrix);
	}
}

long long fibonacci(long long n)
{
	// 행렬 | 1 1 |   |F(n-1)|   |F(n-1)+F(n-2)|
	//      | 1 0 | x |F(n-2)| = |F(n-1)       |
	if (n == 0) return 0;
	else if (n == 1) return 1;

	vector<vector<int>> result = InitMatrix;
	makeMatrix(result, n - 1);

	return result[0][0];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	long long N;
	cin >> N;

	cout << fibonacci(N);
}