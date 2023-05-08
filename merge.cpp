#include <iostream>
#include <cstdlib>
#include <time.h>
#include <fstream>
using namespace std;
class mergeSort
{
public:
    int *arr;
    int length;
    int comparison;
    int *L;
    int *R;
    mergeSort(int n)
    {
        length = n;
        arr = new int[length];
        comparison = 0;
    }
    void populate()
    {
        for (int i = 0; i < length; i++)
            arr[i] = rand() % 100;
    }
    void display()
    {
        cout << length << endl;
        for (int i = 0; i < length; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
    int merge(int *arr, int p, int q, int r)
    {
        int n1 = q - p + 1;
        int n2 = r - q;
        L = new int[n1];
        R = new int[n2];
        for (int i = 0; i < n1; i++)
            L[i] = arr[p + i];
        for (int i = 0; i < n2; i++)
            R[i] = arr[q + 1 + i];
        int i = 0;
        int j = 0;
        int k = p;
        while (i < n1 && j < n2)
        {
            if (L[i] <= R[j])
            {
                arr[k] = L[i];
                i++;
                comparison++;
            }
            else
            {
                comparison++;
                arr[k] = R[j];
                j++;
            }
            k++;
        }
        while (i < n1)
        {
            arr[k] = L[i];
            i++;
            k++;
        }
        while (j < n2)
        {
            arr[k] = R[j];
            j++;
            k++;
        }
        return comparison;
    }
    int merge_sort(int *arr, int p, int r)
    {
        int k;
        if (p < r)
        {
            int q = (p + r) / 2;
            merge_sort(arr, p, q);
            merge_sort(arr, q + 1, r);
            k = merge(arr, p, q, r);
        }
        return k;
    }
};
int main()
{
    srand(time(0));
    ofstream myFile("length.csv");
    ofstream myFile1("compare.csv");
    for (int i = 0; i < 100; i++)
    {
        int n = 30 + rand() % (1000 - 30 + 1);
        mergeSort obj(n);
        obj.populate();
        myFile << obj.length << endl;
        int c = obj.merge_sort(obj.arr, 0, n - 1);
        myFile1 << c << endl;
    }
    return 0;
}