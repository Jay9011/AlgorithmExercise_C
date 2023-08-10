#include <iostream>
#include <vector>
using namespace std;
vector<int> seq;
vector<vector<int>> length;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	seq.resize(N);
	length.resize(N, vector<int>(2, 1));

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	//i를 마지막으로 하는 제일 긴 수열을 계산한다.
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (seq[i] > seq[j])
				length[i][0] = max(length[i][0], length[j][0] + 1);
		}
	}

	//i를 시작으로 하는 제일 긴 수열을 계산한다.
	for (int i = N - 1; i >= 0; i--)
	{
		for (int j = N - 1; j > i; j--)
		{
			if (seq[i] > seq[j])
				length[i][1] = max(length[i][1], length[j][1] + 1);
		}
	}

	int lengthMax = 0;
	for(int i = 0; i < N; i++)
	{
		lengthMax = max(lengthMax, length[i][0] + length[i][1] - 1);
	}

	cout << lengthMax;
}