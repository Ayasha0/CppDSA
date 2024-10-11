#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// brute
// TC ->
void brute(vector<int> &v)
{
    sort(v.begin(), v.end());
}

// better
// TC -> O(2n)
void better(vector<int> &v)
{
    int cnt0 = 0;
    int cnt1 = 0;
    int cnt2 = 0;

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == 0)
        {
            cnt0++;
        }
        else if (v[i] == 1)
        {
            cnt1++;
        }
        else
        {
            cnt2++;
        }
    }

    for (int i = 0; i < cnt0; i++)
    {
        v[i] = 0;
    }
    for (int i = cnt0; i < cnt0 + cnt1; i++)
    {
        v[i] = 1;
    }
    for (int i = cnt0 + cnt1; i < v.size(); i++)
    {
        v[i] = 2;
    }
}

// optimal
// DUTCH NATIONAL FLAG ALGO
// TC -> O(n)
void sorts(vector<int> &v)
{
    int low = 0;
    int mid = 0;
    int high = v.size() - 1;

    while (mid <= high)
    {
        if (v[mid] == 0)
        {
            swap(v[low], v[mid]);
            low++;
            mid++;
        }
        else if (v[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(v[mid], v[high]);
            high--;
        }
    }
}

int main()
{

    vector<int> v = {0, 1, 2, 0, 2, 0, 1, 2, 0};

    // brute(v);
    // better(v);
    sorts(v);

    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;

    return 0;
}