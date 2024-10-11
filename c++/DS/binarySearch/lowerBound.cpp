#include <iostream>
#include <vector>
using namespace std;
// for Q(search insert position) the solution is same as lb

// lower bound = smallest index such that
//  "arr[mid] >= x"
int lowerBound(vector<int> v, int x)
{

    int low = 0;
    int high = v.size() - 1;

    int lb = v.size();

    while (low <= high)
    {

        int mid = (low + high) / 2;

        // may be answer
        if (v[mid] >= x)
        {
            lb = mid;
            // look for more small index on left
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return lb;
}

int main()
{

    vector<int> v = {3, 5, 8, 15, 19};
    int x = 6;

    cout << lowerBound(v, x);

    return 0;
}