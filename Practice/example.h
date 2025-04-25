// // extern int a=50;

// //*********CIRCULAR DOUBLE LINKED LIST ***********/

// // 1.Create a CIRCULAR DOUBLY LINKED LIST
// // We can traverse both to and fro in a doubly linked list

// struct node_d *create_circular_double(struct node_d *begin)
// {
//     struct node_d *new_node, *ptr;
//     int num_double;
//     printf("\n Enter any num| -1 to terminate ");
//     printf("\n Enter the data : ");
//     scanf("%d", &num_double);

//     while (num_double != -1)
//     {

//         // Case 1 Empty Doubly linked list
//         if (begin == NULL)
//         {
//             new_node = (struct node_d *)malloc(sizeof(struct node_d));

//             new_node->prev = NULL;       // Creating a doubly circular linked list with 2 sides traversal possible
//             new_node->data = num_double; // Creating a doubly circular linked list with 2 sides traversal possible
//             new_node->next = begin;      // Creating a doubly circular linked list with 2 sides traversal possible -->Circular manner
//             begin = new_node;
//         }

//         // Case 2 Filled Linked list
//         else
//         {
//             ptr = begin;
//             new_node = (struct node_d *)malloc(sizeof(struct node_d));
//             new_node->data = num_double;
//             while (ptr->next != begin) // Circular manner
//             {
//                 ptr = ptr->next;
            
//             // Adding node at end
//             new_node->prev = ptr; // Previos will be obviously pointer
//             ptr->next = new_node;
//             new_node->next = begin; // next Would be again start_double pointer pointer
//             begin->prev = new_node;
//         }
//     }
//         printf("\n Enter the Data : ");
//         scanf("%d", &num_double);
//     }

//     return begin;
// }

// // 2.Display a CIRCULAR DOUBLY LINKED LIST
// struct node_d *display_circular_double(struct node_d *begin)
// {
//     if (begin != NULL)
//     {
//         struct node_d *ptr = (struct node_d *)malloc(sizeof(struct node_d));
//         ptr = begin;
//         int i = 1;
//         while (ptr->next != begin) // Circular manner
//         {
//             printf("\n Element %d : %d", i, ptr->data);
//             ptr = ptr->next;
//             i++;
//         }
//         printf("\n Element %d : %d", i, ptr->data);
//         return begin;
//     }
//     else
//     {
//         printf("\n NO elements present");
//         return begin;
//     }
// }

// // 3. Insert at Beginning IN A CIRCULAR DOUBLY LINKED LIST

// struct node_d *insert_at_begin_circular_double(struct node_d *begin)

// {
//     if (begin != NULL)
//     {
//         struct node_d *ptr, *new_node;
//         int num;
//         printf("\n Enter the Data to insert at beginning : ");
//         scanf("%d", &num);
//         new_node = (struct node_d *)malloc(sizeof(struct node_d));

//         new_node->data = num;
//         ptr = begin;

//         // Same approach as to add node after traversing till end and add the node at the beginning

//         while (ptr->next != begin)
//         {
//             ptr = ptr->next;
//         }
//         new_node->prev = ptr;   // Making links as in a linked list
//         ptr->next = new_node;   // Making links as in a linked list
//         new_node->next = begin; // Making links as in a linked list
//         begin->prev = new_node; // Making links as in a linked list
//         begin = new_node;

//         return begin;
//     }
//     else
//     {
//         printf("\n Create a List first by Selecting Option 1 ");
//         return begin;
//     }
// }

// // 4.Insert at End IN A CIRCULAR DOUBLY LINKED LIST

// struct node_d *insert_at_end_circular_double(struct node_d *begin)
// {
//     // Same as doubly linked list Just to add prev+next both pointers
//     if (start != NULL)
//     {
//         struct node_d *ptr, *new_node;
//         int num;
//         printf("\n Enter the Data : ");
//         scanf("%d", &num);
//         new_node = (struct node_d *)malloc(sizeof(struct node_d));

//         new_node->data = num; // to be inserted node

//         ptr = begin;
//         while (ptr->next != begin) // Circular list so end will not be NULL
//         {
//             ptr = ptr->next;
//         }
//         ptr->next = new_node;   // Making links in a chain
//         new_node->prev = ptr;   // Making links in a chain
//         new_node->next = begin; // Making links in a chain
//         begin->prev = new_node;

//         return begin;
//     }
//     else
//     {
//         printf("\n Create a List first by Selecting Option 1 ");
//         return begin;
//     }
// }

// // 5.Delete At Beginning OF A CIRCULAR DOUBLY LINKED LIST

// struct node_d *delete_begin_circular_double(struct node_d *begin)
// {
//     struct node_d *ptr, *temp;
//     ptr = begin;
//     while (ptr->next != begin)
//     {
//         ptr = ptr->next;
//     }
//     ptr->next = begin->next; // Because Begin is to be deleted
//     temp = begin;
//     begin = begin->next;
//     begin->prev = ptr; // ptr=last node

//     free(temp);
//     return begin;
// }

// // 6.Delete at end OF A CIRCULAR DOUBLY LINKED LIST
// struct node_d *delete_end_circular_double(struct node_d *begin)
// {
//     struct node_d *ptr;
//     ptr = begin;
//     while (ptr->next != begin)
//     {
//         ptr = ptr->next;
//     }
//     ptr->prev->next = begin; // Making start in place of ptr to complete Circular
//     begin->prev = ptr->prev; // because last node (ptr) is to be deleted

//     free(ptr);
//     return begin;
// }

// // 7.Delete a Given Node in a Circular Linked List

// struct node_d *delete_node_circular_double(struct node_d *begin)
// {
//     struct node_d *ptr;
//     int val;
//     printf("\n Enter the node which has to be deleted ");
//     scanf("%d", &val);
//     ptr = begin;
//     if (ptr->data == val) // if to be deleted node is first node itself
//     {
//         begin = delete_begin_circular_double(begin);
//         return begin;
//     }
//     else
//     {
//         while (ptr->data != val)
//         {
//             ptr = ptr->next;
//         }
//         ptr->prev->next = ptr->next; // Making ptr=ptr->next
//         ptr->next->prev = ptr->prev; // ptr->prev=ptr

//         // Basically we are deleting ptr(i.e,required ) and making links between prev and next of pointer

//         free(ptr);
//         return begin;
//     }
// }

// // 8.Deleting The Entire CIRCULAR DOUBLY LINKED LIST

// struct node_d *delete_full_circular_double(struct node_d *begin)
// {
//     // Same as Singly linked list
//     struct node_d *ptr;
//     ptr = begin;
//     while (ptr->next != begin)
//     {
//         printf("\n %d is to be deleted next", ptr->data);
//         begin = delete_begin_double(ptr);
//         ptr = begin;
//     }
//     free(begin);

//     begin = NULL;
//     return begin;
// }

//  int option_double_circular;

//  case 4:
//             do
//             {

//                 printf("\n\n*******Circular Doubly Linked List Complete******");
//                 printf("\n 1: Create a list");
//                 printf("\n 2: Display the list");
//                 printf("\n 3: Add a node at the beginning");
//                 printf("\n 4: Add a node at the end");
//                 printf("\n 5: Delete a node from beginning");
//                 printf("\n 6: Delete a node from the end");
//                 printf("\n 7: Delete a given node");
//                 printf("\n 8: Delete the entire list");
//                 printf("\n 9: Exit");
//                 printf("\n\n Enter your option : ");
//                 scanf("%d", &option_double_circular);

//                 switch (option_double_circular)
//                 {
//                 case 1:
//                     start_circular_double = create_circular_double(start_circular_double);
//                     printf("\n Circular Doubly Linked List is Created Successfully ");
//                     break;

//                 case 2:
//                     start_circular_double = display_circular_double(start_circular_double);

//                     break;

//                 case 3:
//                     start_circular_double = insert_at_begin_circular_double(start_circular_double);
                    
//                     break;

//                 case 4:
//                     start_circular_double = insert_at_end_circular_double(start_circular_double);

//                     break;

//                 case 5:
//                     start_circular_double = delete_begin_circular_double(start_circular_double);

//                     break;

//                 case 6:
//                     start_circular_double = delete_end_circular_double(start_circular_double);
//                     printf("\n End node is deleted");

//                     break;

//                 case 7:
//                     start_circular_double = delete_node_circular_double(start_circular_double);
//                     printf("\n Selected node is deleted");

//                     break;

//                 case 8:
//                     start_circular_double = delete_full_circular_double(start_circular_double);
//                     printf("\n Complete node is deleted");

//                     break;
//                 default:
//                     printf("\n INVALID OPTION CHOSEN ");
//                     break;
//                 }

//             } while (option_double_circular != 9);

//             break;
//         case 5:
//             do
//             {

//                 printf("\n\n*******Circular Linked List Complete******");
//                 printf("\n 1: Create a list");
//                 printf("\n 2: Display the list");
//                 printf("\n 3: Add a node at the beginning");
//                 printf("\n 4: Add a node at the end");
//                 printf("\n 5: Add a node before a given node");
//                 printf("\n 6: Add a node after a given node ");
//                 printf("\n 7: Delete a node from beginning");
//                 printf("\n 8: Delete a node from the end");
//                 printf("\n 9: Delete a node before a given node");
//                 printf("\n 10: Delete a node after a given node");
//                 printf("\n 11: Delete the entire list");
//                 printf("\n 12: Exit");
//                 printf("\n\n Enter your option : ");
//                 scanf("%d", &option_double);

//                 switch (option_circular)
//                 {
//                 case 1:
//                     start_circular = create_circular(start_circular);

//                     break;

//                 case 2:
//                     start_circular = display_circular(start_circular);

//                     break;

//                 case 3:
//                     start_circular = insert_at_begin_circular(start_circular);

//                     break;

//                 case 4:
//                     start_circular = insert_at_end_circular(start_circular);

//                     break;

//                 case 5:
//                     start_circular = delete_begin_circular(start_circular);
//                     printf("\n Beginning node is deleted");

//                     break;

//                 case 6:
//                     start_circular = delete_end_circular(start_circular);
//                     printf("\n End node is deleted");

//                     break;

//                 case 7:
//                     start_circular = delete_after_circular(start_circular);
//                     printf("\n Selected node is deleted");

//                     break;

//                 case 8:
//                     start_circular = delete_full_circular(start_circular);
//                     printf("\n Complete node is deleted");

//                     break;
//                 default:
//                     printf("\n INVALID OPTION CHOSEN ");
//                     break;
//                 }

//             } while (option_circular != 9);

//             break;
//         }

//1,2,3,4,5,6
//2,1,4,3,6,5
