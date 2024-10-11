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

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void reverse(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(v[i], v[n - i - 1]);
    }
    return;
}

// nearest smallest element to right
vector<int> NSR(vector<int> v)
{
    vector<int> ans;
    stack<pair<int, int>> s;

    int n = v.size();

    for (int i = n - 1; i >= 0; i--)
    {
        if (s.size() == 0)
        {
            ans.push_back(n);
        }

        else if (s.size() > 0 && s.top().first < v[i])
        {
            ans.push_back(s.top().second);
        }

        else if (s.size() > 0 && s.top().first >= v[i])
        {
            while (s.size() > 0 && s.top().first >= v[i])
            {
                s.pop();
            }

            if (s.size() == 0)
            {
                ans.push_back(n);
            }
            else
            {
                ans.push_back(s.top().second);
            }
        }
        s.push({v[i], i});
    }

    reverse(ans);
    cout << "right: ";
    print(ans);
    return ans;
}

// nearest smallest element to left
vector<int> NSL(vector<int> v)
{
    vector<int> ans;
    stack<pair<int, int>> s;

    int n = v.size();

    for (int i = 0; i < n; i++)
    {
        if (s.size() == 0)
        {
            ans.push_back(-1);
        }

        else if (s.size() > 0 && s.top().first < v[i])
        {
            ans.push_back(s.top().second);
        }

        else if (s.size() > 0 && s.top().first >= v[i])
        {
            while (s.size() > 0 && s.top().first >= v[i])
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
    cout << "left: ";
    print(ans);
    return ans;
}

int maxAreaHistogram(vector<int> v)
{

    int n = v.size();

    vector<int> right = NSR(v);
    vector<int> left = NSL(v);

    // find width array
    vector<int> width(n);
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    cout << "width: ";
    print(width);

    // find area array

    vector<int> area(n);
    for (int i = 0; i < n; i++)
    {
        area[i] = v[i] * width[i];
    }

    cout << "area: ";
    print(area);

    // find max area
    int max = area[0];
    for (int i = 1; i < n; i++)
    {
        if (area[i] > max)
        {
            max = area[i];
        }
    }
    return max;
}

int main()
{

    vector<int> v = {6, 2, 5, 4, 5, 1, 6};

    cout << "Array: ";
    print(v);

    cout << maxAreaHistogram(v);

    return 0;
}