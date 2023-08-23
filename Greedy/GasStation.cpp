#include <iostream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	long long result = 0;
	cin >> N;

	int road[100000];
	int cities[100000];

	for (int i = 0; i < N - 1; i++)
		cin >> road[i];
	
	for (int i = 0; i < N; i++)
		cin >> cities[i];

	//���� �����ұ��� Ž���ϸ鼭 ������ ���ϰ�, ��θ� ���� �������� ������ ������Ų��.
	long long bestPrice = cities[0];
	for (int i = 0; i < N - 1; i++)
	{
		if (cities[i] < bestPrice)
			bestPrice = cities[i];

		result += bestPrice * road[i];
	}

	cout << result;
}