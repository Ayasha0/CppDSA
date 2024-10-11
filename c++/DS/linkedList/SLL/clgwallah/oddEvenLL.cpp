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

void oddEvenLL(node *&head)
{
    node *oddHead = head;
    node *evenHead = head->next;

    node *oddPtr = oddHead;
    node *evenPtr = evenHead;

    while (evenPtr && evenPtr->next)
    {
        oddPtr->next = oddPtr->next->next;
        evenPtr->next = evenPtr->next->next;

        oddPtr = oddPtr->next;
        evenPtr = evenPtr->next;
    }

    oddPtr->next = evenHead;
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

    oddEvenLL(l.head);
    l.display();

    return 0;
}