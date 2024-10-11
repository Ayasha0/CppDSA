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

// brute
node *brute(node *head)
{

    node *temp = head;
    int n = 0;

    while (temp)
    {
        n++;
        temp = temp->next;
    }

    int middle = (n / 2) + 1;
    temp = head;
    while (middle--)
    {
        if (middle == 0)
            break;
        temp = temp->next;
    }
    return temp;
}

// optimal
//  FAST SLOW POINTERS
node *middle(node *head)
{
    node *slow = head;
    node *fast = head;

    while (fast && fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);

    l.display();

    node *middleNode = middle(l.head);
    cout << middleNode->data;

    return 0;
}