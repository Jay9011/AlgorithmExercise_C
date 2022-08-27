#include <iostream>

using namespace std;

int Gcd(int a, int b)
{
    int c = a % b;
    while (c != 0)
    {
        a = b;
        b = c;
        c = a % b;
    }

    return b;
}

int Lcm(int a, int b)
{
    return (a * b) / Gcd(a, b);
}

int main()
{
    cout << Gcd(2, 5) << endl; // 1
    cout << Lcm(2, 5) << endl; // 10

    return 0;
}