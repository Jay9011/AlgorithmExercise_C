#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int q;
	string str;
	cin >> str;
	cin >> q;

	vector<vector<int>> alphabet(str.length() + 1, vector<int>(26, 0));

	//누적합 배열 계산
	for (int i = 0; i < str.length(); i++)
	{
		for (int j = 0; j < 26; j++)
		{
			alphabet[i + 1][j] = alphabet[i][j]; //기존 알파벳 누적합 유지
		}
		alphabet[i + 1][str[i] - 'a']++; //추가된 알파벳 누적합 추가
	}

	while (q--)
	{
		char alpha;
		int s, e;
		cin >> alpha >> s >> e;
		//해당 알파벳의 누적합 구간 출력
		cout << alphabet[e + 1][alpha - 'a'] - alphabet[s][alpha - 'a'] << '\n';
	}
}