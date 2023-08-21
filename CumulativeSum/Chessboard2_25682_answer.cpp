#include <iostream>
using namespace std;

int N, M, K;
char board[2000][2000];
int accum[2000][2000];

int main() {
    cin >> N >> M >> K;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < M; j++)
        {
            cin >> board[i][j];
        }
    }

    // 원래 판에 대한 누적합 생성
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= M; j++)
        {
            accum[i][j] = accum[i - 1][j] + accum[i][j - 1] - accum[i - 1][j - 1];

            if  ( (i + j) % 2 == 0 && board[i - 1][j - 1] == 'B' 
                ||(i + j) % 2 == 1 && board[i - 1][j - 1] == 'W')
            {
                accum[i][j]++;
            }
        }
    }

    int result = 1e9;
    for (int i = K; i <= N; i++)
    {
        for (int j = K; j <= M; j++)
        {
            int temp = accum[i][j] - accum[i - K][j] - accum[i][j - K] + accum[i - K][j - K];
            result = min(result, min(temp, K * K - temp));
        }
    }

    cout << result << endl;
}
