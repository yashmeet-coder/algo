#include <iostream>
using namespace std;

class Radix_Sort
{
public:
    int *arr;
    int n;

    Radix_Sort(int len)
    {
        n = len;
        arr = new int[n];
    }

    void input();
    void sort();
    void count_sort(int pos);
    void print();
};

void Radix_Sort::input()
{
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Radix_Sort::sort()
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }
    for (int i = 1; max / i > 0; i *= 10)
    {
        count_sort(i);
    }
}

void Radix_Sort::count_sort(int pos)
{
    int *b = new int[n];
    int k = 10;
    int *count = new int[k];
    for (int i = 0; i < k; i++)
    {
        count[i] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        count[(arr[i] / pos) % 10]++;
    }

    for (int i = 1; i < k; i++)
    {
        count[i] = count[i] + count[i - 1];
    }

    for (int i = n - 1; i >= 0; i--)
    {
        count[(arr[i] / pos) % 10]--;
        b[count[(arr[i] / pos) % 10]] = arr[i];
    }

    for (int i = 0; i < n; i++)
    {
        arr[i] = b[i];
    }
}

void Radix_Sort::print()
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    Radix_Sort obj(5);
    obj.input();
    obj.sort();
    obj.print();
}