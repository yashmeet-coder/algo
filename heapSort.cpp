#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
#include <cmath>
using namespace std;
class heapSort
{
public:
    int *arr;
    int length;
    int comparisions;
    int heapSize;

    heapSort(int n)
    {
        arr = new int[n];
        comparisions = 0;
        length = n;
        heapSize = n;
    }

    void populate()
    {
        for (int i = 0; i < length; i++)
            arr[i] = rand() % 100;
    }

    int parent(int i)
    {
        return i / 2;
    }

    int left_child(int i)
    {
        return (2 * i + 1);
    }

    int right_child(int i)
    {
        return (2 * i + 2);
    }

    int max_heapify(int *array, int i)
    {
        int l = left_child(i);
        int r = right_child(i);
        int largest;
        if (l < heapSize && array[l] > array[i])
        {
            largest = l;
            comparisions++;
        }
        else
        {
            largest = i;
            comparisions++;
        }
        if (r < heapSize && array[r] > array[largest])
        {
            largest = r;
            comparisions++;
        }
        if (largest != i)
        {
            swap(array[i], array[largest]);
            max_heapify(array, largest);
        }
        return comparisions;
    }

    int build_max_heap()
    {
        int c;
        heapSize = length;
        for (int i = (length - 1) / 2; i > 0; i--)
            c = max_heapify(arr, i);
        return c;
    }

    int heap_sort()
    {
        int k = build_max_heap();
        int m;
        for (int i = length - 1; i > 0; i--)
        {
            swap(arr[0], arr[i]);
            heapSize--;
            m = max_heapify(arr, 0);
        }
        return k + m;
    }
};

int main()
{
    heapSort obj(5);
    srand(time(0));
    ofstream myFile("length.csv");
    ofstream myFile1("compare.csv");
    for (int i = 0; i < 100; i++)
    {
        int n = 30 + rand() % (1000 - 30 + 1);
        heapSort obj(n);
        obj.populate();
        myFile << obj.length << endl;
        int c = obj.heap_sort();
        myFile1 << c << endl;
    }
}