#include <iostream>
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

    void insertAtTail(int val)
    {
        node *new_node = new node(val);

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
            cout << temp->data << "-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
        return;
    }
};

void insertAtTail(node *&ansHead, node *&ansTail, int val)
{
    node *new_node = new node(val);

    if (ansHead == NULL)
    {
        ansHead = new_node;
        ansTail = new_node;
        return;
    }

    ansTail->next = new_node;
    ansTail = new_node;
    return;
}

node *reverseLL(node *&head)
{
    node *prevPtr = NULL;
    node *curr = head;
    node *nextPtr = NULL;

    while (curr)
    {
        // cout << "prevptr " << prevPtr->data << endl;
        // cout << "curr " << curr->data << endl;
        // cout << "nextptr " << nextPtr->data << endl;
        nextPtr = curr->next;
        curr->next = prevPtr;

        prevPtr = curr;
        curr = nextPtr;
    }
    return prevPtr;
}

node *add(node *&first, node *&second)
{
    int carry = 0;

    node *ansHead = NULL;
    node *ansTail = NULL;

    while (first != NULL || second != NULL || carry != 0)
    {

        int val1 = 0;
        if (first != NULL)
        {
            val1 = first->data;
        }

        int val2 = 0;
        if (second != NULL)
        {
            val2 = second->data;
        }

        int sum = carry + val1 + val2;

        int digit = sum % 10;

        insertAtTail(ansHead, ansTail, digit);

        carry = sum / 10;

        if (first != NULL)
        {
            first = first->next;
        }
        if (second != NULL)
        {
            second = second->next;
        }
    }

    return ansHead;
}

node *add2LLs(node *first, node *second)
{
    first = reverseLL(first);
    second = reverseLL(second);

    node *ans = add(first, second);
    ans = reverseLL(ans);

    return ans;
}

int main()
{

    linkedList l;
    linkedList l1;

    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);

    l1.insertAtTail(4);
    l1.insertAtTail(5);
    l1.insertAtTail(8);
    l1.insertAtTail(3);

    l.display();
    l1.display();

    linkedList ans;
    ans.head = add2LLs(l.head, l1.head);
    ans.display();

    return 0;
}