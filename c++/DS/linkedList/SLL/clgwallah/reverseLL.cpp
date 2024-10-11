#include <iostream>
using namespace std;

class node
{
public:
    int val;
    node *next;

    node(int data)
    {
        val = data;
        next = NULL;
    }
};

class linkedList
{

public:
    node *head;

    linkedList()
    {
        head = NULL;
    }

    void insertAtTail(int value)
    {

        node *new_node = new node(value);

        if (head == NULL)
        {
            head = new_node;
            return;
        }

        node *temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = new_node;
        return;
    }

    void display()
    {

        node *temp = head;

        while (temp != NULL)
        {
            cout << temp->val << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

// iterative approach
node *reverseLL(node *&head)
{

    node *prevPtr = NULL;
    node *currPtr = head;
    node *nextPtr = NULL;

    while (currPtr)
    {
        nextPtr = currPtr->next;
        currPtr->next = prevPtr;

        prevPtr = currPtr;
        currPtr = nextPtr;
    }
    return prevPtr;
}

node *reverseLLRecursively(node *&head)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    node *new_head = reverseLLRecursively(head->next);
    head->next->next = head;
    head->next = NULL;
    return new_head;
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.display();

    l.head = reverseLL(l.head);
    l.display();

    return 0;
}