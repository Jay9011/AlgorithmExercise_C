#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
	const char* num1 = "123";
	const char* num2 = "3.141592";

	int num = atoi(num1);
	float fnum = atof(num2);

	printf("num1: %d\n", num);
	printf("num2: %f\n", fnum);
}