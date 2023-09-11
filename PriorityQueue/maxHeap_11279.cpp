#include <iostream>
using namespace std;

class myHeap
{
public:
	myHeap(int n)
	{
		arr = static_cast<int*>(malloc(sizeof(int) * n));
		reserve_size = n;
	}
	~myHeap()
	{
		free(arr);
	}

	void push(int num)
	{
		// 0 이외의 숫자가 들어온 겨우
		if(num != 0)
		{
			if (current_size + 1 >= reserve_size) return;

			arr[current_size++] = num;

			int child = current_size - 1;
			int parent = (child - 1) / 2;

			while (parent >= 0 && arr[parent] < arr[child])
			{
				arr[parent] ^= arr[child] ^= arr[parent] ^= arr[child];
				child = parent;
				parent = (child - 1) / 2;
			}
		}
		// 0이 들어온 경우
		else
		{
			if (current_size == 0)
			{
				cout << 0 << '\n';
				return;
			}

			cout << arr[0] << '\n';

			// 마지막 원소와 바꿈
			arr[0] = arr[--current_size];

			int parent = 0;

			while (parent < current_size)
			{
				int lchild = 2 * parent + 1;
				int rchild = lchild + 1;
				int child = -1;

				// 왼쪽 자식과 오른쪽 자식 중 더 큰 값을 선택
				if(lchild < current_size && rchild < current_size)
				{
					if (arr[lchild] > arr[rchild])
						child = lchild;
					else
						child = rchild;
				}
				else if(lchild < current_size)
				{
					child = lchild;
				}

				if(child != -1 && arr[parent] < arr[child])
				{
					arr[parent] ^= arr[child] ^= arr[parent] ^= arr[child];

					parent = child;
				}
				else
				{
					break;
				}
			}
		}
	}

	inline int size() { return current_size; }

private:
	int* arr;
	int current_size = 0;
	int reserve_size = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	myHeap heap = myHeap(N);

	// 0이면 출력하면서 제거, 없으면 0출력
	while(N--)
	{
		int num = 0;
		cin >> num;
		heap.push(num);
	}
}