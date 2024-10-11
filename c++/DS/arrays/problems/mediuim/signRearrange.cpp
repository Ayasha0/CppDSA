#include <iostream>
#include <vector>
using namespace std;

// tc -> O(n)
vector<int> rearrangeBySign(vector<int> &v)
{

    int posIdx = 0;
    int negIdx = 1;

    int n = v.size();

    vector<int> ans(n, 0);

    for (int i = 0; i < n; i++)
    {
        if (v[i] < 0)
        {
            ans[negIdx] = v[i];
            negIdx += 2;
        }
        else
        {
            ans[posIdx] = v[i];
            posIdx += 2;
        }
    }
    return ans;
}

int main()
{

    vector<int> v = {3, 1, -2, -5, 2, -4};

    vector<int> ans = rearrangeBySign(v);

    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }

    return 0;
}