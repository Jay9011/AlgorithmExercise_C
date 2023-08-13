#include <iostream>
#include <vector>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

    string str1, str2;
    cin >> str1 >> str2;

    int len1 = str1.size() + 1;
    int len2 = str2.size() + 1;

    vector<vector<int>> table(len1, vector<int>(len2, 0));

    // LCS 알고리즘 구현
    for (int i = 1; i < len1; i++) 
    {
        for (int j = 1; j < len2; j++) 
        {
            if (str1[i - 1] == str2[j - 1]) 
            {
                // 문자가 같으면 (i-1, j-1)의 값에 1을 더함
                table[i][j] = table[i - 1][j - 1] + 1;
            }
            else 
            {
                // 문자가 다르면 (i, j-1)과 (i-1, j) 중 큰 값을 유지
                table[i][j] = max(table[i - 1][j], table[i][j - 1]);
            }
        }
    }

    cout << table[len1 - 1][len2 - 1];
}