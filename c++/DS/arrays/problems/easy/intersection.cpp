#include <iostream>
#include <vector>
using namespace std;

void print(vector<int> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// brute force
// TC -> O(n1 * n2)
// SC -> O(n2)
vector<int> intersection1(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int m = b.size();

    vector<int> ans;
    int visit[m] = {0};

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i] == b[j] && visit[j] == 0)
            {
                ans.push_back(a[i]);
                visit[j] = 1;
                break;
            }
            if (b[j] > a[i])
                break;
        }
    }
    return ans;
}

// optimal
// TC -> O(n1 + n2)
// SC -> O(1)
vector<int> intersection(vector<int> &a, vector<int> &b)
{

    int n = a.size();
    int m = b.size();

    int i = 0;
    int j = 0;

    vector<int> ans;

    while (i < n && j < m)
    {
        if (a[i] < b[j])
        {
            i++;
        }
        else if (b[j] < a[i])
        {
            j++;
        }
        else
        {
            ans.push_back(a[i]);
            i++;
            j++;
        }
    }
    return ans;
}

int main()
{

    vector<int> a = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> b = {2, 3, 3, 5, 6, 6, 7};

    vector<int> ans = intersection(a, b);

    print(ans);

    return 0;
}