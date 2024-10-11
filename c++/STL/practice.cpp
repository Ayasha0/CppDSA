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

int main()
{

    vector<int> a = {1, 5, 4, 2, 3};
    // int n = 5;
    // print(a);

    // // algorithms
    // sort(a.begin(), a.end());

    // print(a);

    // sort(a.begin(), a.end(), greater<int>);

    // print(a);

    // string s = "123";
    // do
    // {
    //     cout << s << endl;
    // } while (next_permutation(s.begin(), s.end()));

    int maxi = *max_element(a.begin(), a.end());
    cout << maxi;

    return 0;
}