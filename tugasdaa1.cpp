#include <iostream>
#include <limits.h>

using namespace std;

class MaxHeap
{
    int *arr;
    int maxSize;
    int heapSize;

public:
    MaxHeap(int totSize)
    {
        heapSize = 0;
        maxSize = totSize;
        arr = new int[totSize];
    }

    void MaxHeapify(int i)
    {
        int l = lChild(i);
        int r = rChild(i);
        int largest = i;
        if (l < heapSize && arr[l] > arr[i])
            largest = l;
        if (r < heapSize && arr[r] > arr[largest])
            largest = r;
        if (largest != i)
        {
            swap(arr[i], arr[largest]);
            MaxHeapify(largest);
        }
    }

    int parent(int i)
    {
        return (i - 1) / 2;
    }

    int lChild(int i)
    {
        return (2 * i + 1);
    }

    int rChild(int i)
    {
        return (2 * i + 2);
    }

    int removeMax()
    {
        if (heapSize <= 0)
            return INT_MIN;
        if (heapSize == 1)
        {
            heapSize--;
            return arr[0];
        }

        int root = arr[0];
        arr[0] = arr[heapSize - 1];
        heapSize--;

        MaxHeapify(0);

        return root;
    }

    void increaseKey(int i, int newVal)
    {
        arr[i] = newVal;
        while (i != 0 && arr[parent(i)] < arr[i])
        {
            swap(arr[i], arr[parent(i)]);
            i = parent(i);
        }
    }

    int getMax()
    {
        return arr[0];
    }

    int curSize()
    {
        return heapSize;
    }

    void deleteKey(int i)
    {
        increaseKey(i, INT_MAX);
        removeMax();
    }

    void insertKey(int x)
    {
        if (heapSize == maxSize)
        {
            cout << "\nOverflow: Could not insertKey\n";
            return;
        }

        heapSize++;
        int i = heapSize - 1;
        arr[i] = x;

        while (i != 0 && arr[parent(i)] < arr[i])
        {
            int temp = arr[i];
            arr[i] = arr[parent(i)];
            arr[parent(i)] = temp;
            i = parent(i);
        }
    }

    void displayArray()
    {
        cout << "Current array : ";
        for (int idx = 0; idx < heapSize; idx++)
        {
            cout << arr[idx] << ", ";
        }
        cout << "\n";
    }
};

int main()
{
    MaxHeap h(15);

    cout << "Entered 6 keys:- 16,4,10,14,7,9,3,2,8,1\n";
    h.insertKey(16);
    h.insertKey(4);
    h.insertKey(10);
    h.insertKey(14);
    h.insertKey(7);
    h.insertKey(9);
    h.insertKey(3);
    h.insertKey(2);
    h.insertKey(8);
    h.insertKey(1);

    h.displayArray();

    return 0;
}
