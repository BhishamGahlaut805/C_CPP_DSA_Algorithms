#include <iostream>
using namespace std;

class node
{

public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

void insertAtHead(node *&head, int val)
{
    node *n = new node(val);
    n->next = head;
    head = n;
}
void insertatTail(node *&head, int val)

{
    if (head == NULL)
    {
        insertAtHead(head, 1);
        return;
    }
    node *n = (node *)malloc(sizeof(node));
    n->data = val;
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->next = NULL;
}
void display(node *head)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
};
int length(node *head)
{
    int count = 0;
    node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
};
//Main Function to put even/odd alternates

void evenAfterOdd(node *head)
{
    node *odd = head;
    node *even = head->next;
    node *evenstart = even;
    while (odd->next != NULL && even->next != NULL)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = evenstart;
    if (odd->next != NULL)
    {
        even->next = NULL;
    }
}
int main()
{
    node *head = NULL;
    int arr[10] = {91,23 ,32, 4, 500, 61, 71, 80, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        insertatTail(head, arr[i]);
    }
    display(head);
    cout << endl;
    evenAfterOdd(head);
    display(head);
}