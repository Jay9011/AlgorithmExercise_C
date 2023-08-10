#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> wine;
vector<vector<int>> selected;
void taste(int N)
{
	// 첫 번째 잔에 대한 선택
	selected[1][1] = wine[1];

	for(int i = 2; i <= N; i++)
	{
		// 이번 잔을 마시지 않는 경우
		selected[i][0] = max({selected[i - 1][0], selected[i - 1][1], selected[i - 1][2]});
		// 연속 한 잔만 마시는 경우 (이번 잔부터 다시 시작하는 경우)
		selected[i][1] = selected[i - 1][0] + wine[i];
		// 연속 두 잔째 마시는 경우 (이전 잔을 마셨음)
		selected[i][2] = selected[i - 1][1] + wine[i];
	}
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	wine.resize(N + 1);
	selected.resize(N + 1, vector<int>(3));
	for(int i = 1; i <= N; i++)
		cin >> wine[i];

	taste(N);

	cout << max({selected[N][0], selected[N][1], selected[N][2]});
}