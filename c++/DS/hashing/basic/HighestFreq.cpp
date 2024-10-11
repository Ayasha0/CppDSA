#include <iostream>
#include <map>
using namespace std;

int main()
{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // precompute
    // map<key, value>
    // map stores in sorted order
    map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    // traversing map
    for (auto i : mpp)
    {
        cout << i.first << " : " << i.second << endl;
    }

    int maxCnt = -1;
    int maxEle = -1;
    for (auto i : mpp)
    {
        if (i.second > maxCnt)
        {
            maxCnt = i.second;
            maxEle = i.first;
        }
    }

    cout << "max element : " << maxEle << endl;

    return 0;
}