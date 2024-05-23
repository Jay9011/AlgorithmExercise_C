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

int LCM(int a, int b)
{
	return (a * b) / GCD(a, b);
}

int main()
{
	int num1 = 12;
	int num2 = 18;

	int resultGCD = GCD(num1, num2);
	int resultLCM = LCM(num1, num2);

	printf("최대 공약수: %d \n", resultGCD);
	printf("최소 공배수: %d \n", resultLCM);
}