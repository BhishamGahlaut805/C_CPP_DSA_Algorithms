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

int main()
{
    // Allocate memory for linked list in heap
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

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
    return 0;
}
