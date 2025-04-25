#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <malloc.h>

// Complete Linked list all operations in one code

// Simple Linked List

struct node
{
    int data;
    struct node *next;
};

// doubly Linked List
struct node_d
{
    struct node_d *next;
    int data;
    struct node_d *prev;
};

struct node *start = NULL;
struct node *start_circular = NULL;
struct node_d *start_double = NULL;

// 1.Create a Linked list
struct node *create(struct node *start)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("\n Enter any number to add in list | -1 to make it");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    { //-1 shows list not started(error statement)
        new_node->data = num;
        if (start == NULL)
        {                          // Empty linked list
            new_node->next = NULL; // Inserted the element num
            start = new_node;      // At beginning so start become new_node
        }
        else
        {
            ptr = start; // Saving start pointer to avoid garbage value
            // Adding element after start element
            while (ptr->next != NULL)
            {

                ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = NULL;
            }
            printf("\n Enter the data : ");
            scanf("%d", &num);
        }
    }
    return start;
}
// 2.Display a Linked list
struct node *display(struct node *start)
{
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr = start;
    int i = 1;
    while (ptr != NULL)
    {
        printf("\n Element %d : %d", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
    return start;
}

// 3.Insert at beginning
struct node *insert_at_begin(struct node *start)
{
    int num;
    printf("\n Enter the number to insert at beginning : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;   // Making links as in a chain
    ptr->next = start; // Making links as in a chain
    start = ptr;
    return start;
}

// 4.Insert at End
struct node *insert_at_end(struct node *start)
{
    int num;
    printf("\n Enter the number to insert at End : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;        // Node to be added
    struct node *p = start; // Saving our start node
    while (p->next != NULL)
    {
        p = p->next;
    }
    // Now reached at the last node
    p->next = ptr;    // Making links at the end
    ptr->next = NULL; // Making links at the end

    return start;
}
// 5.Add a node at a given position
struct node *insert_at_idx(struct node *start)
{
    int pos;
    printf("\n Enter the position at which you want to insert in between : ");
    scanf("%d", &pos);
    int num;
    printf("\n Enter the number to be inserted in between  : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    struct node *p = start;
    int i = 0;
    if (pos != 1)
    {
        while (i != pos - 2)
        {
            p = p->next;
            i++;
        }
        // Reached at the desired location
        ptr->next = p->next; // Making links
        p->next = ptr;

        return start;
    }
    else
    {
        printf("\n Choose right option ");
        return start;
    }
}
// 6.Add a node before a given Node
struct node *insert_before(struct node *start)
{
    int val;
    printf("\n Enter the node before you want to insert : ");
    scanf("%d", &val);
    int num;
    printf("\n Enter the number to insert : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    struct node *p = start;
    struct node *preptr;
    while (p->data != val)
    {
        preptr = p; // preptr will be the position of p(start) before num(to be added)
        p = p->next;
    }
    preptr->next = ptr; // Making links
    ptr->next = p;      // Making links
    return start;
}

// 7.Add a node after a given node

struct node *insert_after(struct node *start)
{
    int val;
    printf("\n Enter the node after you want to insert : ");
    scanf("%d", &val);
    int num;
    printf("\n Enter the number to insert : ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    ptr->data = num;
    struct node *p = start;
    struct node *preptr = p;
    while (preptr->data != val)
    {               //
        preptr = p; // preptr will be the position of p(start) before num(to be added)
        p = p->next;
    }
    preptr->next = ptr; // Making links
    ptr->next = p;      // Making links
    return start;
}

// 8.Replace a given node
struct node *replace(struct node *start)
{
    int val;
    printf("\n Enter the node you want to replace with : ");
    scanf("%d", &val);
    int num;
    printf("\n Enter the new number you want to replace in place of: ");
    scanf("%d", &num);
    struct node *ptr = (struct node *)malloc(sizeof(struct node));

    ptr->data = num;
    struct node *p = start;
    struct node *preptr;
    while (p->data != val)
    {
        preptr = p;
        p = p->next;
    }
    preptr->next = ptr;
    ptr->next = p;

    // Now deleting the node val
    struct node *a = start;
    struct node *b = start->next;
    while (b->data != val && b->next != NULL)
    {
        a = a->next;
        b = b->next;
    }
    if (b->data == val)
    {
        a->next = b->next;
        free(b);
    }
    return start;
}
// 9.Delete from beginning
struct node *delete_begin(struct node *start)
{
    struct node *p = start;
    start = start->next;
    free(p);
    return start;
}
// 10.Delete from end
struct node *delete_end(struct node *start)
{
    struct node *p = start;
    struct node *q = start->next;
    while (q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }

    p->next = NULL;
    free(q);
    return start;
}
// 11.Delete a Given node
struct node *delete_node(struct node *start)
{
    int val;
    printf("\n Enter the node you want to delete ");
    scanf("%d", &val);
    struct node *p = start;
    struct node *q = start->next;
    while (q->data != val && q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    if (q->data == val)
    {
        p->next = q->next;
        free(q);
    }
    else
    {
        printf("\n Node not found");
    }
    return start;
}
// 12.Delete a node after a given Node
struct node *delete_after(struct node *start)
{
    int val;
    printf("\n Enter the node after you want to delete ");
    scanf("%d", &val);
    struct node *p = start;
    struct node *q;
    while (q->data != val && q->next != NULL)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    return start;
}
// 13.Delete the entire list
struct node *delete_full(struct node *start)
{
    struct node *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_begin(ptr);
            ptr = start;
        }
    }
    return start;
}
// 14.Sorting of a linked list

struct node *sort(struct node *start)
{
    struct node *ptr1, *ptr2;
    int temp;
    ptr1 = start;
    while (ptr1->next != NULL)
    {
        ptr2 = ptr1->next;
        while (ptr2 != NULL)
        {
            if (ptr1->data > ptr2->data) // checking condition in order to sort
            {
                temp = ptr1->data; // using temp variable
                ptr1->data = ptr2->data;
                ptr2->data = temp;
            }
            ptr2 = ptr2->next;
        }
        ptr1 = ptr1->next;
    }
    return start;
}
// 15.Appending a linked list
struct node *append(struct node *start)
{
    int index;
    printf("\nEnter the position of Appending ");
    scanf("%d", &index);
    struct node *ptr = start;
    struct node *newhead = (struct node *)malloc(sizeof(struct node));
    struct node *newtail = (struct node *)malloc(sizeof(struct node));

    // Code for finding length of list
    int length = 0;
    struct node *p = ptr;
    while (p != NULL)
    {
        length++;
        p = p->next;
    }
    // Main code for appending
    int count = 1;
    while (ptr->next != NULL)
    {
        // Assigning newtail
        if (count == length - index)
        { // Position of appending
            newtail = ptr;
        }
        // Assigning newhead
        if (count == length + 1 - index)
        { // position just after newTail will be newhead after appending
            newhead = ptr;
        }
        ptr = ptr->next;
        count++;
    }
    newtail->next = NULL;
    ptr->next = start; // Linking newhead(ptr) as required
    start = newhead;   // newhead becomes start
    return start;
}
// 16.Length of a Linked list
struct node *length(struct node *start)
{
    int i = 0;
    struct node *temp = start;
    while (temp != NULL)
    {
        i++;
        temp = temp->next;
    }
    printf("\n Length of this Linked List is : %d ", i);
    return start;
}
// 17.Searching in a linked list
struct node *search(struct node *start)
{
    int val;
    printf("\n Enter the value you want to search ");
    scanf("%d", &val);
    struct node *ptr = start;
    int i = 0;
    while (ptr->next != NULL)
    {
        if (ptr->data == val)
        {
            printf("\n %d is found at position %d", val, i + 1);
        }

        ptr = ptr->next;
        i++;
    }
    return start;
}

/**********************************************************************************************************************************/
/**********************************************************************************************************************************/

//********CIRCULAR LINKED LIST************

// CIRCULAR LINKED LIST WORK IN A CIRCULAR MANNER LAST->NEXT WILL BE START NOT NULL

// 1.Creating a Circular Linked List

struct node *create_circular(struct node *start)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    struct node *ptr = (struct node *)malloc(sizeof(struct node));
    int num;
    printf("\n Enter any number to add in list | -1 to make it");
    printf("\n Enter the data : ");
    scanf("%d", &num);
    while (num != -1)
    { //-1 shows list not started(error statement)
        new_node->data = num;
        if (start == NULL)
        {                              // Empty linked list
            new_node->next = new_node; // Inserted the element num
            start = new_node;          // At beginning so start become new_node
        }
        else
        {
            ptr = start; // Saving start pointer to avoid garbage value
            // Adding element after start element
            while (ptr->next != start) // POINTER NEXT WILL BE EQUAL TO START AS IT IS CIRCULAR
            {

                ptr = ptr->next;
                ptr->next = new_node;
                new_node->next = start; // POINTER NEXT WILL BE EQUAL TO START AS IT IS CIRCULAR
            }
            printf("\n Enter the data : ");
            scanf("%d", &num);
        }
    }
    return start;
}
// 2.Display a CIRCULAR Linked list

struct node *display_circular(struct node *start)
{
    if (start != NULL)
    {
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr = start;
        int i = 1;
        while (ptr->next != start) // CIRCULAR LINKED LIST
        {
            printf("\n Element %d : %d", i, ptr->data);
            ptr = ptr->next;
            i++;
        }
        printf("\n Element %d : %d", i, ptr->data);
        return start;
    }
    else
    {
        printf("\n NO ELEMENTS PRESENT IN THIS CIRCULAR LINKED LIST ");
        return start;
    }
}

// 3.Insert at beginning OF A CIRCULAR LINKED LIST
struct node *insert_at_begin_circular(struct node *start)
{
    if (start != NULL)
    {
        int num;
        printf("\n Enter the number to insert at beginning : ");
        scanf("%d", &num);
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = num;

        // Approach for Insertion is to traverse at last then insert at beginning to avoid any random values

        struct node *p = start->next;
        while (p->next != start)
        { // Circular manner
            p = p->next;
        }
        p->next = ptr;
        ptr->next = start;
        start = ptr;
        return start;
    }
    else
    {
        printf("\n PLEASE CREATE A CIRCULAR LINKED LIST FIRST BY SELECTING OPTION 1 ");
        return start;
    }
}

// 4.Insert at End OF A CIRCULAR LINKED LIST
struct node *insert_at_end_circular(struct node *start)
{
    if (start != NULL)
    {
        int num;
        printf("\n Enter the number to insert at End : ");
        scanf("%d", &num);
        struct node *ptr = (struct node *)malloc(sizeof(struct node));
        ptr->data = num;         // Node to be added
        struct node *p = start;  // Saving our start node
        while (p->next != start) // Circlar manner
        {
            p = p->next;
        }
        // Now reached at the last node
        p->next = ptr;
        ptr->next = start; // Circlar manner

        return start;
    }
    else
    {
        printf("\n PLEASE CREATE A CIRCULAR LINKED LIST FIRST BY SELECTING OPTION 1 ");
        return start;
    }
}

// 5.Delete from beginning OF A CIRCULAR LINKED LIST
struct node *delete_begin_circular(struct node *start)
{
    struct node *p = start->next;
    while (p->next != start)
    {
        p = p->next;
    }
    p->next = start->next;
    free(start);
    start = p->next;
    return start;
}
// 6.Delete from end OF A CIRCULAR LINKED LIST
struct node *delete_end_circular(struct node *start)
{
    struct node *p = start;
    struct node *q = start->next;
    while (q->next != start) // Circular manner
    {
        p = p->next;
        q = q->next;
    }

    p->next = start; // Circular manner
    free(q);
    return start;
}

// 7.Delete a node after a given Node OF A CIRCULAR LINKED LIST
struct node *delete_after_circular(struct node *start)
{
    int val;
    printf("\n Enter the node after you want to delete ");
    scanf("%d", &val);
    struct node *p = start;
    struct node *q;
    while (q->data != val && q->next != start)
    {
        q = p;
        p = p->next;
    }
    q->next = p->next;
    free(p);
    return start;
}
// 8.Delete the entire CIRCULAR LINKED LIST
struct node *delete_full_circular(struct node *start)
{
    struct node *ptr;
    ptr = start;
    // while (ptr->next != start){
    //     start = delete_end_circular(start);
    // free(start);
    // }
    do
    {
        start = delete_end_circular(start);

    } while (ptr->next != start);
    free(ptr);
    start = NULL;
    return start;
}

/*******************************************************************************************************************************/
/*******************************************************************************************************************************/

//************DOUBLY LINKED LIST **************/

// 1.Create a DOUBLY LINKED LIST
// We can traverse both to and fro in a doubly linked list

struct node_d *create_double(struct node_d *start_double)
{
    struct node_d *new_node, *ptr;
    int num_double;
    printf("\n Enter any num| -1 to terminate ");
    printf("\n Enter the data : ");
    scanf("%d", &num_double);

    while (num_double != -1)
    {

        // Case 1 Empty Doubly linked list
        if (start_double == NULL)
        {
            new_node = (struct node_d *)malloc(sizeof(struct node));

            new_node->prev = NULL;       // Creating a doubly linked list with 2 sides traversal possible
            new_node->data = num_double; // Creating a doubly linked list with 2 sides traversal possible
            new_node->next = NULL;       // Creating a doubly linked list with 2 sides traversal possible
        }

        // Case 2 Filled Linked list
        else
        {
            ptr = start_double;
            new_node = (struct node_d *)malloc(sizeof(struct node_d));
            new_node->data = num_double;
            while (ptr->next != NULL)
            {
                ptr = ptr->next;
            }
            ptr->next = new_node;  // Adding node at end
            new_node->prev = ptr;  // Previous will be obviously pointer
            new_node->next = NULL; // next Would be NULL pointer
        }
        printf("\n Enter the Data : ");
        scanf("%d", &num_double);
    }

    return start_double;
}

// 2.Display a DOUBLY LINKED LIST
struct node_d *display_double(struct node_d *start)
{
    struct node_d *ptr = (struct node_d *)malloc(sizeof(struct node_d));
    ptr = start;
    int i = 1;
    while (ptr != NULL)
    {
        printf("\n Element %d : %d", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
    return start;
}

// 3. Insert at Beginning IN A DOUBLY LINKED LIST

struct node_d *insert_at_begin_double(struct node_d *start)
{

    struct node_d *ptr;
    int num;
    printf("\n Enter the Data : ");
    scanf("%d", &num);
    ptr = (struct node_d *)malloc(sizeof(struct node_d));

    ptr->data = num;
    if (start != NULL)
    {
        start->prev = ptr; // Adding at head/beginning
    }
    ptr->next = start; // Making Links
    ptr->prev = NULL;  // Making Links
    start = ptr;
    return start;
}

// 4.Insert at End IN A DOUBLY LINKED LIST

struct node_d *insert_at_end_double(struct node_d *start)
{

    struct node_d *ptr, *new_node;
    int num;
    printf("\n Enter the Data : ");
    scanf("%d", &num);
    new_node = (struct node_d *)malloc(sizeof(struct node_d));

    new_node->data = num; // to be inserted node

    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = new_node;  // Making links in a chain
    new_node->prev = ptr;  // Making links in a chain
    new_node->next = NULL; // Making links in a chain
    return start;
}

// 5.Insert before a Node in a DOUBLY LINKED LIST
struct node_d *insert_before_double(struct node_d *start)
{
    struct node_d *ptr, *new_node;
    int num, val;

    printf("\n Enter the value before which data has to be inserted ");
    scanf("%d", &val);
    printf("\n Enter the Data : ");
    scanf("%d", &num);
    new_node = (struct node_d *)malloc(sizeof(struct node_d));

    new_node->data = num; // to be inserted node
    ptr = start;

    if (start != NULL)
    {
        while (ptr->data != val)
        {

            ptr = ptr->next;
        }
        new_node->next = ptr;

        new_node->prev = ptr->prev;
        ptr->prev->next = new_node; // ptr=new_node(to be inserted)

        ptr->prev = new_node; // Making Links

        return start;
    }
    else
    {
        printf("\n Insert an Element First ");
        return start;
    }
}
// 6.Insert after a node DOUBLY LINKED LIST

struct node_d *insert_after_double(struct node_d *start)
{
    struct node_d *ptr, *new_node;
    int num, val;
    printf("\n Enter the Data : ");
    scanf("%d", &num);
    printf("\n Enter the value after which data has to be inserted ");
    scanf("%d", &val);
    new_node = (struct node_d *)malloc(sizeof(struct node_d));

    new_node->data = num; // to be inserted node
    ptr = start;

    while (ptr->data != val)

        ptr = ptr->next;

    // new_node->next=ptr;
    // new_node->prev=ptr->prev;
    // ptr->prev->next=new_node;   //placing new node in place of ptr
    // ptr->prev=new_node;         //Making Links

    new_node->prev = ptr;       // Making links as in a Chain
    new_node->next = ptr->next; // Making links as in a Chain
    ptr->next->prev = new_node; // new node in place of ptr
    ptr->next = new_node;       // Making links as in a Chain
    return start;
}

// 7.Delete At Beginning OF A DOUBLY LINKED LIST

struct node_d *delete_begin_double(struct node_d *start)
{
    struct node_d *ptr;
    ptr = start;
    start = start->next;
    start->prev = NULL;
    free(ptr);
    return start;
}

// 8.Delete at end OF A DOUBLY LINKED LIST
struct node_d *delete_end_double(struct node_d *start)
{
    struct node_d *ptr;
    ptr = start;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = NULL; // Making NULL in place of ptr
    free(ptr);
    return start;
}

// 9.Delete a node after a given node IN DOUBLY LINKED LIST

struct node_d *delete_after_double(struct node_d *start)
{
    struct node_d *ptr, *temp;
    int val;
    printf("\n Enter the value after which the node has to be deleted ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->next; // to be deleted node
    ptr->next = temp->next;
    temp->next->prev = ptr; // ptr in place of temp
    free(temp);
    return start;
}

// 10.Delete a node before a given node IN DOUBLY LINKED LIST

struct node_d *delete_before_double(struct node_d *start)
{
    struct node_d *ptr, *temp;
    int val;
    printf("\n Enter the value before which the node has to be deleted ");
    scanf("%d", &val);
    ptr = start;
    while (ptr->data != val)
    {
        ptr = ptr->next;
    }
    temp = ptr->prev; // to be deleted node
    if (temp == start)
    { // case when deleted node is first node itself
        start = delete_begin_double(start);
    }
    else
    {
        ptr->prev = temp->prev;
        temp->prev->next = ptr; // ptr in place of temp
    }
    free(temp);
    return start;
}
// 11.Delete the Entire DOUBLY LINKED LIST
struct node_d *delete_full_double(struct node_d *start)
{
    // Same as Singly linked list
    struct node_d *ptr;
    if (start != NULL)
    {
        ptr = start;
        while (ptr->next != NULL)
        {
            printf("\n %d is to be deleted next", ptr->data);
            start = delete_begin_double(ptr);
            ptr = start;
        }
        free(start);
    }
    start = NULL;
    return start;
}

//*********************************CIRCULAR DOUBLE LINKED LIST *************************************************************************/
//*************************************************************************************************************************************/

// 1.Create a CIRCULAR DOUBLY LINKED LIST
// We can traverse both to and fro in a doubly linked list

struct node_d *create_circular_double(struct node_d *begin)
{
    struct node_d *new_node, *ptr;
    int num_double;
    printf("\n Enter any num| -1 to terminate ");
    printf("\n Enter the data : ");
    scanf("%d", &num_double);

    while (num_double != -1)
    {

        // Case 1 Empty Doubly linked list
        if (begin == NULL)
        {
            new_node = (struct node_d *)malloc(sizeof(struct node_d));

            new_node->prev = NULL;       // Creating a doubly circular linked list with 2 sides traversal possible
            new_node->data = num_double; // Creating a doubly circular linked list with 2 sides traversal possible
            new_node->next = begin;      // Creating a doubly circular linked list with 2 sides traversal possible -->Circular manner
            begin = new_node;
        }

        // Case 2 Filled Linked list
        else
        {
            ptr = begin;
            new_node = (struct node_d *)malloc(sizeof(struct node_d));
            new_node->data = num_double;
            while (ptr->next != begin) // Circular manner
            {
                ptr = ptr->next;

                // Adding node at end
                new_node->prev = ptr; // Previos will be obviously pointer
                ptr->next = new_node;
                new_node->next = begin; // next Would be again start_double pointer pointer
                begin->prev = new_node;
            }
        }
        printf("\n Enter the Data : ");
        scanf("%d", &num_double);
    }

    return begin;
}

// 2.Display a CIRCULAR DOUBLY LINKED LIST
struct node_d *display_circular_double(struct node_d *begin)
{
    if (begin != NULL)
    {
        struct node_d *ptr = (struct node_d *)malloc(sizeof(struct node_d));
        ptr = begin;
        int i = 1;
        while (ptr->next != begin) // Circular manner
        {
            printf("\n Element %d : %d", i, ptr->data);
            ptr = ptr->next;
            i++;
        }
        printf("\n Element %d : %d", i, ptr->data);
        return begin;
    }
    else
    {
        printf("\n NO elements present");
        return begin;
    }
}

// 3. Insert at Beginning IN A CIRCULAR DOUBLY LINKED LIST

struct node_d *insert_at_begin_circular_double(struct node_d *begin)

{
    if (begin != NULL)
    {
        struct node_d *ptr, *new_node;
        int num;
        printf("\n Enter the Data to insert at beginning : ");
        scanf("%d", &num);
        new_node = (struct node_d *)malloc(sizeof(struct node_d));

        new_node->data = num;
        ptr = begin;

        // Same approach as to add node after traversing till end and add the node at the beginning

        while (ptr->next != begin)
        {
            ptr = ptr->next;
        }
        new_node->prev = ptr;   // Making links as in a linked list
        ptr->next = new_node;   // Making links as in a linked list
        new_node->next = begin; // Making links as in a linked list
        begin->prev = new_node; // Making links as in a linked list
        begin = new_node;

        return begin;
    }
    else
    {
        printf("\n Create a List first by Selecting Option 1 ");
        return begin;
    }
}

// 4.Insert at End IN A CIRCULAR DOUBLY LINKED LIST

struct node_d *insert_at_end_circular_double(struct node_d *begin)
{
    // Same as doubly linked list Just to add prev+next both pointers
    if (start != NULL)
    {
        struct node_d *ptr, *new_node;
        int num;
        printf("\n Enter the Data : ");
        scanf("%d", &num);
        new_node = (struct node_d *)malloc(sizeof(struct node_d));

        new_node->data = num; // to be inserted node

        ptr = begin;
        while (ptr->next != begin) // Circular list so end will not be NULL
        {
            ptr = ptr->next;
        }
        ptr->next = new_node;   // Making links in a chain
        new_node->prev = ptr;   // Making links in a chain
        new_node->next = begin; // Making links in a chain
        begin->prev = new_node;

        return begin;
    }
    else
    {
        printf("\n Create a List first by Selecting Option 1 ");
        return begin;
    }
}

// 5.Delete At Beginning OF A CIRCULAR DOUBLY LINKED LIST

struct node_d *delete_begin_circular_double(struct node_d *begin)
{
    struct node_d *ptr, *temp;
    ptr = begin;
    while (ptr->next != begin)
    {
        ptr = ptr->next;
    }
    ptr->next = begin->next; // Because Begin is to be deleted
    temp = begin;
    begin = begin->next;
    begin->prev = ptr; // ptr=last node

    free(temp);
    return begin;
}

// 6.Delete at end OF A CIRCULAR DOUBLY LINKED LIST
struct node_d *delete_end_circular_double(struct node_d *begin)
{
    struct node_d *ptr;
    ptr = begin;
    while (ptr->next != begin)
    {
        ptr = ptr->next;
    }
    ptr->prev->next = begin; // Making start in place of ptr to complete Circular
    begin->prev = ptr->prev; // because last node (ptr) is to be deleted

    free(ptr);
    return begin;
}

// 7.Delete a Given Node in a Circular Linked List

struct node_d *delete_node_circular_double(struct node_d *begin)
{
    struct node_d *ptr;
    int val;
    printf("\n Enter the node which has to be deleted ");
    scanf("%d", &val);
    ptr = begin;
    if (ptr->data == val) // if to be deleted node is first node itself
    {
        begin = delete_begin_circular_double(begin);
        return begin;
    }
    else
    {
        while (ptr->data != val)
        {
            ptr = ptr->next;
        }
        ptr->prev->next = ptr->next; // Making ptr=ptr->next
        ptr->next->prev = ptr->prev; // ptr->prev=ptr

        // Basically we are deleting ptr(i.e,required ) and making links between prev and next of pointer

        free(ptr);
        return begin;
    }
}

// 8.Deleting The Entire CIRCULAR DOUBLY LINKED LIST

struct node_d *delete_full_circular_double(struct node_d *begin)
{
    // Same as Singly linked list
    struct node_d *ptr;
    ptr = begin;
    while (ptr->next != begin)
    {
        printf("\n %d is to be deleted next", ptr->data);
        begin = delete_begin_double(ptr);
        ptr = begin;
    }
    free(begin);

    begin = NULL;
    return begin;
}

/**************************************************************************************************************************************/
/**************************************************************************************************************************************/

//************INT MAIN****************
int main()
{
    int option;
    int number;
    int option_circular;
    int option_double;

    printf("\n\n *******MAIN MENU*******");
    do
    {
        printf("\n\n ******COMPLETE LINKED LIST WITH ALL OPERATIONS********\n");

        printf("\n 1: Singly linked list ");
        printf("\n 2: Circular linked list");
        printf("\n 3: Doubly linked list");
        printf("\n 4: Exit ");
        printf("\n Enter a Number as per your choice ");

        scanf("%d", &number);
        switch (number)
        {
        case 1:

            do
            {
                printf("\n\n*******Singly Linked List Complete******");
                printf("\n 1: Create a list");
                printf("\n 2: Display the list");
                printf("\n 3: Add a node at the beginning");
                printf("\n 4: Add a node at the end");
                printf("\n 5: Add a node in between at an index");
                printf("\n 6: Add a node before a given node");
                printf("\n 7: Add a node after a given node");
                printf("\n 8: Replace a given node with new");
                printf("\n 9: Delete a node from the beginning");
                printf("\n 10: Delete a node from the end");
                printf("\n 11: Delete a given node");
                printf("\n 12: Delete a node after a given node");
                printf("\n 13: Delete the entire list");
                printf("\n 14: Sort the list");
                printf("\n 15: Append a Linked list");
                printf("\n 16: Length of a linked list");
                printf("\n 17: Searching in a Linked list");
                printf("\n 18: Exit ");
                printf("\n\n Enter your option : ");
                scanf("%d", &option);

                switch (option)
                {
                case 1:
                    start = create(start);
                    printf("\n LINKED LIST CREATED");
                    break;
                case 2:
                    start = display(start);
                    break;
                case 3:
                    start = insert_at_begin(start);
                    break;
                case 4:
                    start = insert_at_end(start);
                    break;

                case 5:
                    start = insert_at_idx(start);
                    break;

                case 6:
                    start = insert_before(start);
                    break;
                case 7:
                    start = insert_after(start);
                    break;
                case 8:
                    start = replace(start);
                    break;
                case 9:
                    start = delete_begin(start);
                    printf("\n Beginning node is deleted ");
                    break;
                case 10:
                    start = delete_end(start);
                    printf("\n End node is deleted ");
                    break;
                case 11:
                    start = delete_node(start);
                    printf("\n Given node is deleted ");
                    break;
                case 12:
                    start = delete_after(start);
                    printf("\n Selected Node is deleted ");
                    break;
                case 13:
                    start = delete_full(start);
                    printf("\n Full Linked list is deleted ");
                    break;
                case 14:
                    start = sort(start);
                    printf("\n Linked List is sorted ");
                    break;
                case 15:
                    start = append(start);
                    break;
                case 16:
                    start = length(start);
                    break;
                case 17:
                    start = search(start);
                    break;
                }

            } while (option != 18);

            break;
        case 2:

            do
            {

                printf("\n\n*******Circular Linked List Complete******");
                printf("\n 1: Create a list");
                printf("\n 2: Display the list");
                printf("\n 3: Add a node at the beginning");
                printf("\n 4: Add a node at the end");
                printf("\n 5: Delete a node from beginning");
                printf("\n 6: Delete a node from the end");
                printf("\n 7: Delete a node after a given node");
                printf("\n 8: Delete the entire list");
                printf("\n 9: Exit");
                printf("\n\n Enter your option : ");
                scanf("%d", &option_circular);

                switch (option_circular)
                {
                case 1:
                    start_circular = create_circular(start_circular);

                    break;

                case 2:
                    start_circular = display_circular(start_circular);

                    break;

                case 3:
                    start_circular = insert_at_begin_circular(start_circular);

                    break;

                case 4:
                    start_circular = insert_at_end_circular(start_circular);

                    break;

                case 5:
                    start_circular = delete_begin_circular(start_circular);
                    printf("\n Beginning node is deleted");

                    break;

                case 6:
                    start_circular = delete_end_circular(start_circular);
                    printf("\n End node is deleted");

                    break;

                case 7:
                    start_circular = delete_after_circular(start_circular);
                    printf("\n Selected node is deleted");

                    break;

                case 8:
                    start_circular = delete_full_circular(start_circular);
                    printf("\n Complete node is deleted");

                    break;
                default:
                    printf("\n INVALID OPTION CHOSEN ");
                    break;
                }

            } while (option_circular != 9);

            break;
        case 3:
            do
            {

                printf("\n\n*******Doubly Linked List Complete******");
                printf("\n 1: Create a list");
                printf("\n 2: Display the list");
                printf("\n 3: Add a node at the beginning");
                printf("\n 4: Add a node at the end");
                printf("\n 5: Add a node before a given node");
                printf("\n 6: Add a node after a given node ");
                printf("\n 7: Delete a node from beginning");
                printf("\n 8: Delete a node from the end");
                printf("\n 9: Delete a node after a given node");
                printf("\n 10: Delete a node before a given node");
                printf("\n 11: Delete the entire list");
                printf("\n 12: Exit");
                printf("\n\n Enter your option : ");
                scanf("%d", &option_double);

                switch (option_double)
                {
                case 1:
                    start_double = create_double(start_double);
                    printf("\n Doubly Linked List is Created ");
                    break;

                case 2:
                    start_double = display_double(start_double);

                    break;

                case 3:
                    start_double = insert_at_begin_double(start_double);
                    printf("\n Inserted Successfully at Begin ");

                    break;

                case 4:
                    start_double = insert_at_end_double(start_double);
                    printf("\n Inserted at End Successfully ");
                    break;

                case 5:
                    start_double = insert_before_double(start_double);
                    printf("\n Inserted Successfully ");
                    break;

                case 6:
                    start_double = insert_after_double(start_double);
                    printf("\n Inserted Successfully");

                    break;

                case 7:
                    start_double = delete_begin_double(start_double);
                    printf("\n Beginning node is deleted");

                    break;

                case 8:
                    start_double = delete_end_double(start_double);
                    printf("\n End node is deleted");

                    break;
                case 9:
                    start_double = delete_after_double(start_double);
                    printf("\n Selected node is deleted");

                    break;
                case 10:
                    start_double = delete_before_double(start_double);
                    printf("\n Selected node is deleted");

                    break;
                case 11:
                    start_double = delete_full_double(start_double);
                    printf("\n Full DOUBLY LINKED LIST is deleted");

                    break;

                default:
                    printf("\n INVALID OPTION CHOSEN ");
                    break;
                }

            } while (option_double != 12);

            break;
        case 5:
            int option_double_circular;
            struct node_d *start_circular_double;
            do
            {

                printf("\n\n*******Circular Doubly Linked List Complete******");
                printf("\n 1: Create a list");
                printf("\n 2: Display the list");
                printf("\n 3: Add a node at the beginning");
                printf("\n 4: Add a node at the end");
                printf("\n 5: Delete a node from beginning");
                printf("\n 6: Delete a node from the end");
                printf("\n 7: Delete a given node");
                printf("\n 8: Delete the entire list");
                printf("\n 9: Exit");
                printf("\n\n Enter your option : ");
                scanf("%d", &option_double_circular);

                switch (option_double_circular)
                {
                case 1:
                    start_circular_double = create_circular_double(start_circular_double);
                    printf("\n Circular Doubly Linked List is Created Successfully ");
                    break;

                case 2:
                    start_circular_double = display_circular_double(start_circular_double);

                    break;

                case 3:
                    start_circular_double = insert_at_begin_circular_double(start_circular_double);

                    break;

                case 4:
                    start_circular_double = insert_at_end_circular_double(start_circular_double);

                    break;

                case 5:
                    start_circular_double = delete_begin_circular_double(start_circular_double);

                    break;

                case 6:
                    start_circular_double = delete_end_circular_double(start_circular_double);
                    printf("\n End node is deleted");

                    break;

                case 7:
                    start_circular_double = delete_node_circular_double(start_circular_double);
                    printf("\n Selected node is deleted");

                    break;

                case 8:
                    start_circular_double = delete_full_circular_double(start_circular_double);
                    printf("\n Complete node is deleted");

                    break;
                default:
                    printf("\n INVALID OPTION CHOSEN ");
                    break;
                }

            } while (option_double_circular != 9);

            break;
        }
    } while (number != 4);

    return 0;
}