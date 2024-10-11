#include <iostream>
#include <vector>
using namespace std;

// for unique elements
// tc -> O(logn)
int search(vector<int> v, int k)
{

    int low = 0;
    int high = v.size();

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[mid] == k)
        {
            return mid;
        }

        if (v[low] <= v[mid])
        {
            if (v[low] <= k && k <= v[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (v[mid] <= k && k <= v[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

// for duplicate elements
// tc -> O(n/2)
int dsearch(vector<int> v, int k)
{

    int low = 0;
    int high = v.size();

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[mid] == k)
        {
            return mid;
        }
        if (v[low] == v[mid] && v[mid] == v[high])
        {
            low++, high--;
            continue;
        }

        if (v[low] <= v[mid])
        {
            if (v[low] <= k && k <= v[mid])
            {
                high = mid - 1;
            }
            else
            {
                low = mid + 1;
            }
        }
        else
        {
            if (v[mid] <= k && k <= v[high])
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
    }
    return -1;
}

int main()
{
    // vector<int> v = {4, 5, 1, 2, 3};
    vector<int> v = {3, 1, 2, 3, 3};

    // cout << search(v, 2);
    cout << dsearch(v, 1);

    return 0;
}