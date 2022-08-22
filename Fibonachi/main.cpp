#include <iostream>

using namespace std;

int Fibonachi(int n)
{
    int first = 0;
    int second = 1;

    if (n == 0) return first;
    else if (n == 1) return second;

    int temp = 0;
    for (int i = 2; i <= n; i++)
    {
        temp = first + second;
        first = second;
        second = temp;
    }

    return temp;
}

int main()
{

    cout << Fibonachi(20) << endl;
    // 1 1 2 3 5 8 13 21 34 55 89 144 233 377 610 987 1597 2584 4181 6765(20)

    return 0;
}