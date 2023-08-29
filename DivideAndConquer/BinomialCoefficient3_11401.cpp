#include <iostream>
using namespace std;

const int MOD = 1000000007;

long long power(long long a, long long b)
{
    if (b == 0) return 1;

    //A^B % MOD 를 구한다.
    long long half = power(a, b / 2);
    if (b & 1) 
        return half * half % MOD * a % MOD;
    else 
        return half * half % MOD;
}

long long factorial(int n)
{
    long long result = 1;
    for (int i = 1; i <= n; i++)
    {
        result = (result * i) % MOD;
    }
    return result;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    // 페르마의 소정리를 이용한 나머지 분배
    // (N! % MOD * K!^-1 % MOD * (N-K)!^-1 % MOD)
    long long numer = factorial(N) % MOD;
    long long denomin = (factorial(K) * factorial(N - K)) % MOD;
    long long inverse_denomin = power(denomin, MOD - 2);

    cout << (numer * inverse_denomin) % MOD;
}
