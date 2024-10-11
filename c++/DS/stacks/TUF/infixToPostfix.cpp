#include <iostream>
#include <string>
#include <stack>
using namespace std;

int precedence(char ch)
{
    // cout << ch << endl;
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
    {
        return -1;
    }
}

void display(stack<char> st)
{
    if (st.empty())
    {
        return;
    }
    char curr = st.top();
    st.pop();
    display(st);
    cout << curr << " ";
}

void infixToPostfix(string s)
{

    stack<char> st;
    string result;

    for (int i = 0; i < s.length(); i++)
    {

        char c = s[i];

        // if scanned char is a operand
        if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= 0 && c <= 9))
        {
            result += c;
        }

        // if scanned char is a '('
        else if (c == '(')
        {
            st.push(c);
        }

        // if scanned char is a ');
        else if (c == ')')
        {
            while (st.top() != '(')
            {
                result += st.top();
                st.pop();
            }
            st.pop();
        }

        // if scanned char is a operator
        else
        {
            while (!st.empty() && (precedence(c) <= precedence(st.top())))
            {
                result += st.top();
                st.pop();
            }
            st.push(c);
        }

        // cout << "c : " << c << endl;
        // cout << "result : " << result << endl;
        // cout << "st : ";
        // display(st);
        // cout << endl;
    }

    // pop all remaining elements from the stack
    while (!st.empty())
    {
        result += st.top();
        st.pop();
    }

    cout << "postfix expression: " << result << endl;
}

int main()
{
    string exp = "(p+q)*(m-n)";
    cout << "Infix expression: " << exp << endl;
    infixToPostfix(exp);

    return 0;
}