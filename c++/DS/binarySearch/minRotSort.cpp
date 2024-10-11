#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int findMin(vector<int> v)
{

    int low = 0;
    int high = v.size();

    int mini = INT_MAX;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[low] <= v[mid])
        {
            mini = min(mini, v[low]);
            low = mid + 1;
        }
        else
        {
            mini = min(mini, v[mid]);
            high = mid - 1;
        }
    }
    return mini;
}

int main()
{
    vector<int> v = {4, 5, 1, 2, 3};
    cout << findMin(v);

    return 0;
}