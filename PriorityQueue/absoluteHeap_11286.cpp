#include <iostream>
using namespace std;

class absoluteHeap
{
public:
	absoluteHeap(int n)
	{
		heap = static_cast<int*>(malloc(sizeof(int) * n));
		reserveSize = n;
	}
	~absoluteHeap()
	{
		free(heap);
	}

	void input(int num)
	{
		// 0이 입력되면 출력 후 pop한다.
		if(num == 0)
			cout << pop() << '\n';
		else
			push(num);
	}

private:
	// 1.절대값이 작은 숫자를 위로 보내고
	// 2.같은 수인 경우 작은 숫자를 위로 보낸다
	void push(int n)
	{
		if (currentSize >= reserveSize) return;

		heap[currentSize++] = n;

		int child = currentSize - 1;
		int parent = (child - 1) / 2;

		while (child > 0 && abs(heap[parent]) >= abs(heap[child]))
		{
			// 2-1.부모가 자식보다 작으면, 정렬이 완료된 것으로 보고 종료한다
			if (abs(heap[parent]) == abs(heap[child]) && heap[parent] < heap[child]) break;

			swap(heap[parent], heap[child]);

			child = parent;
			parent = (child - 1) / 2;
		}
	}

	int pop()
	{
		if (currentSize <= 0) return 0;

		int result = heap[0];

		heap[0] = heap[--currentSize];

		int parent = 0;

		while (parent < currentSize)
		{
			int lchild = parent * 2 + 1;
			int rchild = lchild + 1;
			int child = -1;

			if(lchild < currentSize && rchild < currentSize)
			{
				if (abs(heap[lchild]) < abs(heap[rchild]) || // 절대값이 작거나
					(abs(heap[lchild]) == abs(heap[rchild]) && heap[lchild] < heap[rchild])) // 같은 경우 음수 쪽을 선택한다.
					child = lchild;
				else
					child = rchild;
			}
			else if(lchild < currentSize)
			{
				child = lchild;
			}

			if(child != -1 && abs(heap[parent]) > abs(heap[child]) || // 절대값이 작거나
				(abs(heap[parent]) == abs(heap[child]) && heap[parent] > heap[child])) // 같은 경우 음수 라면 바꾼다.
			{
				swap(heap[parent], heap[child]);
				parent = child;
			}
			else
			{
				break; // child가 없는 경우 종료한다
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

	absoluteHeap heap = absoluteHeap(N);

	while(N--)
	{
		int tmp;
		cin >> tmp;
		heap.input(tmp);
	}
}