#include <iostream>
#include <vector>

using namespace std;

int firstOcc(vector<int> v, int k)
{

    int low = 0;
    int high = v.size() - 1;

    int first = -1;

    int mid = (low + high) / 2;

    while (low <= high)
    {
        if (v[mid] == k)
        {
            first = mid;
            high = mid - 1;
        }
        else if (v[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return first;
}

int secondOcc(vector<int> v, int k)
{

    int low = 0;
    int high = v.size() - 1;

    int second = -1;

    int mid = (low + high) / 2;

    while (low <= high)
    {
        if (v[mid] == k)
        {
            second = mid;
            low = mid + 1;
        }
        else if (v[mid] > k)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return second;
}

pair<int, int> firstLastOccurance(vector<int> v, int k)
{

    int first = firstOcc(v, k);
    int second = secondOcc(v, k);

    return {first, second};
}

int main()
{

    vector<int> v = {1, 2, 3, 3, 3, 4, 5};
    int k = 3;

    pair<int, int> ans = firstLastOccurance(v, k);
    cout << "{ " << ans.first << ", " << ans.second << " }";
    cout << false;

    return 0;
}