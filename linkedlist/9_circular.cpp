#include <iostream>
using namespace std;
/*A main point

Here to change the value NODE*& is used because we are
changing the exact value of pointers here.Because Pointers
are used to represent/insert/delete in a linked list .
When we simply used to call by value NODE() is used
and if we want to change the value only using references then call
by value is used i.e., NODE*

*/

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

void print(node *ptr)

{
    node *head = ptr;
    do
    {
        cout << head->data << " ";
        head = head->next;
    } while (head != ptr);
}

// Insertion at head of a circular linked list

void insertatHead(node *&head, int data)
{
    node *n = new node(data);
    if (head == NULL)
    {
        n->next = n;
        head = n;
        return;
    }
    node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->next = head;
    head = n;
};
// Insert at tail of a Circular Linked List
void insertatTail(node *&head, int data)
{
    if (head == NULL)
    {
        insertatHead(head, data);
        return;
    }
    node *n = new node(data);
    node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    ptr->next = n;
    n->next = head;
};
void deleteatHead(node *&head)
{
    node *ptr = head;
    while (ptr->next != head)
    {
        ptr = ptr->next;
    }
    node *todelete = head;
    ptr->next = head->next;
    head = head->next;
    delete (head);
}
// Delete a node from a circular linked list
void deleteAtEnd(node *&head, int pos)
{
    if (pos == 1)
    {
        deleteatHead(head);
        return;
    }
    node *ptr = head;
    int count = 1;
    while (count != pos - 1)
    {
        ptr = ptr->next;
        count++;
    }
    node *todelete = ptr->next;
    ptr->next = ptr->next->next;
    delete (todelete);
}

int main()
{
    node *list = NULL;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0; i < 10; i++)
    {
        insertatTail(list, arr[i]);
    }
    print(list);
    cout << endl;
    insertatTail(list, 2);
    cout << "list After inserting 2 at end\n";
    print(list);
    cout << endl;
    deleteAtEnd(list, 3);
    cout << "After deleting at 3rd position\n";
    print(list);
    cout << endl;
    deleteAtEnd(list, 6);
    cout << "After deleting at 6rd position\n";
    print(list);
    cout << endl;

    return 0;
}