#include <iostream>
#include <vector>
using namespace std;

int max(int a, int b)
{
    return a > b ? a : b;
}

int findMaxConsecutiveOnes(vector<int> v)
{
    int maxi = 0;
    int cnt = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 1)
        {
            cnt++;
            maxi = max(maxi, cnt);
        }
        else
        {
            cnt = 0;
        }
    }
    return maxi;
}

int main()
{

    vector<int> v = {1, 1, 0, 1, 0, 1, 1, 1, 0, 1};

    cout << findMaxConsecutiveOnes(v);

    return 0;
}