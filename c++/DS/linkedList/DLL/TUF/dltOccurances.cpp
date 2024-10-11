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

node *deleteAllOccurances(node *&head, int k)
{

    node *temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = head->next;
            }

            node *nextNode = temp->next;
            node *prevNode = temp->prev;

            if (nextNode != NULL)
            {
                nextNode->prev = prevNode;
            }
            if (prevNode != NULL)
            {
                prevNode->next = nextNode;
            }

            free(temp);
            temp = nextNode;
        }
        else
        {
            temp = temp->next;
        }
    }
    return head;
}

int main()
{

    DLL l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(1);
    l.insertAtTail(1);
    l.insertAtTail(5);

    l.display();

    node *ans = deleteAllOccurances(l.head, 1);
    l.display();

    return 0;
}