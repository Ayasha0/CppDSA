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

node *removeDuplicates(node *head)
{
    node *temp = head;

    while (temp && temp->next)
    {
        node *nextNode = temp->next;

        while (nextNode && nextNode->data == temp->data)
        {
            node *duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;

        if (nextNode)
        {
            nextNode->prev = temp;
        }

        temp = temp->next;
    }
    return head;
}

int main()
{

    DLL l;

    l.insertAtTail(1);
    l.insertAtTail(1);
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(3);
    l.insertAtTail(4);

    l.display();

    l.head = removeDuplicates(l.head);
    l.display();

    return 0;
}