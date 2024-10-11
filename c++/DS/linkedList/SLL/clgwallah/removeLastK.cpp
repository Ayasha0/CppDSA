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

void deleteLastKthNode(node *&head, int k)
{
    node *ptr1 = head;
    node *ptr2 = head;

    // move ptr2 k steps ahead
    int count = k;
    while (count--)
    {
        ptr2 = ptr2->next;
    }

    // if ptr2 is at NULL that means
    // node to be deleted is head;
    if (ptr2 == NULL)
    {
        node *temp = head;
        head = head->next;
        free(temp);
        return;
    }

    // now ptr2 is k steps ahead of ptr1
    //  when ptr2 is at NULL, ptr1 will be at node to be deleted
    while (ptr2->next != NULL)
    {
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }

    // now ptr2 is before node to be deleted
    node *temp = ptr1->next;
    ptr1->next = ptr1->next->next;
    free(temp);
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.display();

    deleteLastKthNode(l.head, 3);
    l.display();

    return 0;
}