#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
int mini = 100;

void push(int x)
{

    if (s.size() == 0)
    {
        s.push(x);
        mini = x;
        return;
    }

    else
    {
        if (x >= mini)
        {
            s.push(x);
        }
        else if (x < mini)
        {
            s.push(2 * x - mini);
            mini = x;
        }
    }

    return;
}

int pop()
{
    int ans = -1;

    if (s.size() == 0)
    {
        return -1;
    }
    else
    {
        if (s.top() >= mini)
        {
            ans = s.top();
            s.pop();
        }
        else if (s.top() < mini)
        {

            mini = 2 * mini - s.top();
            s.pop();
        }
    }
    return ans;
}

int top()
{
    if (s.size() == 0)
    {
        return -1;
    }
    else
    {
        if (s.top() >= mini)
        {
            return s.top();
        }
        else if (s.top() < mini)
        {
            return mini;
        }
    }
}

void getMin()
{
    if (s.size() == 0)
    {
        cout << "stack is empty " << endl;
        return;
    }
    cout << mini << endl;
    return;
}

int main()
{

    push(3);
    getMin();
    push(5);
    getMin();
    push(1);
    getMin();
    pop();
    getMin();

    return 0;
}