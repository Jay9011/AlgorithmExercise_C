#include <iostream>

using namespace std;

void EratosSieve(int n)
{
    int* numbers = (int*)calloc(n + 1, sizeof(int));

    for (int i = 0; i < n + 1; i++)
    {
        numbers[i] = i;
    }
    for (int i = 2; i < n; i++)
    {
        if (numbers[i] == 0) continue;
        for (int j = 2 * i; j < n; j += i)
        {
            numbers[j] = 0;
        }
    }
    // Ãâ·Â
    for (int i = 2; i < n; i++)
    {
        if (numbers[i] != 0)
        {
            cout << numbers[i] << " ";
        }
    }

    free(numbers);
}

int main()
{
    EratosSieve(50);

    return 0;
}