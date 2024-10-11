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

node *rotateByKPlaces(node *&head, int k)
{
    // find length
    int n = 0;

    // find tail
    node *tail = head;
    while (tail->next)
    {
        tail = tail->next;
        n++;
    }
    // for including last node
    n++;

    k = k % n;
    if (k == 0)
    {
        return head;
    }

    // point tail->next = head
    tail->next = head;

    // move to n-k position
    node *temp = head;
    for (int i = 1; i < n - k; i++)
    {
        temp = temp->next;
    }

    // now temp pointing to n-k node
    node *newHead = temp->next;
    temp->next = NULL;

    // return newHead
    return newHead;
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
    l.display();

    l.head = rotateByKPlaces(l.head, 3);
    l.display();

    return 0;
}