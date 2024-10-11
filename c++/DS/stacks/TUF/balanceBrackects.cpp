#include <iostream>
#include <string>
#include <stack>
using namespace std;

bool isBalanced(string s)
{

    stack<char> st;

    for (auto ch : s)
    {
        if (ch == '[' || ch == '{' || ch == '(')
        {
            st.push(ch);
        }
        else
        {
            // if their is no opening brace left to compare the closing bracket
            if (st.empty())
            {
                return false;
            }

            // matching current closing bracket with stacks top() bracket
            if ((st.top() == '(' && ch == ')') || (st.top() == '{' && ch == '}') || (st.top() == '[' && ch == ']'))
            {
                st.pop();
            }

            // if the brackets are different kind
            else
            {
                return false;
            }
        }
    }
    return st.empty();
}

int main()
{

    string s = "[{{(){[(){}]}}}][]";

    if (isBalanced(s))
    {
        cout << "true" << endl;
    }
    else
    {
        cout << "false" << endl;
    }

    return 0;
}