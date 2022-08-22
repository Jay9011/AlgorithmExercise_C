#include <iostream>

using namespace std;

// 문자열 길이 함수
int strLen(char* str)
{
    int counter = 0;

    while (str[counter] != '\0')
    {
        counter++;
    }

    return counter;
}

// 문자열 연결
void strCat(char* dest, unsigned int size, char* src)
{
    int destSize = strLen(dest);
    int srcSize = strLen(src);

    for (int i = 0; i <= srcSize; i++)
    {
        if (src[i] == '\0') break;
        if (size - 1 <= destSize + i)
        {
            dest[destSize + i] = '\0';
            break;
        }

        dest[destSize + i] = src[i];
    }
}

// 문자열 복사
void strCpy(char* dest, unsigned int size, char* src)
{
    if (size <= 1)
        return;

    for (int i = 0; i <= size - 1; i++)
    {
        dest[i] = src[i];

        if (src[i] == '\0') return;
    }

    dest[size - 1] = '\0';
    return;
}

// 문자열 비교
int strCmp(char* str1, char* str2)
{
    int str1Size = strLen(str1);
    int str2Size = strLen(str2);

    int minSize = str1Size <= str2Size ? str1Size : str2Size;

    for (int i = 0; i < minSize; i++)
    {
        if (str1[i] < str2[i]) return -1;
        else if (str1[i] > str2[i]) return 1;
    }

    if (str1Size < str2Size) return -1;
    else if (str1Size > str2Size) return 1;

    return 0;
}

int main()
{
    //char testText[19] = "test Text Code...";
    //char testPatt[] = "Text";
    //cout << strLen(testText) << endl;

    //strCat(testText, 19, testPatt);
    //cout << testText << endl;

    /*char emptyText[5];
    char copyText[] = "Test";

    strCpy(emptyText, 5, copyText);
    cout << emptyText << endl;*/


    char text1[] = "tee";
    char text2[] = "test";

    cout << strCmp(text1, text2) << endl;

    return 0;
}