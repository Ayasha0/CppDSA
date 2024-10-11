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

node *mergeLLs(node *&head1, node *&head2)
{

    node *dummyHead = new node(-1);

    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummyHead;

    while (ptr1 && ptr2)
    {
        if (ptr1->val < ptr2->val)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    if (ptr1)
    {
        ptr3->next = ptr1;
    }

    if (ptr2)
    {
        ptr3->next = ptr2;
    }

    return dummyHead->next;
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(3);
    l.insertAtTail(5);

    linkedList l1;

    l1.insertAtTail(2);
    l1.insertAtTail(4);
    l1.insertAtTail(6);
    l1.insertAtTail(7);

    l.display();
    l1.display();

    linkedList l2;
    l2.head = mergeLLs(l.head, l1.head);
    l2.display();

    return 0;
}