#include <iostream>

using namespace std;

void EratosSieve(int n)
{
    int* numbers = (int*)calloc(n + 1, sizeof(int));

    if (n == 0) return;
    
    for (int i = 0; i < n + 1; i++)
    {
        numbers[i] = i;
    }
    for (int i = 2; i < n + 1; i++)
    {
        if (numbers[i] == 0) continue;
        for (int j = 2 * i; j < n + 1; j += i)
        {
            numbers[j] = 0;
        }
    }
    for (int i = 1; i < n + 1; i++)
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
    EratosSieve(47);    // 1 ~ 47까지 출력

    return 0;
}