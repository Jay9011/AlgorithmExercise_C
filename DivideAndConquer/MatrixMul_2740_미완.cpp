#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> result;

int initMatrix(vector<vector<int>>& Matrix, int N, int M)
{
	// 패딩을 위해 가장 가까운 2의 거듭제곱 찾기
	int newSize = 1;
	while (newSize < N || newSize < M) newSize *= 2;


	Matrix.resize(newSize, vector<int>(newSize, 0)); // 패딩된 크기로 행렬 초기화

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < M; j++)
		{
			cin >> Matrix[i][j];
		}
	}

	// 실제 사용할 행렬 크기 업데이트
	return newSize;
}

// 행렬 곱셈 함수
void matrixMultiply(vector<vector<int>>& A, vector<vector<int>>& B, int posX, int posY, int size)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			for (int k = 0; k < size; k++)
			{
				result[posX + i][posY + j] += A[posX + i][posY + k] * B[posX + k][posY + j];
			}
		}
	}
}

// 분할 정복 행렬 곱셈 함수
void solve(vector<vector<int>>& A, vector<vector<int>>& B, int posX, int posY, int size)
{
	if (size <= 2) // 크기가 2*2인 행렬일 때 곱함
	{
		matrixMultiply(A, B, posX, posY, size);
		return;
	}

	// 4개의 부분 문제로 분할하여 해결
	int newSize = size / 2;
	solve(A, B, posX, posY, newSize);
	solve(A, B, posX, posY + newSize, newSize);
	solve(A, B, posX + newSize, posY, newSize);
	solve(A, B, posX + newSize, posY + newSize, newSize);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	vector<vector<int>> A, B;
	int N, M, newN, newM;

	cin >> N >> M;
	newN = initMatrix(A, N, M);

	cin >> N >> M;
	newM = initMatrix(B, N, M);

	result.resize(newN, vector<int>(newM, 0));
	solve(A, B, 0, 0, newM);

	for (const vector<int>& v : result)
	{
		for (const int& n : v)
		{
			cout << n << ' ';
		}
		cout << '\n';
	}
}