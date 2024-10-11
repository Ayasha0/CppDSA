#include <iostream>
#include <vector>
#include <math.h>
using namespace std;
int max(int a, int b)
{
    return a > b ? a : b;
}

// to find max in the array
int findMax(vector<int> v)
{
    int maxi = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        maxi = max(maxi, v[i]);
    }
    return maxi;
}

// to calculate total hours
int calculateTotalHours(vector<int> v, int hourly)
{
    int totalH = 0;

    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)v[i] / (double)hourly);
    }
    return totalH;
}

// to find minimum Bananas to eat per hour
int minRateToEatBananas(vector<int> v, int hour)
{

    int low = 1;
    high = findMax(v);

    while (low <= high)
    {

        int mid = (low + high) / 2;

        int totalH = calculateTotalHours(v, mid);

        if (totalH <= hour)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}

int main()
{

    vector<int> v = {3, 6, 7, 11};

    int n = 8;

    cout << minRateToEatBananas(v, n);

    return 0;
}