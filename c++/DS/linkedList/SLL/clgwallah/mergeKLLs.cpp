#include <iostream>
#include <vector>
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

node *mergeLLs(node *&head1, node *&head2)
{

    node *dummyHead = new node(-1);

    node *ptr1 = head1;
    node *ptr2 = head2;
    node *ptr3 = dummyHead;

    while (ptr1 && ptr2)
    {
        if (ptr1->val < ptr2->val)
        {
            ptr3->next = ptr1;
            ptr1 = ptr1->next;
        }
        else
        {
            ptr3->next = ptr2;
            ptr2 = ptr2->next;
        }
        ptr3 = ptr3->next;
    }

    while (ptr1)
    {
        ptr3->next = ptr1;
        ptr1 = ptr1->next;
        ptr3 = ptr3->next;
    }

    while (ptr2)
    {
        ptr3->next = ptr2;
        ptr2 = ptr2->next;
        ptr3 = ptr3->next;
    }

    return dummyHead->next;
}

node *mergeKLLs(vector<node *> &lists)
{
    while (lists.size() > 1)
    {
        node *mergedHead = mergeLLs(lists[0], lists[1]);
        lists.push_back(mergedHead);
        lists.erase(lists.begin());
        lists.erase(lists.begin());
    }
    return lists[0];
}

int main()
{

    linkedList l;

    l.insertAtTail(1);
    l.insertAtTail(7);
    l.insertAtTail(8);

    linkedList l1;

    l1.insertAtTail(2);
    l1.insertAtTail(4);
    l1.insertAtTail(5);

    linkedList l2;

    l2.insertAtTail(3);
    l2.insertAtTail(6);

    l.display();
    l1.display();
    l2.display();

    vector<node *> lists;
    lists.push_back(l.head);
    lists.push_back(l1.head);
    lists.push_back(l2.head);

    linkedList mergedLL;
    mergedLL.head = mergeKLLs(lists);
    mergedLL.display();

    return 0;
}