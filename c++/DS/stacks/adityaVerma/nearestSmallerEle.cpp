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

vector<int> nearestSmallerEle(vector<int> v)
{

    vector<int> ans;
    stack<int> s;

    int n = v.size();

    for (int i = 0; i < n; i++)
    {

        if (s.size() == 0)
        {
            ans.push_back(-1);
        }

        else if (s.size() > 0 && s.top() < v[i])
        {
            ans.push_back(s.top());
        }

        else if (s.size() > 0 && s.top() >= v[i])
        {
            while (s.size() > 0 && s.top() >= v[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                ans.push_back(-1);
            }

            else
            {
                ans.push_back(s.top());
            }
        }
        s.push(v[i]);
    }
    return ans;
}

int main()
{

    vector<int> v = {1, 3, 2, 4};

    vector<int> ans = nearestSmallerEle(v);

    print(ans);

    return 0;
}