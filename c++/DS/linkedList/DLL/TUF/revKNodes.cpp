#include <iostream>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

class DLL
{
public:
    node *head;
    node *tail;

    DLL()
    {
        head = NULL;
        tail = NULL;
    }

    void insertAtTail(int val)
    {
        node *new_node = new node(val);

        if (head == NULL)
        {
            head = new_node;
            tail = new_node;
            return;
        }

        tail->next = new_node;
        new_node->prev = tail;
        tail = new_node;
        return;
    }

    void display()
    {
        node *temp = head;
        while (temp)
        {
            cout << temp->data << "  ";
            temp = temp->next;
        }
        cout << endl;
    }
};

void reverseLL(node *&head)
{
    node *prevPtr = NULL;
    node *curr = head;
    node *nextPtr = NULL;

    while (curr)
    {
        nextPtr = curr->next;
        curr->next = prevPtr;

        prevPtr = curr;
        curr = nextPtr;
    }
    head = prevPtr;
}

node *getKthNode(node *temp, int k)
{
    k -= 1;

    while (temp && k < 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

node *kReverse(node *&head, int k)
{

    node *temp = head;
    node *prevNode = NULL;

    while (temp != NULL)
    {
        node *kthNode = getKthNode(temp, k);

        if (kthNode == NULL)
        {
            if (prevNode)
                prevNode->next = temp;
            break;
        }

        node *nextNode = kthNode->next;
        kthNode->next = NULL;

        reverseLL(temp);

        if (temp == head)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }

        prevNode = temp;
        temp = nextNode;
    }
    return head;
}

int main()
{

    DLL l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);
    l.insertAtTail(6);
    l.insertAtTail(7);
    l.insertAtTail(8);

    l.display();

    // reverseLL(l.head);
    l.head = kReverse(l.head, 3);
    l.display();

    return 0;
}