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
        insertAtHead(head, 1);
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
void *append(node *&head, int index)
{

    node *newhead = (node *)malloc(sizeof(node));
    node *newtail = (node *)malloc(sizeof(node));
    node *ptr = head;
    int l = length(head);
    index = index % l;

    int count = 1;
    while (ptr->next != NULL)
    {
        if (count == l - index)
        {                  // Reaching to the location of appending
            newtail = ptr; // new tail become the location before appending
        }
        // Now assiging new head
        if (count == l - index + 1)
        {
            newhead = ptr;
        }
        ptr = ptr->next;
        count++;
    }
    newtail->next = NULL;
    ptr->next = head;
    head = newhead;
};

int main()
{
    node *head = NULL;
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for (int i = 0; i < 10; i++)
    {
        insertatTail(head, arr[i]);
    }
    // int n;
    // int arr[n];
    // cout << "Enter size of linked list" << endl;
    // cin >> n;
    // cout << "Enter Elements of Linked List" << endl;
    // for (int i = 0; i < n; i++)
    // {
    //     cin >> arr[i];
    //     insertatTail(head, arr[i]);
    // }

    display(head);
    cout << endl;
    cout << length(head) << endl;
    append(head, 5);
    cout << "Linked list after appending at 5\n";
    display(head);


    
}