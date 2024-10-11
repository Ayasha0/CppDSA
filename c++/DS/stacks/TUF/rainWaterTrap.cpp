#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int rainWaterTrap(vector<int> v)
{
    int n = v.size();

    int lmax = 0;
    int rmax = 0;
    int total = 0;

    int l = 0;
    int r = n - 1;

    while (l < r)
    {
        if (v[l] <= v[r])
        {
            if (lmax > v[l])
            {
                total += (lmax - v[l]);
            }
            else
            {
                lmax = v[l];
            }
            l++;
        }
        else
        {
            if (rmax > v[r])
            {
                total += (rmax - v[r]);
            }
            else
            {
                rmax = v[r];
            }
            r--;
        }
    }
    return total;
}

int main()
{

    vector<int> v = {3, 0, 0, 2, 0, 4};

    cout << rainWaterTrap(v);

    return 0;
}