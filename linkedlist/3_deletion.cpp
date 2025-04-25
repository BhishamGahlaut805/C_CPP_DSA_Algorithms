#include <iostream>
using namespace std;

struct node
{
    int data;
    struct node *next;
};
void linkedlisttraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

// Case 1 Deletion At head/Beginning of a linked list
struct node *deleteathead(struct node *head)
{
    struct node *p = head;
    head = head->next;
    free(p);
    return head;
};

// Case 2: Deleting the element at a given index from the linked list
struct node *deleteAtIndex(struct node *head, int index)
{
    struct node *p = head;
    struct node *q = head->next;
    for (int i = 0; i < index - 1; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    return head;
};

// Case 3: Deletion at last of a linked list
struct node *deleteAtLast(struct node *head)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
    return head;
};

// Case 4: Deletion at given value of a linked list
struct node *deleteAtValue(struct node *head, int value)
{
    struct node *p = head;
    struct node *q = head->next;
    while (q->data != value && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == value)
    {
        p->next = q->next;
        free(q);
    }
    return head;
};
int main()
{
    // Allocate memory for linked list in heap
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    cout << "Linked list before insertion \n";
    // link first and second nodes
    head->data = 7;
    head->next = second;
    // link second and third nodes
    second->data = 11;
    second->next = third;
    // link third and fourth nodes
    third->data = 66;
    third->next = fourth;
    // terminate the list at fourth node
    fourth->data = 71;
    fourth->next = NULL;

    linkedlisttraversal(head);

    // cout << "\nLinked list after deletion at head \n";
    // struct node *head1 = (struct node *)malloc(sizeof(struct node));

    // head1 = deleteathead(head);
    // linkedlisttraversal(head1);

    //  cout << "\nLinked list after deletion in between \n";
    // struct node *head2 = (struct node *)malloc(sizeof(struct node));

    // head2 = deleteAtIndex(head,2);
    // linkedlisttraversal(head2);

    //      cout << "\nLinked list after deletion at last\n";
    // struct node *head3 = (struct node *)malloc(sizeof(struct node));

    // head3 = deleteAtLast(head);
    // linkedlisttraversal(head3);

    cout << "\nLinked list after deletion at value \n";
    struct node *head2 = (struct node *)malloc(sizeof(struct node));

    head2 = deleteAtValue(head, 66);
    linkedlisttraversal(head2);

    return 0;
}
