#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	vector<int> arr(N >= 3 ? N : 3);
	arr[0] = 1; //1
	arr[1] = 2; //00, 11

	for(int i = 2; i < N; i++)
	{
		arr[i] = (arr[i - 2] + arr[i - 1]) % 15746;
		// arr[2] = 100 [i-2 + "00"], 001, 111 [i-1 + "1"]
	}

	cout << arr[N - 1];
}