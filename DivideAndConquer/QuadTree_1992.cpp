#include <iostream>
using namespace std;

int img[64][64];

struct coord
{
	int x;
	int y;
};

coord getMid(const coord& A, const coord& B)
{
	return { (A.x + B.x) / 2, (A.y + B.y) / 2 };
}

void solve(const coord& start, const coord& end)
{
	if((end.x - start.x) == 1 || end.y - start.y == 1)
	{
		cout << img[start.x][start.y];
		return;
	}

	//이미지의 데이터를 확인한다.
	int check = img[start.x][start.y];
	for(int i = start.x; i < end.x; i++)
	{
		for(int j = start.y; j < end.y; j++)
		{
			//데이터가 서로 다르면 다른 값으로 압축해야 한다.
			if(check != img[i][j])
			{
				cout << '(';

				coord mid = getMid(start, end);
				solve(start, mid);
				solve({ start.x, mid.y }, { mid.x, end.y });
				solve({ mid.x, start.y }, { end.x, mid.y });
				solve(mid, end);

				cout << ')';
				return;
			}
		}
	}

	cout << check;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		string s;
		cin >> s;
		for(int j = 0; j < N; j++)
		{
			img[i][j] = s[j] - '0';
		}
	}

	solve({ 0, 0 }, { N, N });
}