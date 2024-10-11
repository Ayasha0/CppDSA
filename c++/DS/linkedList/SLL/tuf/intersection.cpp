#include <iostream>
#include <unordered_set>
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
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
};

node *brute(node *head1, node *head2)
{
    unordered_set<node *> mpp;

    node *temp = head1;

    while (temp != NULL)
    {
        mpp.insert(temp);
        temp = temp->next;
    }

    temp = head2;
    while (temp != NULL)
    {
        if (mpp.find(temp) != mpp.end())
        {
            return temp;
        }
    }
    return NULL;
}

// better
int getLength(node *head)
{
    int len = 0;
    node *temp = head;
    while (temp != NULL)
    {
        len++;
        temp = temp->next;
    }
    return len;
}

node *moveByK(node *&head, int k)
{
    node *temp = head;
    while (k--)
    {
        temp = temp->next;
    }
    return temp;
}

node *better(node *&head1, node *&head2)
{

    int l1 = getLength(head1);
    int l2 = getLength(head2);

    node *ptr1, *ptr2;
    if (l1 > l2)
    {
        int k = l1 - l2;
        ptr1 = moveByK(head1, k);
        ptr2 = head2;
    }
    else
    {
        int k = l2 - l1;
        ptr1 = head1;
        ptr2 = moveByK(head2, k);
    }

    while (ptr1)
    {
        if (ptr1 == ptr2)
        {
            return ptr1;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return NULL;
}

// optimnal
node *getIntersection(node *&head1, node *&head2)
{
    if (head1 == NULL || head2 == NULL)
    {
        return NULL;
    }

    node *temp1 = head1;
    node *temp2 = head2;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
        {
            return temp1;
        }

        if (temp1 == NULL)
        {
            temp1 = head2;
        }
        if (temp2 == NULL)
        {
            temp2 = head1;
        }
    }
    return temp1;
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtTail(6);

    linkedList l1;
    l1.insertAtTail(9);
    l1.insertAtTail(8);
    l1.head->next->next = l.head->next->next->next;

    l.display();
    l1.display();

    node *ans = getIntersection(l.head, l1.head);
    if (ans != NULL)
    {
        cout << ans->data;
    }
    else
    {
        cout << "-1";
    }

    return 0;
}