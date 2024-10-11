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

vector<int> stockSpan(vector<int> v)
{

    vector<int> ans;
    stack<pair<int, int>> s;

    for (int i = 0; i < v.size(); i++)
    {
        if (s.size() == 0)
        {
            ans.push_back(-1);
        }

        else if (s.size() > 0 && s.top().first > v[i])
        {
            ans.push_back(s.top().second);
        }

        else if (s.size() > 0 && s.top().first <= v[i])
        {
            while (s.size() > 0 && s.top().first <= v[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                ans.push_back(-1);
            }
            else
            {
                ans.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }

    for (int i = 0; i < ans.size(); i++)
    {
        ans[i] = i - ans[i];
    }
    return ans;
}

int main()
{

    vector<int> v = {100, 80, 60, 70, 60, 75, 85};

    vector<int> stockArr = stockSpan(v);

    print(stockArr);

    return 0;
}