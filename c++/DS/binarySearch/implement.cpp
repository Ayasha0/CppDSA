#include <iostream>
#include <vector>
using namespace std;

// tc -> O(logn)
int binarySearch(vector<int> v, int k)
{

    int low = 0;
    int high = v.size() - 1;

    int mid = -1;

    while (low <= high)
    {

        mid = (low + high) / 2;

        if (v[mid] == k)
        {
            return mid;
        }
        else if (v[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return mid;
}

int rbinarySearch(vector<int> v, int low, int high, int k)
{

    if (low > high)
    {
        return -1;
    }

    int mid = (low + high) / 2;

    if (v[mid] == k)
    {
        return mid;
    }
    else if (v[mid] > k)
    {
        return rbinarySearch(v, low, mid, k);
    }
    else
    {
        return rbinarySearch(v, mid + 1, high, k);
    }
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};

    cout << rbinarySearch(v, 0, v.size() - 1, 3);

    return 0;
}