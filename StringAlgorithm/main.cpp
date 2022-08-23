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

    if (srcSize <= 1) return;
    if (destSize >= size) return;

    for (int i = 0; i <= srcSize; i++)
    {
        dest[destSize + i] = src[i];

        if (src[i] == '\0') break;
        else if (size - 1 <= destSize + i)
        {
            dest[destSize + i] = '\0';
            break;
        }
    }
}

// 문자열 복사
void strCpy(char* dest, unsigned int size, char* src)
{
    if (size <= 1) return;

    for (int i = 0; i <= size; i++)
    {
        dest[i] = src[i];

        if (src[i] == '\0') break;
        else if (size - 1 <= i)
        {
            dest[i] = '\0';
            break;
        }
    }
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
    char testText[18] = "test Text Code...";
    char testText2[19] = "test Text Code...";
    char testText3[30] = "test Text Code...";
    char testPatt[] = "Text";
    char emptyText[3];
    char emptyText2[5];
    char emptyText3[10] = "Empty? No";
    char copyText[] = "Test";
    char text1[] = "tee";
    char text2[] = "test";
    char text3[] = "test3";

    cout << strLen(testText) << endl;

    strCat(testText, 18, testPatt);
    strCat(testText2, 19, testPatt);
    strCat(testText3, 30, testPatt);
    cout << testText << endl;
    cout << testText2 << endl;
    cout << testText3 << endl;
    
    strCpy(emptyText, 3, copyText);
    strCpy(emptyText2, 5, copyText);
    strCpy(emptyText3, 10, copyText);
    cout << emptyText << endl;
    cout << emptyText2 << endl;
    cout << emptyText3 << endl;

    cout << strcmp(text1, text2) << " : " << strCmp(text1, text2) << endl;
    cout << strcmp(text2, text2) << " : " << strCmp(text2, text2) << endl;
    cout << strcmp(text3, text2) << " : " << strCmp(text3, text2) << endl;

    return 0;
}