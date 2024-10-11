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

// tc ->
bool checkEqualLL(node *&head1, node *&head2)
{
    node *ptr1 = head1;
    node *ptr2 = head2;

    while (ptr1 && ptr2)
    {
        if (ptr1->val != ptr2->val)
        {
            return false;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
    return true;
}

int main()
{

    linkedList l, l1;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);

    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l.display();
    l1.display();

    cout << checkEqualLL(l.head, l1.head);

    return 0;
}