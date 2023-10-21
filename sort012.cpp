#include <iostream>
#include "linkedlist.cpp"

using namespace std;

Node *sort_0_1_2(Node *head)
{
    Node *zero = NULL;
    Node *one = NULL;
    Node *two = NULL;
    Node *temp = head;
    Node *zero_temp = zero;
    Node *one_temp = one;
    Node *two_temp = two;
    while (temp != NULL)
    {

        if (temp->data == 0 && zero == NULL)
        {
            zero = temp;
            zero_temp = zero;
        }
        else if (temp->data == 0 && zero != NULL)
        {
            zero_temp->next = temp;
            zero_temp = temp;
        }
        else if (temp->data == 1 && one == NULL)
        {
            one = temp;
            one_temp = one;
        }
        else if (temp->data == 1 && one != NULL)
        {
            one_temp->next = temp;
            one_temp = temp;
        }
        else if (temp->data == 2 && two == NULL)
        {
            two = temp;
            two_temp = two;
        }
        else if (temp->data == 2 && two != NULL)
        {
            two_temp->next = temp;
            two_temp = temp;
        }
        temp = temp->next;
    }

    zero_temp->next = one;
    one_temp->next = two;
    two_temp->next = NULL;
    head = zero;
    return head;
}

int main()
{
    Node *n = new Node(2);
    Node *tail = n;
    insertAtTail(tail, 0);
    insertAtTail(tail, 2);
    insertAtTail(tail, 1);
    insertAtTail(tail, 2);

    print(n);

    Node *a = sort_0_1_2(n);
    print(a);
    return 0;
}