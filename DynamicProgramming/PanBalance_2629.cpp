#include <iostream>
#include <vector>
using namespace std;

void solve(const vector<int>& weights, vector<bool>& OutArr)
{
	OutArr[0] = true;

	// 무게가 작은 추부터 정렬되어 들어있기 때문에 차례대로 가능한 무게들을 채워나간다.
	for(const int& w : weights)
	{
		vector<bool> temp(OutArr); // 현재 상태를 임시로 저장

		for (int i = 0; i < OutArr.size(); i++)
		{
			if (OutArr[i]) // 현재 무게가 가능하다면
			{
				if(i + w < OutArr.size())
					temp[i + w] = true; // 모든 무게추가 같은 쪽에 있는 경우

				if(abs(i - w) >= 0)
					temp[abs(i - w)] = true; // 현재 무게추를 반대쪽에 놓았을 때
			}
		}

		OutArr.swap(temp); // 현재 상태를 저장
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N, M, MAX_W = 0;

	cin >> N;
	vector<int> weights(N); // 무게추 초기화
	for (int i = 0; i < N; i++)
	{
		cin >> weights[i];
		MAX_W += weights[i];
	}

	vector<bool> possible(MAX_W + 1, false); // 가능한 무게들을 저장할 벡터
	solve(weights, possible);

	cin >> M;
	while (M--)
	{
		int bead;
		cin >> bead;
		if (bead <= MAX_W && possible[bead])
			cout << "Y ";
		else
			cout << "N ";
	}
}