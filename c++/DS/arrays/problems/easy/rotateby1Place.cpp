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

void rotateby1(vector<int> &v)
{
    int temp = v[0];
    int n = v.size();

    for (int i = 1; i < n; i++)
    {
        v[i - 1] = v[i];
    }

    v[n - 1] = temp;
}

int main()
{

    vector<int> v = {1, 2, 3, 4};

    rotateby1(v);
    print(v);

    return 0;
}