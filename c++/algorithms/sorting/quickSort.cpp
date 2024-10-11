#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(vector<int> &v, int low, int high)
{
    int pivot = v[low];

    int i = low;
    int j = high;

    while (i < j)
    {

        while (v[i] <= pivot && i <= high)
        {
            i++;
        }
        while (v[j] > pivot  && j >= low)
        {
            j--;
        }

        if (i < j)
        {
            swap(v[i], v[j]);
        }
        swap(v[low], v[j]);
        return j;
    }
}

void quickSort(vector<int> &v, int low, int high)
{
    if (low < high)
    {
        int pivotIdx = partition(v, low, high);

        quickSort(v, low, pivotIdx - 1);
        quickSort(v, pivotIdx + 1, high);
    }
}

int main()
{

    vector<int> v = {5, 4, 3, 2, 1};

    quickSort(v, 0, v.size() - 1);

    print(v);

    return 0;
}