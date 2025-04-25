#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node
{
    struct node *prev;
    int data;
    struct node *next;
} node;

// Function to display the linked list
void display(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        printf("%d->", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
// Insertion at head in doubly linked list
node *insert_head(node *head, int val)
{
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = val;  // Set the data for the new node
    ptr->prev = NULL; // The previous node of the new node is always NULL

    if (head == NULL)
    {
        ptr->next = NULL; // If the list is empty, next is NULL
        head = ptr;
    }
    else
    {
        ptr->next = head; // New node's next points to the current head
        head->prev = ptr; // Current head's previous points to the new node
        head = ptr;       // Update head to the new node
    }
    return head;
}
// Deletion at Front
node*delete_head(node*head){
    node *p = head;
    head = head->next;
    head->prev = NULL;
    free(p);
    p = NULL;
    return head;
}
node*insert_end(node*head,int val){
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = val;
    ptr->next = NULL;

    if (head == NULL)
    {
        head = ptr;
    }
    else{
        node *p = head;
        while(p->next!=NULL){
            p = p->next;
        }
        p->next = ptr;
        ptr->prev = p;

    }
    return head;
}
//Delete at end in a doubly linked list
node*delete_end(node*head){
    if(head==NULL){
        return NULL;
    }
    else if (head->next == NULL)
    {
        free(head);
        head = NULL;
    }
    else{
        node *p = head;
        while(p->next!=NULL){
            p = p->next;
        }
        p->prev->next = NULL;
        free(p);
        p = NULL;
    }
    return head;
}

// Function to insert a node before a given node
node *insert_between(node *head, int val, int pos)
{
    // Create a new node and set its data
    node *ptr = (node *)malloc(sizeof(node));
    ptr->data = val;

    // If the list is empty, insert the node as the head
    if (head == NULL)
    {
        ptr->next = NULL;
        ptr->prev = NULL;
        head = ptr;
    }
    else
    {
        node *p = head;
        // Traverse the list to find the position
        while (p != NULL && p->data != pos)
        {
            p = p->next;
        }

        // If the position is found
        if (p != NULL)
        {
            ptr->next = p;
            ptr->prev = p->prev;
            // If the node to insert before is not the head
            if (p->prev != NULL)
            {
                p->prev->next = ptr;
            }
            else
            { // If the node to insert before is the head
                head = ptr;
            }
            p->prev = ptr;
        }
        else
        {
            // If the position is not found, free the allocated memory
            free(ptr);
        }
    }
    return head;
}

// Function to delete the node before a given node
node *delete_before(node *head, int pos)
{
    if (head == NULL || head->next == NULL)
    {
        return head; // Nothing to delete if the list is empty or has only one node
    }

    node *current = head;
    // Traverse to find the node with the given value
    while (current != NULL && current->data != pos)
    {
        current = current->next;
    }

    // If the node with the given value is found
    if (current != NULL && current->prev != NULL)
    {
        node *to_delete = current->prev;

        // If the node to delete is the head node
        if (to_delete == head)
        {
            head = head->next;
            head->prev = NULL;
        }
        else
        {
            to_delete->prev->next = current;
            current->prev = to_delete->prev;
        }

        free(to_delete);
    }

    return head;
}
int main()
    {
        // node *head = NULL;
        // head = insert_head(head, 10);
        // head = insert_head(head, 20);
        // head = insert_head(head, 30);
        // head = insert_head(head, 40);
        // printf("Original Linked List : ");
        // display(head);
        // printf("After Delete at Head : ");
        // head = delete_head(head);
        // display(head);

        // //At End

        // node *head = NULL;
        // head = insert_end(head, 10);
        // head = insert_end(head, 20);
        // head = insert_end(head, 30);
        // head = insert_end(head, 40);
        // printf("Original Linked List : ");
        // display(head);
        // printf("After Delete at Tail : ");
        // head = delete_end(head);
        // display(head);

        // At Mid

        node *head = NULL;
        head = insert_between(head, 10,10);
        head = insert_between(head, 20,10);
        head = insert_between(head, 30,10);
        head = insert_between(head, 40,30);
        printf("Original Linked List : ");
        display(head);

        printf("After Deleting before 30 : ");
        head = delete_before(head,30);
        display(head);
        printf("After Deleting before 10 : ");
        head = delete_before(head, 10);
        display(head);
    }
