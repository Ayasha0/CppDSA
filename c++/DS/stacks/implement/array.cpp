#include <iostream>
using namespace std;

class stack
{
private:
    int capacity;
    int *arr;
    int top;

public:
    stack(int c)
    {
        capacity = c;
        arr = new int[c];
        this->top = -1;
    }

    void push(int data)
    {
        if (this->top == this->capacity - 1)
        {
            cout << "overflow\n"
                 << endl;
            return;
        }
        this->top++;
        this->arr[this->top] = data;
    }

    int pop()
    {
        if (this->top == -1)
        {
            cout << "underflow" << endl;
            return -1;
        }
        int popEle = this->arr[this->top];
        this->top--;
        return popEle;
    }

    bool isEmpty()
    {
        return this->top == -1;
    }

    bool isFull()
    {
        return this->top == this->capacity - 1;
    }

    int getSize()
    {
        return this->top + 1;
    }

    int getTop()
    {
        return this->arr[this->top];
    }
};

int main()
{

    stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.pop();

    cout << "top : " << st.getTop() << endl;

    return 0;
}