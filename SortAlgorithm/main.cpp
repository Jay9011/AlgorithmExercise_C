#include <iostream>

using namespace std;

void InsertionSort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i;
        while (0 < j && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

void QuickSortUtil(int* arr, int lower, int upper)
{
    if (upper <= lower) return;

    int pivot = arr[lower];
    int start = lower;
    int end = upper;

    while (lower < upper)
    {
        while (arr[lower] <= pivot)
        {
            lower++;
        }
        while (arr[upper] > pivot)
        {
            upper--;
        }
        if (lower < upper)
        {
            swap(arr[lower], arr[upper]);
        }
    }

    swap(arr[upper], arr[start]);

    QuickSortUtil(arr, start, upper - 1);
    QuickSortUtil(arr, upper + 1, end);
}

void QuickSort(int* arr, int size)
{
    QuickSortUtil(arr, 0, size - 1);
}

void SelectionSort(int* arr, int size)
{
    int min;
    for (int i = 0; i < size - 1; i++)
    {
        min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(arr[i], arr[min]);
    }
}

int main()
{
    int number[] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };

    QuickSort(number, sizeof(number) / sizeof(*number));
    //InsertionSort(number, sizeof(number) / sizeof(*number));
    //SelectionSort(number, sizeof(number) / sizeof(*number));

    for (int i = 0; i < sizeof(number) / sizeof(*number); i++) 
    {
        cout << number[i] << " ";
    }

    return 0;
}