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
// Case1 Insertion At The Beginning
struct node *insertatbeginning(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = head;
    return ptr; // ptr= updated head/linked list
};

// Case2 Insertion in between
struct node *insertatIndex(struct node *head, int data, int index)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    struct node *p = head; // for securing our list
    int i = 0;

    // for reaching to the location of insertion
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next; // making insertion new list pointer->next to original list->next
    p->next = ptr;
    return head;
};

// Case3 Insertion at end
struct node *insertatEnd(struct node *head, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    struct node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
};

// Case4 insertion at Node
struct node *insertatNode(struct node *head, struct node *preNode, int data)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = data;
    ptr->next = preNode->next;
    preNode->next = ptr;
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

    cout << "\nLinked list after insertion at head \n";
    struct node *head1 = (struct node *)malloc(sizeof(struct node));

    head1 = insertatbeginning(head, 100);
    linkedlisttraversal(head1);

    cout << "\nLinked list after insertion in between \n";
    struct node *head2 = (struct node *)malloc(sizeof(struct node));

    head2 = insertatIndex(head, 100, 3);
    linkedlisttraversal(head2);

    cout << "\nLinked list after insertion at end \n";
    struct node *head3 = (struct node *)malloc(sizeof(struct node));

    head3 = insertatEnd(head, 100);
    linkedlisttraversal(head3);

    cout << "\nLinked list after insertion at Node \n";
    struct node *head4 = (struct node *)malloc(sizeof(struct node));

    //insert after below code
    
    head4 = insertatNode(head, second, 11);
    linkedlisttraversal(head4);

    return 0;
}
