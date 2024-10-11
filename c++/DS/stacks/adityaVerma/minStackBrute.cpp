#include <iostream>
#include <stack>
#include <vector>
using namespace std;

stack<int> s;
stack<int> ss;

void push(int a)
{
    s.push(a);

    if (ss.size() == 0 || ss.top() >= a)
    {
        ss.push(a);
    }
    return;
}

int pop()
{
    if (s.size() == 0)
    {
        return -1;
    }

    int ans = s.top();
    s.pop();

    if (ss.top() == ans)
    {
        ss.pop();
    }
    return ans;
}

void getMin()
{
    if (ss.size() == 0)
    {
        cout << "stack is empty " << endl;
        return;
    }
    cout << ss.top() << endl;
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

    return 0;
}