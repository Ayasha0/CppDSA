#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

// approach 1
int maxFreq(vector<int> &v)
{
    unordered_map<int, int> count;

    int maxEle = -1;
    int maxCnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
        count[v[i]]++;
    }

    for (auto i : count)
    {
        if (i.second > maxCnt)
        {
            maxCnt = i.second;
            maxEle = i.first;
        }
    }
    return maxEle;
}

// approach 2
int maxFreq2(vector<int> &v)
{
    unordered_map<int, int> count;

    int maxCount = 0;
    int maxEle = -1;
    for (int i = 0; i < v.size(); i++)
    {
        count[v[i]]++;
        maxCount = max(maxCount, count[v[i]]);
    }

    for (int i = 0; i < v.size(); i++)
    {
        if (maxCount == count[v[i]])
        {
            maxEle = v[i];
            return maxEle;
        }
    }

    // for (auto i : count)
    // {
    //     if (maxCount == i.second)
    //     {
    //         maxEle = i.first;
    //         return maxEle;
    //     }
    // }
    return -1;
}

int main()
{

    vector<int> v = {1, 3, 3, 3, 2, 2};

    cout << maxFreq2(v);

    return 0;
}