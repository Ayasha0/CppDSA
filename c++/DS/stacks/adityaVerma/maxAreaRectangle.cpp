#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void print2D(vector<vector<int>> v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

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

void reverse(vector<int> &v)
{
    int n = v.size();
    for (int i = 0; i < n / 2; i++)
    {
        swap(v[i], v[n - i - 1]);
    }
    return;
}

int max(int a, int b)
{
    return a > b ? a : b;
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
    // cout << "right: ";
    // print(ans);
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
    // cout << "left: ";
    // print(ans);
    return ans;
}

int maxAreaHistogram(vector<int> v)
{
    cout << "sub array: ";
    print(v);

    int n = v.size();

    vector<int> right = NSR(v);
    vector<int> left = NSL(v);

    // find width array
    vector<int> width(n);
    for (int i = 0; i < n; i++)
    {
        width[i] = right[i] - left[i] - 1;
    }
    // cout << "width: ";
    // print(width);

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
    cout << endl
         << endl;
    return max;
}

int maxAreaRectangle(vector<vector<int>> v)
{

    int n = v.size();
    int m = v[0].size();

    vector<int> ans(m);

    for (int j = 0; j < m; j++)
    {
        ans[j] = v[0][j];
    }
    // cout << "ans: ";
    // print(ans);

    int maxi = maxAreaHistogram(ans);

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 0)
            {
                ans[j] = 0;
            }
            else
            {
                ans[j] += v[i][j];
            }
        }
        maxi = max(maxi, maxAreaHistogram(ans));
    }
    return maxi;
}

int main()
{

    vector<vector<int>> v = {{0, 1, 1, 0}, {1, 1, 1, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}};

    cout << "Array: " << endl;
    print2D(v);

    cout << maxAreaRectangle(v);

    return 0;
}