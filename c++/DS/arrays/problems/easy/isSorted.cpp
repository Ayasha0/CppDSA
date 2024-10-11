#include <iostream>
#include <vector>
using namespace std;

// TC -> O(n)
bool isSorted(vector<int> v)
{

    for (int i = 1; i < v.size(); i++)
    {
        if (v[i - 1] > v[i])
        {
            return false;
        }
    }
    return true;
}

int main()
{

    vector<int> v = {1, 2, 3, 4};

    cout << isSorted(v);

    return 0;
}