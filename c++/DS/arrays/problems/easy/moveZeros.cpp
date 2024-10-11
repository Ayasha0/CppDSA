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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// here j always points to 0
// i points to non-zero ele

// TC -> O(n)
// how ?
//    -> O(x) + O(n - x)
//    -> O(n)
// x = for finding first 0 ele and
// assigning it to j
void moveZeros(vector<int> &v)
{

    int n = v.size();

    int j = -1;

    // placing j at 0 ele
    for (int i = 0; i < n; i++)
    {
        if (v[i] == 0)
        {
            j = i;
            break;
        }
    }

    // no zeros
    if (j == -1)
        return;

    for (int i = j + 1; i < n; i++)
    {
        if (v[i] != 0)
        {
            swap(v[i], v[j]);
            j++;
        }
    }
}

int main()
{

    vector<int> v = {1, 2, 0, 3, 0, 0, 4, 5};

    print(v);
    moveZeros(v);

    print(v);

    return 0;
}