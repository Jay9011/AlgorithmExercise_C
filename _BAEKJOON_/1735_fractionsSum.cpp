#include <cstdio>

int GCD(int a, int b)
{
	while (b != 0)
	{
		int r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int main()
{
	int c1, p1, c2, p2, c, p;
	scanf("%d %d %d %d", &c1, &p1, &c2, &p2);

	p = p1 * p2;
	c = c1 * p2 + c2 * p1;

	int gcd = GCD(c, p);

	printf("%d %d", c / gcd, p / gcd);
}