#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DLL
{
public:
    node *head;
    node *tail;

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int val)
    {
        node *new_node = new node(val);

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void display()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main()
{

    DLL l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);

    l.display();

    return 0;
}