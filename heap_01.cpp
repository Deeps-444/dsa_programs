#include <iostream>

using namespace std;

int swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// first we will have max heap
void maxHeapify(int arr[], int n, int i)
{
    // define large index
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(&arr[largest], &arr[i]);
        maxHeapify(arr, n, largest);
    }
}

void buildMaxheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        maxHeapify(arr, n, i);
    }
}

// MIN HEAP
void minHeapify(int arr[], int n, int i)
{
    // define large index
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left] < arr[smallest])
    {
        smallest = left;
    }
    if (right < n && arr[right] < arr[smallest])
    {
        smallest = right;
    }

    if (smallest != i)
    {
        swap(&arr[smallest], &arr[i]);
        minHeapify(arr, n, smallest);
    }
}

void buildMinheap(int arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        minHeapify(arr, n, i);
    }
}

// sorting
void heapSort(int arr[], int n)
{
    // build heap
    buildMaxheap(arr, n);

    // sort
    for (int i = n - 1; i > 0; i--)
    {
        swap(&arr[0], &arr[i]);
        maxHeapify(arr, i, 0);
    }
}

// driving function]
int main()
{
    // take input from user:
    int n, arr[10], dup[10], arr2[10];
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        dup[i] = arr[i];
        arr2[i] = arr[i];
    }

    cout << "MAX heap ====" << endl;
    buildMaxheap(arr, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    cout << "\nMIN heap ====" << endl;
    buildMinheap(dup, n);
    for (int i = 0; i < n; i++)
    {
        cout << dup[i] << " ";
    }

    // sorting===>
    cout << "\nSorting===" << endl;
    heapSort(arr2, n);
    for (int i = 0; i < n; i++)
    {
        cout << arr2[i] << " ";
    }
    return 0;
}