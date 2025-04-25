#include <iostream>
using namespace std;

// FLOYD'S ALGORITHM
// HARE AND TORTOISE ALGORITHM
// FOR DEETCTING,REMOVING A CYCLE FROMA LINKED LIST

class node
{
private:
    /* data */
public:
    int data;
    node *next;
    node(int value)
    {
        data = value;
        next = NULL;
    }
};

// Making a Cycle in Linked List
void MakeCircularlist(node *&head, int pos)
{

    node *ptr = head;
    node *p;
    int count = 1;
    while (ptr->next != NULL)
    {
        if (count = pos)
        {
            p = ptr;
        }
        ptr = ptr->next;
        count++;
    }
    ptr->next = p;
}
// Detecting a Cycle in Linked List
bool detectCycle(node *&head)
{
    node *slow = head;
    node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (fast == slow) // When fast and slow become eqaul then we are in a loop/Cycle
        {
            return 1;
        }
    }
    return 0;
}
// Removing a cycle from Linked list
void removecycle(node *head)
{
    node *slow = head;
    node *fast = head;
    do
    {
        slow = slow->next;
        fast = fast->next->next;
    } while (slow != fast);
    fast = head;
    while (slow->next != fast->next)
    {
        slow = slow->next;
        fast = fast->next;
    }
    slow->next = NULL;
}
void print(node *head)
{
    node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

int main()
{
    // Allocate memory for linked list in heap
    node *head = (node *)malloc(sizeof(node));
    node *second = (node *)malloc(sizeof(node));
    node *third = (node *)malloc(sizeof(node));
    node *fourth = (node *)malloc(sizeof(node));
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
    print(head);
    cout << "\n"
         << detectCycle(head) << endl;
    MakeCircularlist(head, 1);
    // print(head);
    cout << detectCycle(head) << endl;
    removecycle(head);
    cout << detectCycle(head) << endl;
    print(head);
}