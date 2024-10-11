#include <iostream>
#include <stack>
using namespace std;

void display(stack<int> s)
{
    while (!s.empty())
    {
        cout << s.top() << endl;

        s.pop();
    }
    cout << endl
         << endl;
    return;
}


void insertAtBottom(stack<int> &s, int x)
{
    if (s.empty())
    {
        s.push(x);
        return;
    }

    int curr = s.top();
    s.pop();

    insertAtBottom(s, x);
    s.push(curr);
}

int main()
{

    stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);

    display(s);

    

    display(s);

    return 0;
}