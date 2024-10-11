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

int getLength(node *head)
{
    int len = 0;
    node *temp = head;

    while (temp != NULL)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

node *moveHeadByK(node *head, int k)
{
    node *ptr = head;
    while (k--)
    {
        ptr = ptr->next;
    }
    return ptr;
}

// tc ->
node *getIntersection(node *&head1, node *&head2)
{

    // step 1
    // find lengths of LL
    int l1 = getLength(head1);
    int l2 = getLength(head2);

    // step2
    // find differnce k between LLs and move longer LL ptr by k steps
    node *ptr1, *ptr2;
    if (l1 > l2)
    {
        int k = l1 - l2;
        ptr1 = moveHeadByK(head1, k);
        ptr2 = head2;
    }
    else
    {
        int k = l2 - l1;
        ptr1 = head1;
        ptr2 = moveHeadByK(head2, k);
    }

    // step3
    // compare ptr1 and ptr2
    while (ptr1)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
            // cout << ptr1->val;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

int main()
{

    linkedList l, l1;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);

    l1.insertAtTail(6);

    l1.head->next = l.head->next->next->next;
    l.display();
    l1.display();

    node *intersection = getIntersection(l.head, l1.head);

    if (intersection)
    {
        cout << intersection->val;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}