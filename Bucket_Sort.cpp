#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Bucket_Sort
{
public:
    float *arr;
    int n;
    Bucket_Sort(int len)
    {
        n = len;
        arr = new float[n];
    }

    void input();
    void fill_bucket();
    vector<float> sort(vector<float> v);
    void print();
};

void Bucket_Sort::input()
{
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
}

void Bucket_Sort::fill_bucket()
{
    vector<float> v[n];
    for (int i = 0; i < n; i++)
    {
        int index = n * arr[i];
        v[index].push_back(arr[i]);
    }
    for (int i = 0; i < n; i++)
    {
        v[i] = sort(v[i]);
    }

    int k = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < v[i].size(); j++)
            arr[k++] = v[i][j];
}

vector<float> Bucket_Sort::sort(vector<float> v1)
{
    for (int i = 1; i < n; i++)
    {
        int j = i - 1;
        int temp = arr[i];
        while (arr[j] > temp && j >= 0)
        {
            exchange(arr[j], temp);
            j--;
        }
    }
    return v1;
}

void Bucket_Sort::print(

)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    Bucket_Sort obj(5);
    obj.input();
    obj.fill_bucket();
    obj.print();
}
