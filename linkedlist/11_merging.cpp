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
// Merging 2 Linked list
node *merge(node *&head1, node *&head2)
{
    node *p1 = head1;
    node *p2 = head2;
    node *dummynode = new node(0); // 0 is initializer
    node *p3 = dummynode;
    while (p1 != NULL && p2 != NULL)
    {
        if (p1->data > p2->data)
        {
            p3->next = p2; // smaller value to new node
            p2 = p2->next;
        }
        else
        {
            p3->next = p1;
            p1 = p1->next;
        }
        p3 = p3->next;
    }
    // Now case where either p1/p2 becomes NULL
    while (p1 != NULL)
    {
        p3->next = p1;
        p1 = p1->next;
        p3 = p3->next;
    }
    while (p2 != NULL)
    {
        p3->next = p2;
        p2 = p2->next;
        p3 = p3->next;
    }
    return dummynode;
};

node *mergeRecursion(node *&head1, node *head2)
{
    if (head1 == NULL)
    {
        return head2;
    }
    if (head2 == NULL)
    {
        return head1;
    }
    node *result;
    if (head1->data < head2->data)
    {
        result = head1;
        result->next = mergeRecursion(head1->next, head2);
    }
    else
    {
        result = head2;
        result->next = mergeRecursion(head1, head2->next);
    }
    return result;
}
int main()
{
    node *head1 = NULL;
    node *head2 = NULL;
    int arr1[] = {2, 4, 5, 7};
    int arr2[] = {1, 3, 6};

    for (int i = 0; i < 4; i++)
    {
        insertatTail(head1, arr1[i]);
    }

    for (int i = 0; i < 3; i++)
    {
        insertatTail(head2, arr2[i]);
    }

    cout << "\nLinked list first is:\n";
    display(head1);
    cout << "\nSecond linked list is:\n";
    display(head2);
    cout << endl;
    cout << "New linked list is:" << endl;
    node *newhead = mergeRecursion(head1, head2);
    display(newhead);
}