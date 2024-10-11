#include <iostream>
using namespace std;

// without recursion
int NormalbinarySearch(int a[], int size, int key)
{

    int start = 0;
    int end = size - 1;

    int mid = (start + end) / 2;

    while (start <= end)
    {

        if (a[mid] == key)
            return mid;

        if (a[mid] > key)
            end = mid - 1;

        else
            start = mid + 1;

        mid = (start + end) / 2;
    }
    return -1;
}

bool binarySearch(int *a, int s, int e, int k)
{
    // base case
    if (s > e)
        return false;

    int mid = (s + e) / 2;

    if (a[mid] == k)
        return true;

    if (a[mid] > k)
        binarySearch(a, s, mid - 1, k);
    else
        binarySearch(a, mid + 1, e, k);
}

int main()
{

    int a[] = {1, 2, 3, 4, 5};
    int size = 5;

    cout << binarySearch(a, 0, 5, 1);

    return 0;
}