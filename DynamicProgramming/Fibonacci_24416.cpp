#include <iostream>
using namespace std;
int counter1 = 0;
int counter2 = 0;

int fibR(int n)
{
	if (n == 1 || n == 2)
	{
		counter1++;
		return 1;
	}

	return fibR(n - 1) + fibR(n - 2);
}

int fibD(int n)
{
	if (n == 1 || n == 2)
		return 1;

	int n1 = 1, n2 = 1, result = 1;
	for(int i = 3; i <= n; i++)
	{
		n1 = n2;
		n2 = result;
		result = n1 + n2;
		counter2++;
	}

	return result;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	fibR(N);
	fibD(N);

	cout << counter1 << ' ' << counter2;
}