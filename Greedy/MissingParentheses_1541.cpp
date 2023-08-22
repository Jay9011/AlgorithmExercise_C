#include <iostream>
#include <sstream>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int result = 0;
	
	string exp;
	getline(cin, exp);

	stringstream ss(exp);
	bool isMinus = false;
	while (!ss.eof())
	{
		int num;
		ss >> num;
		
		// int�� �޾ƿ��鼭 ���� ������ ��� ���ڴ� �������� ����Ѵ�.
		if (num < 0) isMinus = true;
		if (isMinus && num > 0) num *= -1;

		result += num;
	}

	cout << result;
}