#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

// brute force
// TC -> O(n^2)
int brute(vector<int> &v, int k)
{
    int s = 0;
    int len = 0;
    for (int i = 0; i < v.size(); i++)
    {
        s = 0;
        for (int j = i; j < v.size(); j++)
        {
            s += v[j];
            if (s == k)
            {
                len = max(len, j - i + 1);
            }
        }
    }
    return len;
}

// optimal (2 POINTERs)
// TC -> O(2n)
// SC -> O(1)
int longestSubArrSumK(vector<int> v, int k)
{
    int left = 0, right = 0;

    int n = v.size();
    int sum = v[0];
    int maxLen = 0;

    while (right < n)
    {
        while (left <= right && sum > k)
        {
            sum -= v[left];
            left++;
        }
        if (sum == k)
        {
            maxLen = max(maxLen, right - left + 1);
        }
        right++;
        if (right < n)
        {
            sum += v[right];
        }
    }
    return maxLen;
}

int main()
{

    vector<int> v = {1, 2, 3, 1, 1, 1, 1, 3, 3};

    cout << longestSubArrSumK(v, 6);

    return 0;
}