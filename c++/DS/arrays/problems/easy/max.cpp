#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// brute force
// TC -> O(n log n)
// SC -> O(1)
int brute(vector<int> v)
{
    sort(v.begin(), v.end());

    return v[v.size() - 1];
}

// optimal
// TC -> O(n)
int largestElement(vector<int> v)
{

    int max = v[0];

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] > max)
        {
            max = v[i];
        }
    }
    return max;
}

int main()
{

    vector<int> v = {1, 2, 3, 4};

    cout << largestElement(v);

    return 0;
}