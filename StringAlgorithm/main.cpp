#include <iostream>

using namespace std;

// ���ڿ� ���� �Լ�
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