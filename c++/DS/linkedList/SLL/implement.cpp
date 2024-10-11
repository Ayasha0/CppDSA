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

    void insertAtHead(int value)
    {
        node *new_node = new node(value);

        if (head == NULL)
        {
            head = new_node;
            return;
        }

        new_node->next = head;

        head = new_node;
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
    }

    void insertAtPos(int value, int pos)
    {

        if (pos == 0)
        {
            insertAtHead(value);
            return;
        }

        node *new_node = new node(value);

        int currPos = 0;
        node *temp = head;

        while (currPos != pos - 1)
        {
            temp = temp->next;
            currPos++;
        }

        new_node->next = temp->next;
        temp->next = new_node;
    }

    void deleteHead()
    {

        node *temp = head;
        head = head->next;

        free(temp);
    }

    void deleteNode(int pos)
    {

        if (pos == 0)
        {
            deleteHead();
            return;
        }

        else
        {
            node *curr = head;
            node *prev = NULL;

            int currPos = 0;

            while (currPos < pos)
            {
                prev = curr;
                curr = curr->next;
                currPos++;
            }

            prev->next = curr->next;
            free(curr);
        }
    }

    void update(int value, int pos)
    {
        int currPos = 0;
        node *temp = head;

        while (currPos != pos)
        {
            temp = temp->next;
            currPos++;
        }

        temp->val = value;
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
        cout << "NULL " << endl;
    }
};

int main()
{

    linkedList l;
    l.insertAtHead(3);
    l.insertAtHead(2);
    l.insertAtHead(1);
    l.display();

    l.insertAtTail(4);
    l.display();

    l.insertAtPos(3, 1);
    l.display();

    l.deleteNode(1);
    l.display();

    l.update(5, 3);
    l.display();

    return 0;
}