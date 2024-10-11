#include <iostream>
#include <vector>
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

vector<pair<int, int>> findPairs(node *head, node *tail, int k)
{

    vector<pair<int, int>> ans;

    node *left = head;
    node *right = tail;

    while (left->data <= right->data)
    {
        if (left->data + right->data == k)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (left->data + right->data < k)
        {
            left = left->next;
        }
        else
        {
            right = right->prev;
        }
    }
    return ans;
}

int main()
{

    DLL l;
    l.insertAtTail(1);
    l.insertAtTail(2);
    l.insertAtTail(3);
    l.insertAtTail(4);
    l.insertAtTail(5);

    l.display();

    vector<pair<int, int>> ans = findPairs(l.head, l.tail, 5);

    for (auto i : ans)
    {
        cout << "{ " << i.first << " , " << i.second << " }" << endl;
    }

    return 0;
}