#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;

int noOfTimesArrRotated(vector<int> v)
{

    int low = 0;
    int high = v.size();

    int mini = INT_MAX;
    int idx = -1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (v[low] <= v[high])
        {
            if (v[mid] < mini)
            {
                idx = mid;
                mini = v[mid];
            }
        }

        if (v[low] <= v[mid])
        {
            if (v[mid] < mini)
            {
                idx = low;
                mini = v[mid];
            }
            low = mid + 1;
        }
        else
        {
            if (v[mid] < mini)
            {
                idx = mid;
                mini = v[mid];
            }
            high = mid - 1;
        }
    }
    return idx;
}

int main()
{
    vector<int> v = {4, 5, 1, 2, 3};
    cout << noOfTimesArrRotated(v);

    return 0;
}