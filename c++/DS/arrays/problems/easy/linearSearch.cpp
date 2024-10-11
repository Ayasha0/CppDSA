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

bool linearSearch(vector<int> v, int key)
{

    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] == key)
        {
            return true;
        }
    }
    return false;
}

int main()
{

    vector<int> v = {1, 2, 3, 4, 5};

    int key = 3;

    if (linearSearch(v, key))
    {
        cout << "present" << endl;
    }
    else
    {
        cout << "absent" << endl;
    }

    return 0;
}