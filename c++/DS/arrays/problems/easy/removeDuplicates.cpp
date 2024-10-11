#include <iostream>
#include <vector>
#include <set>
using namespace std;

void print(vector<int> v, int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << v[i] << " ";
    }
    cout << endl;
}

// brute force
// TC -> O(n logn + n)
int sizeOfUniqueArr(vector<int> &v)
{

    // push array ele into set
    set<int> st;
    // O(n logn)
    for (int i = 0; i < v.size(); i++)
    {
        st.insert(v[i]); // O(logn) for insert operation
    }

    // push back into the array and
    // return unique ele index
    int index = 0;
    // O(n)
    for (auto it : st)
    {
        v[index] = it;
        index++;
    }

    return index;
}

// optimal
// TC -> O(n)
int removeDuplicates(vector<int> &v)
{
    int i = 0;

    // O(n)
    for (int j = 1; j < v.size(); j++)
    {
        if (v[i] != v[j])
        {
            v[i + 1] = v[j];
            i++;
        }
    }

    return i;
}

int main()
{

    vector<int> v = {3, 2, 1, 5, 2};

    print(v, v.size());
    // int newSize = sizeOfUniqueArr(v);
    int newSize = removeDuplicates(v);

    print(v, newSize);

    return 0;
}