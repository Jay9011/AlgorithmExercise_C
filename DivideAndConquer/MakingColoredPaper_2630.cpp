#include <iostream>
using namespace std;

bool paper[128][128];
int blueTotal;
int whiteTotal;
struct coord
{
	int x;
	int y;

	coord operator+(const coord& B) const
	{
		return { B.x + x, B.y + y };
	}
	coord operator-(const coord& B) const
	{
		return { B.x - x, B.y - y };
	}
	coord operator/(const int& n) const
	{
		return { x / n, y / n };
	}
};

void dividePaper(coord start, coord end)
{
	if((end - start).x == 1 || (end - start).y == 1)
	{
		if (paper[start.x][start.y]) blueTotal += 1;
		else whiteTotal += 1;

		return;
	}

	bool check = paper[start.x][start.y];
	for(int i = start.x; i < end.x; i++)
	{
		for(int j = start.y; j < end.y; j++)
		{
			if(check != paper[i][j])
			{
				coord mid = (start + end) / 2;
				dividePaper(start, mid);
				dividePaper({ mid.x, start.y }, { end.x, mid.y });
				dividePaper({ start.x, mid.y }, { mid.x, end.y });
				dividePaper(mid, end);

				return;
			}
		}
	}

	if (check) blueTotal += 1;
	else whiteTotal += 1;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			cin >> paper[i][j];
		}
	}

	dividePaper({ 0, 0 }, { N, N });

	cout << whiteTotal << '\n' << blueTotal;
}