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
 
//TC -> O(n1 + n2)
vector<int> unionOfArr(vector<int> a, vector<int> b)
{

    int n1 = a.size();
    int n2 = b.size();

    int i = 0;
    int j = 0;

    vector<int> unionArr;

    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
        {
            if (unionArr.size() == 0 || unionArr.back() != a[i])
            {
                unionArr.push_back(a[i]);
            }
            i++;
        }
        else
        {
            if (unionArr.size() == 0 || unionArr.back() != b[j])
            {
                unionArr.push_back(b[j]);
            }
            j++;
        }
    }
    while (i < n1)
    {
        if (unionArr.size() == 0 || unionArr.back() != a[i])
        {
            unionArr.push_back(a[i]);
        }
        i++;
    }
    while (j < n2)
    {
        if (unionArr.size() == 0 || unionArr.back() != b[j])
        {
            unionArr.push_back(b[j]);
        }
        j++;
    }
    return unionArr;
}

int main()
{

    vector<int> v1 = {1, 2, 2, 3, 3, 4, 5, 6};
    vector<int> v2 = {2, 3, 3, 5, 6, 6, 7};

    vector<int> arr = unionOfArr(v1, v2);

    print(arr);
    return 0;
}