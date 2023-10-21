#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    ~Node()
    {
        int v = this->data;
        if (this->next != NULL)
        {
            delete next;
            // this->next = NULL;
        }
        cout << "memory freed for node with data : " << v << endl;
    }
};

void insertAtHead(Node *&head, int d)
{
    // create new node
    Node *temp = new Node(d);
    temp->next = head;
    // *temp.next
    head = temp;
}

void insertAtTail(Node *&tail, int d)
{
    Node *temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtMiddle(Node *&head, Node *&tail, int position, int d)
{
    if (position == 1)
    {
        insertAtHead(head, d);
        return;
    }
    int count = 1;
    Node *temp = head;
    Node *nodeToInsert = new Node(d);
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        insertAtTail(tail, d);
        return;
    }
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void deleteNode(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete (temp);
    }
    else
    {
        Node *current = head;
        int count = 1;
        Node *prev = NULL;
        while (count < position)
        {
            prev = current;
            current = current->next;
            count++;
        }
        if (current->next == NULL)
        {
            tail = prev;
            prev->next = NULL;
            delete current;
            return;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}