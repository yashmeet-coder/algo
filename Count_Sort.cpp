#include <iostream>
using namespace std;

class Count_Sort
{
public:
    int *arr;
    int n;
    int k;

    Count_Sort()
    {
        cout << "Enter the size of the array: ";
        cin >> n;
        cout << "Enter the value of k: ";
        cin >> k;
        arr = new int[n];
        cout << "Enter the elements: ";
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];

        }
    }

    int *sort()
    {
        int *b = new int[n];
        int *count = new int[k];
        for (int i = 0; i < k; i++)
        {
            count[i] = 0;
        }
        for (int i = 0; i < n; i++)
        {
            count[arr[i]]++;
        }
         
        for (int i = 0; i < k; i++)
        {
            count[i] = count[i] + count[i- 1];
        }

        for (int i = n - 1; i >= 0; i--)
        {
            count[arr[i]]--;
            b[count[arr[i]]] = arr[i];
        }

        return b;
    }
};

int main()
{
    Count_Sort obj;
    int *result = obj.sort();
    cout << "Sorted array: ";
    for (int i = 0; i < obj.n; i++)
    {
        cout << *(result + i) << " ";
    }
}