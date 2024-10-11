#include <iostream>
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
    int hash[13] = {0};
    for (int i = 0; i < n; i++)
    {
        hash[arr[i]]++;
    }

    int q;
    cin >> q;

    while (q--)
    {
        int number;
        cin >> number;
        // fetch
        cout << number << " : " << hash[number] << endl;
    }

    // // traversal
    // cout << endl
    //      << "Traversal : " << endl;
    // for (int i = 0; i < 13; i++)
    // {
    //     cout << i << " : " << hash[i] << endl;
    // }
    // cout << endl;

    return 0;
}