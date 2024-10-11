#include <iostream>
#include <vector>
using namespace std;

// floor ->
//  "arr[mid] <= x"
int floor(vector<int> v, int x)
{

    int low = 0;
    int high = v.size() - 1;

    int ans = v.size();

    while (low <= high)
    {

        int mid = (low + high) / 2;

        // may be answer
        if (v[mid] <= x)
        {
            ans = v[mid];
            // look for more small index on left
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}

int main()
{

    vector<int> v = {3, 5, 8, 15, 19};
    int x = 6;

    cout << floor(v, x);

    return 0;
}