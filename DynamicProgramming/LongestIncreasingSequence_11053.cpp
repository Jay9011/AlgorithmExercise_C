#include <iostream>
#include <vector>
using namespace std;
vector<int> seq;
vector<int> length;
int maxLength = 1;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;
	seq.resize(N);
	length.resize(N, 1);

	for (int i = 0; i < N; i++)
		cin >> seq[i];

	//i까지의 수를 마지막으로 가지는 수열의 길이를 저장
	for (int i = 1; i < N; i++)
	{
		for (int j = 0; j < i; j++)
		{
			//j까지를 마지막으로 하는 수열 다음에 i가 올 수 있는 경우 중 가장 큰 경우의 수를 저장한다.
			if (seq[i] > seq[j])
				length[i] = max(length[i], length[j] + 1);
		}
		if (length[i] > maxLength) maxLength = length[i];
	}

	cout << maxLength;
}