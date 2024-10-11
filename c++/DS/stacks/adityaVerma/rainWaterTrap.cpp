#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print(vector<int> v)
{
    for (auto i : v)
    {
        cout << i << " ";
    }
    cout << endl;
}

int max(int a, int b)
{
    return a > b ? a : b;
}

int min(int a, int b)
{
    return a < b ? a : b;
}

int rainWaterTrapped(vector<int> v)
{
    int n = v.size();

    vector<int> maxL(n);
    vector<int> maxR(n);

    maxL[0] = v[0];

    for (int i = 1; i < n; i++)
    {
        maxL[i] = max(v[i], maxL[i - 1]);
    }

    cout << "maxL: ";
    print(maxL);

    maxR[n - 1] = v[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        maxR[i] = max(v[i], maxR[i + 1]);
    }
    cout << "maxR: ";
    print(maxR);

    vector<int> water(n);
    for (int i = 0; i < n; i++)
    {
        water[i] = min(maxL[i], maxR[i]) - v[i];
    }
    cout << "water: ";
    print(water);

    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += water[i];
    }
    return sum;
}

int main()
{

    vector<int> v = {3, 0, 0, 2, 0, 4};

    cout << rainWaterTrapped(v);

    return 0;
}