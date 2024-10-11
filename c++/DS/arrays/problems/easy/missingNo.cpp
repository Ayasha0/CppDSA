#include <iostream>
#include <vector>
using namespace std;

// brute force
// TC -> O(n * n)
int brute(vector<int> v)
{
    int N = v.size();
    for (int i = 1; i <= N; i++)
    {
        int flag = 0;
        for (int j = 0; j < v.size(); j++)
        {
            if (v[j] == i)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            return i;
    }
}

// better
// TC -> O(2n)
// how ?
//    -> O(n) + O(n)
int better(vector<int> v)
{
    int n = v.size();

    int hash[n + 1] = {0};

    for (int i = 0; i < n; i++)
    {
        hash[v[i]] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (hash[i] == 0)
        {
            return i;
        }
    }
}

// optimal #1
// TC -> O(n)
int missingNo(vector<int> v)
{

    int n = v.size();

    int N = n + 1;
    int sum = (N * (N + 1)) / 2;

    int s2 = 0;

    for (int i = 0; i < n; i++)
    {
        s2 += v[i];
    }

    return sum - s2;
}

// optimal #2
// TC -> O(n)
int missingNoXOR(vector<int> v)
{
    int n = v.size();

    int xor1 = 0;
    int xor2 = 0;

    for (int i = 0; i < n; i++)
    {
        xor2 = xor2 ^ v[i];
        xor1 = xor1 ^ (i + 1);
    }

    xor1 = xor1 ^ (n + 1);

    return xor1 ^ xor2;
}

int main()
{

    vector<int> v = {1, 2, 4, 5};

    cout << missingNoXOR(v);

    return 0;
}