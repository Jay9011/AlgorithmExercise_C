#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, max = 0;
	cin >> N;

	vector<int> question(N);
	vector<long long> sequence;
	
	for(int i = 0; i < N; i++)
	{
		cin >> question[i];
		if (max < question[i]) max = question[i];
	}

	//초기화
	sequence.resize(max >= 6 ? max + 1 : 6);
	sequence[0] = 0;
	sequence[1] = 1;
	sequence[2] = 1;
	sequence[3] = 1;
	sequence[4] = 2;
	sequence[5] = 2;

	//점화식: P(N-1) + P(N-5) = P(N)
	for(int i = 6; i <= max; i++)
		sequence[i] = sequence[i - 1] + sequence[i - 5];

	//출력
	for (const int i : question)
		cout << sequence[i] << '\n';
}