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

// node *add(node *&list)
// {
//     int carry = 1;

//     node *ansHead = NULL;
//     node *ansTail = NULL;

//     while (list != NULL)
//     {

//         int val = 0;

//         val = list->data;

//         int sum = carry + val;

//         int digit = sum % 10;

//         insertAtTail(ansHead, ansTail, digit);

//         carry = sum / 10;

//         list = list->next;
//     }

//     if (carry != 0)
//     {
//         insertAtTail(ansHead, ansTail, carry);
//     }

//     return ansHead;
// }

// node *add1(node *list)
// {
//     list = reverseLL(list);

//     node *ans = add(list);
//     ans = reverseLL(ans);

//     return ans;
// }

// TUF
// Brute force
// tc -> O(3n)
// sc -> O(1)
node *brute(node *&head)
{
    int carry = 1;
    node *temp = head;

    // O(n)
    while (temp != NULL)
    {
        temp->data = temp->data + carry;

        if (temp->data < 10)
        {
            carry = 0;
            break;
        }
        if (temp->data >= 10)
        {
            carry = 1;
            temp->data = 0;
        }
        temp = temp->next;
    }

    if (carry != 0)
    {
        node *new_node = new node(carry);

        head = reverseLL(head); // O(n)
        new_node->next = head;
        return new_node;
    }
    head = reverseLL(head); // O(n)
    return head;
}

// optimal
// tc -> O(n)
// sc -> O(n)

int addMe(node *temp)
{
    if (temp == NULL)
    {
        return 1;
    }

    int carry = addMe(temp->next);
    temp->data += carry;

    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

node *add1(node *head)
{
    int carry = addMe(head);

    if (carry == 1)
    {
        node *new_node = new node(1);
        new_node->next = head;
        head = new_node;
    }

    return head;
}

int main()
{

    linkedList l;

    l.insertAtTail(9);
    l.insertAtTail(9);
    l.insertAtTail(9);

    l.display();

    linkedList ans;
    ans.head = add1(l.head);
    ans.display();

    return 0;
}