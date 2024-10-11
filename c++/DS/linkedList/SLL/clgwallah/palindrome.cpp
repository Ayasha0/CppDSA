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

// find middle ele
//  break LL into 2
//  reverse second half LL
//  compare the 2 parts of LL

bool palindrome(node *head)
{
    node *slow = head;
    node *fast = head;

    // find middle ele
    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }

    // break LL into 2
    node *curr = slow->next;
    node *prev = slow;
    slow->next = NULL;

    // reverse second half LL
    while (curr)
    {
        node *nextPtr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextPtr;
    }

    // compare the 2 parts of LL
    node *head1 = head;
    node *head2 = prev;

    while (head2)
    {
        if (head1->val != head2->val)
        {
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    return true;
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    // l.insertAtTail(4);
    l.insertAtTail(2);
    l.insertAtTail(1);
    l.display();

    cout << palindrome(l.head);

    return 0;
}