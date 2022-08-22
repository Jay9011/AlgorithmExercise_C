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

int main()
{
    char tmp[] = "test Text Code...";

    cout << strLen(tmp) << endl;

    return 0;
}