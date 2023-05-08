#include <iostream>
#include <time.h>
using namespace std;

class Insertion_Sort
{
public:
    int *arr;
    int size;

    Insertion_Sort(int n)
    {
        size = n;
        arr = new int[size];
    }

    void setArray()
    {
        for (int i = 0; i < size; i++)
            arr[i] = rand() % 500;
    }

    int sort()
    {
        int comparisions = 0;
        int temp = 0;
        for (int i = 1; i < size; i++)
        {
            temp = arr[i];
            int j = i - 1;
            while (temp < arr[j] && j >= 0)
            {
                comparisions++;
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1] = temp;
        }
        return comparisions;
    }

    void display()
    {
        for (int i = 0; i < size; i++)
            cout << arr[i] << " ";
    }
};

int main()
{
    srand(time(0));
    int n;
    for (int i = 50; i <= 500; i += 50)
    {
        Insertion_Sort obj(i);
        obj.setArray();
        int count = obj.sort();
        cout << "Size of array: " << i << " ";
        cout << "Comparisions: " << count;
        cout << endl;
    }
}