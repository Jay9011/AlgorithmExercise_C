#include <iostream>
#include <cstring>
using namespace std;

int result[101][101][101];

int w(int a, int b, int c)
{
	if (a <= 0 || b <= 0 || c <= 0)
		return result[a + 50][b + 50][c + 50] = 1;

	if (result[a + 50][b + 50][c + 50] != -1)
		return result[a + 50][b + 50][c + 50];

	if (a > 20 || b > 20 || c > 20)
		return result[a + 50][b + 50][c + 50] = w(20, 20, 20);

	if(a < b && b < c)
		return result[a + 50][b + 50][c + 50] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);

	return result[a + 50][b + 50][c + 50] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	memset(result, -1, sizeof(result));

	int a, b, c;
	while(cin >> a >> b >> c)
	{
		if (a == -1 && b == -1 && c == -1) break;

		cout << "w(" << a << ", " << b << ", " << c<< ") = " << w(a, b, c) << '\n';
	}
}