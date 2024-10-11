#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force
// TC -> O(n logn * n)
int brute(vector<int> v)
{
    // O(n logn)
    sort(v.begin(), v.end());

    int n = v.size();
    int largest = v[n - 1];

    // O(n)
    for (int i = n - 2; i >= 0; i++)
    {
        if (v[i] != largest)
        {
            return v[i];
            break;
        }
    }
}

// better solution
// TC -> O(2n)
int better(vector<int> v)
{
    int n = v.size();

    int largest = v[0];

    // O(n)
    for (int i = 1; i < n; i++)
    {
        if (v[i] > largest)
        {
            largest = v[i];
        }
    }

    int slargest = -1;

    // O(n)
    for (int i = 0; i < n; i++)
    {
        if (v[i] > slargest && v[i] != largest)
        {
            slargest = v[i];
        }
    }
    return slargest;
}

// optimal
// TC -> O(n)
int secondLargest(vector<int> v)
{
    int n = v.size();

    int largest = v[0];
    int slargest = -1;

    // O(n)
    for (int i = 1; i < n; i++)
    {
        if (v[i] > largest)
        {
            slargest = largest;
            largest = v[i];
        }
        else if (v[i] < largest && v[i] > slargest)
        {
            slargest = v[i];
        }
    }
    return slargest;
}

int main()
{

    vector<int> v = {3, 2, 1, 5, 2};

    cout << secondLargest(v);

    return 0;
}