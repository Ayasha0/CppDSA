#include <iostream>
#include <vector>
#include <algorithm>
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
// TC -> O(n+d)
// SC -> O(d)
void rotateByD(vector<int> &v, int d)
{
    int n = v.size();
    d = d % n;

    vector<int> temp(d);

    // place in temp[]
    for (int i = 0; i < d; i++)
    {
        temp[i] = v[i];
    }

    // shifting
    for (int i = d; i < n; i++)
    {
        v[i - d] = v[i];
    }

    // pushing temp[] ele into v[]
    for (int i = n - d; i < n; i++)
    {
        v[i] = temp[i - (n - d)];
    }
}

// optimal
// TC -> O(2n)
// SC -> O(1)
// void rotate(vector<int> &v, int d)
// {
//     int n = v.size();

//     rev(v, v, v + d);
//     rev(v, v + d, v + n);
//     rev(v, v, v + n);
// }

int main()
{

    vector<int> v = {1, 2, 3, 4, 5};
    int d = 3;

    print(v);
    rotateByD(v, d);
    print(v);

    return 0;
}