#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

class stack
{

public:
    node *head;
    int size;

    stack()
    {
        head = NULL;
        size = 0;
    }

    void push(int val)
    {

        node *new_node = new node(val);

        size++;

        if (head == NULL)
        {
            head = new_node;
            return;
        }

        new_node->next = head;
        head = new_node;
        return;
    }

    int pop()
    {
        if (head == NULL)
        {
            cout << "underflow" << endl;
            return -1;
        }

        size--;

        node *temp = head;
        head = head->next;
        int popVal = temp->data;
        free(temp);
        return popVal;
    }

    int getTop()
    {
        return head->data;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return this->head == NULL;
    }
};

int main()
{

    stack st;

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    st.pop();

    cout << "top : " << st.getTop() << endl;

    return 0;
}