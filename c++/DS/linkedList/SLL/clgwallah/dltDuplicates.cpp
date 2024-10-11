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

// tc -> O(n)
void deleteDuplicates(node *&head)
{

    node *curr_node = head;

    // for traversing all distinct elements
    while (curr_node)
    {
        // for traversing all similar elements
        while (curr_node->next && curr_node->val == curr_node->next->val)
        {
            // delete curr_node -> next
            node *temp = curr_node->next;
            curr_node->next = curr_node->next->next;

            free(temp);
        }
        // this loop ends when current node and next node values are different
        // or list ends
        curr_node = curr_node->next;
    }

    return;
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(1);
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.display();

    deleteDuplicates(l.head);
    l.display();

    return 0;
}