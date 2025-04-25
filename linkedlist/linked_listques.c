#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the node structure
typedef struct node
{
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

// Function to reverse a linked list
node *reverse(node *head)
{
    node *prev = NULL;    // Initialize the previous pointer to NULL
    node *current = head; // Start with the head of the list
    node *next;           // To keep track of the next node

    // Traverse through the list
    while (current != NULL)
    {
        next = current->next; // Store the next node
        current->next = prev; // Reverse the current node's pointer
        prev = current;       // Move the previous pointer to current node
        current = next;       // Move to the next node in the original list
    }
    return prev; // prev will be the new head of the reversed list
}

// Function to find and print the middle element of the linked list
struct node *mid(struct node *head)
{
    struct node *ptr = head; // Initialize ptr to head
    struct node *p = head;
    int len = 0;

    // Calculate the length of the linked list
    while (ptr != NULL)
    {
        len++;
        ptr = ptr->next;
    }

    // Move p to the middle of the list
    for (int i = 0; i < len / 2; i++)
    {
        p = p->next;
    }

    // Print the middle element
    printf("Mid element is at index %d and value is: %d\n", len / 2, p->data);
    return head;
}

// Function to swap adjacent nodes in a linked list
node *swap(node *head)
{
    // If the list is empty or has only one node, no swap is needed
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    // New head will be the second node
    node *newHead = head->next;
    node *prev = NULL;
    node *current = head;

    // Loop through the list in pairs
    while (current != NULL && current->next != NULL)
    {
        node *nextPair = current->next->next; // Store the node after the pair
        node *second_pair = current->next;    // The second node in the pair

        // Swap the pair
        second_pair->next = current;
        current->next = nextPair;

        // Connect the previous pair with the current swapped pair
        if (prev != NULL)
        {
            prev->next = second_pair;
        }

        // Move pointers forward
        prev = current;
        current = nextPair;
    }
    return newHead; // Return the new head of the modified list
}

// Function to remove duplicates from a sorted linked list
node *removeDuplicates(node *head)
{
    node *ptr = head;
    while (ptr != NULL && ptr->next != NULL)
    {
        if (ptr->data == ptr->next->data)
        {
            ptr->next = ptr->next->next; // Remove duplicate
        }
        else
        {
            ptr = ptr->next; // Move to next node
        }
    }
    return head;
}

// Function to detect a loop in the linked list
bool detect_loop(struct node *head)
{
    struct node *slow = head;
    struct node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true; // Loop detected
        }
    }
    return false; // No loop
}

// Function to insert a new node at the head of the linked list
node *insert_head(node *head, int val)
{
    node *ptr = (node *)malloc(sizeof(node)); // Allocate memory for new node
    ptr->data = val;                          // Set the data of the new node
    if (head == NULL)
    {
        head = ptr;
        head->next = NULL;
    }
    else
    {
        ptr->next = head;
        head = ptr;
    }
    return head;
}

int main()
{
    // node *head = NULL; // Initialize head to NULL
    // head = insert_head(head, 50);
    // head = insert_head(head, 40);
    // head = insert_head(head, 30);
    // head = insert_head(head, 20);
    // head = insert_head(head, 10);

    // printf("Original Linked List : ");
    // display(head);        // Display the original list
    // printf("Reverse Linked List : ");
    // head = reverse(head); // Reverse the list
    // display(head);        // Display the reversed list

    // head = mid(head);
    // head = swap(head);

    // display(head);

    //For removeduplicates

    // node *head = NULL; // Initialize head to NULL
    // head = insert_head(head, 50);
    // head = insert_head(head, 40);
    // head = insert_head(head, 40);
    // head = insert_head(head, 40);
    // head = insert_head(head, 10);
    // printf("Original Sorted Linked List : ");
    // display(head);        // Display the original list
    // head = removeDuplicates(head);
    // display(head);

    //For loop detection
    node *head = NULL; // Initialize head to NULL
    head = insert_head(head, 50);
    head = insert_head(head, 40);
    head = insert_head(head, 40);
    head = insert_head(head, 40);
    head = insert_head(head, 10);
    printf("Original Sorted Linked List : ");
    display(head); // Display the original list
    if(detect_loop(head)==true){
        printf("Loop detected\n");
    }
    else{
        printf("No loop detected\n");
    }
    printf("Making a loop in original Linked List...\n");
    head->next->next = head;
    if (detect_loop(head) == true)
    {
        printf("Loop detected\n");
    }
    else
    {
        printf("No loop detected\n");
    }
    return 0;
}
