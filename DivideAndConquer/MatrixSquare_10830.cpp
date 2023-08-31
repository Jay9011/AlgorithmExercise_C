#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> A;
constexpr int MOD = 1000;

void initMatrix(int n)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < n; j++)
			cin >> A[i][j];
}

vector<vector<int>> mulMatrix(const vector<vector<int>>& mat1, const vector<vector<int>>& mat2, int size)
{
	vector<vector<int>> result(size, vector<int>(size, 0));

	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			for(int k = 0; k < size; k++)
			{
				result[i][j] += (mat1[i][k] * mat2[k][j]) % MOD;
			}
			result[i][j] %= MOD;
		}
	}

	return result;
}

vector<vector<int>> dividePow(int n, int size)
{
	if (n == 1) return A;

	// 분할 정복
	vector<vector<int>> halfMat = dividePow(n / 2, size);

	if(n & 1) // n이 홀수인 경우
	{
		return mulMatrix(A, mulMatrix(halfMat, halfMat, size), size);
	}
	else
	{
		return mulMatrix(halfMat, halfMat, size);
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, B;
	cin >> N >> B;

	A.resize(N, vector<int>(N));
	initMatrix(N);

	A = dividePow(B, N);

	// 출력
	for(vector<int>& v : A)
	{
		for(const int& n : v)
		{
			cout << n << ' ';
		}
		cout << '\n';
	}
}