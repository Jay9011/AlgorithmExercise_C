#include <iostream>
#include <cmath>
using namespace std;

long long solve(long long A, long long B, long long C)
{
	if (!B) return 1;

	// A ^ B % C
	// B가 홀수: (A * A ^ (B-1/2))^2 % C
	// B가 짝수: (A ^ (B/2))^2 % C
	long long half = solve(A, B / 2, C);
	if (B & 1)
		return (half * half % C * A) % C;
	else
		return (half * half) % C;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int A, B, C;
	cin >> A >> B >> C;

	cout << solve(A, B, C);
}