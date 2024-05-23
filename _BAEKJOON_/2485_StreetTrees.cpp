#include <cstdio>
#include <cstdlib>

// 1. 같은 간격
// 2. 가능한 한 적은 수

// 기존 가로수가 (1, 3, 7, 13)의 위치에 있다면 (5, 9, 11)의 위치에 추가하면 같은 간격
// 기존 가로수가 (2, 6, 12, 18)에 있다면 (4, 8, 10, 14, 16)에 가로수를 추가해야 같은 간격

int GCD(int a, int b)
{
	while (b != 0)
	{
		int tmp = a % b;
		a = b;
		b = tmp;
	}

	return a;
}

int main()
{
	int num = 0;
	int trees[100000] = { 0, };
	int distance = 0;
	
	scanf("%d", &num);

	for (int i = 0; i < num; i++)
	{
		scanf("%d", &trees[i]);
	}

	// 첫 트리 사이의 거리를 저장한다.
	distance = trees[1] - trees[0];

	// 이후, 각 트리 사이의 간격에 대한 최소 공배수를 찾는다.
	for (int i = 2; i < num; i++)
	{
		distance = GCD(distance, trees[i] - trees[i - 1]);
	}

	// 필요한 나무 수는 심어야 할 거리에 심어야 할 나무의 수를 구한 뒤, 현재 심어진 나무 수를 빼면 된다.
	int totalTrees = ((trees[num - 1] - trees[0]) / distance) + 1;
	int needTrees = totalTrees - num;

	printf("%d", needTrees);
}