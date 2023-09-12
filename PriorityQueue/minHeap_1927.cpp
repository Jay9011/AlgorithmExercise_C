#include <iostream>
using namespace std;

class MinHeap
{
public:
	MinHeap(int s)
	{
		heap = static_cast<int*>(malloc(sizeof(int) * s));
		reserveSize = s;
	}
	~MinHeap()
	{
		free(heap);
	}

	void push(int num)
	{
		// 0이면 꺼내서 출력한다.
		if(num == 0)
		{
			cout << pop() << '\n';
		}
		else
		{
			if (currentSize + 1 >= reserveSize) return;

			heap[currentSize++] = num;

			int child = currentSize - 1;
			int parent = (child - 1) / 2;

			// parent가 현재 노드 값 보다 크다면 바꿔야 한다.
			while(parent >= 0 && heap[parent] > heap[child])
			{
				heap[parent] ^= heap[child] ^= heap[parent] ^= heap[child];
				child = parent;
				parent = (child - 1) / 2;
			}
		}
	}

private:
	int pop()
	{
		if (currentSize <= 0) return 0;

		int result = heap[0];

		heap[0] = heap[--currentSize];

		int parent = 0;
		while(parent < currentSize)
		{
			int lchild = parent * 2 + 1;
			int rchild = lchild + 1;
			int child = -1;

			//왼쪽 자식과 오른쪽 자식 중 더 작은 쪽을 선택한다.
			if(lchild < currentSize && rchild < currentSize)
			{
				if (heap[lchild] < heap[rchild])
					child = lchild;
				else
					child = rchild;
			}
			else if(lchild < currentSize)
			{
				child = lchild;
			}

			// 만약 child가 parent보다 더 작으면 둘을 바꿔준다.
			if(child != -1 && heap[child] < heap[parent])
			{
				heap[child] ^= heap[parent] ^= heap[child] ^= heap[parent];
				parent = child;
			}
			else //child가 없는 경우 끝낸다.
			{
				break;
			}
		}

		return result;
	}

private:
	int* heap;

	int reserveSize = 0;
	int currentSize = 0;
};

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int N;
	cin >> N;

	MinHeap heap = MinHeap(N);

	while(N--)
	{
		int tmp;
		cin >> tmp;
		heap.push(tmp);
	}
}