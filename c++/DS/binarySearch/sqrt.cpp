#include <iostream>
#include <vector>
using namespace std;

int floorSqrt(int n)
{

    int low = 1, high = n;

    while (low <= high)
    {
        long long mid = (low + high) / 2;

        if ((mid * mid) <= n)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return high;
}

int main()
{

    int n = 28;

    cout << floorSqrt(n);

    return 0;
}