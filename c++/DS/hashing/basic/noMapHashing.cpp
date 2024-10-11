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
    // for (auto i : mpp)
    // {
    //     cout << i.first << " : " << i.second << endl;
    // }

    // query
    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;

        cout << number << ": " << mpp[number] << endl;
    }

    return 0;
}