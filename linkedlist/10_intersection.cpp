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
        insertAtHead(head, val);
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
    cout << endl;
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

// Function for intersecting two linked lists
void intersect(node *&head1, node *&head2, int pos)
{
    node *temp1 = head1;
    pos--;
    while (pos--)
    {
        temp1 = temp1->next;
    }
    node *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp1;
}

// Find the intersection point of two linked lists
int intersection(node *&head1, node *&head2)
{

    int l1 = length(head1);
    int l2 = length(head2);

    int d = 0;
    node *ptr1;
    node *ptr2;
    if (l1 > l2)
    {
        d = l1 - l2;
        ptr1 = head1; // storing larger linked list in ptr1
        ptr2 = head2;
    }
    else
    {
        d = l2 - l1;
        ptr1 = head2;
        ptr2 = head1;
    }
    while (d)
    {
        ptr1 = ptr1->next;
        if (ptr1 == NULL)
        {
            return -1;
        }
        d--;
    }
    while (ptr1 != NULL && ptr2 != NULL)
    {
        if (ptr1 == ptr2)
        {
            return ptr1->data;
        }
        ptr1 = ptr1->next;
        ptr2 = ptr2->next;
    }
}

int main()
{

    node *head = NULL;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        insertatTail(head, arr[i]);
    }
    // display(head);
    node *head1 = NULL;
    int arr1[10] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100};

    for (int i = 0; i < 10; i++)
    {
        insertatTail(head1, arr1[i]);
    }

    intersect(head, head1, 7);
    display(head);
    cout << endl;

    display(head1);
    cout << endl;
    cout << intersection(head, head1);
    cout << endl;

    return 0;
}