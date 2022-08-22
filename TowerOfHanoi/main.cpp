#include <iostream>

using namespace std;

void Hanoi(int num, char from, char to, char temp)
{
    if (num < 1) return;

    Hanoi(num - 1, from, temp, to);
    cout << "��ũ" << num << "�� " << from << "���� " << to << "�� �ű�ϴ�." << endl;
    Hanoi(num - 1, temp, to, from);
}

int main()
{
    Hanoi(10, 'A', 'B', 'C');

    return 0;
}