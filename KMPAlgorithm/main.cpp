#include <iostream>

using namespace std;

void KMPPreprocess(char* pattern, int* shiftArr)
{
    const int size = strlen(pattern);
    int i = 0;
    int j = -1;

    shiftArr[i] = j;
    while (i < size)
    {
        while (0 <= j && pattern[i] != pattern[j])
        {
            j = shiftArr[j];
        }
        i++;
        j++;
        shiftArr[i] = j;
    }
}

int KMP(char* text, char* pattern)
{
    int i = 0, j = 0, count = 0;

    const int textSize = strlen(text);
    const int patternSize = strlen(pattern);

    int* shiftArr = (int*)calloc(patternSize + 1, sizeof(int));
    KMPPreprocess(pattern, shiftArr);

    while (i < textSize)
    {
        while (0 <= j && text[i] != pattern[j])
        {
            j = shiftArr[j];
        }
        i++;
        j++;
        if (j == patternSize)
        {
            return (i - patternSize);
        }
    }

    free(shiftArr);

    return -1;
}

int KMPFindCount(char* text, char* pattern)
{
    int i = 0, j = 0, count = 0;
    const int textSize = strlen(text);
    const int patternSize = strlen(pattern);

    int* shiftArr = (int*)calloc(patternSize + 1, sizeof(int));
    KMPPreprocess(pattern, shiftArr);

    while (i < textSize)
    {
        while (0 <= j && text[i] != pattern[j])
        {
            j = shiftArr[j];
        }
        i++;
        j++;
        if (j == patternSize)
        {
            count++;
            j = shiftArr[j];
        }
    }

    free(shiftArr);

    return count;
}

int main()
{
    char text[] = "ababacabacaabacaaba";
    char pattern[] = "abacaaba";

    cout << KMP(text, pattern) << endl;
    cout << KMPFindCount(text, pattern) << endl;

    return 0;
}